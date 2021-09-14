#include <iostream>

#include "algoritmos.hpp"

using namespace std;

int main()
{
    int opt = 5;

    while (opt != 0)
    {
        cout << "1. void ordenacionSeleccion();" << endl;
        cout << "2. void productoMatricesCuadradas();" << endl;
        cout << "3. void fibonacciRecursivo();" << endl;
        cout << "0. Salir del programa." << endl;
        cout << "Introduzca el numero correspondiente a la opcion que quiera ejecutar de las anteriores: ";

        cin >> opt;

        switch (opt)
        {
        case 0:
            
            break;

        case 1:

            srand(time(0));
            ordenacionSeleccion();

            break;

        case 2:
            
            srand(time(0));
            //productoMatricesCuadradas();

            break;

        case 3:
            
            srand(time(0));
            //fibonacciRecursivo();

            break;
        
        default:

            cout << "\nLa opcion elegida es erronea pruebe con uan de las siguientes:" << endl;
            cout << "1. void ordenacionSeleccion();" << endl;
            cout << "2. void productoMatricesCuadradas();" << endl;
            cout << "3. void fibonacciRecursivo();" << endl;
            cout << "0. Salir del programa." << endl;
            cout << "Introduzca el numero correspondiente a la opcion que quiera ejecutar de las anteriores: ";

            cin >> opt;

            break;
        }
    }

    cout << "Saliendo del programa..." << endl;

    return 0;
}
