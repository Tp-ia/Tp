#include "../jeu/plateau.h"
#include "./profondeur_dabord.h"//juste pour la struct retour, chnager endroit de retour
#include "heuristiques.cpp"
#include <list>
#include <algorithm>

#define MIN 1000;

using namespace std;

//TODO
list<Etat> filsEtatIDA(Etat initial,Etat but,int (*h)(Etat,Etat)){
    list<Etat> successors;
    
    return successors;
}

//TODO
bool contains(Etat actuel,list<Etat> chemin){//parcours dune liste
    auto it = find(chemin.begin(),chemin.end(),actuel);
    if(it !=chemin.end()){
        return true;
    }
    else return false;
}


retour search(list<Etat> &chemin, int g,int lim,int (*h)(Etat,Etat),Etat but){
    retour resultat;
    resultat.but=false;
    Etat node = chemin.back();
    int f =g + h(node,but);
    if(f>lim){
        resultat.lim=f;
        return resultat;
    }
    if(node.equals(&but)){
        resultat.e=&node;
        resultat.but=true;
        return resultat;
    }
    int min=MIN;
    list<Etat> successors = filsEtatIDA(node,but,h);
    for(Etat actuel = successors.front();!successors.empty();actuel=successors.front()){
        if(!contains(actuel,chemin)){
            chemin.push_back(actuel);
            resultat = search(chemin,g+1,lim,h,but);
            if(resultat.but){
                return resultat;
            }
            if(resultat.lim<lim){
                min=resultat.lim;
            }
            chemin.pop_back();
        }
        successors.pop_front();
    }
    return resultat;
}

//RETOUR Etat OU PATH?
Etat ida_star(Etat initial,Etat but,int (*h)(Etat,Etat)){
    int lim = h(initial,but);
    list<Etat> chemin ={initial};
    retour resultat;
    resultat.but=false;
    resultat.e=&initial;
    while(!resultat.but){
        resultat = search(chemin,0,lim,h,but);
        lim=resultat.lim;
    }
    return resultat.but;
}

