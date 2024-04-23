#include "../jeu/plateau.cpp"
#include <queue>

typedef struct{
    bool but;
    Etat *e;

} retour ;

std::queue<Etat> filsEtat(Etat *e){
    std::queue<Etat> filsEtat;
    for(int num_tige_depart =0;num_tige_depart<4;num_tige_depart++){
        for(int num_tige_arrive=0; num_tige_arrive<4;num_tige_arrive++){
            if(num_tige_arrive!=num_tige_depart && e->tiges[num_tige_depart].size()==0 && e->tiges[num_tige_arrive].size()>=3 ){
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

int main(){
    Etat *e = new Etat(0);
}