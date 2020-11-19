#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>

using namespace std;

class Edge;

// Clase Vertice //////////////////////////////////////////////////////////////////////////////////////////////////
class Vertex{
    Vertex *next;
    Edge *adj;
    string name;
    friend class Graph;
};

// Clase Arista ///////////////////////////////////////////////////////////////////////////////////////////////////
class Edge{
    Edge *next;
    Vertex *adj;
    int cost;
    friend class Graph;
};

// Clase Graph ////////////////////////////////////////////////////////////////////////////////////////////////////
class Graph{
    Vertex *graph;
    public:
        void start();
        bool empty();
        Vertex *getVertex(string);
        void addEdge(Vertex*, Vertex*, int);
        void addVertex(string);
        void AdjList();
        void deleteEdge(Vertex*, Vertex*);
        void deleteVertex(Vertex* );
        void printGraph();
};

// Start //////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::start(){
    graph = NULL;
}

// Empty //////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graph::empty(){
    return graph == NULL;
}

// Get Vertex /////////////////////////////////////////////////////////////////////////////////////////////////////
Vertex *Graph::getVertex(string name){
    Vertex *aux;    //Declaramos un auxiliar
    aux = graph;    //Posicionamos el auxiliar en el primer vertice del grafo
    while(aux != NULL){         //Vamos a recorrer el grafo mientras no encontremos nulo
        if(aux->name == name){  //Checamos si el valor del auxiliar es el mismo que nos dan
            return aux;         //Regresamos el auxiliar
        }
        aux = aux->next;        //Nos seguimos moviendo
    }
    return NULL;
}

// Add Vertex /////////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::addVertex(string name){
    Vertex *newVertex = new Vertex; //Creamos un nuevo vertice
    newVertex->name = name;         //Lo inicializamos
    newVertex->next = NULL;
    newVertex->adj = NULL;
    if(empty()){            //Si el grafo esta vacio
        graph = newVertex;  //Ponemos nuestro vertice en la primera posición
    }
    else{                   //En caso contrario
        Vertex *aux;        //Usamos un auxiliar
        aux = graph;
        while(aux->next != NULL){   //Recorremos todos los vertices hasta llegar al ultimo
            aux = aux->next;        //Nos movemos
        }
        aux->next = newVertex;      //Agregamos el nuevo vertice
    }
}

// Add Edge //////////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::addEdge(Vertex *origin, Vertex* destiny, int cost){
    Edge *newEdge = new Edge;   //Creamos un nueva arista
    newEdge->cost = cost;       //La inicializamos
    newEdge->next = NULL;
    newEdge->adj = NULL;
    Edge *aux;                  //Generamos un auxiliar 
    aux = origin->adj;
    if(aux == NULL){            //Si encontramos nulo al principio
        origin->adj = newEdge;  //El origen en su adyasente va a ser igual a nueva arista
        newEdge->adj = destiny; //La nueva arista en su adyascente va a ser igual al destino
    }
    else{                       //En caso contrario
        while(aux->next != NULL){ //Nos vamos a localizar en la ultima posición
            aux = aux->next;
        }
        aux->next = newEdge;    //Creamos la nueva arista en la ultima posición
        newEdge->adj = destiny; //La nueva arista en su adyascente va a ser igual al destino
    }
}

// Adjacent List /////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::AdjList(){
    Vertex *auxV;   //Auxiliar para vertice
    Edge *auxE;     //Auxiliar para arista
    auxV = graph;
    while(auxV != NULL){            //Recorremos todos los vertices
        cout<<auxV->name<<" -> ";  
        auxE = auxV->adj;
        while(auxE != NULL){        //Recorremos las aristas de los vertices
            cout<<auxE->adj->name<<" -> ";
            auxE = auxE->next;
        }
        auxV = auxV->next;
        cout<<"\n";
    }
}

// Delete Edge //////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::deleteEdge(Vertex *origin, Vertex *destiny){
    Edge *p, *q;
    p = origin->adj;
    if(p == NULL){  //Si esta vacio el vertice origen
        cout<<"-1\n";  //Regresa -1
    }
    else if(p->adj == destiny){ //En caso de que el grafo no este vacio
        origin->adj = p->next;
        delete(p);
    }
    else{
        while(p->adj != destiny){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete(p);
    }
}

// Delete Vertex /////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::deleteVertex(Vertex *vert){
    Vertex *p, *q;
    Edge *aux;
    p = graph;
    while(p != NULL){
        aux = p->adj;
        while(aux != NULL){
            if(aux->adj == vert){
                deleteEdge(p, aux->adj);
            }
            aux = aux->next;
        }
        p = p->next;
    }
    p = graph;
    if(graph == vert){
        graph = graph->next;
        delete(p);
    }
    else{
        while(p != vert){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete(p);
    }
}

// Print Graph /////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::printGraph(){
    Vertex *auxV;   //Auxiliar para vertice
    Edge *auxE;     //Auxiliar para arista
    auxV = graph;
    ofstream write("output.txt");
    if(write.is_open()){
        while(auxV != NULL){            //Recorremos todos los vertices
            write<<auxV->name<<" -> ";  
            auxE = auxV->adj;
            while(auxE != NULL){        //Recorremos las aristas de los vertices
                write<<auxE->adj->name<<" -> ";
                auxE = auxE->next;
            }
            auxV = auxV->next;
            write<<"\n";
        }
        write.close();
    }
}

// Fin de la transmición /////////////////////////////////////////////////////////////////////////////////////////
#endif //GRAPH_H
