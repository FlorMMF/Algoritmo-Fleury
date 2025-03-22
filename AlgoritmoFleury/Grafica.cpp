#include "Grafica.hpp"
#include "Cola.hpp"
#include "LaPila.hpp"
#include <iostream>
Grafica::Grafica():primero(nullptr), ultimo(nullptr), numNodos(0),
    numAristas(0){}

Grafica::Grafica(const Grafica &g):primero(nullptr), ultimo(nullptr),
    numNodos(0), numAristas(0){
    *this = g;
}

Grafica::~Grafica(){
    Vaciar();
}

Grafica & Grafica::operator= (const Grafica &g){
    if(this == &g) return *this;
    Vaciar();
    Nodo *nodoVisitado = g.primero;
    while(nodoVisitado != nullptr){
        Agregar(nodoVisitado -> nombre);
        nodoVisitado = nodoVisitado -> siguiente;
    }
    nodoVisitado = g.primero;
    Arista *aristaVisitada;
    while(nodoVisitado != nullptr){
        aristaVisitada = nodoVisitado -> primera;
        while(aristaVisitada != nullptr){
            if(!Buscar(nodoVisitado -> nombre,
            aristaVisitada -> adyacente -> nombre)){
                Agregar(nodoVisitado -> nombre,
                aristaVisitada -> adyacente -> nombre);
            }
            aristaVisitada = aristaVisitada -> siguiente;

        }
        nodoVisitado = nodoVisitado-> siguiente;
    }
    return *this;
}

//Agregar nodo
void Grafica::Agregar(char nom){
    Nodo * nuevo = new Nodo(nom);
    numNodos == 0 ? primero = nuevo: ultimo -> siguiente = nuevo;
    ultimo = nuevo ;
    ++numNodos;
}

//Agregar Aristas
void Grafica::Agregar(char nomInicial, char nomFinal){
    Nodo *dirInicial = buscarDireccion(nomInicial);
    if(dirInicial == nullptr)return;
    Nodo *dirFinal = buscarDireccion(nomFinal);
    if(dirFinal == nullptr)return;
    //Agregar el nodo final en el inicial
    dirInicial -> Agregar(dirFinal);
    //Agregar el nodo inicial en la lsita del nodo final
    dirFinal -> Agregar(dirInicial);

    ++numAristas;

}

//Eliminar nodo
void Grafica::Eliminar(char nom){
    Nodo *ant, *porBorrar = buscarDireccion(nom, &ant);
    if(porBorrar == nullptr)return;
    numAristas -= porBorrar -> Vaciar();
    if(ant == nullptr) {
            primero = primero -> siguiente;
    }else {
        ant -> siguiente = porBorrar -> siguiente;
    }
    if(primero == nullptr) ultimo = nullptr;
    delete porBorrar;
    --numNodos;
}

//Eliminar arista
void Grafica::Eliminar(char nomInicial, char nomFinal){
    Nodo *dirInicial = buscarDireccion(nomInicial);
    if(dirInicial == nullptr)return;
    Nodo *dirFinal = buscarDireccion(nomFinal);
    if(dirFinal == nullptr)return;
    //Eliminar el final de la lista del inicial
    dirInicial -> Eliminar(dirFinal);
    //Eliminar el inicial de la lista del final
    dirFinal  -> Eliminar(dirInicial);
    --numAristas;
}

//Conocer numero de nodods
int Grafica::ObtenerNumNodos() const{
    return numNodos;
}

//Conocer numero de aristas
int Grafica::ObtenerNumAristas() const{
    return numAristas;
}

//Conocer grado de un nodo
int Grafica::ObtenerGrado(char nom) const{
    Nodo * nodoBuscado = buscarDireccion(nom);
    if(nodoBuscado == nullptr) throw "Nodo inexistente";
    return nodoBuscado -> grado;
}

//Buscar Nodo
bool Grafica::Buscar(char nom) const{
    return buscarDireccion(nom) != nullptr;
}

