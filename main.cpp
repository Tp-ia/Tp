#include "jeu/plateau.h"
#include "parcour/parcour.h"
#include "parcour/heuristiques.h"
#include <cstdlib>
#include <string>


Etat *etat_1 = new Etat(0);
Etat *etat_2 = new Etat(0);
Etat *etat_3 = new Etat(0);
Etat *etat_4 = new Etat(0);
Etat *etat_5 = new Etat(0);
Etat *etat_6 = new Etat(0);
Etat *etat_7 = new Etat(0);
Etat *etat_8 = new Etat(0);

void init_etat(){
    
    etat_1->add_cube(0,3);
    etat_1->add_cube(0,2);
    etat_1->add_cube(1,1);
    etat_1->add_cube(2,6);
    etat_1->add_cube(2,5);
    etat_1->add_cube(2,4);
    etat_1->add_cube(3,7);
    etat_1->add_cube(3,8);
    etat_1->add_cube(3,9);

    etat_2->add_cube(0,3);
    etat_2->add_cube(0,2);
    etat_2->add_cube(0,1);
    etat_2->add_cube(2,6);
    etat_2->add_cube(2,5);
    etat_2->add_cube(2,4);
    etat_2->add_cube(3,7);
    etat_2->add_cube(3,8);
    etat_2->add_cube(3,9);

    etat_3->add_cube(0,3);
    etat_3->add_cube(0,2);
    etat_3->add_cube(0,1);
    etat_3->add_cube(2,6);
    etat_3->add_cube(2,5);
    etat_3->add_cube(2,4);
    etat_3->add_cube(3,7);
    etat_3->add_cube(3,8);
    etat_3->add_cube(3,9);

    etat_4->add_cube(0,3);
    etat_4->add_cube(0,2);
    etat_4->add_cube(0,1);
    etat_4->add_cube(2,6);
    etat_4->add_cube(2,5);
    etat_4->add_cube(2,4);
    etat_4->add_cube(1,9);
    etat_4->add_cube(1,8);
    etat_4->add_cube(1,7);

    etat_5->add_cube(0,3);
    etat_5->add_cube(0,2);
    etat_5->add_cube(0,7);
    etat_5->add_cube(1,6);
    etat_5->add_cube(1,4);
    etat_5->add_cube(1,8);
    etat_5->add_cube(2,9);
    etat_5->add_cube(2,5);
    etat_5->add_cube(2,1);

    etat_6->add_cube(0,3);
    etat_6->add_cube(0,1);
    etat_6->add_cube(0,2);
    etat_6->add_cube(1,6);
    etat_6->add_cube(1,4);

    etat_6->add_cube(1,5);
    etat_6->add_cube(2,9);
    etat_6->add_cube(2,7);
    etat_6->add_cube(2,8);

    etat_7->add_cube(0,3);
    etat_7->add_cube(0,2);
    etat_7->add_cube(0,8);
    etat_7->add_cube(1,6);
    etat_7->add_cube(1,4);
    etat_7->add_cube(2,9);
    etat_7->add_cube(2,7);
    etat_7->add_cube(2,5);
    etat_7->add_cube(3,1);

    etat_8->add_cube(0,4);
    etat_8->add_cube(0,7);
    etat_8->add_cube(0,1);
    etat_8->add_cube(1,5);
    etat_8->add_cube(1,8);
    etat_8->add_cube(1,2);
    etat_8->add_cube(2,6);
    etat_8->add_cube(2,9);
    etat_8->add_cube(2,3);
}
Etat *convertStringToEtat(char *c){
    if(c[0] == '1') return etat_1;
    if(c[0] == '2') return etat_2;
    if(c[0] == '3') return etat_3;
    if(c[0] == '4') return etat_4;
    if(c[0] == '5') return etat_5;
    if(c[0] == '6') return etat_6;
    if(c[0] == '7') return etat_7;
    if(c[0] == '8') return etat_8;
    cerr<<"number etat must be beetween 1 and 8";
    exit(1);
}

int main(int argc, char *argv[]){
    if(argc!=3){
        cerr<<"correct usage: parcour <number etat start> <number etat end>";
    }

    init_etat();

    ida_star(convertStringToEtat(argv[1]),convertStringToEtat(argv[2]),fine);

}