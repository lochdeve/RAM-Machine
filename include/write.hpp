#ifndef __Write__
#define __Write__
#include <iostream>
#include <string>

#include "cinta_salida.hpp"
#include "instruccion.hpp"
class Write : public Instruccion {
 public:
  Write(std::string, std::string, Cinta_salida&);
  virtual ~Write();
  void ejecutar(Memoria& memoria, unsigned long& program_counter, bool debug);
  std::string get_nombre();
  std::string get_operando();

 private:
  std::string nombre_instruccion_;
  int operando_;
  int direccionamiento_;
  Cinta_salida* cinta_;
};

#endif