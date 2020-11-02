#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"

using namespace std;

// obtenerContenido ////////////////////////////////////////
template <class T>
bool obtenerContenido(BST<T> &tree, string archivo){
    ifstream read(archivo);
    if(!read){
        cout<<"Error no se pudo abrir el archivo: "<<archivo<<endl;
        return false;
    }
    string dato;
    while (getline(read, dato)){
        if(dato.size() > 0){
            tree.add(dato);
		}
    }
    read.close();
    return true;
}

int main(){
    BST<string> tree;
    string dato;
    bool info = obtenerContenido(tree,"input.txt");
    int opc;
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
            cout<<"\tNuevo correo "<< dato << " fue agregado exitosamente\n";    
        }
        if(opc == 2){
            cout<<tree.inorder();
        }

        if(opc == 3){
            cout<<"Introduce correo: ";
            cin>>dato;
            cout<<tree.find(dato);
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
            //tree.write("output.txt");
            cout<<"Fin de la transmision"<<endl;
        }
    } while(opc != 6);
    return 0;
}
