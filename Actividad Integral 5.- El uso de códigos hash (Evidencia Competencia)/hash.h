#ifndef HASH_H_
#define HASH_H_

#include <string>
#include <sstream>
#include <fstream>

template <class Key, class Value>
class HashT {
private:
	unsigned int (*func) (const Key);
	unsigned int size;	// Tamaño de la tabla
	unsigned int count;	// Ocupación de la tabla
	
	Key *keys;			
	Key initialValue;	
	Value *values;		
	long indexOf(const Key) const;
	
public:
	HashT(unsigned int, Key, unsigned int (*f) (const Key));
	~HashT();
	bool full() const;
	bool put(Key, Value);
	bool contains(const Key) const;
	Value get(const Key);
	void clear();
	std::string toString() const;
};

// Constructor de la tabla HashT
template <class Key, class Value>
HashT<Key, Value>::HashT(unsigned int sze, Key init, unsigned int (*f) (const Key)) {
	size = sze;
	keys = new Key[size];	// Creamos un arreglo de Key con tamaño size
	initialValue = init;
	for(unsigned int i = 0; i < size; i++){
		keys[i] = init;
	} 
	values = new Value[size];
	for(int i = 0; i < size; i++){
		values[i] = 0;
	}
	func = f;
	count = 0;
}

// Destructo de la tabla HashT
template <class Key, class Value>
HashT<Key, Value>::~HashT() {
	delete[] keys;
	keys = 0;
	delete[] values;
	values = 0;
	count = 0;
	size = 0;
	func = 0;
}

// Verificamos si se lleno 
template <class Key, class Value>
bool HashT<Key, Value>::full() const {
	return (count >= size);
}

// Desplazamiento para el manejo de colisiones
template <class Key, class Value>
long HashT<Key, Value>::indexOf(const Key k) const {
	unsigned int i, start;
	start = i = func(k) % size;
	do{
		if(keys[i] == k){
			return i;
		}
		i = (i+1) % size;
	} while(start != i);
	return -1;
}

// Agrega keys y valores
template <class Key, class Value>
bool HashT<Key, Value>::put(Key k, Value v){
	unsigned i, start;
	long pos;
	// Si ya existe actualizar
	pos = indexOf(k);
	if(pos != -1){
		values[pos] = v;
		return true;
	}
	// Si no existe inserta en nuevo espacio
	start = i = func(k) % size;
	do{
		if (keys[i] == initialValue){
			keys[i] = k;
			values[i] = v;
			return true;
		}
		i = (i+1) % size;
	} while (start != i);
	return false;
}

// Verificar si hay o no un dato
template <class Key, class Value>
bool HashT<Key, Value>::contains(const Key k) const {
	long pos;
	pos = indexOf(k);
	return (pos != -1);
}

// Extraer un valor que le corresponde a una llave
template <class Key, class Value>
Value HashT<Key, Value>::get(const Key k){
	unsigned int i, start;
	long pos;
	pos = indexOf(k);
	if (pos != -1){
		return values[pos];
	}
	return -1;
}

// Resetea los valores
template <class Key, class Value>
void HashT<Key, Value>::clear() {
	count = 0;
	for(unsigned int i = 0; i < size; i++){
		keys[i] = initialValue;
	}
}

// Convertimos nuestros datos en strings
template <class Key, class Value>
std::string HashT<Key, Value>::toString() const {
	std::stringstream aux;
	for (unsigned int i = 0; i < size; i++) {
		aux << "[" << i << " " << keys[i] << ": " << values[i] << "]\n";
	}
	return aux.str();
}
// Fin de la transmición /////////////////////////////////////////////////////////////////
#endif /* HASH_H_ */
	
