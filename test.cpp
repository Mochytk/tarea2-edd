#include <iostream>
#include <fstream>
#include <string>
#include "LinkList.cpp"
#include "DeBlock.cpp"

using namespace std;

int main(){
  ifstream archivo;
  archivo.open("pruebas.txt");

  // Verificamos que el archivo abra correctamente
  if (!archivo.is_open()){
    cout << "No se pudo abrir el archivo" << endl;
  }
  int tam, sub_tam, cant_oper; // creamos variables para el tamaño de la lista, el tamaño de las sub-listas y la cantidad de operaciones a realizar
  archivo >> tam >> sub_tam; // Lee el tamaño original de la lista y el tamaño de las sub listas

  int lista[tam] // Generamos una arreglo con el tamaño de la lista dada por el archivo
  for (int i = 0; i < n; i++) {
    archivo >> lista[i];
  }

  archivo >> cant_oper; // Lee la cantidad de operaciones

  string operaciones; // Creamos un string para leer las operaciones

  for (int j = 0; j < cant_oper; j++){
    getline(archivo, operaciones); // Leemos las operaciones una a una
    string operation;
    if (operation == "I"){
      
      n++;
    } else if (operation == "G"){
    } else if (operation == "L"){
      cout << n << endl;
    }
  }
  
}
