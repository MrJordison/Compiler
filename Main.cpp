#include <iostream>
#include <string>
#include <vector>
#include "Automate.hpp"

using namespace std;

int main(){	
        //automate types
        vector<char> * s= new vector<char>;
        char s0[] = {'i','n','t','c','h','a','r','s','g','f','l','o','b'};
        for(int i(0);i<13;++i){
            s->push_back(s0[i]);
        }

        vector <int> * f = new vector <int>;
        int f0 [] = {3,7,13,18,22};
        for(int i(0);i<5;++i){
            f->push_back(f0[i]);
        }

        vector <vector<int> * > * t = new vector< vector<int> * >(23);
        int t0[] ={1,-1,-1,4,-1,-1,-1,8,-1,14,-1,-1,19};
        int t1[] ={-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int t2[] ={-1,-1,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int t3[] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int t4[] ={-1,-1,-1,-1,5,-1,-1,-1,-1,-1,-1,-1,-1};
        int t5[] ={-1,-1,-1,-1,-1,6,-1,-1,-1,-1,-1,-1,-1};
        int t6[] ={-1,-1,-1,-1,-1,-1,7,-1,-1,-1,-1,-1,-1};
        int t7[] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int t8[] ={-1,-1,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int t9[] ={-1,-1,-1,-1,-1,-1,10,-1,-1,-1,-1,-1,-1};
        int t10[] ={11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int t11[] ={-1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int t12[] ={-1,-1,-1,-1,-1,-1,-1,-1,13,-1,-1,-1,-1};
        int t13[] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int t14[] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,-1,-1};
        int t15[] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,16,-1};
        int t16[] ={-1,-1,-1,-1,-1,17,-1,-1,-1,-1,-1,-1,-1};
        int t17[] ={-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int t18[] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int t19[] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,-1};
        int t20[] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,21,-1};
        int t21[] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,-1,-1};
        int t22[] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        for(int i(0);i<t->size();++i){
            t->at(i) = new vector<int>;
            switch(i){
                case 0:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t0[j]);   
                    }
                    break;
                case 1:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t1[j]);   
                    }
                    break;
                case 2:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t2[j]);   
                    }
                    break;
                case 3:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t3[j]);   
                    }
                    break;
                case 4:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t4[j]);   
                    }
                    break;
                case 5:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t5[j]);   
                    }
                    break;
                case 6:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t6[j]);   
                    }
                    break;
                case 7:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t7[j]);   
                    }
                    break;
                case 8:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t8[j]);   
                    }
                    break;
                case 9:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t9[j]);   
                    }
                    break;
                case 10:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t10[j]);   
                    }
                    break;
                case 11:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t11[j]);   
                    }
                    break;
                case 12:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t12[j]);   
                    }
                    break;
                case 13:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t13[j]);   
                    }
                    break;
                case 14:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t14[j]);   
                    }
                    break;
                case 15:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t15[j]);   
                    }
                    break;
                case 16:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t16[j]);   
                    }
                    break;
                case 17:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t17[j]);   
                    }
                    break;
                case 18:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t18[j]);   
                    }
                    break;
                case 19:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t19[j]);   
                    }
                    break;
                case 20:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t20[j]);   
                    }
                    break;
                case 21:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t21[j]);   
                    }
                    break;
                case 22:
                    for(int j(0);j<13;++j){
                        t->at(i)->push_back(t22[j]);   
                    }
                    break;
            }
        }
        Automate * a = new Automate(0,f,t,s);
        a->isValid("bool");
        a->isValid("int");
        a->isValid("char");
        a->isValid("string");
        a->isValid("float");
        a->isValid("flat");
        a->isValid("rgttrg");


        return 0;
}
