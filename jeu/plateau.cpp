#include <iostream>
#include <stack>




class Etat {
    public:
        std::stack<int> tiges[4];
        Etat();
        void print();
        void add_cube(int num_tige, int cube);
        int suppr_cube(int num_tige);
        void move(int num_tige_depart, int num_tige_destination);
        bool equals(Etat *e);
        Etat clone();

};

bool Etat::equals(Etat *e){
    for(int i = 0; i<4;i++){
        if(tiges[i]!=e->tiges[i]){
            return false
        }
    }
    return true;
}

Etat::Etat(){
    for(int i = 0; i<4;i++){
        for(int j = 0; j<3;j++){
            tiges[i][j]=0;
        }
    }
}

void Etat::print(){
    for(int i = 2; i>=0;i--){
        for(int j = 0; j<4;j++){
            std::cout<<tiges[j][i];
            std::cout<< " ";
        }
        std::cout<< "\n";
    }
}

void Etat::add_cube(int tige, int cube){
    if(nb_cube[tige] >= 3){
        std::cout<< "tiges deja pleine\n";
        exit(0);
    }
    tiges[tige][nb_cube[tige]] = cube;
    nb_cube[tige]++;
}

int Etat::suppr_cube(int tige){
    if(nb_cube[tige] <= 0){
        std::cout<< "pas de cube a deplacer\n";
        exit(0);
    }
    nb_cube[tige]--;
    int cube = tiges[tige][nb_cube[tige]];
    tiges[tige][nb_cube[tige]] = 0;
    
    return cube;
}

void Etat::move(int tige_depart, int tige_destination){
    add_cube(tige_destination, suppr_cube(tige_depart));
}

// int main(){
//     Etat *e = new Etat();
    
//     e->print();
//     std::cout<<"\n";
//     e->add_cube(1, 3);
//     e->print();
//     std::cout<<"\n";

//     // e->suppr_cube(1);
//     // e->print();
//     // std::cout<<"\n";
//     e->move(1, 2);
//     e->print();

// }