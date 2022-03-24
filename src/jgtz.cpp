#include "../include/jgtz.hpp"

Jgtz::Jgtz(std::string nombreinstruccion, std::string operando,
           std::map<std::string, int>& direccion_salto) {
  nombre_instruccion_ = nombreinstruccion;
  etiqueta_ = operando;
  direccion_salto_ = &direccion_salto;
}

Jgtz::~Jgtz() {
  direccion_salto_ = NULL;
  delete direccion_salto_;
}

std::string Jgtz::get_nombre() { return nombre_instruccion_; }

std::string Jgtz::get_operando() { return etiqueta_; }

void Jgtz::ejecutar(Memoria& memoria, unsigned long& program_counter,
                    bool debug) {
  bool salta = false;
  if (memoria.get_memoria()[0] > 0) {
    salta = true;
    program_counter = direccion_salto_->find(etiqueta_)->second - 1;
  }
  if (debug) {
    std::cout << "Instruccion " << program_counter << ": "
              << nombre_instruccion_;
    if (!salta) {
      std::cout
          << " No salta a " << etiqueta_
          << " ya que el contenido del acumulador es menor o igual que cero "
          << std::endl;
    } else {
      std::cout << " Salta a " << etiqueta_ << " ya que el contenido: ["
                << memoria.get_memoria()[0]
                << "] del acumulador es mayor que cero "
                << " que estaba en el acumulador" << std::endl;
    }
  }
}
