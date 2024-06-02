#include <iostream>
#include "TablaHashDA.hpp"

using namespace std;

int main() {
    TablaHashDA tabla(10);
    if(tabla.agregar(1, "smn")){
        cout << "Se agregó algo" << endl;
    }else{
        cout << "Error al agregar" << endl;
    }

    tabla.imprimir();
    std::cout << "Capacidad: " << tabla.obtenerCapacidad() << std::endl;
    std::cout << "Tamaño: " << tabla.obtenerTam() << std::endl;
    return 0;
}
