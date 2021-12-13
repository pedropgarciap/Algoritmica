#include <iostream>

#include "algoritmos.hpp"

using namespace std;

int main(){

    int opt = 5;

    while (opt != 0){

        cout << "\n1. Problema del cambio;" << endl;
        cout << "2. Problema de la mochila;" << endl;
        cout << "3. Problema del cambio opcional;" << endl;
        cout << "0. Salir del programa." << endl;
        cout << "Introduzca el numero correspondiente a la opcion que quiera ejecutar de las anteriores: ";

        cin >> opt;

        switch (opt){

            case 0:
                
                break;

            case 1:
                
                problemaCambio();

                break;

            case 2:
                
                problemaMochila();

                break;

            case 3:

                problemaCambioOpcional();

                break;
            
            default:

                cout << "\nLa opcion elegida es erronea pruebe con una de las siguientes:" << endl;
                cout << "1. Problema del cambio;" << endl;
                cout << "2. Problema de la mochila;" << endl;
                cout << "3. Problema del cambio opcional;" << endl;
                cout << "0. Salir del programa." << endl;
                cout << "Introduzca el numero correspondiente a la opcion que quiera ejecutar de las anteriores: ";

                cin >> opt;

                break;
        }
    }

    cout << "Saliendo del programa..." << endl;

    return 0;
}