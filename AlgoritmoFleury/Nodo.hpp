
/**<
    \file Nodo.hpp
 */
#include "Arista.hpp"
#ifndef NODO_HPP_INCLUDED
#define NODO_HPP_INCLUDED
struct Nodo{
    char nombre;
    int grado;
    Arista * primera, * ultima;
    Nodo * siguiente;
    Nodo(char nom, Nodo * siguiente = nullptr);

    //Agregar una arista
    void Agregar(Nodo * ady);
    //Eliminar una arista
    void Eliminar(Nodo * ady);
    //vaciar el nodo
    int Vaciar();
    //Buscar una arista
    bool Buscar(Nodo * ady) const;
    //Imprimir informacion de un nodo
    void Imprimir() const;

    Arista * BuscarDireccion(Nodo * ady, Arista ** ant = nullptr) const;

};

#endif // NODO_HPP_INCLUDED
