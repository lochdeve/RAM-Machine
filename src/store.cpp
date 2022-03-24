#include "../include/store.hpp"
Store::Store(std::string nombreinstruccion, std::string operando) {
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

Store::~Store() {}

void Store::ejecutar(Memoria& memoria, unsigned long& program_counter,
                     bool debug) {
  switch (direccionamiento_) {
    case DIRECTO: {
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_
                  << " Se Guarda el contenido del acumulador en el registro "
                  << operando_ << std::endl;
      }
      memoria.set_memoria(operando_, memoria.get_memoria()[0]);
    } break;
    case INDIRECTO: {
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_
                  << " Se Guarda el contenido del acumulador en el registro "
                  << memoria.get_memoria()[operando_] << std::endl;
      }
      memoria.set_memoria(memoria.get_memoria()[operando_],
                          memoria.get_memoria()[0]);
    } break;
    case INMEDIATO: {
      std::string error = "La instruccion READ no puede manejar inmediatos";
      throw error;
    } break;
    default:
      break;
  }
}

std::string Store::get_nombre() { return nombre_instruccion_; }

std::string Store::get_operando() { return std::to_string(operando_); }