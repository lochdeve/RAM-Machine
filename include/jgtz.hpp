#ifndef __Jgtz__
#define __Jgtz__
#include <iostream>
#include <map>
#include <string>

#include "instruccion.hpp"
class Jgtz : public Instruccion {
 public:
  Jgtz(std::string, std::string, std::map<std::string, int>&);
  virtual ~Jgtz();
  void ejecutar(Memoria& memoria, unsigned long& program_counter, bool debug);
  std::string get_nombre();
  void set_operando(int nuevo) { etiqueta_ = nuevo; }
  std::string get_operando();

 private:
  std::string nombre_instruccion_;
  std::string etiqueta_;
  int direccionamiento_;
  std::map<std::string, int>* direccion_salto_;
};

#endif