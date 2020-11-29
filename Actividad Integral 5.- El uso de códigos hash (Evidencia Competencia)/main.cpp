#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include "hash.h"
#include "info.h"

using namespace std;

// Funciones
unsigned int myHash (const string word);
string IntToString(int x);
vector<string> split(const string &s, char delimiter);

int main(int argc, char* argv[]) {
    string matricula;
    int nip; 
    int nr, op;

    vector<Info> info;

    cout<<"***Este programa es para obtener la matricula y nip de los residentes***"<<"\n";
    cout<<" - Ingresar el número de residentes que se pueden registrar: ";
    cin>>nr;

    HashT <string, int> hash(nr, string("empty"), myHash);

    do { 
        cout<<"\t--Opciones para el sistema--\n";
        cout<<"1. Agregar nuevo alumno"<<endl;
        cout<<"2. Mostrar lista completa de residente"<<endl;
        cout<<"3. Buscar nip de algun alumno"<<endl;
        cout<<"4. Ingresar datos en un archivo read.txt"<<endl;
        cout<<"5. Exit |->"<< endl;
        // Ingresar opciones
        cout<<"\nIngrese una opcion: ";
        cin>>op;
        switch (op) {
            case 1:
                // Agrega un nuevo residente (En cuanto se llena la lista deja de agregar recidentes)
                cout<<"Ingresa la matricula del alumno: ";
                cin.ignore();
                getline(cin, matricula);
                cout<<"Ingresa un nip de tu agrado (de preferencia de 4 digitos): ";
                cin>>nip;
                hash.put(matricula, nip);
                cout<<"\n";
            break;
            case 2:
                // Imprime los residentes agregados
                cout<<hash.toString()<<"\n";              
            break;
            case 3:
                // Regresa el nip del residente, en caso de no encotrar nada regresa -1
                cout<<"Ingresa la matricula del alumno: ";
                cin.ignore();
                getline(cin, matricula);
                cout<<"El nip es: "<<hash.get(matricula)<<endl;
                cout<<"\n";
            break;
            case 4:
                string line;
                ifstream read("input.txt");
                if(read.is_open()){
                    while (getline(read, line)){
                        info.push_back(Info(line));
                    }
                    read.close();
                    for (int i = 0; i<info.size(); i++){
                        info[i].split_data();
                        hash.put(info[i].get_matricula(), info[i].get_nip());
                    }
                    cout<<"\n";
                }
                else
                    cout << "Unable to open file" << '\n';
            break;
        }        
    } while (op != 5);            // Fin de la transmición
    // Escribe el registro en un archivo .txt
    ofstream write("output.txt");
    if(write.is_open()){
        write<<hash.toString();
        write.close();
    }
    else
        cout<<"[Error]: No se pudo realizar la operacion"<<"\n";
    cout<<"\tFin de la transmición\n";
	return 0;
}

// Función hash
unsigned int myHash (const string word){       
    int acum = 0;
    for (int i = 0; i < word.length(); i++){
        acum += int(word[i]);
    }
    return  acum; 
}

// Función para convertir un entero a un string
string IntToString(int x){
    ostringstream st;
    st << x;
    return st.str();
}