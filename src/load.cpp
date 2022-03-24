#include "../include/load.hpp"
Load::Load(std::string nombreinstruccion, std::string operando) {
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

Load::~Load() {}

void Load::ejecutar(Memoria& memoria, unsigned long& program_counter,
                    bool debug) {
  switch (direccionamiento_) {
    case DIRECTO: {
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_ << " Se carga del registro "
                  << operando_ << " el valor "
                  << memoria.get_memoria()[operando_]
                  << " y se pone en el acumulador" << std::endl;
      }
      memoria.set_memoria(0, memoria.get_memoria()[operando_]);
    } break;
    case INDIRECTO: {
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_ << " Se carga del registro "
                  << operando_ << " el valor "
                  << memoria.get_memoria()[memoria.get_memoria()[operando_]]
                  << " y se pone en el acumulador" << std::endl;
      }
      memoria.set_memoria(
          0, memoria.get_memoria()[memoria.get_memoria()[operando_]]);
    } break;
    case INMEDIATO: {
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_ << " Se carga del registro "
                  << operando_ << " el valor " << operando_
                  << " y se pone en el acumulador" << std::endl;
      }
      memoria.set_memoria(0, operando_);
    } break;
    default:
      std::cout << "No existe este tipo de direccionamiento o es erroneo"
                << std::endl;
      break;
  }
}

std::string Load::get_nombre() { return nombre_instruccion_; }

std::string Load::get_operando() { return std::to_string(operando_); }