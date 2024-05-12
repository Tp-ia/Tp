#include <iostream>
#include "plateau.h"

using namespace std;


Etat::Etat(int level) { 
  this->level = level;
 }

std::queue<Etat> Etat::filsEtat(){
    std::queue<Etat> filsEtat;
    for(int num_tige_depart =0;num_tige_depart<4;num_tige_depart++){
        for(int num_tige_arrive=0; num_tige_arrive<4;num_tige_arrive++){
            if(num_tige_arrive!=num_tige_depart && tiges[num_tige_depart].size()!=0 && tiges[num_tige_arrive].size()<3 ){
                Etat *fils=clone();
                fils->pere=this;
                fils->move(num_tige_depart,num_tige_arrive);
                fils->level++;
                filsEtat.push(*fils);
            }
        }
    }
    return filsEtat;
}


list<Etat> Etat::filsEtatIDA(Etat *but,int (*h)(Etat*,Etat*)){
	list<Etat> successors;
	for(int num_tige_depart =0;num_tige_depart<4;num_tige_depart++){
    for(int num_tige_arrive=0; num_tige_arrive<4;num_tige_arrive++){
            if(num_tige_arrive!=num_tige_depart && tiges[num_tige_depart].size()!=0 && tiges[num_tige_arrive].size()<3 ){
                Etat *fils=clone();
                fils->move(num_tige_depart,num_tige_arrive);
                fils->level++;
				fils->setcost(h(this,but));
                successors.push_back(*fils);
            }
        }
    }

	successors.sort();
    return successors;
}



bool Etat::operator==(const Etat& autre) const{
    for (int i = 0; i < 4; i++) {
      if (this->tiges[i] != autre.tiges[i]) {
        return false;
      }
  }
  return true;
}


void Etat::print() {
  list<int> tempStack;
  for (int i = 0; i < 4; i++) {
    tempStack = tiges[i];
    cout << "tige " << i << "= ";
    while (!tempStack.empty()) {
      std::cout << tempStack.back() << " ";
      tempStack.pop_back();
    }

    std::cout << "\n";
  }
}

void Etat::printChemin(){
  Etat *actuel= this;
  for(int i = level;i>0;i--){
    print();
    actuel = actuel->pere;
  }
  actuel->print();
}

void Etat::add_cube(int num_tige, int cube) {
  if (tiges[num_tige].size() >= 3) {
    std::cout << "tiges deja pleine\n";
    exit(0);
  }
  tiges[num_tige].push_back(cube);
}

int Etat::suppr_cube(int num_tige) {
  if (tiges[num_tige].size() <= 0) {
    std::cout << "pas de cube a deplacer\n";
    exit(0);
  }
  int cube = tiges[num_tige].back();
  tiges[num_tige].pop_back();
  return cube;
}

void Etat::move(int tige_depart, int tige_destination) {
  add_cube(tige_destination, suppr_cube(tige_depart));
}

Etat* Etat::clone(){
    Etat *copy =new Etat(level);
    for(int i =0;i<4;i++){
        copy->tiges[i]=tiges[i];
        copy->level=level;
    }
    return copy;
}

// int main() {
//   Etat *e = new Etat(0);

//   e->print();
//   std::cout << "\n";
//   e->add_cube(1, 3);
//   e->print();
//   std::cout << "\n";

//   e->suppr_cube(1);
//   e->print();
//   std::cout << "\n";

//   e->add_cube(1, 3);

//   e->move(1, 2);
//   e->print();
// }