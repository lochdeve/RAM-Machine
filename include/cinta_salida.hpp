#ifndef __cinta_salida__
#define __cinta_salida__
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Cinta_salida {
 public:
  Cinta_salida();
  Cinta_salida(Cinta_salida& copia);
  Cinta_salida(char* fichero_salida);

  ~Cinta_salida();

  std::vector<int>* get_cinta();
  std::vector<int> get_cinta() const;
  int get_cabezal() const;

  void incrementar_cabezal();
  void write(int);
  void mostrar_cinta_salida();

 private:
  std::vector<int> salida_;
  char* archivo_;
  int cabezal_;
};

#endif