#include "../jeu/plateau.h"
#include "parcour.h"
#include <list>
#include <algorithm>
#include "heuristiques.h"

#define MIN 1000;

using namespace std;


bool contains(Etat *actuel,list<Etat> chemin){//parcours dune liste
    auto it = find(chemin.begin(),chemin.end(),*actuel);
    if(it !=chemin.end()){
        return true;
    }
    else return false;
}



list<Etat> *recreateGenealogie(Etat *e){
    list<Etat> *l = new list<Etat>();
    l->push_front(*e);
    while(l->front().getpere()){
        l->push_front(*l->front().getpere());
    }
    return l;
}

retour ida_sous_fonction(Etat *e,Etat *etat_but,int lim,int (*h)(Etat*,Etat*)){
    retour resultat;
    resultat.but = false;
    resultat.e = new Etat(0);
    resultat.lim=1000;
    list<Etat> enAttente;
    list<Etat> vus;
    enAttente.push_front(*e);
    // int compteur=0;
    while (!enAttente.empty() && !resultat.but ) {
        // compteur++;
        Etat *prochain = enAttente.front().clone(); // Utilisation d'une référence
        enAttente.pop_front();
        vus.push_front(*prochain);
        if (*prochain == *etat_but) {
            resultat.but = true;
            resultat.e = prochain->clone();
        } else {
            list<Etat> q = prochain->filsEtatIDA(etat_but,h);
            for (Etat& fils : q) { // Utilisation d'une référence
                if (fils.getlevel()+fils.getcost()<=lim && !elementDansListe(vus, &fils)) {
                    // cout << fils.getlevel();
                    enAttente.push_front(fils);
                }
                if(fils.getlevel()+fils.getcost()<resultat.lim){
                    resultat.lim=fils.getlevel();
                }
            }
        }
    }
    return resultat;
}

retour ida_star(Etat *initial,Etat *but,int (*h)(Etat*,Etat*)){
    retour r;
    r.but = false;
    int seuil = h(initial,but);
    int compteur = 0;

    while(!r.but){
        compteur++;
        r = ida_sous_fonction(initial, but,seuil,nombreCubeMalMis);
        seuil=r.lim;
    }

    r.l = recreateGenealogie(r.e);
    return r;
}
