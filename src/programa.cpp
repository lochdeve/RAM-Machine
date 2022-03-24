#include "../include/programa.hpp"

Programa::Programa() {}

Programa::Programa(char* nombre_fichero, Cinta_entrada& cinta_entrada,
                   Cinta_salida& cinta_salida) {
  std::fstream fichero;
  bool existe_halt = false;
  fichero.open(nombre_fichero, std::ios::in);
  std::string operando;
  Instruccion* instruccion_obj;
  int ultima_instruccion = 0;
  if (fichero) {
    std::string instruccion;
    while (fichero >> instruccion) {
      for (unsigned long i = 0; i < instruccion.size(); i++)
        instruccion[i] = toupper(instruccion[i]);

      if (instruccion.front() == ';' || instruccion.front() == '#') {
        getline(fichero, instruccion);
      } else if (instruccion.back() == ':') {  // Etiqueta
        instruccion.pop_back();
        if (etiquetas_.find(instruccion) != etiquetas_.end()) {
          std::string error =
              "ERROR: El programa tiene etiquetas con el mismo nombre";
          throw error;
        }
        etiquetas_.insert(make_pair(instruccion, (int)instrucciones_.size()));
      } else if (instruccion == "LOAD") {
        fichero >> operando;
        instruccion_obj = new Load(instruccion, operando);
        instrucciones_.push_back(instruccion_obj);
        ultima_instruccion++;
      } else if (instruccion == "STORE") {
        fichero >> operando;
        instruccion_obj = new Store(instruccion, operando);
        instrucciones_.push_back(instruccion_obj);
        ultima_instruccion++;
      } else if (instruccion == "ADD") {
        fichero >> operando;
        instruccion_obj = new Add(instruccion, operando);
        instrucciones_.push_back(instruccion_obj);
        ultima_instruccion++;
      } else if (instruccion == "SUB") {
        fichero >> operando;
        instruccion_obj = new Sub(instruccion, operando);
        instrucciones_.push_back(instruccion_obj);
        ultima_instruccion++;
      } else if (instruccion == "MULT") {
        fichero >> operando;
        instruccion_obj = new Mult(instruccion, operando);
        instrucciones_.push_back(instruccion_obj);
        ultima_instruccion++;
      } else if (instruccion == "DIV") {
        fichero >> operando;
        instruccion_obj = new Div(instruccion, operando);
        instrucciones_.push_back(instruccion_obj);
        ultima_instruccion++;
      } else if (instruccion == "READ") {  // Lectura de la cinta
        fichero >> operando;
        instruccion_obj = new Read(instruccion, operando, cinta_entrada);
        instrucciones_.push_back(instruccion_obj);
        ultima_instruccion++;
      } else if (instruccion == "WRITE") {  // Write de la cinta
        fichero >> operando;
        instruccion_obj = new Write(instruccion, operando, cinta_salida);
        instrucciones_.push_back(instruccion_obj);
        ultima_instruccion++;
      } else if (instruccion == "JUMP") {
        fichero >> operando;
        for (unsigned long i = 0; i < operando.size(); i++)
          operando[i] = toupper(operando[i]);
        instruccion_obj = new Jump(instruccion, operando, etiquetas_);
        instrucciones_.push_back(instruccion_obj);
        ultima_instruccion++;
      } else if (instruccion == "JGTZ") {
        fichero >> operando;
        for (unsigned long i = 0; i < operando.size(); i++)
          operando[i] = toupper(operando[i]);
        instruccion_obj = new Jgtz(instruccion, operando, etiquetas_);
        instrucciones_.push_back(instruccion_obj);
        ultima_instruccion++;
      } else if (instruccion == "JZERO") {
        fichero >> operando;
        for (unsigned long i = 0; i < operando.size(); i++)
          operando[i] = toupper(operando[i]);
        instruccion_obj = new Jzero(instruccion, operando, etiquetas_);
        instrucciones_.push_back(instruccion_obj);
        ultima_instruccion++;
      } else if (instruccion ==
                 "HALT") {  // Intruccion de finalizacion de programa
        ultima_instruccion++;
        existe_halt = true;
        instruccion_obj = new Halt(instruccion, ultima_instruccion);
        instrucciones_.push_back(instruccion_obj);
      } else {
        std::string instruccion_no_existe = "Esta instruccion no existe";
        throw instruccion_no_existe;
      }
    }

    fichero.close();

  } else {
    std::string error_fichero = "El fichero no se ha abierto";
    throw error_fichero;
  }
  if (!existe_halt) {
    std::string error = "En este programa no existe ninguna instruccion halt";
    throw error;
  }
}

Programa::Programa(const Programa& programa_original) {
  instrucciones_ = programa_original.instrucciones_;
  etiquetas_ = programa_original.etiquetas_;
}

Programa::~Programa() {}

std::vector<Instruccion*> Programa::get_instrucciones() {
  return instrucciones_;
}

std::map<std::string, int> Programa::get_etiquetas() const {
  return etiquetas_;
}

std::ostream& Programa::write(std::ostream& os) {
  for (unsigned long i = 0; i < instrucciones_.size(); i++) {
    std::cout << instrucciones_[i]->get_nombre() << std::endl;
  }
  return os;
}
