#include "TablaHashDA.hpp"

int main() {
  // Crear una tabla hash con capacidad inicial de 10 elementos
  TablaHashDA tabla(10);

  // Agregar elementos
  tabla.agregar(1, "Elemento1");
  tabla.agregar(2, "Elemento2");
  tabla.agregar(11, "Elemento3"); // Este debería colisionar con el elemento 1
  tabla.agregar(21, "Elemento4");
  tabla.agregar(31, "Elemento5");

  // Imprimir la tabla
  tabla.imprimir();
  std::cout << "Buscando el elemento 2...\n";
  // Buscar elementos
  if (tabla.buscar(2, "Elemento2")) {
    std::cout << "El elemento 2 fue encontrado en la tabla." << std::endl;
  } else {
    std::cout << "El elemento 2 no fue encontrado en la tabla." << std::endl;
  }
  std::cout << "Busca el elemento 3...\n";
  if (tabla.buscar(11, "Elemento3")) {
    std::cout << "El elemento 11 fue encontrado en la tabla." << std::endl;
  } else {
    std::cout << "El elemento 11 no fue encontrado en la tabla." << std::endl;
  }
  std::cout << "Eliminando el elemento 2 y elemento 3\n";
  // Eliminar elementos
  tabla.eliminar(2, "Elemento2");
  tabla.eliminar(11, "Elemento3");

  // Imprimir la tabla actualizada
  tabla.imprimir();

  // Obtener capacidad y tamaño actual
  std::cout << "Capacidad de la tabla: " << tabla.obtenerCapacidad()
            << std::endl;
  std::cout << "Tamaño actual de la tabla: " << tabla.obtenerTam() << std::endl;

  return 0;
}
