#ifndef __Halt__
#define __Halt__
#include <iostream>
#include <string>

#include "instruccion.hpp"
class Halt : public Instruccion {
 public:
  Halt(std::string, int&);
  virtual ~Halt();
  void ejecutar(Memoria& memoria, unsigned long& program_counter, bool debug);
  std::string get_nombre();
  std::string get_operando();

 private:
  std::string nombre_instruccion_;
  int ultimainstruccion_;
};

#endif