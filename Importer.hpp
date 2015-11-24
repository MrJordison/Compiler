#pragma once
#include <string>
#include <fstream>

#include "Automate.hpp"

class Importer{
    private : 
        std::string path;
        std::ifstream * file;

    public:
        //constructor
        Importer();
        Importer(std::string p);
        ~Importer();

        //getters, setters
        std::string get_path() const;
        void set_path(std::string);

        &ifstream get_file() const;

        //functions
        &vector<string,Automate*> import_automate();


    
};
