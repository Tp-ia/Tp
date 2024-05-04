#include "profondeur_dabord.h"
#include "../jeu/plateau.h"

int main(int argc,char ** argv){
    Etat * initial_1=new Etat(0);
    Etat * initial_2=new Etat(0);
    Etat *but_1 = new Etat(0);
    Etat *but_2 = new Etat(0);
    Etat *but_3 = new Etat(0);
    Etat *but_4 = new Etat(0);
    Etat *but_5 = new Etat(0);
    Etat *but_6 = new Etat(0);

    initial_1->add_cube(0,3);
    initial_1->add_cube(0,2);
    initial_1->add_cube(1,1);
    initial_1->add_cube(2,6);
    initial_1->add_cube(2,5);
    initial_1->add_cube(2,4);
    initial_1->add_cube(3,7);
    initial_1->add_cube(3,8);
    initial_1->add_cube(3,9);

    initial_2->add_cube(0,3);
    initial_2->add_cube(0,2);
    initial_2->add_cube(0,1);
    initial_2->add_cube(2,6);
    initial_2->add_cube(2,5);
    initial_2->add_cube(2,4);
    initial_2->add_cube(3,7);
    initial_2->add_cube(3,8);
    initial_2->add_cube(3,9);

    but_1->add_cube(0,3);
    but_1->add_cube(0,2);
    but_1->add_cube(0,1);
    but_1->add_cube(2,6);
    but_1->add_cube(2,5);
    but_1->add_cube(2,4);
    but_1->add_cube(3,7);
    but_1->add_cube(3,8);
    but_1->add_cube(3,9);

    but_2->add_cube(0,3);
    but_2->add_cube(0,2);
    but_2->add_cube(0,1);
    but_2->add_cube(2,6);
    but_2->add_cube(2,5);
    but_2->add_cube(2,4);
    but_2->add_cube(1,7);
    but_2->add_cube(1,8);
    but_2->add_cube(1,9);

    but_3->add_cube(0,3);
    but_3->add_cube(0,2);
    but_3->add_cube(0,7);
    but_3->add_cube(1,6);
    but_3->add_cube(1,4);
    but_3->add_cube(1,8);
    but_3->add_cube(2,9);
    but_3->add_cube(2,5);
    but_3->add_cube(2,1);

    but_4->add_cube(0,3);
    but_4->add_cube(0,1);
    but_4->add_cube(0,2);
    but_4->add_cube(1,6);
    but_4->add_cube(1,4);
    but_4->add_cube(1,5);
    but_4->add_cube(2,9);
    but_4->add_cube(2,7);
    but_4->add_cube(2,8);

    but_5->add_cube(0,3);
    but_5->add_cube(0,2);
    but_5->add_cube(0,8);
    but_5->add_cube(1,6);
    but_5->add_cube(1,4);
    but_5->add_cube(2,9);
    but_5->add_cube(2,7);
    but_5->add_cube(2,5);
    but_5->add_cube(3,1);

    but_6->add_cube(0,4);
    but_6->add_cube(0,7);
    but_6->add_cube(0,1);
    but_6->add_cube(1,5);
    but_6->add_cube(1,8);
    but_6->add_cube(1,2);
    but_6->add_cube(2,6);
    but_6->add_cube(2,9);
    but_6->add_cube(2,3);
    
    return 0;
}
