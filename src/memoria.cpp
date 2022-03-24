#include "../include/memoria.hpp"

Memoria::Memoria(int size) { memoria_.resize(size); }
Memoria::Memoria() { memoria_.resize(6); }
Memoria::~Memoria() {}

int Memoria::load(int pos) { return memoria_[pos]; }

void Memoria::set_memoria(int posicion, int dato) {
  if (posicion > (int)memoria_.size() - 1) {
    memoria_.resize(posicion + 1);
  }
  memoria_[posicion] = dato;
}

std::ostream& Memoria::write(std::ostream& os) {
  os << std::endl << "Contenido de los registros utilizados:" << std::endl;
  for (size_t i = 0; i < memoria_.size(); i++) {
    std::cout << "Registro " << i << ": " << memoria_[i] << std::endl;
  }
  return os;
}