//Buscar aristas
bool Grafica::Buscar(char nomInicial, char nomFinal)const{
    Nodo *dirInicial = buscarDireccion(nomInicial);
    if(dirInicial == nullptr)return false;
    Nodo *dirFinal = buscarDireccion(nomFinal);
    if(dirFinal == nullptr)return false;

    return dirInicial -> Buscar(dirFinal);
}

//Imprimir
void Grafica::Imprimir() const{
    Nodo * visitado = primero;
    while(visitado != nullptr){
        std::cout << visitado -> nombre << ": ";
        visitado -> Imprimir();
        std::cout << std::endl;
        visitado = visitado -> siguiente;
    }
    std::cout << std::endl;
}

//Vaciar nodo
void Grafica::Vaciar(char nom){
    Nodo *porVaciar = buscarDireccion(nom);
    if(porVaciar == nullptr) return;
    numAristas -= porVaciar -> Vaciar();

}

//Vaciar grafica
void Grafica::Vaciar(){

    while(primero != nullptr){
        Eliminar(primero -> nombre);
    }
}

Nodo * Grafica::buscarDireccion(char nom, Nodo **ant) const{
     Nodo * aux = primero;
    if(ant != nullptr) *ant= nullptr;
    while(aux != nullptr && aux -> nombre != nom){
        if(ant != nullptr) *ant = aux;
        aux = aux -> siguiente;
    }
    return aux;
}

std::string AlgoritmoFleury(const Grafica &g){
    std::string paseo = "";
    /*Pila<char> pila;
    Cola<char> cola;

    Grafica copia = g;

    Nodo *v_c = g.buscarDireccion(g.primero -> nombre);
    Nodo *v_p = g.buscarDireccion(g.primero -> nombre);

    cola.Encolar(v_c -> nombre);
    pila.Apilar(v_p -> nombre);

    while(v_c->grado!=0 && v_p->grado!=0){
        copia.Imprimir();
        if(v_c->grado >= 1 ){
            Arista *AriC=v_c->primera;
            Nodo *NodoC=AriC->adyacente;

            while(NodoC->grado == 1){
                AriC=AriC->siguiente;
                NodoC=AriC->adyacente;

            }
            if(AriC == nullptr || NodoC == nullptr)continue;
            copia.Eliminar(v_c -> nombre, NodoC -> nombre);
            cola.Encolar(NodoC -> nombre);
            v_c = NodoC;
        }

        if(v_p -> grado == 1){
            Nodo *k = v_p->primera->adyacente;
            copia.Eliminar(v_p->nombre, k->nombre);
            pila.Apilar(k -> nombre);
            v_p=k;
        }

    }
    */
     Grafica copia=g;

    Cola<Nodo*> recorrido;
    Pila<Nodo*> principal;
    Nodo *v_c = copia.buscarDireccion(copia.primero -> nombre); //nodo que maneja la cola
    Nodo *v_p = copia.buscarDireccion(copia.primero -> nombre); //nodo que maneja la pila

    recorrido.Encolar(v_c);
    principal.Apilar(v_p);


    while(v_c->grado!=0 && v_p->grado!=0){
        copia.Imprimir();
        if(v_c->grado!=0 && v_p->grado!=1){
            Arista *AriC=v_c->primera;
            Nodo *NodoC=AriC->adyacente;

            while(NodoC->grado<=1){
                AriC=AriC->siguiente;
                NodoC=AriC->adyacente;
            }

            copia.Eliminar(v_c->nombre, NodoC->nombre);
            recorrido.Encolar(NodoC);
            v_c=NodoC;
        }

        if(v_p->grado==1){
            Nodo *NodoP = v_p->primera->adyacente;
            copia.Eliminar(v_p->nombre, NodoP->nombre);
            principal.Apilar(NodoP);
            v_p=NodoP;
        }
    }




    while(recorrido.CantidadElementos() != 0){
        paseo = paseo + recorrido.ObtenerPrimero() -> nombre;
        recorrido.Desencolar();
    }
    while(principal.CantidadElementos() != 0){
        paseo = paseo + principal.ObtenerTOPE() -> nombre;
        principal.Desapilar();
    }
    return paseo;
}

