#include "../include/halt.hpp"

Halt::Halt(std::string nombreinstruccion, int& size_programa) {
  nombre_instruccion_ = nombreinstruccion;
  ultimainstruccion_ = size_programa;
}

Halt::~Halt() {}

std::string Halt::get_nombre() { return nombre_instruccion_; }

std::string Halt::get_operando() { return ""; }

void Halt::ejecutar(Memoria& memoria, unsigned long& program_counter,
                    bool debug) {
  if (debug) {
    std::cout << "Instruccion " << program_counter << ": "
              << nombre_instruccion_ << "Se termina la ejecucion del programa"
              << std::endl;
  }
  program_counter = ultimainstruccion_;
}
