#ifndef __Sub__
#define __Sub__
#include <iostream>
#include <string>

#include "instruccion.hpp"
class Sub : public Instruccion {
 public:
  Sub(std::string, std::string);
  virtual ~Sub();
  void ejecutar(Memoria& memoria, unsigned long& program_counter, bool debug);
  std::string get_nombre();
  std::string get_operando();

 private:
  std::string nombre_instruccion_;
  int operando_;
  int direccionamiento_;
};

#endif