#include <map>
#include <iostream>
#include "Automate.hpp"
#include "Importer.hpp"

using namespace std;

int main(){	

    Importer * importer = new Importer("./../src/datas.csv");
    map <string,Automate * > automates = importer->import_automate();
    for (pair<string,Automate *> a : automates){
        cout<<a.first<<endl;
        a.second->affiche();
    }
    return 0;
}
