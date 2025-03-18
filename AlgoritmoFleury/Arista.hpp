/**<
    \file Arista.hpp
 */

#ifndef ARISTA_HPP_INCLUDED
#define ARISTA_HPP_INCLUDED
//struct Nodo{
//
//};

struct Nodo;

struct Arista{
    Nodo * adyacente;
    Arista * siguiente;
    Arista (Nodo * ady, Arista * sig = nullptr): adyacente(ady), siguiente(sig){}
};

#endif // ARISTA_HPP_INCLUDED
