#ifndef __Instruccion__
#define __Instruccion__
#include <iostream>
#include <map>
#include <string>

#include "memoria.hpp"

enum { DIRECTO, INDIRECTO, INMEDIATO };
class Instruccion {
 public:
  virtual ~Instruccion() = default;
  virtual void ejecutar(Memoria& memoria, unsigned long& program_counter,
                        bool debug) = 0;
  virtual std::string get_nombre() = 0;
  virtual std::string get_operando() = 0;
};

#endif