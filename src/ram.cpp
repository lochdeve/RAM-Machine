#include "../include/ram.hpp"

Ram::Ram(Programa& programa, Cinta_entrada& cinta_entrada,
         Cinta_salida& cinta_salida) {
  programa_ = programa;
  cinta_entrada_ = cinta_entrada;
  cinta_salida_ = cinta_salida;
  opcion_debug_ = false;
  program_counter_ = 0;
  numero_instrucciones_ = 0;
}

Ram::~Ram() {}

void Ram::ejecucion() {
  std::string finalizacion = "El programa ha finalizado con exito ";
  std::vector<Instruccion*> vector_instrucciones;
  vector_instrucciones = programa_.get_instrucciones();

  while (program_counter_ < vector_instrucciones.size()) {
    try {
      programa_.get_instrucciones()[program_counter_]->ejecutar(
          memoria_, program_counter_, opcion_debug_);
      program_counter_++;

    } catch (const std::string& e) {
      program_counter_ = programa_.get_instrucciones().size() - 1;
      finalizacion = e;
      std::cout << "ERROR: " << e << std::endl;
    }
    numero_instrucciones_++;
  }
  std::cout << std::endl << finalizacion << std::endl << std::endl;
}

void Ram::ejecucion_traza(bool traza) {
  std::string finalizacion = "El programa ha finalizado con exito ";
  if (program_counter_ < programa_.get_instrucciones().size()) {
    if (traza) {
      std::cout << "Instruccion ejecutada: ";
      std::cout
          << programa_.get_instrucciones()[program_counter_]->get_nombre()
          << " "
          << programa_.get_instrucciones()[program_counter_]->get_operando()
          << std::endl
          << std::endl;
    }
    try {
      programa_.get_instrucciones()[program_counter_]->ejecutar(
          memoria_, program_counter_, opcion_debug_);
      program_counter_++;
    } catch (const std::string& e) {
      program_counter_ = programa_.get_instrucciones().size() - 1;
      finalizacion = e;
      std::cout << "ERROR: " << e << std::endl;
    }

  } else {
    std::cout << std::endl
              << "El programa ha terminado ya no hay mas instrucciones"
              << std::endl
              << std::endl;
  }
}

void Ram::menu_opciones() {
  char opcion;
  do {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "|Opciones de la maquina RAM |" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    std::cout << "t: Traza" << std::endl;
    std::cout << "r: Ver los registros" << std::endl;
    std::cout << "e: Ejecutar" << std::endl;
    std::cout << "s: Desensamblador" << std::endl;
    std::cout << "i: Ver cinta de entrada" << std::endl;
    std::cout << "o: Ver cinta de salida" << std::endl;
    std::cout << "h: Ayuda" << std::endl;
    std::cout << "x: Salir" << std::endl;
    std::cout << "Opcion: ";
    std::cin >> opcion;
    opcion_debug_ = false;
    switch (opcion) {
      case 't': {
        opcion_debug_ = true;
        ejecucion_traza(false);
      } break;
      case 'e':
        ejecucion();
        break;
      case 'r':
        memoria_.write(std::cout);
        break;
      case 's': {
        unsigned long varias_ejecuciones = 0;
        do {
          std::cout << "¿Cuantas instrucciones quieres que se desensamblar?"
                    << std::endl;
          std::cin >> varias_ejecuciones;
        } while (varias_ejecuciones < 1);
        if (varias_ejecuciones > 1) {
          for (size_t i = 0; i < varias_ejecuciones; i++) {
            ejecucion_traza(true);
          }
        } else {
          ejecucion_traza(true);
        }
      } break;
      case 'i':
        cinta_entrada_.mostrar_cinta_entrada();
        break;
      case 'o':
        cinta_salida_.mostrar_cinta_salida();
        break;
      case 'h':
        std::cout
            << std::endl
            << "Para la correcta ejecucion del programa se debera instroducir:"
            << std::endl
            << std::endl;
        break;
        std::cout << "./ejecutable fichero_de_programa fichero_cinta_entrada "
                     "fichero_cinta_salida";
      case 'x':
        std::cout << "" << std::endl;
        break;
      default:
        std::cout << std::endl
                  << "Opcion no existente elija una opcion de las mostradas en "
                     "el menu"
                  << std::endl;
        break;
    }
  } while (opcion != 'x');
}

int Ram::numero_instrucciones() {
  return numero_instrucciones_;
  ;
}

std::ostream& Ram::write(std::ostream& os) {
  memoria_.write(std::cout);
  programa_.write(std::cout);
  cinta_entrada_.mostrar_cinta_entrada();
  cinta_salida_.mostrar_cinta_salida();
  os << std::endl;
  return os;
}
