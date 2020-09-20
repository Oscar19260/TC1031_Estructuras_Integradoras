#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <vector>
#include <list>

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
	void copiarArreglo(std::vector<T>&, std::vector<T>&, int, int);
	void arregloMerge(std::vector<T>&, std::vector<T>&, int, int, int);
	void splitMerge(std::vector<T>&, std::vector<T>&, int, int);
public:
	std::vector<T> ordenaMerge(std::vector<T>&);
};

// Swap ////////////////////////////////////////
template <class T>
void Sorts<T>::swap(std::vector<T> &vs, int i, int j) {
	T aux = vs[i];
	vs[i] = vs[j];
	vs[j] = aux;
}

// Merge Sort ////////////////////////////////////////
template <class T>
void Sorts<T>::copiarArreglo(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for(int i = low; i <= high; i++){
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::arregloMerge(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i,j,k;
	i = low;
	j = mid+1;
	k = low;
	while(i <= mid && j <= high){
		if(A[i] < A[j]){
			B[k] = A[i];
			i++;
		}
		else{
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if(i > mid){
		for(; j <= high; j++){
			B[k++] = A[j];
		}
	}
	else{
		for(; i <= mid; i++){
			B[k++] = A[i];
		}
	}
}

template <class T>
void Sorts<T>::splitMerge(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;
	if((high-low) < 1){
		return;
	}
	mid = (high+low)/2;
	splitMerge(A, B, low, mid);
	splitMerge(A, B, mid+1, high);
	arregloMerge(A, B, low, mid, high);
	copiarArreglo(A, B, low, high);
}

template <class T>
std::vector<T> Sorts<T>::ordenaMerge(std::vector<T>& vs) {
	std::vector<T> tmp(vs.size());
	splitMerge(vs, tmp, 0, vs.size()-1);
	return vs;
}

// Fin de la transmisión ////////////////////////////////////////
#endif /* FUNCIONES_H_ */
