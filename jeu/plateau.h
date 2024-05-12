#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include <list>
#include <queue>

using namespace std;
class Etat {
    private:
        
        int level;
        int cost;
        Etat *pere;
    public:
        std::list<int> tiges[4];
        Etat(int level);
        int getlevel(){ return level;}
        int getcost(){ return cost;}
        void setcost(int cost){ this->cost = cost;}
        void print();
        void add_cube(int num_tige, int cube);
        int suppr_cube(int num_tige);
        void move(int num_tige_depart, int num_tige_destination);
        Etat* clone();
        queue<Etat> filsEtat();
        list<Etat> filsEtatIDA(Etat *but,int (*h)(Etat*,Etat*));
        bool operator==(const Etat& autre) const;
        bool operator<(const Etat& other) const {
        return cost < other.cost;
    }
        void printChemin();
        bool equals(Etat *autre);
};

#endif