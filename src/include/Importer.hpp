#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <map>

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

        std::ifstream& get_file() const;

        //functions
        std::map<std::string,Automate*> import_automate();
        static std::vector<std::string> split(std::string, char delimiter);


    
};
