#include "../include/div.hpp"
Div::Div(std::string nombreinstruccion, std::string operando) {
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

Div::~Div() {}

void Div::ejecutar(Memoria& memoria, unsigned long& program_counter,
                   bool debug) {
  switch (direccionamiento_) {
    case DIRECTO: {
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_ << " Se divide "
                  << memoria.get_memoria()[0] << " entre el valor "
                  << memoria.get_memoria()[operando_]
                  << " que estaba en el acumulador" << std::endl;
      }
      if (memoria.get_memoria()[operando_] == 0) {
        std::string error = "No se puede dividir un numero entre cero";
        throw error;
      } else {
        memoria.set_memoria(
            0, memoria.get_memoria()[0] / memoria.get_memoria()[operando_]);
      }
    } break;
    case INDIRECTO: {
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_ << " Se divide "
                  << memoria.get_memoria()[0] << " entre el valor "
                  << memoria.get_memoria()[memoria.get_memoria()[operando_]]
                  << " que estaba en el acumulador" << std::endl;
      }
      if (memoria.get_memoria()[operando_] == 0) {
        std::string error = "No se puede dividir un numero entre cero";
        throw error;
      } else {
        memoria.set_memoria(
            0, memoria.get_memoria()[0] /
                   memoria.get_memoria()[memoria.get_memoria()[operando_]]);
      }
    } break;
    case INMEDIATO: {
      if (debug) {
        std::cout << "Instruccion " << program_counter << ": "
                  << nombre_instruccion_ << " Se divide "
                  << memoria.get_memoria()[0] << " entre el valor " << operando_
                  << " que estaba en el acumulador" << std::endl;
      }
      if (memoria.get_memoria()[operando_] == 0) {
        std::string error = "No se puede dividir un numero entre cero";
        throw error;
      } else {
        memoria.set_memoria(0, memoria.get_memoria()[0] / operando_);
      }
    } break;
    default:
      break;
  }
}

std::string Div::get_nombre() { return nombre_instruccion_; }

std::string Div::get_operando() { return std::to_string(operando_); }