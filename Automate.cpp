#include "Automate.hpp"

using namespace std;

Automate::Automate(int & i, vector<int> & f, vector < vector<int> > & t, vector<char> & s):
	initial(i),finaux(f),transitions(t),symboles(s){}

bool Automate::isValid(string mot){
	//départ à l'état initial
	int etat = initial;
	//regarde à chaque lettre du mot à tester..
	for(int i(0);i<mot.length();++i){
		//...si elle sont dans la table des symboles de l'automate
		for(int j(0);j<symboles.size();++j){
			//si oui on va à l'état suivant selon la table des transitions
			if(mot[i]==symboles[j]){
				etat = transitions[etat][j];
			}
			//sinon le mot n'est pas reconnu
			else{
				return false;
			}
		}
	}
	//si toutes les lettres font parti de l'alphabet, regarde si l'état récupéré est un état final
	for(int i(0);i<finaux.size();++i){
		if(etat== finaux[i]){
			return true;
		}
	}
	return false;
}
