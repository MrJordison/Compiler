#pragma once

#include "Automate.hpp"
#include "Importer.hpp"
#include <string>
#include <map>
#include <list>
#include <vector>

class AnalyseurLexical{
    private:
        std::list<std::string> sortautomates;
        std::map<std::string, Automate *> automates;

    public:
        void import_automates(std::string file, Importer * i);
        std::vector<std::pair<std::string, std::string> > analyse_chaine(std::string chaine);

};
