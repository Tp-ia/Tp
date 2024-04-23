#include <iostream>
#include <stack>


class Etat {
    public:
        std::stack<int> tiges[4];
        int level;
        Etat(int level);
        // void print();
        void add_cube(int num_tige, int cube);
        int suppr_cube(int num_tige);
        void move(int num_tige_depart, int num_tige_destination);
        bool equals(Etat *e);
        Etat clone();

};

Etat::Etat(int level){
    this->level = level;
}

bool Etat::equals(Etat *e){
    for(int i = 0; i<4;i++){
        if(tiges[i]!=e->tiges[i]){
            return false;
        }
    }
    return true;
}

// void Etat::print(){
//     for(int i = 2; i>=0;i--){
//         for(int j = 0; j<4;j++){
//             std::cout<<tiges[j][i];
//             std::cout<< " ";
//         }
//         std::cout<< "\n";
//     }
// }

void Etat::add_cube(int num_tige, int cube){
    if(tiges[num_tige].size() >= 3){
        std::cout<< "tiges deja pleine\n";
        exit(0);
    }
    tiges[num_tige].push(cube);
}

int Etat::suppr_cube(int num_tige){
    if(tiges[num_tige].size() <= 0){
        std::cout<< "pas de cube a deplacer\n";
        exit(0);
    }
    int cube = tiges[num_tige].top();
    tiges[num_tige].pop();
    return cube;
}

void Etat::move(int tige_depart, int tige_destination){
    add_cube(tige_destination, suppr_cube(tige_depart));
}

int main(){
    Etat *e = new Etat(0);
    
    // e->print();
    std::cout<<"\n";
    e->add_cube(1, 3);
    // e->print();
    std::cout<<"\n";

    // e->suppr_cube(1);
    // e->print();
    // std::cout<<"\n";
    e->move(1, 2);
    // e->print();

}