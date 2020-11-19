#include <iostream>
#include <string>
#include <fstream>
#include "graph.h"

int main(){
    Graph graph;
    graph.start();

    graph.addVertex("Queretaro");
    graph.addVertex("Mexico");
    graph.addVertex("Veracruz");
    graph.addVertex("Hidalgo");
    graph.addVertex("Puebla");
    graph.addVertex("Guadalajara");

    graph.addEdge(graph.getVertex("Queretaro"), graph.getVertex("Mexico"));
    graph.addEdge(graph.getVertex("Veracruz"), graph.getVertex("Queretaro"));
    graph.addEdge(graph.getVertex("Veracruz"), graph.getVertex("Hidalgo"));
    graph.addEdge(graph.getVertex("Mexico"), graph.getVertex("Hidalgo"));
    graph.addEdge(graph.getVertex("Hidalgo"), graph.getVertex("Guadalajara"));
    graph.addEdge(graph.getVertex("Puebla"), graph.getVertex("Veracruz"));
    graph.addEdge(graph.getVertex("Puebla"), graph.getVertex("Mexico"));
    graph.addEdge(graph.getVertex("Puebla"), graph.getVertex("Hidalgo"));
    graph.addEdge(graph.getVertex("Puebla"), graph.getVertex("Guadalajara"));
    graph.AdjList();

    cout<<"\n";
    graph.deleteVertex(graph.getVertex("Veracruz"));
    graph.AdjList();

    cout<<"\n";
    graph.deleteVertex(graph.getVertex("Puebla"));
    graph.AdjList();

    cout<<"\n";
    graph.deleteEdge(graph.getVertex("Mexico"), graph.getVertex("Hidalgo"));
    graph.AdjList();
}