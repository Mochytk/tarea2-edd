#include <iostream>
#include "LinkList.cpp"  // Incluye el archivo de definición de la lista enlazada.

typedef int tElem;  // Definición del tipo de elemento que contendrá el DeBlock.


class DeBlock {
  private:
    int cant_elems;  // Número de elementos totales en el DeBlock.
    LinkList l;  // Lista enlazada que almacena los elementos.

  public:
    // Constructor: Crea un DeBlock a partir de un array de elementos, su cantidad y un tamaño de bloque (b).
    DeBlock(tElem* elems, int n, int b);

    // Inserta un elemento en una posición dada.
    int insert(int pos, tElem elem);

    // Obtiene el valor en una posición específica.
    tElem get_value(int pos);

    // Devuelve la cantidad de elementos en el DeBlock.
    int length();
};

/*****
* DeBlock
******
* Constructor del TDA
******
* Input:
* tElem* elems: arreglo de elementos
* int n: tamaño del arreglo
* int b: tamaño de los bloques
******
* Returns:
* Nada.
*****/
DeBlock::DeBlock(tElem* elems, int n, int b) {
    cant_elems = n;  // Inicializa la cantidad total de elementos.
    for (int i = 0; i < n; i += b) {
        int block_size = (i + b <= n) ? b : n - i;  // Calcula el tamaño del bloque actual.
        for (int j = 0; j < block_size; j++) {
            l.append(elems[i + j]);  // Agrega los elementos al bloque actual en la lista enlazada.
        }
    }
}

/*****
* int DeBlock::insert
******
* Insertar la 
******
* Input:
* int pos: posición en donde insertar
* tElem elem: elemento a insertar
******
* Returns:
* Retorna 1 si el elemento se insertó correctamente
*****/
int DeBlock::insert(int pos, tElem elem) {
    if (pos < 0 || pos > cant_elems) {
        return 0;  // Posición inválida
    }

    int pos_in_block = pos % l.length();  // Calcula la posición en el bloque actual.

    l.moveToPos(pos_in_block);  // Mueve el cursor de la lista al lugar correcto.

    l.insert(elem);  // Inserta el elemento en la posición especificada.

    cant_elems++;  // Incrementa la cantidad total de elementos en el DeBlock.
    return 1;
}

/*****
* tElem DeBlock::get_value
******
* Obtener el valor del elemento en una posición específica
******
* Input:
* int pos: Posición en donde buscar
******
* Returns:
* Retorna el elemento en la posición pedida.
*****/
tElem DeBlock::get_value(int pos) {
    if (pos < 0 || pos >= cant_elems) {
      std::cout << "Posición no válida" << "\n";  // Imprime un mensaje de error si la posición no es válida.
    }

    int block_number = pos / l.length();  // Calcula el número de bloque correspondiente.
    int pos_in_block = pos % l.length();  // Calcula la posición en el bloque actual.

    l.moveToPos(block_number * l.length() + pos_in_block);  // Mueve el cursor de la lista a la posición correcta.

    return l.getValue();  // Devuelve el valor en la posición especificada.
}

/*****
* DeBlock::length
******
* Retorna el número de datos en la estructura.
******
* Input:
* Ninguno.
******
* Returns:
* La cantidad de elementos de la lista asociada.
*****/
int DeBlock::length() {
    return cant_elems;  // Devuelve la cantidad total de elementos en el DeBlock.
}
