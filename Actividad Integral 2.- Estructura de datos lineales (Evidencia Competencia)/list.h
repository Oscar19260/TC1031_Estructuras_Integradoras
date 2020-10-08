#ifndef LIST_H_
#define LIST_H_

#include <list>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

template <class T> class List;

// Clase Node ////////////////////////////////////////
template <class T>
class Node {
private:
    T value;
	Node<T> *next;
	Node(T);
	Node(T, Node<T>*);
	Node(const Node<T>&);

	friend class List<T>;
};

// Constructores del nodo ////////////////////////////////////////
template <class T>
Node<T>::Node(T val) : value(val), next(0) {}

template <class T>
Node<T>::Node(T val, Node* nxt) : value(val), next(nxt) {}

template <class T>
Node<T>::Node(const Node<T> &source) : value(source.value), next(source.next) {}

// Clase List ////////////////////////////////////////
template <class T>
class List {
    private:
        Node<T> *head;
        int size;

    public:
        List();
        List(const List<T>&);
        ~List();
        bool empty() const;
        void addFirst(T);
        void add(T);
        void show();
        void remove(T);
        T find(T) const;
        void clear();
        std::string toString() const;
        void write(string);
};

// Constructores de lista ////////////////////////////////////////
template <class T>
List<T>::List(): head(0), size(0) {}

template <class T>
List<T>::List(const List<T> &source){
	Node<T> *p, *q;
	if (source.empty()) {
		size = 0;
		head = 0;
	} 
    else {
		p = source.head;
		head = new Node<T>(p->value);
		q = head;
		p = p->next;
		while(p != 0) {
			q->next = new Node<T>(p->value);
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

// Destructor de lista ////////////////////////////////////////
template <class T>
List<T>::~List() { 
	clear();
}

// Empty ////////////////////////////////////////
template <class T>
bool List<T>::empty() const {   //Lista vacia
	return (head == 0);
}

// Add ////////////////////////////////////////
template <class T>
void List<T>::addFirst(T val) { 
	Node<T> *newNode;           //Creamos un nuevo nodo
	newNode = new Node<T>(val); //Definimos el nodo
	newNode->next = head;       //Lo movemos para que la cabeza apunte
	head = newNode;             //La cabeza lo apunta
	size++;                     //Agrandamos el tamaño de la lista
}

template <class T>
void List<T>::add(T val){
    Node<T> *newNode, *p;       //Creamos dos punteros
    newNode = new Node<T>(val); //Definimos el nodo
	if (head == 0) {            //Si la cabeza apunta a nulo la lista esta vacia
		addFirst(val);          //Hacemos el addFirst
		return;
	}
	p = head;                   //Ponemos un puntero dirigiendose a lo mismo que cabeza
	while (p->next != 0) {      //Mientra el puntero en la posición no sea nula
		p = p->next;            //Se sigue moviendo
	}
	newNode->next = 0;          //Movemos el nodo al vacio
	p->next = newNode;          //Colocamos el elemento en la posición libre
	size++;                     //Agrandamos el tamaño de la lista                
}

// Show ////////////////////////////////////////
template <class T>
void List<T>::show(){
    Node<T> *p;         //Creamos un nuevo nodo
    p = head;           //El nuevo nodo apunta a la lista
    while(p != NULL){   //Recorremos toda la lista
        cout<<p->value<<"\n";
        p = p->next;
    }
}

// Find ////////////////////////////////////////
template <class T>
T List<T>::find(T val) const{
    Node<T> *p;         //Creamos un nuevo nodo
    p = head;           //El nuevo nodo apunta a la lista
    while (p != 0){     //Recorremos la lista
        if (p->value == val){   //Si se encuentra el valor regresa un mensaje y la persona
            cout<<"La persona si esta en la lista\n";
            return val;
        }
        p = p->next;    //Nos movemos al siguiente elemento
    }                           //Si no se encuentra el valor regresa un mensaje y -1
    cout<<"La persona NO esta en la lista\n";
    return "-1";
}

// Remove ////////////////////////////////////////
template <class T>
void List<T>::remove(T val){
	if(head != NULL){       //Preguntamos si la lista esta vacia
        Node<T> *p;
        Node<T> *q = NULL;
        p = head;
        while((p != NULL) && (p->value != val)){ //Recorremos la lista
            q = p;
            p = p->next;
        }
        if(p == NULL){      //No se encontro un elemento
            cout<<"La persona no existe\n";
        }
        else if(q == NULL){ //Eliminamos el primer elemento de la lista
            head = head->next;
            delete p;
            cout<<"Elemento eliminado\n";
        }
        else{               //Eliminamos un elemento 
            q->next = p->next;
            delete p;
            cout<<"Elemento eliminado\n";
        }
    } 
}

// Clear ////////////////////////////////////////
template <class T>
void List<T>::clear(){
    Node<T> *p, *q;     //Creamos 2 punteros
    p = head;           //Uno lo apuntamos a la cabeza
    while(p != 0){      //Mientra la lista no este vacia
        q = p->next;    //El otro apuntador lo vamos moviendo por la lista
        delete p;       //Eliminamos el puntero
        p = q;          //Igualamos el puntero a la siguente posicion
    }
    head = 0;
    size = 0;                 
}

// Transformar a string ////////////////////////////////////////
template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Node<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

// Escribir en un archivo ////////////////////////////////////////
template <class T>
void List<T>::write(string file){
	ofstream archivo;
    archivo.open(file);
	Node<T> *p;
    p = head;
	while (p != 0) {
        archivo<< p->value << endl;
		//cout<<"\n";
        p = p->next;
	}
    archivo.close();
}

// Fin de la transmisión ////////////////////////////////////////
#endif /* LIST_H_ */
