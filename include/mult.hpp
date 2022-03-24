#ifndef __Mult__
#define __Mult__
#include <iostream>
#include <string>

#include "instruccion.hpp"
class Mult : public Instruccion {
 public:
  Mult(std::string, std::string);
  virtual ~Mult();
  void ejecutar(Memoria& memoria, unsigned long& program_counter, bool debug);
  std::string get_nombre();
  std::string get_operando();

 private:
  std::string nombre_instruccion_;
  int operando_;
  int direccionamiento_;
};

#endif