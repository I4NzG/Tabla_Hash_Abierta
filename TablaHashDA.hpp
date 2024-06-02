//
// Created by Remil on 31/05/2024.
//

#ifndef TABLAHASHDA_TABLAHASHDA_HPP
#define TABLAHASHDA_TABLAHASHDA_HPP

#include <iostream>
#include <string>

/**
 * \class TablaHashDA
 * \brief Clase que representa una tabla hash con direccionamiento abierto.
 *
 * La clase TablaHashDA implementa una tabla hash utilizando el m&eacute;todo de
 * direccionamiento abierto. Esto implica que los elementos se almacenan
 * directamente en la tabla y se maneja la colisi&oacute;n buscando la siguiente
 * posici&oacute;n disponible.
 *
 * La clase permite insertar, eliminar y buscar elementos, imprimir la tabla,
 * y obtener informaci&oacute;n sobre su capacidad y tama&ntilde;o actual.
 */
// IMPORTANTE: LOS NUMEROS QUE ACEPTA SON SOLO LOS NATURALES EL -1 ES MI PIVOTE
// PARA SABER SI ALGUN LUGAR ESTÁ VACIO;

class TablaHashDA {
public:
  /**
   * \brief Constructor que inicializa la tabla hash con una capacidad dada.
   * \param capacidad N&uacute;mero de elementos que puede almacenar la tabla.
   */
  TablaHashDA(int capacidad);
  /**
   * \brief Destructor de la clase TablaHashDA.
   */
  ~TablaHashDA();
  /**
   * \brief Constructor de copia.
   * \param otra Objeto a copiar.
   */
  TablaHashDA(const TablaHashDA &otra);
  /**
   * \brief Operador de asignaci&oacute;n.
   * \param otra Objeto a asignar.
   * \return Referencia a la instancia actual.
   */
  TablaHashDA &operator=(const TablaHashDA &otra);
  /**
   * \brief Agrega un elemento a la tabla hash.
   * \param numero N&uacute;mero del elemento a agregar.
   * \param nombre Nombre del elemento a agregar.
   * \return true si el elemento fue agregado con &eacute;xito, false en caso
   * contrario.
   */
  bool agregar(int numero, const std::string &nombre);
  /**
   * \brief Elimina un elemento de la tabla hash.
   * \param numero N&uacute;mero del elemento a eliminar.
   * \param nombre Nombre del elemento a eliminar.
   * \return true si el elemento fue eliminado con &eacute;xito, false en caso
   * contrario.
   */
  bool eliminar(int numero, const std::string &nombre);
  /**
   * \brief Busca un elemento en la tabla hash.
   * \param numero N&uacute;mero del elemento a buscar.
   * \param nombre Nombre del elemento a buscar.
   * \return true si el elemento fue encontrado, false en caso contrario.
   */
  bool buscar(int numero, const std::string &nombre);
  /**
   * \brief Imprime la tabla hash.
   */
  void imprimir() const;
  /**
   * \brief Obtiene la capacidad de la tabla hash.
   * \return Capacidad de la tabla.
   */
  int obtenerCapacidad() const;
  /**
   * \brief Obtiene el tama&ntilde;o actual de la tabla hash.
   * \return N&uacute;mero de elementos almacenados en la tabla.
   */
  int obtenerTam() const;

private:
  int capacidad;
  int tam;
  struct Entrada {
    int numero;
    std::string nombre;
    Entrada();
    Entrada(int numero, const std::string &nombre);
    bool operator==(const Entrada &otra) const;
    bool operator!=(const Entrada &otra) const;
  } *tabla, eliminado; // Eliminado sirve para marcar las posiciones eliminadas.

  int funcionHash(int numero) const;
  /**
   * \brief Funci&oacute;n hash para calcular el &iacute;ndice de un
   * n&uacute;mero. \param numero N&uacute;mero a calcular el &iacute;ndice.
   * \return &Iacute;ndice calculado para el n&uacute;mero.
   */
  int sondeo(int hash, int i) const;

  /**
   * \brief Funci&oacute;n de sondeo para manejar colisiones.
   * \param hash &Iacute;ndice hash inicial.
   * \param i Intento de sondeo.
   * \return Nuevo &iacute;ndice calculado despu&eacute;s del sondeo.
   */
  void rehash();
  /**
   * \brief Funci&oacute;n para rehashing de la tabla cuando est&aacute; llena.
   */
};

#endif // TABLAHASHDA_TABLAHASHDA_HPP
