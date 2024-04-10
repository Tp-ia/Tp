#include <iostream>


typedef struct{
    int nb_cube;
    int cube[3];
} tige;

class Etat {
    public:
    tige tiges[3];
    void move(int tige_depart, int tige_destination);
};

void Etat::move(int tige_depart, int tige_destination){

    if(tiges[tige_depart].nb_cube <= 0){


    }

    int cube = tiges[tige_depart].cube[tiges[tige_depart].nb_cube];

}

int main(){

}