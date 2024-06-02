//
// Created by Remil on 31/05/2024.
//

#include "TablaHashDA.hpp"

//********************************************************
TablaHashDA::TablaHashDA(int capacidad) : capacidad(capacidad), tam(0){
    tabla = new Entrada[capacidad];
    eliminado = Entrada(-1, "<eliminado>");
}

TablaHashDA::~TablaHashDA(){
    delete[] tabla;
}

TablaHashDA::TablaHashDA(const TablaHashDA &otra) : capacidad(otra.capacidad), tam(otra.tam){
    tabla = new Entrada[capacidad];
    for (int i = 0; i < capacidad; ++i) {
        tabla[i] = otra.tabla[i];
    }
    eliminado = otra.eliminado;
}


TablaHashDA &TablaHashDA::operator=(const TablaHashDA &otra){
    if (this == &otra) {
        return *this;
    }
    delete[] tabla;
    capacidad = otra.capacidad;
    tam = otra.tam;
    tabla = new Entrada[capacidad];
    for (int i = 0; i < capacidad; ++i) {
        tabla[i] = otra.tabla[i];
    }
    eliminado = otra.eliminado;
    return *this;
}

//********************************************************

bool TablaHashDA::agregar(int numero, const std::string &nombre){
    if ((tam + 1) * 4 >= capacidad * 3){
        rehash();
    }

    for (int i = 0; i < capacidad; ++i){
        int indice = sondeo(funcionHash(numero), i);
        if (tabla[indice].numero == -1 || tabla[indice] == eliminado){
            tabla[indice] = Entrada(numero, nombre);
            ++tam;
            return true;
        }
        if (tabla[indice].numero == numero && tabla[indice].nombre == nombre){
            return false;
        }
    }
    return false;
}


bool TablaHashDA::eliminar(int numero, const std::string &nombre){
    for (int i = 0; i < capacidad; ++i){
        int indice = sondeo(funcionHash(numero), i);
        if (tabla[indice].numero == -1){
            return false;
        }
        if (tabla[indice] == Entrada(numero, nombre)){
            tabla[indice] = eliminado;
            --tam;
            return true;
        }
    }
    return false;
}

bool TablaHashDA::buscar(int numero, const std::string &nombre){
    for (int i = 0; i < capacidad; ++i){
        int indice = sondeo(funcionHash(numero), i);
        if (tabla[indice].numero == -1){
            return false;
        }
        if (tabla[indice] == Entrada(numero, nombre)) {
            return true;
        }
    }
    return false;
}

//********************************************************

void TablaHashDA::imprimir() const{
    for (int i = 0; i < capacidad; ++i){
        if (tabla[i].numero != -1 && tabla[i] != eliminado){
            std::cout << i << ": (" << tabla[i].numero << ", " << tabla[i].nombre << ")" << std::endl;
        }else{
            std::cout << i << ": " << "<vacio o eliminado>" << std::endl;
        }
    }
}

//********************************************************

int TablaHashDA::obtenerCapacidad() const{
    return capacidad;
}

int TablaHashDA::obtenerTam() const{
    return tam;
}

//*********************************************************

TablaHashDA::Entrada::Entrada() : numero(-1), nombre(""){}

TablaHashDA::Entrada::Entrada(int numero, const std::string &nombre) : numero(numero), nombre(nombre){}

bool TablaHashDA::Entrada::operator==(const TablaHashDA::Entrada &otra) const{
    return numero == otra.numero && nombre == otra.nombre;
}

bool TablaHashDA::Entrada::operator!=(const TablaHashDA::Entrada &otra) const{
    return !(*this == otra);
}

int TablaHashDA::funcionHash(int numero) const{
    return numero % capacidad;
}

int TablaHashDA::sondeo(int hash, int i) const{
    return (hash + i) % capacidad;
}

void TablaHashDA::rehash() {
    int nuevaCapacidad = capacidad * 2;
    Entrada *nuevaTabla = new Entrada[nuevaCapacidad];

    Entrada *temp = tabla;
    int tempCapacidad = capacidad;

    tabla = nuevaTabla;
    capacidad = nuevaCapacidad;
    tam = 0;

    for (int i = 0; i < tempCapacidad; ++i) {
        if (temp[i].numero != -1 && temp[i] != eliminado) {
            agregar(temp[i].numero, temp[i].nombre);
        }
    }

    delete[] temp;
}
