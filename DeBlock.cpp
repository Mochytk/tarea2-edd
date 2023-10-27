
class DeBlock {
  private:
    int cant_elems;
    tListadeLista l;
  public:
    DeBlock(tElem* elems, int n, int b);
    int insert(int pos, tElem elem);
    tElem erase(int pos);
    tElem get_value(int pos);
    int length();
    void clear();
}
