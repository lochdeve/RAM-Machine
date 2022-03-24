#ifndef __cinta_entrada__
#define __cinta_entrada__
#include <fstream>
#include <iostream>
#include <vector>

class Cinta_entrada {
 public:
  Cinta_entrada();
  Cinta_entrada(Cinta_entrada &);
  Cinta_entrada(char *cinta_entrada);
  ~Cinta_entrada();

  std::vector<int> get_cinta();
  void read(int);
  void add_cinta(int);
  int get_cabezal() const;
  void incrementar_cabezal();

  void mostrar_cinta_entrada();

 private:
  std::vector<int> entrada_;
  int cabezal_;
};

#endif