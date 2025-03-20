#include <iostream>

#include "Grafica.hpp"
using namespace std;

int main()
{
    //ejemplo para las pruebas
    Grafica g;

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

    g.Imprimir();

    cout << endl << AlgoritmoFleury(g) << endl;
    return 0;
}
