#include "../jeu/plateau.h"
#include <queue>

using namespace std;


typedef struct{
    bool but;
    Etat *e;

} retour ;

std::queue<Etat> filsEtat(Etat *e){
    std::queue<Etat> filsEtat;
    for(int num_tige_depart =0;num_tige_depart<4;num_tige_depart++){
        for(int num_tige_arrive=0; num_tige_arrive<4;num_tige_arrive++){
            if(num_tige_arrive!=num_tige_depart && e->tiges[num_tige_depart].size()!=0 && e->tiges[num_tige_arrive].size()<3 ){
                Etat *fils=e->clone();
                fils->move(num_tige_depart,num_tige_arrive);
                filsEtat.push(*fils);
            }
        }
    }
    return filsEtat;
}

retour ProfondeurDAbord(Etat *e){

}

void printQueue(const queue<Etat>& q) {
    // Create a copy of the queue to preserve its original content
    queue<Etat> tempQueue = q;

    // Dequeue and print elements from the temporary queue
    cout << "Queue: \n";
    while (!tempQueue.empty()) {
        tempQueue.front().print();
        tempQueue.pop();
        cout << "\n";
    }
    cout << endl;
}

int main(){
    Etat *e = new Etat(0);
    e->add_cube(1, 3);
    queue<Etat> q = filsEtat(e);

    printQueue(q);



}