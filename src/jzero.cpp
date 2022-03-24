#include "../include/jzero.hpp"

Jzero::Jzero(std::string nombreinstruccion, std::string operando,
             std::map<std::string, int>& direccion_salto) {
  nombre_instruccion_ = nombreinstruccion;
  etiqueta_ = operando;
  direccion_salto_ = &direccion_salto;
}

Jzero::~Jzero() {
  direccion_salto_ = NULL;
  delete direccion_salto_;
}

void Jzero::ejecutar(Memoria& memoria, unsigned long& program_counter,
                     bool debug) {
  bool salta = false;

  if (memoria.get_memoria()[0] == 0) {
    salta = true;
    program_counter = direccion_salto_->find(etiqueta_)->second - 1;
  }
  if (debug) {
    std::cout << "Instruccion " << program_counter << ": "
              << nombre_instruccion_;
    if (!salta) {
      std::cout << " No salta a " << etiqueta_
                << " ya que el contenido del acumulador es distinto de cero "
                << std::endl;
    } else {
      std::cout << " Salta a " << etiqueta_ << " ya que el contenido: ["
                << memoria.get_memoria()[0]
                << "] del acumulador es mayor que cero "
                << " que estaba en el acumulador" << std::endl;
    }
  }
}

std::string Jzero::get_nombre() { return nombre_instruccion_; }

std::string Jzero::get_operando() { return etiqueta_; }
