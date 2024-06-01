//
// Created by Remil on 31/05/2024.
//

#ifndef TABLAHASHDA_TABLAHASHDA_HPP
#define TABLAHASHDA_TABLAHASHDA_HPP

#include <iostream>
#include <string>

//IMPORTANTE: LOS NUMEROS QUE ACEPTA SON SOLO LOS NATURALES EL -1 ES MI PIVOTE PARA SABER SI ALGUN LUGAR ESTÁ VACIO;

class TablaHashDA{
public:
    TablaHashDA(int capacidad);
    ~TablaHashDA();
    TablaHashDA(const TablaHashDA & otra);
    TablaHashDA& operator=(const TablaHashDA & otra);

    bool agregar(int numero, const std::string & nombre);
    bool eliminar(int numero, const std::string & nombre);
    bool buscar(int numero, const std::string & nombre);

    void imprimir() const;

    int obtenerCapacidad() const;
    int obtenerTam() const;

private:
    int capacidad;
    int tam;
    struct Entrada{
        int numero;
        std::string nombre;
        Entrada();
        Entrada(int numero, const std::string & nombre);
        bool operator==(const Entrada& otra) const;
        bool operator!=(const Entrada& otra) const;
    } * tabla, eliminado; //Eliminado sirve para marcar las posiciones eliminadas.

    int funcionHash(int numero) const;
    int sondeo(int hash, int i) const;
    void rehash();
};

#endif //TABLAHASHDA_TABLAHASHDA_HPP
