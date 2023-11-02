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
    cant_elems = n;
    for (int i = 0; i < n; i += b) {
        int block_size = (i + b <= n) ? b : n - i;
        for (int j = 0; j < block_size; j++) {
            l.append(elems[i + j]);
        }
    }
}

int DeBlock::insert(int pos, tElem elem) {
    if (pos < 0 || pos > cant_elems) {
        return 0;  // Posición inválida
    }

    int block_number = pos / l.length();
    int pos_in_block = pos % l.length();

    l.moveToPos(pos_in_block);

    l.insert(elem);

    cant_elems++;
    return 1;
}

tElem DeBlock::erase(int pos) {
    if (pos < 0 || pos >= cant_elems) {
    }

    int block_number = pos / l.length();
    int pos_in_block = pos % l.length();

    l.moveToPos(block_number * l.length() + pos_in_block);

    tElem deleted_value = l.erase();

    cant_elems--;
    return deleted_value;
}

tElem DeBlock::get_value(int pos) {
    if (pos < 0 || pos >= cant_elems) {
    }

    int block_number = pos / l.length();
    int pos_in_block = pos % l.length();

    l.moveToPos(block_number * l.length() + pos_in_block);

    return l.getValue();
}

int DeBlock::length() {
    return cant_elems;
}

void DeBlock::clear() {
    l.clear();
    cant_elems = 0;
}
