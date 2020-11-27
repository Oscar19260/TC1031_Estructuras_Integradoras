#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std; 

template <class T> class BST;

// Clase TreeNode /////////////////////////////////////////////
template <class T>
class TreeNode {
	private:
		T value;
		TreeNode *left, *right;
		TreeNode<T>* predecesor();

	public:
		TreeNode(T);
		TreeNode(T, TreeNode<T>*, TreeNode<T>*);
		void add(T);
		bool find(T);
		void remove(T);
		void removeChilds();
		void inorder(std::stringstream&) const;		
		friend class BST<T>;
};

// Constructores TreeNode /////////////////////////////////////////////
template <class T>
TreeNode<T>::TreeNode(T val): value(val), left(0), right(0) {}

template <class T>
TreeNode<T>::TreeNode(T val, TreeNode<T> *le, TreeNode<T> *ri): value(val), left(le), right(ri) {}

// predecesor /////////////////////////////////////////////
template <class T>
TreeNode<T>* TreeNode<T>::predecesor(){
	TreeNode<T> *l, *r;		//Creamos los nodos l y r
	l = left;				//El puntero l apunta a la izquierda
	r = right;				//El puntero r apunta a la derecha
	if (left == 0) {		//Si mi izquierda es nulo
		if (right != 0) {	//Checo que mi derecha no sea nulo
			right = 0;		//La derecha la ponemos como nulo
		}
		return r;			//Regresamos r
	}
	if (left->right == 0) {	//Si en el lado izquierdo el derecho es nulo
		left = left->left;	//El izquierdo se regresa
		l->left = 0;		//El nodo en la izquierda se hace nulo
		return l;			//Regresamos l
	}
	TreeNode<T> *parent, *child;	//Creamos nodos parent y child
	parent = left;					//El nodo padre apunta a la izquierda
	child = left->right;			//El nodo hijo apunta a la siguiente posición de parent
	while (child->right != 0) {		//Mientras hijo se pueda seguir moviendo a la derecha
		parent = child;				//El padre se vuelve hijo
		child = child->right;		//Child se mueve a la derecha
	}
	parent->right = child->left;	//El padre a la derecha es igual al hijo en la izquierda
	child->left = 0;				//La posición del hijo a la izquierda se vuelve 0
	return child;					//Regresamos child
}

// Add /////////////////////////////////////////////
template <class T>
void TreeNode<T>::add(T val){
	if (val < value){				
		if (left != 0){
			left->add(val);
		} 
		else {
			left = new TreeNode<T>(val);
		}
	} 
	else {
		if (right != 0){
			right->add(val);
		} 
		else {
			right = new TreeNode<T>(val);
		}
	}
}

// Find /////////////////////////////////////////////
template <class T>
bool TreeNode<T>::find(T val){
	if (val == value){		//Si encuentra el valor en la raíz regresa true
		return true;
	} 
	else if (val < value){	//Si el valor es menor
		return (left != 0 && left->find(val));		//Se mueve a la izquierda hasta encontrar el valor
	} 
	else if (val > value){	//Si el valor es mayor
		return (right != 0 && right->find(val));	//Se mueve a la derecha hasta encontrar el valor
	}
	return false;			//Si no encuentra el valor regresa false
}

// Remove /////////////////////////////////////////////
template <class T>
void TreeNode<T>::remove(T val){
	TreeNode<T> * pred, *old;
	if (val < value) {
		if (left != 0) {
			if (left->value == val) {
				old = left;
				pred = left->predecesor();
				if (pred != 0) {
					pred->left = old->left;
					pred->right = old->right;
				}
				left = pred;
				delete old;
			} 
			else {
				left->remove(val);
			}
		}
	} 
	else if (val > value) {
		if (right != 0) {
			if (right->value == val) {
				old = right;
				pred = right->predecesor();
				if (pred != 0) {
					pred->left = old->left;
					pred->right = old->right;
				}
				right = pred;
				delete old;
			} 
			else {
				right->remove(val);
			}
		}
	}
}

