#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "bst.h"

using namespace std;

int main(){
    BST<string> tree;
    string dato;
    string line;
    string correo;
    int opc;

    ifstream read("input.txt");
    if(read.is_open()){
        while(read>>correo){
        tree.add(correo);
        }
    }
    read.close();
    
    do {
        cout<<"\n--------Bienvenido--------\n";
        cout<<"1.- Agregar Correo\n";
        cout<<"2.- Mostrar Datos\n";
        cout<<"3.- Buscar Persona\n";
        cout<<"4.- Remover Persona\n";
        cout<<"5.- Limpiar Datos\n";
        cout<<"6.- Exit\n";
        cin>>opc;
        if(opc == 1){
            cout<<"Introduce correo: ";
            cin>>dato;
            tree.add(dato);
            cout<<"\tNuevo correo "<<dato<< " fue agregado exitosamente\n";    
        }
        if(opc == 2){
            cout<<tree.inorder();
        }

        if(opc == 3){
            cout<<"Introduce correo: ";
            cin>>dato;
            cout<<tree.find(dato);
            cout<<"\n";
        }

        if(opc == 4){
            cout<<"Introduce correo: ";
            cin>>dato;
            tree.remove(dato);
        }

        if(opc == 5){
            tree.clear();
        }

        if(opc == 6){
            cout<<"Fin de la transmision"<<endl;
            // Escribir en un archivo ////////////////////////////////////////
            ofstream write("output.txt");
            if(write.is_open()){
                write<< tree.inorder();
                write.close();
            }
            else
                cout << "Unable to open file" << '\n';
            }
    } while(opc != 6);
    return 0;
}
