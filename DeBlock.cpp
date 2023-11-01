#include "LinkList.cpp"
typedef int tElem;

class DeBlock {
  private:
    int cant_elems;
    LinkList l;
    LinkList bloqueActual;
  
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

tElem DeBlock::get_value(int pos){
  // Esto son ideas que tuve en una iluminación, deberiamos dividir la posición por b (la cantidad de elementos del sub bloque) y con eso podemos acceder directamente al elemento de la lista de listas, ahí ya es cosa de sacar el resto y usar eso para la posición
}

int DeBlock:: length(){
  
}
