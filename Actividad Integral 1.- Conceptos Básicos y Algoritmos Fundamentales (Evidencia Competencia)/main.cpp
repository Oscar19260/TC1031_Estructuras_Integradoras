#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include "funciones.h"

using namespace std;

// obtenerContenido ////////////////////////////////////////
template <class T>
bool obtenerContenido(vector<T> &vs, string archivo){
    ifstream lee(archivo);
    if(!lee){
        cout<< "No se puede abrir el archivo: "<<endl;
        return false;
    }
    string line;
    while (getline(lee, line)){
        if(line.size() > 0){
            vs.push_back(line);
		}
    }
    lee.close();
    return true;
}

// Verificar ////////////////////////////////////////
bool verificar(string nom){
    ifstream leer("info.txt", ios::in);
    string Nom;
    string Gen;
    string Type;
    leer>>Nom;
    while(!leer.eof()){
        leer>>Gen;
        leer>>Type;
        if (Nom == nom){
            leer.close();
            return false;
        }
        leer>>Nom;
    }
    leer.close();
    return true;
}

// Agregar pokemon ////////////////////////////////////////
void agregarP(ofstream &esc){
    string Nom;
    string Gen;
    string Type;
    esc.open("info.txt", ios::out | ios::app);
    cout<<"Nombre: ";
    cin>>Nom;
    cout<<"Generacion: ";
    cin>>Gen;
    cout<<"Tipo(s) (tipo1/tipo2): ";
    cin>>Type;
    esc<<Nom<<" "<<Gen<<" "<<Type<<"\n";
    if(verificar(Nom))
    esc.close();
}

// Buscar pokemon ////////////////////////////////////////
void buscarPokemon(ifstream &read){
    read.open("info.txt", ios::in);
    string nom, gen, type, naux;
    int band = 0;
    cout<<"Ingresa el nombre del pokemon: ";
    cin>>naux;
    read>>nom;
    while(!read.eof() && band == 0){
        read>>gen;
        read>>type;
        if(nom == naux){
            cout<<"Nombre: "<<nom<<endl;
            cout<<"Generacion: "<<gen<<endl;
            cout<<"Tipo(s): "<<type<<endl;
            cout<<"--------------"<<endl;
            band = 1;
        }
        read>>nom;
    }
    read.close();
    if (band == 0){
        cout<<"El pokemon no se encuentra"<<endl;
    }
}

// Ver pokemon ////////////////////////////////////////
void verPokemon(ifstream &read){
    string nom;
    string gen;
    string type;
    read.open("info.txt", ios::in);
    if(read.is_open()){
        cout<<"----------Pokemon's Registrados----------"<<endl;
        cout<<" Nombre Generacion Tipo(s)"<<endl;
        read>>nom;
        while(!read.eof()){
            read>>gen;
            read>>type;
            cout<<nom<<" "<<gen<<" "<<type<<endl;
            cout<<"--------------"<<endl;
            read>>nom;
        }
        read.close();
    }
    else{
        cout<<"Error"<<endl;
    }
}


// Main ////////////////////////////////////////
int main(int argc, char const *argv[]){
    vector<string> vs;
    Sorts<string> sorts;
    ofstream esc;
    ifstream read;
    bool info = obtenerContenido(vs,"info.txt");

    sorts.ordenaMerge(vs);

    ofstream escribe("example.txt");
    if(escribe.is_open()){
        for (string & line: vs){
            escribe<<line<<endl;
        }
        escribe.close();
    }
    int opc;
    
    do{
        cout<<"\n--------Bienvenido--------\n";
        cout<<"1 Agregar Pokemon\n";
        cout<<"2 Ver Pokemons\n";
        cout<<"3 Ordenar Pokedex\n";
        cout<<"4 Buscar Pokemon\n";
        cout<<"5 Salir\n";
        cin>>opc;

        switch(opc){
            case 1: 
                agregarP(esc);
            break;

            case 2:
                verPokemon(read);
            break;

            case 3:
                for(string & line : vs){
                    cout<<line<<endl;
                    cout<<"--------------"<<endl;
                }
            break;
    
            case 4:
                buscarPokemon(read);
            break;

            case 777: 
                cout<<"piii Chu chu pi-i kachuópi Pi-pi-kaaa-chu"<<endl;
            break;
        }
    } while(opc != 5);
    cout<<"Hasta la proxima\n";

    return 0;
}

// http://pikachize.eye-of-newt.com/

