#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <list>
#include "pancake.h"

using namespace std;

template <class T>
string arrayToString(const vector<T> &);

int main(){
    vector<int> vi;
    vector<string> vs;
	Sort<int> sort;
    Sort<string> sorts;

    int arr1[] = {1, 5, 4, 9};
	vector<int> vectori1 (arr1, arr1 + sizeof(arr1) / sizeof(int) );
    vector<int> vectori2 = {44, 55, 533, 75, 452, 99, 2, 43, 1, 23};

    vector<string> vectors1, vectors2;
    vectors1 = {"perro", "gato", "lagartija", "ajolote", "tucan", "hamster"};
    vectors2 = {"A", "O", "I", "U", "E"};

    string resuli1 = "[1, 4, 5, 9]";
    string resuli2 = "[1, 2, 23, 43, 44, 55, 75, 99, 452, 533]";

    string resuls1 = "[ajolote, gato, hamster, lagartija, perro, tucan]";
    string resuls2 = "[A, E, I, O, U]";

    vi = vectori1;
    sort.pancake(vi);
	cout << " 1 " <<(!resuli1.compare(arrayToString(vi)) ? "success\n" : "fail\n");

    vi = vectori2;
    sort.pancake(vi);
	cout << " 2 " <<(!resuli2.compare(arrayToString(vi)) ? "success\n" : "fail\n");

    vs = vectors1;
    sorts.pancake(vs);
	cout << " 3 " <<(!resuls1.compare(arrayToString(vs)) ? "success\n" : "fail\n");

    vs = vectors2;
    sorts.pancake(vs);
	cout << " 4 " <<(!resuls2.compare(arrayToString(vs)) ? "success\n" : "fail\n");

    return 0;
}

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