#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include "pancake.h"

using namespace std;

// Funciones
void ver(ifstream &, vector<string>&);
void buscar(ifstream &);

int main(int argc, char const *argv[]){
    vector<string> vs;
    Sort<string> sorts;
    string matricula;
    ofstream write("output.txt");
    int opc;

    // lectura de archivos
    ifstream read("input.txt");
    if(!read){
        cout<< "No se puede abrir el archivo: "<<endl;
        return false;
    }
    string line;
    while (getline(read, line)){
        if(line.size() > 0){
            vs.push_back(line);
		}
    }
    read.close();
    
    do{
        cout<<"\n--------Bienvenido--------\n";
        cout<<"1.- Mostrar lista\n";
        cout<<"2.- Ordenar Lista\n";
        cout<<"3.- Buscar Alumno\n";
        cout<<"4.- Salir |->\n";
        cin>>opc;

        switch(opc){
            case 1:
                ver(read, vs);
            break;

            case 2:
                sorts.pancake(vs);
                for(string & line : vs){
                    cout<<line<<endl;
                }
            break;
    
            case 3:
                buscar(read);
            break;
        }

    } while(opc != 4);
    cout<<"-----Hasta la proxima-----\n";
    if(write.is_open()){
        for (string & line: vs){
            write<<line<<endl;
            }
         write.close();
    }
}

// Buscar 
void buscar(ifstream &read){
    read.open("input.txt", ios::in);
    string matricula, nombre, ape, correo, naux;
    int band = 0;
    cout<<"Ingresa la matricula: ";
    cin>>naux;
    read>>matricula;
    while(!read.eof() && band == 0){
        read>>nombre;
        read>>ape;
        read>>correo;
        if(matricula == naux){
            cout<<"Matricula: "<<matricula<<endl;
            cout<<"Nombre: "<<nombre<<" "<<ape<<endl;
            cout<<"Correo: "<<correo<<endl;
            band = 1;
        }
        read>>matricula;
    }
    read.close();
    if (band == 0){
        cout<<"No esta el alumno"<<endl;
    }
}


// Ver 
void ver(ifstream &read, vector<string>& vs){
    string matricula;
    string nombre;
    string ape;
    string correo;
    string line;
    read.open("input.txt");
    if(read.is_open()){
        cout<<" \tMatricula - Nombre - Correo"<<endl;
    }
    for(string & line : vs){
        cout<<line<<endl;
    } 
    read.close();
}
