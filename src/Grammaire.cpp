#include "include/Grammaire.hpp"

#include <vector>
#include <iostream>

using namespace std;

Grammaire::Grammaire(){
    al = nullptr;
}

vector<string> Grammaire::analyse_chaine(string chaine){
    //Analyse lexicale de la chaine
    vector<pair<string,string> > tabl = al->analyse_chaine(chaine);
    //Création de la pile pour l'automate
    vector<string> pile;
    //ajout de l'axiome comme départ de l'automate
    pile.push_back(axiome->get_val());
    //initialisation des curseur de chaine et de l'automate
    int cpt(0);

    int tempcp(-1);
    Regle * rtmp;
    vector<string> res;
    while(1){
        //Regarde si le terme en haut de pile est un terme terminal ou non 
        tempcp = get_terminal(pile[cpt]);
        //si ce n'est pas un terme terminal..
        if(tempcp==-1){
            //Récupérer l'indice de la sous règle du terme non terminal permettant d'avoir le terme terminal
            //au niveau du curseur de la chaine à analyser
            tempcp=(*transitions[regles[get_nonTerminal(pile[cpt])]])[get_terminal(tabl[cpt].first)];   
            //Si la sous règle permet de l'avoir...
            if(tempcp!=-1){
                rtmp = regles[get_nonTerminal(pile[cpt])];
                //Remplacer le terme non terminal par cette dernière
                pile.erase(pile.begin()+cpt);
                pile.insert(pile.begin()+cpt,(*rtmp)[tempcp].begin(),(*rtmp)[tempcp].end());
            }
            else{
                cout<< "Erreur, la règle ne permet pas de trouver le symbole terminal"<<endl;
                break;
            }
        }
        //Sinon si c'est un terme terminal..
        else{
            //Si il est égal au terme dans la chaine, on passe au terme suivant
            if(pile[cpt]==tabl[cpt].first || pile[cpt]==tabl[cpt].second)
                ++cpt;
            //Sinon erreur
            else{
                cout<< "Erreur, le terme trouvé ne correspond pas à celui dans la chaine"<<endl;
                break;
            }
        }
    }
    return res;
}

void Grammaire::import(string path, Importer * i){
    i->set_path(path);
    //Si le fichier existe
    if(i->get_file()){

        //declaration des différentes variables tampons
        string contenu("");
        vector<string> line_split;
        int cpt(1); //indique quelle partie de la grammaire est lue dans le fichier
        string axiome_value("");
        Regle * r = nullptr;
        vector<string>::iterator it;
        string actual_regle("");

        while(getline(i->get_file(),contenu)){
            //Si la ligne contient un tiret on incrémente le cpt
            if(contenu=="-")
                ++cpt;
            else{
                switch(cpt){
                    //1e partie du fichier : lecture de la valeur de l'axiome
                    case 1:
                        //la valeur de l'axiome est stockée dans une variable temporaire
                        axiome_value=contenu;
                        break;

                    //2e partie du fichier : lecture des termes terminaux
                    case 2:
                        //découpage de la ligne
                        line_split = Importer::split(contenu,'#');
                        terminaux = vector<string>(line_split.begin(),line_split.end());
                        break;

                    //3e partie du fichier : lecture des règles et de leurs transitions
                    case 3:
                        //decoupage de la ligne selon le séparateur
                        line_split = Importer::split(contenu,'#');
                        //si la valeur de la règle lue dans la ligne n'est pas la même que celle lue précédemment
                        if(line_split[0]!=actual_regle){
                            //on actualise la valeur de la règle lue par la nouvelle
                            actual_regle = line_split[0];
                            //on créée une nouvelle règle que l'on ajoute à la liste des règles de la grammaire
                            r = new Regle(line_split[0]);
                            regles.push_back(r);
                            //on ajoute une ligne au tableau des transitions pour cette règle
                            transitions.insert(pair<Regle *, vector<int> *>(r, new vector<int>(terminaux.size(),-1)));
                            //si cette règle correspond à la variable temporaire  de l'axiome, on met à jour l'attribut axiome de la classe
                            if(line_split[0]==axiome_value && axiome==nullptr)
                                axiome = r;
                        }
                        it = line_split.begin();
                        //On créé un iterator qui commence à la deuxième valeur lue de la ligne...
                        advance(it,2);

                        //Si c'est une sous règle..
                        if(line_split[1]=="<::=sr>"){
                            //on construit une sous règle avec tous les éléments trouvés après celle ci pour l'ajouter à la règle
                            r->add_sousRegle(list<string>(it, line_split.end()));
                        }
                        //Si c'est la ligne de transitions du tableau...
                        else if(line_split[1]=="<::=t>"){
                            transitions[r][stoi(line_split[2])];
                        }
                        break;
                    
                    //4e partie du fichier : lecture du tableau de transitions de la grammaire
                    case 4:
                        //découpage de la ligne
                        line_split = Importer::split(contenu,'#');

                        break;
                }
            }
        }
    }
}

int Grammaire::get_terminal(string terme){
    for(int i(0);i<terminaux.size();++i){
        if(terme==terminaux[i])
            return i;
    }
    return -1;
}

int Grammaire::get_nonTerminal(string terme){
    for(int i(0);i<regles.size();++i){
        if(regles[i]->get_val()==terme)
            return i;
    }
    return -1;
}
