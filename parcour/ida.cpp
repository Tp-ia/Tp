#include "../jeu/plateau.h"
#include "parcour.h"
#include <list>
#include <algorithm>

#define MIN 1000;

using namespace std;

bool contains(Etat *actuel,list<Etat> chemin){//parcours dune liste
    auto it = find(chemin.begin(),chemin.end(),*actuel);
    if(it !=chemin.end()){
        return true;
    }
    else return false;
}
// retour ida_star(Etat *initial,Etat *but,int (*h)(Etat*,Etat*)){
//     int compteur = 0;
//     int lim = h(initial,but);
//     list<Etat> chemin ={*initial};
//     retour resultat;
//     resultat.but=false;
//     resultat.e=initial;
//     // cout<<"debut while\n";
//     while(!resultat.but){
//         compteur++;
//         // cout<< compteur <<" search\n";
//         resultat = search(chemin,lim,h,but);
//         // cout<< compteur <<"fin search\n";
//         lim=resultat.lim;
//     }
//     return resultat;
// }

list<Etat> *recreateGenealogie(Etat *e){
    list<Etat> *l = new list<Etat>();
    l->push_front(*e);
    while(l->front().getpere()){
        l->push_front(*l->front().getpere());
    }
    return l;
}

void printList(list<Etat> liste){
    for (auto& element : liste)
        element.print();
}

retour ProfondeurDAbordBorneeIDA(Etat *e,Etat *etat_but,int lim, int (*h)(Etat*,Etat*)){
    retour resultat;
    resultat.but = false;
    list<Etat> enAttente;
    list<Etat> vus;
    enAttente.push_front(*e);
    int nSeuil = 100000;
    resultat.lim = lim;
    while (!enAttente.empty() && !resultat.but) {
        Etat prochain = enAttente.front();
        vus.push_front(prochain);
        enAttente.pop_front();
        if (prochain == *etat_but) {
            resultat.but = true;
            resultat.e = prochain.clone();
        } else {
            list<Etat> q = prochain.filsEtatIDA(etat_but,h);
            for (Etat& fils : q) { // Utilisation d'une référence
                if (fils.getlevel()+fils.getcost()<=lim) {
                    if( !elementDansListe(vus, &fils))
                        enAttente.push_front(fils);
                } else {
                    nSeuil = (nSeuil < fils.getlevel()+fils.getcost()) ? nSeuil : fils.getlevel()+fils.getcost();
                }
            }
        }
    }
    if(enAttente.empty()){
        if(resultat.lim<nSeuil)
            resultat.lim = nSeuil;
    }
    return resultat;
}

retour ida_star(Etat *initial,Etat *but,int (*h)(Etat*,Etat*)){
    retour r;
    r.but = false;
    r.lim = h(initial,but);
    int compteur = 0;

    while(!r.but){
        compteur++;
        r = ProfondeurDAbordBorneeIDA(initial, but,r.lim,h);
    }
    // r.l = recreateGenealogie(r.e);
    // printList(*r.l);
    
    return r;
}