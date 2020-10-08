#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "list.h"

using namespace std; 

// obtenerContenido ////////////////////////////////////////
template <class T>
bool obtenerContenido(List<T> &l1, string archivo){
    ifstream read(archivo);
    if(!read){
        cout<<"Error no se pudo abrir el archivo: "<<archivo<<endl;
        return false;
    }
    string dato;
    while (getline(read, dato)){
        if(dato.size() > 0){
            l1.add(dato);
		}
    }
    read.close();
    return true;
}

int main(){
    List<string> l1;
    string dato; 
    bool info = obtenerContenido(l1,"input.txt");
    int opc;
    do {
        cout<<"\n--------Bienvenido--------\n";
        cout<<"1.- Agregar Persona\n";
        cout<<"2.- Mostrar lista\n";
        cout<<"3.- Buscar Persona\n";
        cout<<"4.- Remover Persona\n";
        cout<<"5.- Limpiar lista\n";
        cout<<"6.- Exit\n";
        cin>>opc;
        if(opc == 1){
            cout<<"Introduce Matricula-Nombre: ";
            cin>>dato;
            l1.add(dato);
            cout<<"\tNueva persona "<< dato << " fue agregada exitosamente\n";    
        }
        if(opc == 2){
            l1.show();
            cout<<"\n"; 
        }

        if(opc == 3){
            cout<<"Introduce Matricula-Nombre: ";
            cin>>dato;
            cout<<l1.find(dato); 
        }

        if(opc == 4){
            cout<<"Introduce Matricula-Nombre: ";
            cin>>dato;
            l1.remove(dato);
        }

        if(opc == 5){
            l1.clear();
        }

        if(opc == 6){
            l1.write("output.txt");
            cout<<"Fin de la transmision"<<endl;
        }
    } while(opc != 6); 
    return 0;
}


/*
    ofstream write("example.txt");
    if(write.is_open()){
        for (string & dato: l1){
        write<< dato <<endl;
        }
        write.close();
    }
*/