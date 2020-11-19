#include <iostream>
#include <string>
#include <fstream>
#include "graph.h"

using namespace std;

int main(){
    Graph graph;
    graph.start();
    int opc, cost;
    string name;
    string origin, destiny;
    
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

    do{
        cout<<"1.- Ingresar lugar"<<endl;
        cout<<"2.- Ingresar recorrido lugar, origen y costo"<<endl;
        cout<<"3.- Mostrar en lista"<<endl;
        cout<<"4.- Eliminar lugar"<<endl;
        cout<<"5.- Eliminar recorrido"<<endl;
        cout<<"6.- Salir"<<endl;
        cin>>opc;
        switch(opc){
            case 1:
                cout<<"Ingresar lugar: ";
                cin.ignore();
                getline(cin, name);
                cout<<"\n";
                graph.addVertex(name);
                break;

            case 2:
                if(graph.empty()){
                    cout<<"Vacio"<<endl;
                }
                else{
                    cout<<"Ingresar el nombre del lugar de origen: ";
                    cin.ignore();
                    getline(cin, origin);
                    cout<<"Ingresar el nombre del lugar de destino: ";
                    getline(cin, destiny);
                    if(graph.getVertex(origin) == NULL || graph.getVertex(destiny) == NULL){
                        cout<<"El lugar no es valido \n";
                    }
                    else{
                        graph.addEdge(graph.getVertex(origin), graph.getVertex(destiny));
                    }
                }
                cout<<"\n";
                break;

            case 3:
                graph.AdjList();
                cout<<"\n";
                break;

            case 4:
                cout<<"Ingresar el lugar a eliminar: ";
                cin.ignore();
                getline(cin, name);
                if(graph.getVertex(name) == NULL){
                    cout<<"No se encontro el lugar";
                }
                else{
                    graph.deleteVertex(graph.getVertex(name));
                }
                break;

            case 5:
                if(graph.empty()){
                    cout<<"Vacio"<<endl;
                }
                else{
                    cout<<"Ingresar el nombre de lugar de origen: ";
                    cin.ignore();
                    getline(cin, origin);
                    cout<<"Ingresar el nombre de lugar de destino: ";
                    getline(cin, destiny);
                    if(graph.getVertex(origin) == NULL || graph.getVertex(destiny) == NULL){
                        cout<<"No se encontro el dato"<<endl;
                    }
                    else{
                        graph.deleteEdge(graph.getVertex(origin), graph.getVertex(destiny));
                    }
                }
                break;
        }
    } while(opc != 6);
    graph.printGraph();
}