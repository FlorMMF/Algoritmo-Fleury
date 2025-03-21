#ifndef GRAFICA_HPP_INCLUDED
#define GRAFICA_HPP_INCLUDED
#include <string>
#include "Nodo.hpp"

class Grafica{
friend std::string AlgoritmoFleury(const Grafica &g);
public:
    Grafica();
    Grafica(const Grafica &g);
    ~Grafica();
    Grafica & operator= (const Grafica &g);
    //Agregar nodo
    void Agregar(char nom);
    //Agregar Aristas
    void Agregar(char nomInicial, char nomFinal);
    //Eliminar nodo
    void Eliminar(char nom);
    //Eliminar arista
    void Eliminar(char nomInicial, char nomFinal);
    //Conocer numero de nodods
    int ObtenerNumNodos() const;
    //Conocer numero de aristas
    int ObtenerNumAristas() const;
    //Conocer grado de un nodo
    int ObtenerGrado(char nom) const;
    //Buscar Nodo
    bool Buscar(char nom) const;
    //Buscar aristas
    bool Buscar(char nomInicial, char nomFinal)const;
    //Imprimir
    void Imprimir() const;
    //Vaciar nodo
    void Vaciar(char nom);
    //Vaciar grafica
    void Vaciar();

private:
    Nodo *primero, *ultimo;
    int numNodos, numAristas;

    Nodo *buscarDireccion(char nom, Nodo **ant = nullptr) const ;

};

#endif // GRAFICA_HPP_INCLUDED
