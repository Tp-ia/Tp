#include "parcour.h"
#include "../jeu/plateau.h"
#include <queue>
#include <stack>
#include <list>

using namespace std;

bool elementDansListe(const std::list<Etat>& liste,  Etat const* etat) {
    for (const auto& element : liste) {
        if (&element == etat) { // Assuming operator== is defined for Etat
            return true;
        }
    }
    return false;
}

retour ProfondeurDAbord(Etat *e,Etat *etat_but){
    retour resultat;
    resultat.but=false;
    resultat.e=e;
    list<Etat> enAttente;
    list<Etat> vus;
    enAttente.push_front(*e);
    Etat fils=Etat(0);
    Etat prochain=Etat(0);
    list<Etat> q;
    while(!enAttente.empty() && !resultat.but){
        prochain=enAttente.front();
        enAttente.pop_front();
        vus.push_front(prochain);
        if(prochain == *etat_but){
            resultat.but=true;
            resultat.e=etat_but;
        }
        else{
            q = prochain.filsEtat();
            while(!q.empty()){
                fils = q.front();
                q.pop_front();
                if(!elementDansListe(vus,&fils)){
                    enAttente.push_front(fils);
                }
            }
        }
    }
    return resultat;
}

retour ProfondeurDAbordBornee_sous_fonction(Etat *e,Etat *etat_but,int lim){
    retour resultat;
    resultat.but=false;
    resultat.e=e;
    list<Etat> enAttente;
    list<Etat> vus;
    enAttente.push_front(*e);
    Etat fils=Etat(0);
    Etat prochain=Etat(0);
    list<Etat> q;
    while(!enAttente.empty() && !resultat.but){
        prochain=enAttente.front();
        enAttente.pop_front();
        vus.push_front(prochain);
        if(prochain == *etat_but){
            resultat.but=true;
            resultat.e=etat_but;
        }
        else{
            q = prochain.filsEtat();
            while(!q.empty()){
                fils = q.front();
                q.pop_front();
                if(!elementDansListe(vus,&fils) && fils.getlevel()<=lim){
                    enAttente.push_front(fils);
                }
            }
        }
    }
    return resultat;
}

retour ProfondeurDAbordBornee(Etat *e,Etat *etat_but,int pas){
    int lim=0;
    retour resultat=ProfondeurDAbordBornee_sous_fonction(e,etat_but,lim);
    while(!resultat.but){
        lim+=pas;
        resultat=ProfondeurDAbordBornee_sous_fonction(e,etat_but,lim);
    }
    resultat.lim = lim;
    return resultat;
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

// int main(){
//     Etat *e = new Etat(0);
//     e->add_cube(1, 3);
//     queue<Etat> q = e->filsEtat();

//     printQueue(q);
// }