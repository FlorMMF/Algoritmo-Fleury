#include <iostream>
#include "Grafica.hpp"
using namespace std;

bool esEuler(const Grafica &g);

int main(){
    try{
        Grafica g;
        int numNod, numAris;
        
        cout << "Ingrese al n\243mero de nodos: ";
        cin >> numNod;
        
        for (int i = 0; i < numNod; ++i){
            char nodo;
            cout << "Ingresa el nombre del nodo " << i + 1 << ": ";
            cin >> nodo;
            g.Agregar(nodo);
        }
        
        cout << "Ingresa el n\243mero de aristas: ";
        cin >> numAris;
        
        for (int i = 0; i < numAris; ++i){
            char inicial, final;
            cout << "Ingresa la arista: " << i + 1 << " entre dos nodos separados por un espacio: ";
            cin >> inicial >> final;
            g.Agregar(inicial, final);
        }
        
        cout << "La gr\240fica ingresada es: \n";
        g.Imprimir();
        
        if (esEuler(g)){
            cout << "La gr\240fica es Eulariana, por lo que se ejecutar\240 el algoritmo de Fleury. \n";
            cout << "Paseo Eulariano: " << AlgoritmoFleury(g) << endl;
        } else{
            cout << "La gr\240fica no es Elariano, por lo que el algoritmo de Fleury es imposible de ejecutarse. \n";
        }


    }catch(const char * mensaje){
        cerr << mensaje << endl;
    }

    return 0;
}

bool esEuler(const Grafica &g){
    for (char i = 'a'; i <= 'z'; ++i){ //lo puse como char pero puede ser cualquier cosa
        if (g.Buscar(i) && g.ObtenerGrado(i) % 2 != 0){
            return false;
        }
    }
    return true;
}