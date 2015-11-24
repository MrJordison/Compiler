#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <iostream>
#include <vector>
#include <string>

class Automate{
	private:
		int initial;
		std::vector<int> finaux;
		std::vector<std::vector <int> * > transitions;
		std::vector<char> symboles;
                int containsSymbol(char s);
	public:
		Automate(int i, std::vector<int> & f, std::vector < std::vector<int>* > & t, std::vector<char> & s);
		bool isValid(std::string mot);
                
                //à refaire avec operator<<
                void affiche() const;

};

#endif
