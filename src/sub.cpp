#include "../include/sub.hpp"

Sub::Sub(std::string nombreinstruccion, std::string operando) {
  nombre_instruccion_ = nombreinstruccion;
  if (operando.front() == '=') {
    operando.erase(0, 1);
    direccionamiento_ = INMEDIATO;
  } else if (operando.front() == '*') {
    operando.erase(0, 1);
    direccionamiento_ = INDIRECTO;
  } else {
    direccionamiento_ = DIRECTO;
  }

  int numero = atoi(operando.c_str());
  operando_ = numero;
}

Sub::~Sub() {}

void Sub::ejecutar(Memoria& memoria, unsigned long& program_counter,
                   bool debug) {
  switch (direccionamiento_) {
    case DIRECTO: {
      if (debug) {
        std::cout << "Instruccion: " << program_counter << " Se resta "
                  << memoria.get_memoria()[0] << " a "
                  << memoria.get_memoria()[operando_] << std::endl;
      }
      memoria.set_memoria(
          0, memoria.get_memoria()[0] - memoria.get_memoria()[operando_]);
    } break;
    case INDIRECTO: {
      if (debug) {
        std::cout << "Instruccion: " << program_counter << " Se resta "
                  << memoria.get_memoria()[0] << " a "
                  << memoria.get_memoria()[memoria.get_memoria()[operando_]]
                  << std::endl;
      }
      memoria.set_memoria(
          0, memoria.get_memoria()[0] -
                 memoria.get_memoria()[memoria.get_memoria()[operando_]]);
    } break;
    case INMEDIATO: {
      if (debug) {
        std::cout << "Instruccion: " << program_counter << " Se resta "
                  << memoria.get_memoria()[0] << " a " << operando_
                  << std::endl;
      }
      memoria.set_memoria(0, memoria.get_memoria()[0] - operando_);
    } break;
    default:
      break;
  }
}

std::string Sub::get_nombre() { return nombre_instruccion_; }

std::string Sub::get_operando() { return std::to_string(operando_); }