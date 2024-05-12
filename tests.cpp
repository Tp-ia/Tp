#include "parcour/parcour.h"
#include "jeu/plateau.h"
#include <list>
#include "parcour/heuristiques.h"







bool Etat::equals(Etat*autre){
    cout << "==\n";
    for (int i = 0; i < 4; i++) {
      if (this->tiges[i] != autre->tiges[i]) {
        cout << i;
        cout <<"\n";
        return false;
      }
  }
  return true;
}




//encore a faire: fonctions heuristiques,tester les fonctions et terminer ida
int main(int argc,char ** argv){
    Etat *initial_1=new Etat(0);
    Etat *initial_2=new Etat(0);
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


    
    retour r21 = ProfondeurDAbord(initial_2, but_1);

    if(r21.but == true){
        if(r21.e == but_1){
            cout << "reussit\n";
        } else {
            r21.e->print();
            but_1->print();
        }
    } else {
        cout << "echec\n";
    }

    retour r21b = ProfondeurDAbordBornee(initial_2, but_1, 1);

    if(r21b.but == true){
        if(r21b.e == but_1){
            cout << "reussit\n";
        } else {
            r21b.e->print();
            but_1->print();
        }
    } else {
        cout << "echec\n";
    }

    retour r11b = ProfondeurDAbordBornee(initial_1, but_1, 1);

    if(r11b.but == true){
        if(r11b.e == but_1){
            cout << "reussit\n";
        } else {
            r11b.e->print();
            but_1->print();
        }
    } else {
        cout << "echec\n";
    }

    Etat e21 = ida_star(initial_2, but_1, nombreCubeMalMis);
    if(e21 == *but_1) cout <<"reussit\n";
    else cout<< "echec\n";
    Etat e11 = ida_star(initial_1, but_1, nombreCubeMalMis);

    

    // retour r11 = ProfondeurDAbord(initial_1, but_1); //tourne a l'infinit. C'est normal ?

    // if(r11.but == true){
    //     if(r11.e == but_1){
    //         cout << "reussit\n";
    //     } else {
    //         r11.e->print();
    //         but_1->print();
    //     }
    // } else {
    //     cout << "echec\n";
    // }

    return 0;
}
