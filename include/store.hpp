#ifndef __Store__
#define __Store__
#include <iostream>
#include <string>

#include "instruccion.hpp"
class Store : public Instruccion {
 public:
  Store(std::string, std::string);
  virtual ~Store();
  void ejecutar(Memoria& memoria, unsigned long& program_counter, bool debug);
  std::string get_nombre();
  std::string get_operando();

 private:
  std::string nombre_instruccion_;
  int operando_;
  int direccionamiento_;
};

#endif