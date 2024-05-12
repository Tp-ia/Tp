#include "../jeu/plateau.h"
#include "parcour.h"
#include <list>
#include <algorithm>

#define MIN 1000;

using namespace std;



//TODO
bool contains(Etat *actuel,list<Etat> chemin){//parcours dune liste
    auto it = find(chemin.begin(),chemin.end(),*actuel);
    if(it !=chemin.end()){
        return true;
    }
    else return false;
}


retour search(list<Etat> &chemin, int lim,int (*h)(Etat*,Etat*),Etat *but){
    retour resultat;
    resultat.but=false;
    Etat node = chemin.back();
    int f = node.getlevel() + node.getcost();
    if(f>lim){
        resultat.lim=f;
        return resultat;
    }
    if(node == *but){
        resultat.e=&node;
        resultat.but=true;
        return resultat;
    }
    int min=MIN;
    list<Etat> successors = node.filsEtatIDA(but,h);
    for(Etat actuel = successors.front();!successors.empty();actuel=successors.front()){
        if(!contains(&actuel,chemin)){
            chemin.push_back(actuel);
            resultat = search(chemin,lim,h,but);
            if(resultat.but){
                return resultat;
            }
            if(resultat.lim<min){
                min=resultat.lim;
            }
            chemin.pop_back();
        }
        successors.pop_front();
    }
    return resultat;
}

//RETOUR Etat OU PATH?
Etat ida_star(Etat *initial,Etat *but,int (*h)(Etat*,Etat*)){
    int compteur = 0;
    int lim = h(initial,but);
    list<Etat> chemin ={*initial};
    retour resultat;
    resultat.but=false;
    resultat.e=initial;
    while(!resultat.but){
        compteur++;
        resultat = search(chemin,lim,h,but);
        lim=resultat.lim;
    }
    cout << compteur;
    return resultat.but;
}

