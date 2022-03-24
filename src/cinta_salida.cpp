#include "../include/cinta_salida.hpp"

Cinta_salida::Cinta_salida() { cabezal_ = 0; }

Cinta_salida::Cinta_salida(char* fichero_salida) {
  archivo_ = fichero_salida;
  remove(fichero_salida);
  cabezal_ = 0;
}

Cinta_salida::Cinta_salida(Cinta_salida& copia) {
  salida_ = copia.salida_;
  archivo_ = copia.archivo_;
  cabezal_ = copia.cabezal_;
}

Cinta_salida::~Cinta_salida() {}

std::vector<int>* Cinta_salida::get_cinta() { return &salida_; }

std::vector<int> Cinta_salida::get_cinta() const { return salida_; }

int Cinta_salida::get_cabezal() const { return cabezal_; }

void Cinta_salida::incrementar_cabezal() { cabezal_++; }

void Cinta_salida::write(int resultado) {
  salida_.push_back(resultado);
  std::fstream fichero;
  fichero.open(archivo_, std::ios::app);
  fichero << resultado << " ";
  fichero.close();
}

void Cinta_salida::mostrar_cinta_salida() {
  std::cout << std::endl
            << "Cinta de salida: "
            << "[ ";
  std::string elementos;
  std::ifstream fichero;
  fichero.open(archivo_, std::ios::in);
  while (fichero >> elementos) {
    std::cout << elementos;
  }
  std::cout << " ]" << std::endl << std::endl;
}
