#include "include/Automate.hpp"
#include "include/Importer.hpp"

#include <vector>
#include <map>
#include <iostream>

using namespace std;


int main(){	

    Importer * importer = new Importer("./../src/datas.csv");
    map <string,Automate * > automates = importer->import_automate();
    string test;
    cout<<"Entrez la chaine à tester :"<<endl;
    getline(cin,test);
    vector<string> tab = importer->split(test,' ');
    string res="";
    for(string s : tab){
        cout<<"-----------------------------------------------"<<endl;
        res  = " "+s+" ";
        if(automates["mot-cle"]->isValid(s))
            res+="mot-cle";
        else if(automates["type"]->isValid(s))
            res+="type";
        else if(automates["operateur"]->isValid(s))
            res+="operateur";
        else if(automates["separateur"]->isValid(s))
            res+="separateur";
        else if(automates["chiffre"]->isValid(s))
            res+="chiffre";
        else if(automates["identificateur"]->isValid(s))
            res+="identificateur";
        else {
            res+="error non reconnu";
            cout<<res<<endl;
            break;
        }
        cout<<res<<endl;
    } 
    return 0;
}
