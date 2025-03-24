#ifndef GRAFICA_HPP_INCLUDED
#define GRAFICA_HPP_INCLUDED
#include <string>
#include "Nodo.hpp"
/**

 * \file Grafica.hpp

 * Este archivo contiene la definici&oacute;n de los m&eacute;todos
    que simulan una grafica

 * \author Flor Machado y Elias Peregrina

 * \date 23/3/2025

 */
class Grafica{
friend std::string AlgoritmoFleury(const Grafica &g);
public:
    /** \brief Constructor de la gr&aacute;fica
     *
     */
    Grafica();
    /** \brief Constructor de copias
     *
     * \param const grafica, gr&aacute;fica que se copiar&acute;
     */
    Grafica(const Grafica &g);
    /* \brief Destructor de la gr&aacute;fica
     *
     *
     */
     ~Grafica();
    /** \brief Operador de asignaci&oacute;n, libera la memoria previa
     y copia los valores de la gr&aacute;fica proporcionada
     *
     * \param const grafica, gr&aacute;fica de la cual se copiar&acute;n los valores
     */
    Grafica & operator= (const Grafica &g);
    //Agregar nodo
    /** \brief Agrega un nodo a la gr&aacute;fica
     *
     * \param nom char, el nombre que se le dar&aacute al nodo
     * \return void
     *
     */
    void Agregar(char nom);
    //Agregar Aristas
    /** \brief Agregar una arista entre dos nodos
     *
     * \param nomInicial char
     * \param nomFinal char
     * \return void
     *
     */
    void Agregar(char nomInicial, char nomFinal);
    //Eliminar nodo
    /** \brief Elimina un nodo escogido de la gr&aacute;fica
     *\param char nom, el nombre del nodo escogido
     * \return void
     *
     */
    void Eliminar(char nom);
    //Eliminar arista
    /** \brief Elimina una arista entre dos nodos
     *
     * \param nomInicial char
     * \param nomFinal char
     * \return void
     *
     */
    void Eliminar(char nomInicial, char nomFinal);
    //Conocer numero de nodods
    /** \brief M&eacute;todo que devuelve la cantidad de nodos que hay
            en una gr&aacute;fica
     *
     * \return int
     *
     */
    int ObtenerNumNodos() const;
    //Conocer numero de aristas
    /** \brief M&eacute;todo que devuelve la cantidad de aristas
            que hay en una gr&aacute;fica
     *
     * \return int
     *
     */
    int ObtenerNumAristas() const;
    //Conocer grado de un nodo
    /** \brief M&eacute;todo que devuelve el grado de un nodo dado
     *
     * \param nom char
     * \return int
     *
     */
    int ObtenerGrado(char nom) const;
    //Buscar Nodo
    /** \brief M&eacute;todo para encontrar un nodo
     *
     * \param nom char
     * \return bool
     *
     */
    bool Buscar(char nom) const;
    //Buscar aristas
    /** \brief M&eacute;todo para encontrar una arista
     *
     * \param nomInicial char
     * \param nomFinal char
     * \return bool
     *
     */
    bool Buscar(char nomInicial, char nomFinal)const;
    //Imprimir
    /** \brief M&eacute;todo para imprimir una gr&aacute;fica
     *
     * \return void
     *
     */
    void Imprimir() const;
    //Vaciar nodo
    /** \brief M&eacute;todo para vaciar un nodo
     *
     * \param nom char
     * \return void
     *
     */
    void Vaciar(char nom);
    //Vaciar grafica
    /** \brief M&eacute;todo para vaciar una gr&aacute;fica
     *
     * \return void
     *
     */
    void Vaciar();

private:
    Nodo *primero, *ultimo;
    int numNodos, numAristas;

    Nodo *buscarDireccion(char nom, Nodo **ant = nullptr) const ;

};

#endif // GRAFICA_HPP_INCLUDED
