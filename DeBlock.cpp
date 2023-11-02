#include <iostream>
#include "LinkList.cpp"
typedef int tElem;

class DeBlock {
  private:
    int cant_elems;
    LinkList l;

  public:
    DeBlock(tElem* elems, int n, int b);
    int insert(int pos, tElem elem);
    tElem erase(int pos);
    tElem get_value(int pos);
    int length();
    void clear();
};

DeBlock::DeBlock(tElem* elems, int n, int b) {
  int numBlocks = (n + b - 1) / b; // Calcula la cantidad de bloques necesarios
  int indiceActual = 0;

  for (int i = 0; i < numBlocks; i++) {
    LinkList bloque; // Crea una nueva lista enlazada para cada bloque

    // Llena el bloque con elementos desde el arreglo 'elems'
    for (int j = 0; j < b && indiceActual < n; j++) {
      bloque.append(elems[indiceActual]);
      indiceActual++;
    }

    l.append(bloque); // Agrega el bloque a la lista de bloques
  }

  cant_elems = n; // Establece la cantidad total de elementos en 'cant_elems'
}

int DeBlock::insert(int pos, tElem elem){
  
}

tElem DeBlock::erase(int pos){
  
}

tElem DeBlock::get_value(int pos){
  
}

int DeBlock::length() {
    return cant_elems;
}

void DeBlock::clear(){
  
}
