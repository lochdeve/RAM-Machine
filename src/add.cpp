#include "../include/add.hpp"

Add::Add(std::string nombreinstruccion, std::string operando) {
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

Add::~Add() {}

void Add::ejecutar(Memoria& memoria, unsigned long& program_counter,
                   bool debug) {
  switch (direccionamiento_) {
    case DIRECTO: {
      if (debug) {
        std::cout << "Instruccion: " << program_counter << " Se suma "
                  << memoria.get_memoria()[operando_] << " a "
                  << memoria.get_memoria()[0] << std::endl;
      }
      memoria.set_memoria(
          0, memoria.get_memoria()[operando_] + memoria.get_memoria()[0]);
    } break;
    case INDIRECTO: {
      if (debug) {
        std::cout << "Instruccion: " << program_counter << " Se suma "
                  << memoria.get_memoria()[memoria.get_memoria()[operando_]]
                  << " a " << memoria.get_memoria()[0] << std::endl;
      }
      memoria.set_memoria(
          0, memoria.get_memoria()[memoria.get_memoria()[operando_]] +
                 memoria.get_memoria()[0]);
    } break;
    case INMEDIATO: {
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_ << " Se suma " << operando_
                  << " al valor " << memoria.get_memoria()[0]
                  << " que estaba en el acumulador" << std::endl;
      }
      memoria.set_memoria(0, memoria.get_memoria()[0] + operando_);
    } break;
    default:
      break;
  }
}

std::string Add::get_nombre() { return nombre_instruccion_; }

std::string Add::get_operando() { return std::to_string(operando_); }