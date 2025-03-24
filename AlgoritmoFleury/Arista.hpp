/**

 * \file Arista.hpp

 * Este archivo contiene la definici&oacute;n de los m&eacute;todos
    que simulan una arista

 * \author Flor Machado y Elias Peregrina

 * \date 23/3/2025

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
    /** \brief Constructor de una arista
     *
     * \param sig
     * \return Arista (Nodo * ady, Arista * sig = nullptr): adyacente(ady),
     *
     */
    Arista (Nodo * ady, Arista * sig = nullptr): adyacente(ady), siguiente(sig){}
};

#endif // ARISTA_HPP_INCLUDED
