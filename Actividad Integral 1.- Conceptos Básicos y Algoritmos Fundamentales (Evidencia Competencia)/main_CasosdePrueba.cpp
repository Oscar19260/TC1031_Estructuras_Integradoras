#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <string>
#include "funciones.h"

using namespace std;

template <class T>
string arrayToString(const vector<T> &v) {
	stringstream aux;
	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	aux << "]";
	return aux.str();
}

int main(){
	vector<int> test;
	Sorts<int> sort;

    int a1[] = {5, 6, 2, 1};
	vector<int> r1 (a1, a1 + sizeof(a1)/sizeof(int));
	int a2[] = {13, 2, 6, 49, 25};
	vector<int> r2 (a2, a2 + sizeof(a2)/sizeof(int));
    int a3[] = {118, 220, 40, 8, 119};
	vector<int> r3 (a3, a3 + sizeof(a3)/sizeof(int));

	string comp1 = "[1, 2, 5, 6]";
	string comp2 = "[2, 6, 13, 25, 49]";
    string comp3 = "[8, 40, 118, 119, 220]";

	test = r1;
	sort.ordenaMerge(test);
	cout<<" 1 "<<(!comp1.compare(arrayToString(test)) ? "success\n" : "fail\n");

	test = r2;
	sort.ordenaMerge(test);
	cout<<" 2 "<<(!comp2.compare(arrayToString(test)) ? "success\n" : "fail\n");

    test = r3;
	sort.ordenaMerge(test);
	cout<<" 3 "<<(!comp3.compare(arrayToString(test)) ? "success\n" : "fail\n");
}