
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

    /** \brief Agrega una arista de un nodo inicial a un nodo dado
     *
     * \param ady Nodo*
     * \return void
     *
     */
    void Agregar(Nodo * ady);
    //Eliminar una arista
    /** \brief Elimina una arista de un nodo objeto a otro
     *
     * \param ady Nodo*
     * \return void
     *
     */
    void Eliminar(Nodo * ady);
    //vaciar el nodo
    /** \brief Vuelve el grado del nodo a 0, sin aristas
     *
     * \return int
     *
     */
    int Vaciar();
    //Buscar una arista
    /** \brief Busca un nodo por su nombre
     *
     * \param ady Nodo*
     * \return bool
     *
     */
    bool Buscar(Nodo * ady) const;
    //Imprimir informacion de un nodo
    /** \brief Imprime la informaci&oacute;n de un nodo
     *
     * \return void
     *
     */
    void Imprimir() const;

    /** \brief Busca la direcci&oacute;n de un nodo
     *
     * \param ady Nodo*
     * \param Arista ** ant = nullptr
     * \return Arista*
     *
     */
    Arista * BuscarDireccion(Nodo * ady, Arista ** ant = nullptr) const;

};

#endif // NODO_HPP_INCLUDED
