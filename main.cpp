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

  std::cout << std::endl;

  std::cout << "Buscando el elemento 2...\n";
  // Buscar elementos
  if (tabla.buscar(2, "Elemento2")) {
    std::cout << "El elemento 2 fue encontrado en la tabla." << std::endl;
  } else {
    std::cout << "El elemento 2 no fue encontrado en la tabla." << std::endl;
  }
  std::cout << "Busca el elemento 11...\n";
  if (tabla.buscar(100, "Elemento100")) {
    std::cout << "El elemento 100 fue encontrado en la tabla." << std::endl;
  } else {
    std::cout << "El elemento 100 no fue encontrado en la tabla." << std::endl;
  }

  std::cout << std::endl;

  std::cout << "Eliminando el elemento 2 y elemento 3\n";
  // Eliminar elementos
  tabla.eliminar(2, "Elemento2");
  tabla.eliminar(11, "Elemento3");

  // Imprimir la tabla actualizada
  tabla.imprimir();

  std::cout << std::endl;

  // Obtener capacidad y tamaño actual
  std::cout << "Capacidad de la tabla: " << tabla.obtenerCapacidad()
            << std::endl;
  std::cout << "Tamaño actual de la tabla: " << tabla.obtenerTam() << std::endl;

  std::cout << std::endl;

  std::cout << "Agregando mas elementos...\n";
  // Agregar más elementos para hacer rehashing
  tabla.agregar(41, "Elemento6");
  tabla.agregar(51, "Elemento7");
  tabla.agregar(61, "Elemento8");
  tabla.agregar(2, "Elemento2");
  tabla.agregar(11, "Elemento3");

  // Imprimir la tabla actualizada después del rehashing
  tabla.imprimir();

  std::cout << std::endl;

  // Obtener la nueva capacidad y tamaño actual
  std::cout << "Nueva capacidad de la tabla: " << tabla.obtenerCapacidad()
            << std::endl;
  std::cout << "Tamaño actual de la tabla: " << tabla.obtenerTam() << std::endl;

  std::cout << std::endl;

  std::cout << "Seguna tabla: " << std::endl;
  TablaHashDA tabla2(2);
  tabla2.imprimir();
  std::cout << std::endl;
  std::cout << "Copiar la primera tabla en la segunda tabla: " << std::endl;
  tabla2 = tabla;
  tabla2.imprimir();

  return 0;

}
