#ifndef __Div__
#define __Div__
#include <iostream>
#include <string>

#include "instruccion.hpp"
class Div : public Instruccion {
 public:
  Div(std::string, std::string);
  virtual ~Div();
  void ejecutar(Memoria& memoria, unsigned long& program_counter, bool debug);
  std::string get_nombre();
  std::string get_operando();

 private:
  std::string nombre_instruccion_;
  int operando_;
  int direccionamiento_;
};

#endif