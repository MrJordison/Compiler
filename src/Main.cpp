#include "include/Automate.hpp"
#include "include/Importer.hpp"
#include "include/AnalyseurLexical.hpp"

#include <vector>
#include <map>
#include <iostream>

using namespace std;


int main(){	

    Importer * importer = new Importer();
    AnalyseurLexical a;
    a.import_automates("./../src/datas.csv", importer);
    cout<<"Entrez la chaine à analyser : ";
    string chaine;
    getline(cin,chaine);
    a. analyse_chaine(chaine);


    return 0;
}
