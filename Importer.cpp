#include <iostream>
#include "Importer.hpp"

using namespace std;

Importer::Importer(){
    path="";
    file = nullptr;
}

Importer::Importer(string p){
    set_path(p);
}

Importer::~Importer(){
    if(file)
        delete file;
    file = nullptr;
}

string Importer::get_path() const{
    return path;
}

void Importer::set_path(string p){
    path = p;
    file = new ifstream(p, ios::in);
    if(file) 
        cout<< "ouverture fichier"<<endl;
    else
        cout<<" problème ouverture"<<endl;
}

&ifstream Importer::get_file() const{
    return *file;
}

&map<string,Automate*> Importer::import_automate(){

}
