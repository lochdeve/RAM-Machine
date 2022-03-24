#ifndef __Read__
#define __Read__
#include <iostream>
#include <string>

#include "cinta_entrada.hpp"
#include "instruccion.hpp"
class Read : public Instruccion {
 public:
  Read(std::string, std::string, Cinta_entrada&);
  virtual ~Read();
  void ejecutar(Memoria& memoria, unsigned long& program_counter, bool debug);
  std::string get_nombre();
  std::string get_operando();

 private:
  std::string nombre_instruccion_;
  int operando_;
  int direccionamiento_;
  Cinta_entrada* cinta_;
};

#endif