#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "DeBlock.cpp"  // Incluye la implementación del TDA DeBlock

int main() {
    std::ifstream inputFile("pruebas.txt");
    if (!inputFile) {
        std::cerr << "No se pudo abrir el archivo de entrada." << std::endl;
        return 1;
    }

    int n, b;
    inputFile >> n >> b;

    tElem* elems = new tElem[n];
    for (int i = 0; i < n; i++) {
        inputFile >> elems[i];
    }

    DeBlock db(elems, n, b);

    int q;
    inputFile >> q;

    std::string line;
    std::getline(inputFile, line); // Leer línea en blanco después de q
    for (int i = 0; i < q; i++) {
        std::getline(inputFile, line);
        std::istringstream iss(line);
        std::string operation;
        iss >> operation;
        
        if (operation == "G") {
            int pos;
            iss >> pos;
            tElem value = db.get_value(pos);
            std::cout << value << std::endl;
        } else if (operation == "I") {
            int pos, value;
            iss >> pos >> value;
            db.insert(pos, value);
        } else if (operation == "L") {
            int len = db.length();
            std::cout << len << std::endl;
        }
    }

    delete[] elems;
    inputFile.close();

    return 0;
}
