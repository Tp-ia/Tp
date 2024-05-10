#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include <stack>
#include <queue>
#include <list>

using namespace std;
class Etat {
    private:
        std::stack<int> tiges[4];
        int level;
        int cost;
    public:
        Etat(int level);
        int getlevel(){ return level;}
        int getcost(){ return cost;}
        void setcost(int cost){ this->cost = cost;}
        void print();
        void add_cube(int num_tige, int cube);
        int suppr_cube(int num_tige);
        void move(int num_tige_depart, int num_tige_destination);
        bool equals(Etat *e);
        Etat* clone();
        queue<Etat> filsEtat();
        list<Etat> filsEtatIDA(Etat *but,int (*h)(Etat*,Etat*));
        bool operator==(Etat&autre);
        bool operator<(const Etat& other) const {
        return cost < other.cost;
    }
        
        //ajouter path ou pereEtat
};

#endif