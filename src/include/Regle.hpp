#pragma once

#include <list>
#include <string>

class Regle{
    private : 
        std::string valeur;
        std::list<std::list<std::string> > listSousRegles;

    public : 
        Regle(std::string symb);
        Regle(std::string symb, std::list<std::list<std::string > >l);
        std::string get_val() const;
        const std::list<std::list<std::string> > & get_listSousRegles() const;
        const std::list<std::string> & operator[](int i) const;
        void add_sousRegle(std::list<std::string> sr);


};

