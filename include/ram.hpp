#ifndef __Ram__
#define __Ram__
#include "cinta_entrada.hpp"
#include "cinta_salida.hpp"
#include "memoria.hpp"
#include "programa.hpp"
class Ram {
 public:
  Ram();
  Ram(Programa& programa, Cinta_entrada& cinta_entrada,
      Cinta_salida& cinta_salida);
  ~Ram();

  void ejecucion();
  void ejecucion_traza(bool traza);
  void menu_opciones();

  int numero_instrucciones();

  std::ostream& write(std::ostream&);

 private:
  Memoria memoria_;
  Cinta_entrada cinta_entrada_;
  Cinta_salida cinta_salida_;
  Programa programa_;
  unsigned long program_counter_;
  bool opcion_debug_;
  int numero_instrucciones_;
};

#endif