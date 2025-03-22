#include <iostream>

#include "Grafica.hpp"
using namespace std;

int main()
{
    try{
        Grafica g;
        //ejemplo para las pruebas
        /*


        g.Agregar('a');
        g.Agregar('b');
        g.Agregar('c');
        g.Agregar('d');
        g.Agregar('e');
        g.Agregar('f');

        g.Agregar('a', 'b');
        g.Agregar('a', 'd');
        g.Agregar('a', 'e');
        g.Agregar('a', 'f');
        g.Agregar('b', 'f');
        g.Agregar('b', 'd');
        g.Agregar('b', 'c');
        g.Agregar('c', 'd');
        g.Agregar('d', 'e');

        */
        g.Agregar('a');
        g.Agregar('b');
        g.Agregar('c');
        g.Agregar('d');
        g.Agregar('e');
        g.Agregar('f');
        g.Agregar('g');

        g.Agregar('a','f');
        g.Agregar('a','b');
        g.Agregar('b','f');
        g.Agregar('b','c');
        g.Agregar('b','g');
        g.Agregar('c','d');
        g.Agregar('c','e');
        g.Agregar('c','g');
        g.Agregar('d','e');
        g.Agregar('g','e');
        g.Agregar('g','f');
        g.Agregar('e','f');

        cout << endl << AlgoritmoFleury(g) << endl;
    }catch(const char * mensaje){
        cerr << mensaje;
    }

    return 0;
}
