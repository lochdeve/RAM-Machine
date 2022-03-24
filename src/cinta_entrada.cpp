#include "../include/cinta_entrada.hpp"

Cinta_entrada::Cinta_entrada() {
  entrada_.resize(5);
  cabezal_ = 0;
}

Cinta_entrada::Cinta_entrada(Cinta_entrada &copia) {
  entrada_.resize(5);
  entrada_ = copia.get_cinta();
  cabezal_ = copia.cabezal_;
}

Cinta_entrada::Cinta_entrada(char *cinta_entrada) {
  std::fstream fichero;
  fichero.open(cinta_entrada, std::ios::in);
  int datos_cinta;
  while (fichero >> datos_cinta) {
    entrada_.push_back(datos_cinta);
  }
  fichero.close();
  cabezal_ = 0;
}

Cinta_entrada::~Cinta_entrada() {}

std::vector<int> Cinta_entrada::get_cinta() { return entrada_; }

int Cinta_entrada::get_cabezal() const { return cabezal_; }

void Cinta_entrada::incrementar_cabezal() { cabezal_++; }

void Cinta_entrada::read(int nueva_entrada) {
  entrada_.push_back(nueva_entrada);
  cabezal_++;
}

void Cinta_entrada::add_cinta(int nuevo) { entrada_.push_back(nuevo); }

void Cinta_entrada::mostrar_cinta_entrada() {
  std::cout << std::endl << "Cinta de entrada: [";
  for (unsigned long i = 0; i < entrada_.size(); i++) {
    std::cout << entrada_[i];
    if (i != entrada_.size() - 1) {
      std::cout << ",";
    }
  }
  std::cout << "]" << std::endl << std::endl;
}
