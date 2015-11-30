#pragma once

#include "AnalyseurLexical.hpp"
#include "Importer.hpp"
#include "Regle.hpp"

#include <string>
#include <list>
#include <map>

class Grammaire{

    private:
        Regle * axiome;
        std::list<std::string> terminaux;
        std::list<Regle * > regles;
        std::map<std::string, std::list <int> *> transitions;
        AnalyseurLexical * al;

    public:
        //Constructeur
        Grammaire();

        bool analyse_chaine(std::string chaine);
        void import(std::string path, Importer * i);


};
