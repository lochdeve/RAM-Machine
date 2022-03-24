#ifndef __Load__
#define __Load__
#include <iostream>
#include <string>

#include "instruccion.hpp"
class Load : public Instruccion {
 public:
  Load(std::string, std::string);
  virtual ~Load();
  void ejecutar(Memoria& memoria, unsigned long& program_counter, bool debug);
  std::string get_nombre();
  std::string get_operando();

 private:
  std::string nombre_instruccion_;
  int operando_;
  int direccionamiento_;
};

#endif