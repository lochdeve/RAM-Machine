#ifndef __Add__
#define __Add__
#include <iostream>
#include <string>

#include "instruccion.hpp"
class Add : public Instruccion {
 public:
  Add(std::string, std::string);
  virtual ~Add();
  void ejecutar(Memoria& memoria, unsigned long& program_counter, bool debug);
  std::string get_nombre();
  std::string get_operando();

 private:
  std::string nombre_instruccion_;
  int operando_;
  int direccionamiento_;
};

#endif