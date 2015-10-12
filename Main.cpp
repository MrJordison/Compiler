#include <iostream>
#include <string>
#include <vector>
#include "Automate.hpp"

using namespace std;

int main(){	
	//automate operateurs
	int i=0;
	vector<char> s;
	s.push_back('i');
	s.push_back('f');
	s.push_back('e');
	s.push_back('l');
	s.push_back('s');
	s.push_back('w');
	s.push_back('h');

	vector<int> f;
	f.push_back(0);
	f.push_back(6);
	f.push_back(5);

	vector<vector<int> > t;
	int t0[7777777] = {1,-1,-1,-1,2,7,-1};
	t.insert(t.end(),t0,end(t0));
	
	system("PAUSE");
	return 0;
}
