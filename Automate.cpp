#include "Automate.hpp"

using namespace std;

Automate::Automate(int i, vector<int> *& f, vector < vector<int> * > *& t, vector<char> *& s):initial(i){
   finaux = f;
   transitions =t;
   symboles=s;
}
bool Automate::isValid(string mot){
	//départ à l'état initial
	int etat = initial;
	//regarde à chaque lettre du mot à tester..
	for(int i(0);i<mot.length();++i){
            //...si elle sont dans la table des symboles de l'automate
            int valid = containsSymbol(mot[i]);
            if(valid!=-1 && transitions->at(etat)->at(valid)!=-1){
                etat = transitions->at(etat)->at(valid);
            }
            else{
                return false;
            }
	}
	//si toutes les lettres font parti de l'alphabet, regarde si l'état récupéré est un état final
	for(int i(0);i<finaux->size();++i){
		if(etat== finaux->at(i)){
			return true;
		}
	}
	return false;
}

int Automate::containsSymbol(char s){
    for(int i(0);i<symboles->size();++i){
        if(symboles->at(i)==s){
            return i;
        }
    }
    return -1;
}
