#include <iostream>
#include <stack>

using namespace std;
class Etat {
    public:
        std::stack<int> tiges[4];
        int level;
        Etat(int level);
        void print();
        void add_cube(int num_tige, int cube);
        int suppr_cube(int num_tige);
        void move(int num_tige_depart, int num_tige_destination);
        bool equals(Etat *e);
        Etat* clone();

};