#include <iostream>

#include "algoritmos.hpp"

using namespace std;

int main(){

    int opt = 5;

    while (opt != 0){

        cout << "\n1. NReinas Backtracking;" << endl;
        cout << "2. NReinas solución C/2;" << endl;
        cout << "3. NReinas Las Vegas;" << endl;
        cout << "4. NReinas Poda" << endl;
        cout << "5. Montecarlo" << endl;
        cout << "0. Salir del programa." << endl;
        cout << "Introduzca el numero correspondiente a la opcion que quiera ejecutar de las anteriores: ";

        cin >> opt;

        switch (opt){

            case 0:
                
                break;

            case 1:
                
                reinasBacktracking();

                break;

            case 2:
                
                reinasBacktrackingBlocked();

                break;

            case 3:

                srand(time(0));
                reinasLasVegas();

                break;

            case 4:

                reinasCoste();

                break;

            case 5:

                srand(time(0));
                montecarlo();

                break;
            
            default:

                cout << "\n1. NReinas Backtracking;" << endl;
                cout << "2. NReinas solución C/2;" << endl;
                cout << "3. NReinas Las Vegas;" << endl;
                cout << "4. NReinas Poda" << endl;
                cout << "5. Montecarlo" << endl;
                cout << "0. Salir del programa." << endl;
                cout << "Introduzca el numero correspondiente a la opcion que quiera ejecutar de las anteriores: ";

                cin >> opt;

                break;
        }
    }

    cout << "Saliendo del programa..." << endl;

    return 0;
}