// Remove Childs /////////////////////////////////////////////
template <class T>
void TreeNode<T>::removeChilds(){		//Borra un subárbol completo
	if (left != 0) {			//Si la izquierda es diferente de 0
		left->removeChilds();	//Hace una llamada recursiva a la izquierda
		delete left;			//Elimina left de forma recursiva
		left = 0;				//left se iguala a 0
	}
	if (right != 0) {			//Si la derecha es diferente de 0
		right->removeChilds();	//Hace una llamada recursiva a la derecha
		delete right;			//Elimina right de forma recursiva
		right = 0;				//right se iguala a 0
	}
}


// Inorder /////////////////////////////////////////////
template <class T>
void TreeNode<T>::inorder(std::stringstream &aux) const{
	if (left != 0) {			//Si la izquierda no es nula
		left->inorder(aux);		//Imprimimos los valores de la izquierda de manera recursiva
	}
	if (aux.tellp() != 1) {		//Mientras pueda seguir avanzando 
		aux << "\n";
	}
	aux << value;				//Imprimimos el valor
	if (right != 0) {			//Si la derecha no es nula
		right->inorder(aux);	//Imprimimos los valores de la derecha de manera recursiva
	}
}


// Clase BST /////////////////////////////////////////////
template <class T>
class BST{
	private:
		TreeNode<T> *root;

	public:
		BST();
		~BST();
		bool empty() const;
		void add(T);
		bool find(T) const;
		void remove(T);
		void clear();
		std::string inorder() const;
};

// Constructor BST /////////////////////////////////////////////
template <class T>
BST<T>::BST(): root(0) {}

// Destructor BST /////////////////////////////////////////////
template <class T>
BST<T>::~BST(){
	clear();	//Limpiamos el árbol
}

// Empty /////////////////////////////////////////////
template <class T>
bool BST<T>::empty() const{
	return (root == 0);	//El árbol esta vacio
}

// Add /////////////////////////////////////////////
template<class T>
void BST<T>::add(T val){
	if (root != 0){				//Revisamos que el árbol no este vacio	
		if (!root->find(val)){	//Si el valor no se encuentra en el árbol	
			root->add(val);		//Se incerta un nuevo valor al arból
		}
	} 
	else {
		root = new TreeNode<T>(val);	//Se pone el valor como raíz
	}
}

// Find /////////////////////////////////////////////
template <class T>
bool BST<T>::find(T val) const{
	if (root != 0){					//Revisamos que el árbol no este vacio	
		return root->find(val);		//Regresamos true si se encuentra el valor
	}
	else {							//Si no encontramos el valor regresamos false
		return false;				
	}
}

// Remove /////////////////////////////////////////////
template <class T>
void BST<T>::remove(T val){
	if (root != 0) {							//Revisamos que el árbol no este vacio
		if (val == root->value) {				//Revisar si estamos trabajando con la raiz
			TreeNode<T> *pred = root->predecesor();	//Sacamos el valor directamente del predecesor de la raiz
			if (pred != 0) {					//Si el predecesor no es nulo
				pred->left = root->left;		//El predecesor a la izquierda es la raiz a la izquierda
				pred->right = root->right;		//El predecesor a la derecha es la raiz a la derecha
			}
			delete root;						//Se borra la raiz
			root = pred;						//Marcamos a root como el nuevo predecesor					
		} 
		else {									
			root->remove(val);
		}
	}
}

// Limpiar todo el árbol /////////////////////////////////////////////
template <class T>
void BST<T>::clear(){
	if (root != 0){				//Revisamos que el árbol no este vacio
		root->removeChilds();	//La raíz se mueve para borrar subárboles
	}
	delete root;				//Se borra la raíz
	root = 0;					//La raíz se iguala a 0
}

// Inorder /////////////////////////////////////////////
template <class T>
std::string BST<T>::inorder() const{
	std::stringstream aux;	//Converitmos los datos en string
	if (!empty()) {			//Si el árbol no esta vacio
		root->inorder(aux);	//Imprime los datos en inorder
	}
	aux<<"\n";
	return aux.str();		//Regresa los datos en string
}

// Fin de la transmisión ////////////////////////////////////////
#endif /* BST_H_ */
