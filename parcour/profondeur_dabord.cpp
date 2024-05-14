#include "parcour.h"
#include "../jeu/plateau.h"
#include <queue>
#include <stack>
#include <list>

using namespace std;

bool elementDansListe(std::list<Etat>& liste,  Etat* etat) {
    for (auto& element : liste) {
        if (element == *etat && element.getlevel()<= etat->getlevel()) { // Assuming operator== is defined for Etat
            // Etat *print =(Etat*)etat;
            // cout << "je suis la";
            // print->print();
            return true;
        }
    }
    return false;
}

void printelementDansListe(std::list<Etat>& liste) {
    for (auto& element : liste) {
        element.print();
    }
    
}


retour ProfondeurDAbord(Etat *e, Etat *etat_but) {
    retour resultat;
    resultat.but = false;
    resultat.e = new Etat(0);
    list<Etat> enAttente;
    list<Etat> vus;
    enAttente.push_front(*e);
    // etat_but->print();
    // int compteur=0;
    while (!enAttente.empty() && !resultat.but ) {
        // compteur++;
        Etat prochain = *enAttente.front().clone(); // Utilisation d'une référence
        // prochain.print();
        // etat_but->print();
        enAttente.pop_front();
        vus.push_front(prochain);
        if (prochain == *etat_but) {
            resultat.but = true;
            resultat.e = prochain.clone();
        } else {
            list<Etat> q = prochain.filsEtat();
            // cout << vus.size()<< "\n";
            // printelementDansListe(vus);
            // cout<< "\n";
            for (Etat& fils : q) { // Utilisation d'une référence
                if (!elementDansListe(vus, &fils)) {
                    // fils.print();
                    enAttente.push_front(fils);
                }
            }
        }
    }
    free(&enAttente);
    free(&vus);
    return resultat;
}

retour ProfondeurDAbordBornee_sous_fonction(Etat *e,Etat *etat_but,int lim){
    retour resultat;
    resultat.but = false;
    resultat.e = new Etat(0);
    list<Etat> enAttente;
    list<Etat> vus;
    enAttente.push_front(*e);
    // int compteur=0;
    while (!enAttente.empty() && !resultat.but ) {
        // compteur++;
        Etat *prochain = enAttente.front().clone(); // Utilisation d'une référence
        enAttente.pop_front();
        vus.push_front(*prochain);
        if (*prochain == *etat_but) {
            resultat.but = true;
            resultat.e = prochain->clone();
        } else {
            list<Etat> q = prochain->filsEtat();
            for (Etat& fils : q) { // Utilisation d'une référence
                if (fils.getlevel()<=lim && !elementDansListe(vus, &fils)) {
                    // cout << fils.getlevel();
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
        cout << lim << std::endl;
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

// void printQueue(const queue<Etat>& q) {
//     // Create a copy of the queue to preserve its original content
//     queue<Etat> tempQueue = q;

//     // Dequeue and print elements from the temporary queue
//     cout << "Queue: \n";
//     while (!tempQueue.empty()) {
//         tempQueue.front().print();
//         tempQueue.pop();
//         cout << "\n";
//     }
//     cout << endl;
// }

// int main(){
//     Etat *e = new Etat(0);
//     e->add_cube(1, 3);
//     queue<Etat> q = e->filsEtat();

//     printQueue(q);
// }