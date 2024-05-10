#include "../jeu/plateau.h"

int nombreCubeMalMis(Etat *e,Etat but){
    std::list<int>::iterator it,it_but;
    int total=0;
    int compteur=0;
    for(int i = 0;i<4;i++){
        if(but.tiges[i].empty() || e->tiges[i].empty()){
            total+=e->tiges[i].size();
        }   
        else{
            compteur=0;
            it = e->tiges[i].begin();
            it_but = but.tiges[i].begin();
            while(it!=e->tiges[i].end() && it_but!=but.tiges[i].end())
                if(*it !=*it_but)
                    break;
                compteur++;
                it++;
                it_but++;
            }
            total+=but.tiges[i].size()-compteur; 
        }
        
    }
}