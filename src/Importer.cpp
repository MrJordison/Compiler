#include <iostream>
#include <sstream>
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
    file = new ifstream(path, ios::in);
    if(file) 
        cout<< "ouverture fichier"<<endl;
    else
        cout<<" problème ouverture"<<endl;
}

ifstream& Importer::get_file() const{
    return *file;
}

map<string,Automate*> Importer::import_automate(){
    map<string,Automate *> res;

    //variables tampons pour creer un automate
    string name;
    vector<int> f;
    vector<vector <int> * > tr;
    vector<char> sym;
    int mode_lecture;

    string contenu("");
    int cpt=0;
    vector<string> line_split;
    
    //Test si le fichier existe ou non
    if(file){
        //Parcours de toutes les lignes du fichiers contenant les automates
        while(getline(*file,contenu)){
            ++cpt;
            cout<<cpt<<endl;
            switch(cpt){ 
                //1e ligne : nom de l'unité lexicale reconnue par l'automate
                case 1:
                    name = contenu;
                    break;
                
                //2e ligne : dimensions du tableau des transitions 
                case 2:
                    line_split = split(contenu,'#');
                    //Remplie avec la valeur par défaut les lignes du tableau
                    for(int i(0);i<stoi(line_split[0]) ;++i)
                        tr.push_back(new vector<int>(stoi(line_split[1]),-1));
                    break;

                //3e ligne : liste des états finaux de l'automate
                case 3:
                    line_split = split(contenu,'#');
                    //split de la ligne puis ajout de chaque token cast en integer dans le vecteur
                    for(string s : line_split)
                        f.push_back(stoi(s));
                    break;
                
                //4e ligne : liste des symboles de l'automate
                case 4:
                    line_split = split(contenu,'#');
                    
                    for(string s : line_split){
                        //ajout du symbole courant dans le tableau
                        sym.push_back(s.at(0));
                    }
                    break;

                //5e ligne : indique le mode de lecture à appliquer pour la suite de l'automate...
                case 5:
                    mode_lecture = stoi(contenu);
                    break;
                
                default:
                    //Au delà de la 5e ligne : contient les valeurs du tableau de transitions
                    if(cpt>5 && contenu!=""){
                        line_split = split(contenu,'#');

                        //Si le mode de lecture est à 1, les valeurs sont stockées sous la forme [n° ligne, n° symbole, état suivant]
                        if(mode_lecture==1)
                            tr.at(stoi(line_split[0]))->at(stoi(line_split[1])) = stoi(line_split[2]);   

                        //Sinon, chaque ligne suivante est une ligne complète du tableau de transition à ajouter dans l'ordre de lecture
                        else{
                            //La ligne où l'on doit ajouter les valeurs lues correspondent à la valeur du compteur - 6
                            for(int i(0);i<line_split.size();++i)
                                tr.at(cpt-6)->at(i)=stoi(line_split[i]);
                        }
                    }
                    else{
                        //signifie que la ligne est vide, et donc la fin de la définition de l'automate
                        //et donc sa création et l'ajout dans le tableau retourné par la fonction
                        //réinitialisation du compteur et des variables tampons;
                        
                        res.insert(pair<string,Automate *>(name,new Automate(0,f,tr,sym)));
                        
                        name="";
                        tr.clear();
                        sym.clear();
                        f.clear();
                        mode_lecture=0;
                        cpt=0;
                    }
                    break;
            }
        }
    }
    return res;
} 

//Fonction permettant de split un string d'après un char
vector<string> Importer::split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }               
    return internal;
}
