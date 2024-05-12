#ifndef PROFONDEUR_H
#define PROFONDEUR_H

#include "../jeu/plateau.h"
#include <queue>
using namespace std;

typedef struct{
    bool but;
    Etat *e;
    int lim;
} retour ;

retour ProfondeurDAbord(Etat *e,Etat *etat_but);
retour ProfondeurDAbordBornee(Etat *e,Etat *etat_but,int pas);
Etat ida_star(Etat *initial,Etat *but,int (*h)(Etat*,Etat*));

#endif