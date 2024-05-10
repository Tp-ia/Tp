#ifndef PROFONDEUR_DABORD_H
#define PROFONDEUR_DABORD_H

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

#endif