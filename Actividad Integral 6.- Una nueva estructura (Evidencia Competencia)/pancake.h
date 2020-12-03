#ifndef PANCAKE_H_
#define PANCAKE_H_

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

// Clase Sort ///////////////////////////////////
template <class T>
class Sort{
    private:
        void flip(vector<T>&, int);
        int max(vector<T>&, int);
    public:
        vector<T> pancake(vector<T>&);
};

// Flip ////////////////////////////////////////
template <class T>
void Sort<T>::flip(vector<T>& vs, int k) {
    int init = 0;
	while(init < k){
        T aux = vs[init];
        vs[init] = vs[k];
        vs[k] = aux;
        init++;
        k--;
    }
}

// Maximum Element /////////////////////////////
template <class T>
int Sort<T>::max(vector<T>& vs, int n) {
    int num = 0;
    for(int i = 0; i < n; i++){
        if(vs[i] > vs[num]){
           num = i;
        }
    }
    return num;
}

// Pancake Sorting /////////////////////////////
template <class T>
vector<T> Sort<T>::pancake(vector<T>& vs){
    vector<T> sort;
    for(int i = vs.size(); i > 1; i--){
        int num = max(vs, i);
        if(num != i-1){
            flip(vs, num);
            flip(vs, i-1);
        }
    }
    return vs;
}

// Fin de la transmisión ////////////////////////////////////////
#endif /*PANCAKE_H_*/