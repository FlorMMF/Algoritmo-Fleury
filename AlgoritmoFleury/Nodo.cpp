/**<
    \file Nodo.cpp
 */

 #include "Nodo.hpp"
 #include <iostream>

 Nodo::Nodo(char nom, Nodo * sig):nombre(nom), grado(0),
    primera(nullptr), ultima(nullptr), siguiente(sig){
 }

 //Agregar una arista
void Nodo::Agregar(Nodo * ady){
    Arista * nueva = new Arista(ady);
    grado == 0 ? primera = nueva : ultima -> siguiente = nueva;
    ultima = nueva;
    ++grado;
}
//Eliminar una arista
void Nodo::Eliminar(Nodo * ady){
    Arista *ant, *porBorrar = BuscarDireccion(ady, &ant);
    if(porBorrar == nullptr)return;
    ant == nullptr ? primera = primera -> siguiente : ant-> siguiente = porBorrar -> siguiente;
    if(primera == nullptr) ultima = nullptr;
    delete porBorrar;
    --grado;

}
//vaciar el nodo
int Nodo::Vaciar(){
    int numArist = 0;
    while(primera != nullptr){
        Arista * porBorrar = primera;
        //Si la arista no es un lazo, se elimina a este vértice del
        //de la lista de aristas del vértice adyacente
        if (primera -> adyacente != this) primera -> adyacente -> Eliminar(this);
        primera = primera -> siguiente;
        delete porBorrar;
        ++numArist;
    }
    ultima = nullptr;
    grado = 0;
    return numArist;
}
//Buscar una arista
bool Nodo::Buscar(Nodo * ady) const{
    return BuscarDireccion(ady) != nullptr;

}

//Imprimir informacion de un nodo
void Nodo::Imprimir() const{
    Arista *visitada = primera;
    while(visitada != nullptr){
        std :: cout << visitada ->adyacente-> nombre << ", ";
        visitada = visitada -> siguiente;
    }
    std::cout <<"\b\b";
}

 Arista * Nodo::BuscarDireccion(Nodo * ady, Arista ** ant)const {
    Arista * aux = primera;
    if(ant != nullptr) *ant= nullptr;
    while(aux != nullptr && aux -> adyacente != ady){
        if(ant != nullptr) *ant = aux;
        aux = aux -> siguiente;
    }
    return aux;

 }
