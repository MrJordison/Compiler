#include "include/Regle.hpp"

#include <iostream>

using namespace std;

Regle::Regle(string symb){
    valeur = symb;
}

Regle::Regle(string symb, list<list<string> > l){
    valeur = symb;
    listSousRegles = l;
}

string Regle::get_val() const{
    return valeur;
}

const list<list<string> > & Regle::get_listSousRegles() const{
    return listSousRegles;
}

//Fonction qui retourne la sous-règle d'une règle à l'indice i
const list<string> & Regle::operator[](int i) const{
    if(i<listSousRegles.size() && i>=0){
        list<list<string> >::const_iterator it=listSousRegles.begin();
        advance(it,i);
        return *it;
    }
    else
        cout<<"error indice invalide";
}

//Fonction qui ajoute une sous règle à une règle
void Regle::add_sousRegle(list<string> sr){
    listSousRegles.push_back(sr);
}
