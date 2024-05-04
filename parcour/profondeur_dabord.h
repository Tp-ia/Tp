#ifndef PROFONDEUR_DABORD_H
#define PROFONDEUR_DABORD_H

#include "../jeu/plateau.h"
#include <queue>
using namespace std;

typedef struct{
    bool but;
    Etat *e;

} retour ;
retour ProfondeurDAbord(Etat *e,Etat *etat_but);

#endif