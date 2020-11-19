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

    graph.addEdge(graph.getVertex("Queretaro"), graph.getVertex("Mexico"), 300);
    graph.addEdge(graph.getVertex("Veracruz"), graph.getVertex("Queretaro"), 500);
    graph.addEdge(graph.getVertex("Veracruz"), graph.getVertex("Hidalgo"), 350);
    graph.addEdge(graph.getVertex("Mexico"), graph.getVertex("Hidalgo"), 250);
    graph.addEdge(graph.getVertex("Hidalgo"), graph.getVertex("Guadalajara"), 750);
    graph.addEdge(graph.getVertex("Puebla"), graph.getVertex("Veracruz"), 400);
    graph.addEdge(graph.getVertex("Puebla"), graph.getVertex("Mexico"), 450);
    graph.addEdge(graph.getVertex("Puebla"), graph.getVertex("Hidalgo"), 550);
    graph.addEdge(graph.getVertex("Puebla"), graph.getVertex("Guadalajara"), 800);
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