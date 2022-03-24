#ifndef __Jzero__
#define __Jzero__
#include <iostream>
#include <map>
#include <string>

#include "instruccion.hpp"
class Jzero : public Instruccion {
 public:
  Jzero(std::string, std::string, std::map<std::string, int>&);
  virtual ~Jzero();
  void ejecutar(Memoria& memoria, unsigned long& program_counter, bool debug);
  std::string get_nombre();
  std::string get_operando();

 private:
  std::string nombre_instruccion_;
  std::string etiqueta_;
  int direccionamiento_;
  std::map<std::string, int>* direccion_salto_;
};

#endif