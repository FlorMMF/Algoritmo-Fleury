#ifndef LAPILA_HPP_INCLUDED
#define LAPILA_HPP_INCLUDED

template <typename Tipo>
/**

 * \file LaPila.hpp

 * Este archivo contiene la definici&oacute;n de los m&eacute;todos que simulan una pila

 * \author Flor Machado y Elias Peregrina

 * \date 23/3/2025

 */
class Pila{
public:
    /** \brief Constructor de la pila
     *
     */
    Pila();
     /** \brief Constructor de copias
     *
     * \param const Pila, pila que se copiar&acute;
     */
    Pila(const Pila &p);
    /* \brief Destructor de la Pila
     *
     *
     */
    ~Pila();
     /** \brief Operador de asignaci&oacute;n, libera la memoria previa y copia los valores de la pila proporcionada
     *
     * \param const Pila, pila de la cual se copiar&acute;n los valores
     */
    Pila & operator=(const Pila &v);
    /** \brief Agrega un elemento agregado a la pila
     *
     * \param Tipo valor, valor el cual se agrega&acute; a la matriz
     * \return void
     *
     */
    void Apilar(Tipo valor);
    /** \brief Quita el &uacute;  ltimo elemento agregado a la pila
     *
     * \return void
     *
     */
    void Desapilar();
    /** \brief Obtiene el &uacute;  ltimo elemento de la pila
     *
     * \return Tipo Devuelve el &uacute;  ltimo elemento de la pila
     *
     */
    Tipo ObtenerTOPE() const;
    /** \brief Comprueba si la pila esta vac&iacute;  a
     *
     * \return bool, si la pila esta vac&iacute;  a devuelve true
     *
     */
    bool EstaVacia() const;

    /** \brief Devuele el tope al estado inicial, simulando que la pila esta vac&iacute;  a
     *
     * \return void
     *
     */
    void Vaciar();
    //para pruebas
    /** \brief Imprime la pila
     *
     * \return void
     *
     */
    void imprimir() const;
    /** \brief Cuenta el n&uacte;mero de elementos que se encuentran en la pila
     *
     * \return tope + 1, aumenta en 1 el tamaño del tope de la pila
     *
     */
    int CantidadElementos() const;
private:
    int numElem;
    struct Elemento{
        Tipo valor;
        Elemento *siguiente;
    }*tope;

};
#include "LaPila.tpp"

#endif // LAPILA_HPP_INCLUDED
