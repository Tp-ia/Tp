#include "parcour.h"
#include "../jeu/plateau.h"
#include <queue>
#include <stack>
#include <list>

using namespace std;

bool elementDansListe(const list<Etat>& liste, const Etat* etat) {
    for (const Etat& element : liste) {
        if (element == *etat) {
            return true; // L'état est trouvé dans la liste
        }
    }
    return false; // L'état n'est pas trouvé dans la liste
}


retour ProfondeurDAbord(Etat *e, Etat *etat_but) {
    retour resultat;
    resultat.but = false;
    resultat.e = e;
    list<Etat> enAttente;
    list<Etat> vus;
    enAttente.push_front(*e);

    while (!enAttente.empty() && !resultat.but) {
        Etat prochain = *enAttente.front().clone(); // Utilisation d'une référence
        enAttente.pop_front();
        vus.push_front(prochain);

        if (prochain == *etat_but) {
            resultat.but = true;
            resultat.e = prochain.clone();
        } else {
            list<Etat> q = prochain.filsEtat();
            for (Etat& fils : q) { // Utilisation d'une référence
                if (!elementDansListe(vus, &fils)) {
                    enAttente.push_front(fils);
                }
            }
        }
    }
    return resultat;
}

retour ProfondeurDAbordBornee(Etat *e,Etat *etat_but,int lim){
    retour resultat;
    resultat.but = false;
    resultat.e = e;
    list<Etat> enAttente;
    list<Etat> vus;
    enAttente.push_front(*e);

    while (!enAttente.empty() && !resultat.but) {
        Etat prochain = *enAttente.front().clone(); // Utilisation d'une référence
        enAttente.pop_front();
        vus.push_front(prochain);

        if (prochain == *etat_but) {
            resultat.but = true;
            resultat.e = prochain.clone();
        } else {
            list<Etat> q = prochain.filsEtat();
            for (Etat& fils : q) { // Utilisation d'une référence
                if (!elementDansListe(vus, &fils) && fils.getlevel()<=lim) {
                    enAttente.push_front(fils);
                }
            }
        }
    }
    return resultat;
}

retour DFID(Etat *e,Etat *etat_but,int pas){
    int lim=0;
    retour resultat=ProfondeurDAbordBornee(e,etat_but,lim);
    while(!resultat.but){
        lim+=pas;
        resultat=ProfondeurDAbordBornee(e,etat_but,lim);
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