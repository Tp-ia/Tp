#include "../jeu/plateau.h"
#include <iostream>
#include <list>
#include "../parcour/heuristiques.h"
// Fonction de test
void test_Etat() {
    // Test 1
    std::cout << "Test 1 passed" << std::endl;
    Etat *initial_1=new Etat(0);
    if (initial_1->getlevel()==0) {
        std::cout << "Test 1 passed" << std::endl;
    } else {
        std::cout << "Test 1 failed" << std::endl;
    }
}

void test_add_cube(){
    Etat *initial_1= new Etat(0);
    initial_1->add_cube(0,3);
    if(initial_1->tiges[0].front()==3 && initial_1->tiges[0].size()==1){
        std::cout << "Test 2.a passed" << std::endl;
    } else {
        std::cout << "Test 2.a failed" << std::endl;
    }

    initial_1->add_cube(0,4);
    if(initial_1->tiges[0].back()==4 && initial_1->tiges[0].size()==2){
        std::cout << "Test 2.b passed" << std::endl;
    } else {
        std::cout << "Test 2.b failed" << std::endl;
    }

    initial_1->add_cube(0,5);
    if(initial_1->tiges[0].back()==5 && initial_1->tiges[0].size()==3){
        std::cout << "Test 2.c passed" << std::endl;
    } else {
        std::cout << "Test 2.c failed" << std::endl;
    }
}

void test_supp_cube(){
    Etat *initial_1= new Etat(0);
    initial_1->add_cube(0,3);
    initial_1->add_cube(0,4);
    initial_1->add_cube(0,5);
    initial_1->suppr_cube(0);
    if(initial_1->tiges[0].back()==4 && initial_1->tiges[0].size()==2){
        std::cout << "Test 3.a passed" << std::endl;
    } else {
        std::cout << "Test 3.a failed" << std::endl;
    }
    initial_1->suppr_cube(0);
    if(initial_1->tiges[0].back()==3 && initial_1->tiges[0].size()==1){
        std::cout << "Test 3.b passed" << std::endl;
    } else {
        std::cout << "Test 3.b failed" << std::endl;
    }
    initial_1->suppr_cube(0);
    if(initial_1->tiges[0].size()==0){
        std::cout << "Test 3.c passed" << std::endl;
    } else {
        std::cout << "Test 3.c failed" << std::endl;
    }
}

void test_move(){
    Etat *initial_1= new Etat(0);
    initial_1->add_cube(0,3);
    initial_1->add_cube(0,4);
    initial_1->add_cube(0,5);
    initial_1->move(0,1);
    if(initial_1->tiges[0].back()==4 && initial_1->tiges[0].size()==2 && initial_1->tiges[1].back()==5){
        std::cout << "Test 4 passed" << std::endl;
    } else {
        std::cout << "Test 4 failed" << std::endl;
    }
}

void test_filsEtat(){
    Etat *initial_1= new Etat(0);
    initial_1->add_cube(0,3);
    initial_1->add_cube(0,2);
    initial_1->add_cube(1,1);
    initial_1->add_cube(2,6);
    initial_1->add_cube(2,5);
    initial_1->add_cube(2,4);
    initial_1->add_cube(3,7);
    initial_1->add_cube(3,8);
    initial_1->add_cube(3,9);
    std::list<Etat> fE=initial_1->filsEtat();
    if(fE.size()==6){
        std::cout << "Test 5 passed" << std::endl;
        // std::cout << "etat initial" << std::endl;
        // initial_1->print();
        // std::cout << "fils de l'etat initial" << std::endl;
        // for(int i = 0; i<6;i++){
        //     std::cout << "fils" << std::endl;
        //     fE.front().print();
        //     fE.pop();
        // }
    } else {
        std::cout << "Test 5 failed" << std::endl;
    }
}

void test_egal(){
    Etat *initial_1= new Etat(0);
    initial_1->add_cube(0,3);
    initial_1->add_cube(0,2);
    initial_1->add_cube(1,1);
    initial_1->add_cube(2,6);
    initial_1->add_cube(2,5);
    initial_1->add_cube(2,4);
    initial_1->add_cube(3,7);
    initial_1->add_cube(3,8);
    initial_1->add_cube(3,9);
    Etat *initial_2= new Etat(0);
    initial_2->add_cube(0,3);
    initial_2->add_cube(0,2);
    initial_2->add_cube(1,1);
    initial_2->add_cube(2,6);
    initial_2->add_cube(2,5);
    initial_2->add_cube(2,4);
    initial_2->add_cube(3,7);
    initial_2->add_cube(3,8);
    initial_2->add_cube(3,9);
    std::list<Etat> fE=initial_1->filsEtat();
    if(*initial_2==*initial_1){
            std::cout << "Test 6 passed" << std::endl;
        }
        else{
            std::cout << "Test 6 failed" << std::endl;
        }
    for(int i = 0; i<6;i++){
        if(fE.front()==*initial_1){
            std::cout << "Test 6 failed" << std::endl;
        }
        else{
            std::cout << "Test 6"<< i << "passed" << std::endl;
        }
        fE.pop_front();
    }
}



void test_FILS_ETAT(Etat*init,Etat * but){
    for (auto& element : init->filsEtatIDA(but,nombreCubeMalMis)) {
        element.print();
        cout << element.getcost();
    }
}

int main() {
    test_Etat();
    test_add_cube();
    test_supp_cube();
    test_move();
    test_filsEtat();
    test_egal();
    
    return 0;
}