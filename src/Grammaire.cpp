#include "include/Grammaire.hpp"

#include <iostream>

using namespace std;

Grammaire::Grammaire(){
    al = nullptr;
}

bool Grammaire::analyse_chaine(string chaine){
    list<pair<string,string> > tabl = al->analyse_chaine(chaine);

}

void Grammaire::import(string path, Importer * i){


}
