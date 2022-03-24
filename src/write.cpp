#include "../include/write.hpp"

Write::Write(std::string nombreinstruccion, std::string operando,
             Cinta_salida& cinta_salida) {
  nombre_instruccion_ = nombreinstruccion;
  if (operando.front() == '=') {
    direccionamiento_ = INMEDIATO;
    operando.erase(0, 1);
  } else if (operando.front() == '*') {
    operando.erase(0, 1);
    direccionamiento_ = INDIRECTO;
  } else {
    direccionamiento_ = DIRECTO;
  }
  cinta_ = &cinta_salida;
  int numero = atoi(operando.c_str());
  operando_ = numero;
}
Write::~Write() {
  cinta_ = NULL;
  delete cinta_;
}

void Write::ejecutar(Memoria& memoria, unsigned long& program_counter,
                     bool debug) {
  switch (direccionamiento_) {
    case DIRECTO: {
      if (operando_ == 0) {
        std::string error = "ERROR: No se puede hacer WRITE 0 en el programa";
        throw error;
      }
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_ << " Se escribe en la posicion "
                  << cinta_->get_cabezal()
                  << " el valor: " << memoria.get_memoria()[operando_]
                  << " en la cinta de salida " << std::endl;
      }
      cinta_->write(memoria.get_memoria()[operando_]);
      cinta_->incrementar_cabezal();
    } break;
    case INDIRECTO: {
      if (memoria.get_memoria()[operando_] == 0) {
        std::string error = "ERROR: No se puede hacer WRITE *0 en el programa";
        throw error;
      }
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_ << " Se escribe en la posicion "
                  << cinta_->get_cabezal() << " el valor: "
                  << memoria.get_memoria()[memoria.get_memoria()[operando_]]
                  << " en la cinta de salida " << std::endl;
      }
      cinta_->write(memoria.get_memoria()[memoria.get_memoria()[operando_]]);
      cinta_->incrementar_cabezal();
    } break;
    case INMEDIATO: {
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_ << " Se escribe en la posicion "
                  << cinta_->get_cabezal() << " el valor: " << operando_
                  << " en la cinta de salida " << std::endl;
      }
      cinta_->write(operando_);
      cinta_->incrementar_cabezal();
    } break;
    default:
      break;
  }
}

std::string Write::get_nombre() { return nombre_instruccion_; }

std::string Write::get_operando() { return std::to_string(operando_); }