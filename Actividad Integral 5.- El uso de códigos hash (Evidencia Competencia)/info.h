#ifndef INFO_H_
#define INFO_H_

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<string> split(const string &s, char delimiter){
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter)){
      tokens.push_back(token);
   }
   return tokens;
}

class Info{
  private:
    string datos;
    string matricula;
    string snip;
  public:
    //Constructor por vacio
    Info():datos(""), matricula(""), snip(""){};
    //Funciones
    //Constructor parametrizado
    Info(string data): datos(data), matricula(""), snip(""){};
    void split_data();
    string get_matricula();
    int get_nip();
};

// Separar datos 
void Info::split_data(){
    vector<string> aux;
    aux = split(datos,' ');
    matricula = aux[0];
    snip = aux[1];
    
}

// Obtenemos la matricula
string Info::get_matricula(){
    return matricula;
}

// Obtenemos el nip
int Info::get_nip(){
    return stoi(snip);
}

#endif /*Info_H*/
