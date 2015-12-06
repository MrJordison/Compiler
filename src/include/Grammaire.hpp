#pragma once

#include "AnalyseurLexical.hpp"
#include "Importer.hpp"
#include "Regle.hpp"

#include <string>
#include <vector>
#include <map>

class Grammaire{

    private:
        Regle * axiome;
        std::vector<std::string> terminaux;
        std::vector<Regle * > regles;
        std::map<Regle *, std::vector <int> *> transitions;
        AnalyseurLexical * al;

    public:
        //Constructeur
        Grammaire(AnalyseurLexical * a);

        std::vector<std::pair<std::string,std::vector<std::string> > > analyse_chaine(std::string chaine);
        void import(std::string path, Importer * i);
        int get_terminal(std::string terme);
        int get_nonTerminal(std::string terme);


};
