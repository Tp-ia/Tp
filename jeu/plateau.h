#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include <stack>
#include <queue>

using namespace std;
class Etat {
    private:
        std::stack<int> tiges[4];
        int level;
        int cout;
        Etat *pere;
    public:
        Etat(int level);
        int getlevel(){ return level;}
        int getcout(){ return cout;}
        void print();
        void add_cube(int num_tige, int cube);
        int suppr_cube(int num_tige);
        void move(int num_tige_depart, int num_tige_destination);
        bool equals(Etat *e);
        Etat* clone();
        queue<Etat> filsEtat();
        bool operator==(Etat&autre);
        void printChemin();
};

#endif