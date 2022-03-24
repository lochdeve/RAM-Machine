#include "../include/read.hpp"

Read::Read(std::string nombreinstruccion, std::string operando,
           Cinta_entrada& cinta_entrada) {
  nombre_instruccion_ = nombreinstruccion;
  if (operando.front() == '=') {
    std::string error = "La instruccion READ no puede manejar inmediatos";
    throw error;
  } else if (operando.front() == '*') {
    operando.erase(0, 1);
    direccionamiento_ = INDIRECTO;
  } else {
    direccionamiento_ = DIRECTO;
  }
  cinta_ = &cinta_entrada;
  int numero = atoi(operando.c_str());
  operando_ = numero;
}

Read::~Read() {
  cinta_ = NULL;
  delete cinta_;
}

void Read::ejecutar(Memoria& memoria, unsigned long& program_counter,
                    bool debug) {
  switch (direccionamiento_) {
    case DIRECTO: {
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_ << " Se lee de la posicion "
                  << cinta_->get_cabezal()
                  << " el valor: " << cinta_->get_cinta()[cinta_->get_cabezal()]
                  << " en el registro: " << operando_ << std::endl;
      }
      memoria.set_memoria(operando_,
                          cinta_->get_cinta()[cinta_->get_cabezal()]);
      cinta_->incrementar_cabezal();
    } break;
    case INDIRECTO: {
      if (debug) {
        std::cout
            << "Instruccion " << program_counter << ": " << nombre_instruccion_
            << " Se lee de la posicion " << cinta_->get_cabezal()
            << " el valor: "
            << cinta_->get_cinta()[cinta_->get_cinta()[cinta_->get_cabezal()]]
            << " en el registro: " << operando_ << std::endl;
      }
      memoria.set_memoria(
          operando_,
          cinta_->get_cinta()[cinta_->get_cinta()[cinta_->get_cabezal()]]);
      cinta_->incrementar_cabezal();
    } break;
    default:
      throw "Tipo de direccionamiento desconocido";
      break;
  }
}

std::string Read::get_nombre() { return nombre_instruccion_; }

std::string Read::get_operando() { return std::to_string(operando_); }
