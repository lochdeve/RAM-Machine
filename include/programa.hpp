#ifndef __Programa__
#define __Programa__
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "add.hpp"
#include "cinta_salida.hpp"
#include "div.hpp"
#include "halt.hpp"
#include "instruccion.hpp"
#include "jgtz.hpp"
#include "jump.hpp"
#include "jzero.hpp"
#include "load.hpp"
#include "mult.hpp"
#include "read.hpp"
#include "store.hpp"
#include "sub.hpp"
#include "write.hpp"
class Programa {
 public:
  Programa();
  Programa(char*, Cinta_entrada&, Cinta_salida&);
  Programa(const Programa&);
  ~Programa();
  std::vector<Instruccion*> get_instrucciones();
  std::map<std::string, int> get_etiquetas() const;
  std::ostream& write(std::ostream&);

 private:
  std::vector<Instruccion*> instrucciones_;
  std::map<std::string, int> etiquetas_;
  bool opcion_debug_;
};
#endif