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


// retour search(list<Etat> &chemin, int lim,int (*h)(Etat*,Etat*),Etat *but){
//     retour resultat;
//     resultat.but=false;
    
//     Etat node = chemin.back();
//     resultat.e = node.clone();
//     int f = node.getlevel() + node.getcost();
//     // cout<<"debut if\n";
//     if(f>lim){
//         resultat.lim=f;
//         // cout<<"return premier\n";
//         resultat.e = node.clone();
//         return resultat;
//     }
//     // cout<<"2eme if\n";
//     if(node == *but){
//         resultat.e = node.clone();
//         resultat.but=true;
//         return resultat;
//     }
//     // cout<<"fin if\n";
//     int min=MIN;
//     list<Etat> successors = node.filsEtatIDA(but,h);
//     for(Etat actuel = successors.front();!successors.empty();){
//         // cout<<"nouvelle iteration\n";
//         actuel=successors.front();
//         if(!contains(&actuel,chemin)){
//             chemin.push_back(actuel);
//             // cout<<"appele search interne\n";
//             resultat = search(chemin,lim,h,but);
//             // cout<<"fin search interne\n";
//             if(resultat.but){
//                 return resultat;
//             }
    
//             if(resultat.lim<min){
//                 min=resultat.lim;
//             }
//             chemin.pop_back();
//         }
//         // cout<<"pop succ\n";
//         successors.pop_front();
//         // cout<<"reboucle for\n";
//         // cout<<successors.size()<<" size succ\n";
//         // cout<<successors.empty()<<" is emppty succ\n";
//     }
//     // cout<<"end for\n";
//     return resultat;
// }

// //RETOUR Etat OU PATH?
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
    resultat.e = new Etat(0);
    list<Etat> enAttente;
    list<Etat> vus;
    enAttente.push_front(*e);
    int nSeuil = 100000;

    while (!enAttente.empty() && !resultat.but) {
        Etat prochain = enAttente.front();
        vus.push_front(prochain);
        enAttente.pop_front();
        if (prochain == *etat_but) {
            prochain.print();
            resultat.but = true;
            resultat.e = prochain.clone();
        } else {
            list<Etat> q = prochain.filsEtatIDA(etat_but,h);
            for (Etat& fils : q) { // Utilisation d'une référence
                if (fils.getlevel()+fils.getcost()<=lim && !elementDansListe(vus, &fils)) {
                    enAttente.push_front(fils);
                } else {
                    nSeuil = (nSeuil < fils.getlevel()+fils.getcost()) ? nSeuil : fils.getlevel()+fils.getcost();
                }
            }
        }
    }
    if(enAttente.empty()){
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
    r.l = recreateGenealogie(r.e);
    printList(*r.l);
    return r;
}