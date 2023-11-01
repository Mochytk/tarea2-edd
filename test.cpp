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
    getline(archivo, operacion); // Leemos las operaciones una a una
    stringstream linea(operacion) // Con un stringstream para analizar la linea como tokens separados
    string operation; // Generamos el string operation
    linea >> operation; // Sacamos la operacion de la linea leyendo el primer token
    
    if (operation == "I"){
      int pos; // Creamos un entero para guardar la posición
      tElem val; // Creamos un tElem para guardar el valor a insertar
      linea >> pos >> val; // las leemos de la linea de la operación
      
      int insertado = insert(pos, val);
      
      if (insertado == 1){
        cout << insertado << endl;
      } else {
        cout << "Error al insertar el elemento" << endl;
      }
      
      n++;
    } else if (operation == "G"){
      int pos;
      linea >> pos;
      if (pos <= n){
        cout << lista[pos];
      } else {
        cout << "Posición fuera de rango" << endl;
      }    
    } else if (operation == "L"){
      cout << n << endl;
    }
  }
}
