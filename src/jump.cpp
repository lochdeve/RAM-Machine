#include "../include/jump.hpp"

using namespace std;

Jump::Jump(std::string nombreinstruccion, std::string operando,
           std::map<std::string, int>& direccion_salto) {
  nombre_instruccion_ = nombreinstruccion;
  etiqueta_ = operando;
  direccion_salto_ = &direccion_salto;
}

Jump::~Jump() {
  direccion_salto_ = NULL;
  delete direccion_salto_;
}

std::string Jump::get_nombre() { return nombre_instruccion_; }

std::string Jump::get_operando() { return etiqueta_; }

void Jump::ejecutar(Memoria& memoria, unsigned long& program_counter,
                    bool debug) {
  if (debug) {
    std::cout << "Instruccion " << program_counter << ": "
              << nombre_instruccion_ << " Salta a " << etiqueta_ << std::endl;
  }
  program_counter = direccion_salto_->find(etiqueta_)->second - 1;
}
