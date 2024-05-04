#include "profondeur_dabord.h"
#include "../jeu/plateau.h"
#include <queue>

using namespace std;

bool elementDansQueue(const queue<Etat>& maQueue, Etat* elementRecherche) {
    queue<Etat> maQueueTemp = maQueue; // Copie de la file pour éviter de la modifier

    while (!maQueueTemp.empty()) {
        if (maQueueTemp.front().equals(elementRecherche)) {
            return true; // L'élément est trouvé
        }
        maQueueTemp.pop(); // Passe à l'élément suivant
    }

    return false; // L'élément n'est pas trouvé
}

retour ProfondeurDAbord(Etat *e,Etat *etat_but){
    retour resultat;
    resultat.but=false;
    resultat.e=e;
    stack<Etat> enAttente;
    queue<Etat> vus;
    enAttente.push(*e);
    Etat fils=Etat(0);
    Etat prochain=Etat(0);
    queue<Etat> q;
    while(!enAttente.empty() && !resultat.but){
        prochain=enAttente.top();
        enAttente.pop();
        vus.push(prochain);
        if(prochain.equals(etat_but)){
            resultat.but=true;
            resultat.e=etat_but;
        }
        else{
            q = prochain.filsEtat();
            while(!q.empty()){
                fils = q.front();
                q.pop();
                if(!elementDansQueue(vus,&fils)){
                    enAttente.push(fils);
                }
            }
        }
    }
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