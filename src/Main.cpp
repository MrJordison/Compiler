#include "include/Automate.hpp"
#include "include/Importer.hpp"
#include "include/AnalyseurLexical.hpp"
#include "include/Grammaire.hpp"

#include <vector>
#include <map>
#include <iostream>

using namespace std;

//Partie analyseur lexical
void part1(){
    Importer * importer = new Importer();
    AnalyseurLexical a;
    a.import_automates("./../src/datas.csv", importer);
    cout<<"Entrez la chaine à analyser : ";
    string chaine;
    getline(cin,chaine);
    a. analyse_chaine(chaine);
}

//Partie analyseur syntaxique
void part2(){
    Importer * importer = new Importer();
    AnalyseurLexical a;
    a.import_automates("./../src/lexical_part2.csv", importer);
    Grammaire g(&a);
    g.import("./../src/syntaxique_part2.csv",importer);

    cout<<"Entrez la chaine à analyser : ";
    string chaine;
    getline(cin,chaine);
    string str;
    for (pair<string, vector<string> > p : g.analyse_chaine(chaine)){
        str=p.first+" ::= ";
        for(string s : p.second)
            str+= s;
        cout << str << endl;
    }   
}

int main(){	

    part2();

    return 0;
}
