#include "heuristiques.h"

int nombreCubeMalMis(Etat *e, Etat *but) {
    std::list<int>::iterator it, it_but;
    int total = 0;
    int compteur = 0;
    for (int i = 0; i < 4; i++) {
        if (but->tiges[i].empty() || e->tiges[i].empty()) {
            total += e->tiges[i].size();
        } else {
            compteur = 0;
            it = e->tiges[i].begin();
            it_but = but->tiges[i].begin();
            while (it != e->tiges[i].end() && it_but != but->tiges[i].end()){
                if (*it != *it_but)
                    break;
                compteur++;
                it++;
                it_but++;
            }
            total += but->tiges[i].size() - compteur;
        }
    }
    return total;
}

int* searchValeur(int valeur,Etat *but){
    int* ij=new int[2];
    for(int i = 0;i<4;i++){
        int j = 0;
        for (auto element : but->tiges[i]){
            if(element ==valeur){
                ij[0]=i;
                ij[1]=j;
                return ij;
            }
            j++;            
        }
    }
}

int fine(Etat *e, Etat *but){
    std::list<int>::iterator it, it_but;
    int total = 0;
    int compteur = 0;
    for (int valeur = 1; valeur < 10; valeur++) {
        int*ij=searchValeur(valeur,e);
        int*ij_but=searchValeur(valeur,but);
        if(ij[0]!=ij_but[0] || ij[1]!=ij_but[1]){
            total += e->tiges[ij[0]].size() - ij[1];
            if(e->tiges[ij_but[0]].size()>ij_but[1]){
                total+= e->tiges[ij_but[0]].size() - ij_but[1];
            }
        }
    }
    return total;
}
