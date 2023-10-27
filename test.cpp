#include <iostream>
#include <fstream>
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
  
}
