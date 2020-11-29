#include <iostream>
#include <cstring>
#include <string>
#include "hash.h"

using namespace std;

unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

int main(int argc, char* argv[]) {
	HashT <string, int> hash(9, string("empty"), myHash);
	string ans;
	
	hash.put(string("Chuck"), 10);
	hash.put(string("Red"), 43);
	hash.put(string("Ryan"), 34);
	hash.put(string("Bob"), 12);
	hash.put(string("Mike"), 33);
	hash.put(string("Sean"), 23);
	hash.put(string("Mark"), 19);

	ans = "[0 Mark: 19]\n[1 empty: 0]\n[2 empty: 0]\n[3 Mike: 33]\n[4 Red: 43]\n[5 Ryan: 34]\n[6 Bob: 12]\n[7 Sean: 23]\n[8 Chuck: 10]\n";   
	cout << " 1 " <<((!ans.compare(hash.toString().c_str())) ? "success\n" : "fail\n");

	hash.put(string("Max"), 99);
	hash.put(string("Fin"), 75);

	ans = "[0 Mark: 19]\n[1 Max: 99]\n[2 Fin: 75]\n[3 Mike: 33]\n[4 Red: 43]\n[5 Ryan: 34]\n[6 Bob: 12]\n[7 Sean: 23]\n[8 Chuck: 10]\n";
	cout << " 2 " <<((!ans.compare(hash.toString().c_str())) ? "success\n" : "fail\n");

	cout << " 3 " <<((hash.get("Mark") == 19) ? "success\n" : "fail\n");
	cout << " 4 " <<((hash.get("Max") == 99) ? "success\n" : "fail\n");
	cout << " 5 " <<((hash.get("Chuck") != 20) ? "success\n" : "fail\n");
	
	return 0;
}
