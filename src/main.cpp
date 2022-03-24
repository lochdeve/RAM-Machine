#include <fstream>
#include <iostream>

#include "../include/ram.hpp"
int main(int argc, char* argv[]) {
  try {
    bool debug = false;
    if (argv[4]) {
      if (*argv[4] == '1') {
        debug = true;
      }
    }

    Cinta_entrada cinta_entrada(argv[2]);
    Cinta_salida cinta_resultado(argv[3]);
    Programa programa(argv[1], cinta_entrada, cinta_resultado);
    Ram sistema_ram(programa, cinta_entrada, cinta_resultado);

    if (debug) {
      sistema_ram.menu_opciones();
    } else {
      sistema_ram.ejecucion();
      std::cout << "Numero de instrucciones ejecutadas: "
                << sistema_ram.numero_instrucciones() << std::endl;
    }
  } catch (std::string& e) {
    std::cout << e << std::endl;
  }
  return 0;
}
