#include <iostream>

#include "algoritmos.hpp"

using namespace std;

int main()
{
    int opt = 5;

    while (opt != 0)
    {
        cout << "\n1. void ordenacionQuickSort();" << endl;
        cout << "2. void ordenacionFusion();" << endl;
        cout << "3. void ordenacionQuickSort(); divide y venceras" << endl;
        cout << "4. void ordenacionFusion(); divide y venceras" << endl;
        cout << "5. Generar Graficos" << endl;
        cout << "0. Salir del programa." << endl;
        cout << "Introduzca el numero correspondiente a la opcion que quiera ejecutar de las anteriores: ";

        cin >> opt;

        switch (opt)
        {
        case 0:
            
            break;

        case 1:

            srand(time(0));
            ordenacionQuickSort();

            break;

        case 2:
            
            srand(time(0));
            ordenacionFusion();

            break;

        case 3:
            
            srand(time(0));
            ordenacionQuickSortDyV();

            break;
        
        case 4:
            
            srand(time(0));
            ordenacionFusionDyV();

            break;

        case 5:
            
            srand(time(0));
            system("./ejemplo_gnuplot.sh");

            break;

        default:

            cout << "\nLa opcion elegida es erronea pruebe con uan de las siguientes:" << endl;
            cout << "1. void ordenacionQuickSort();" << endl;
            cout << "2. void ordenacionFusion();" << endl;
            cout << "3. void ordenacionQuickSort(); divide y venceras" << endl;
            cout << "4. void ordenacionFusion(); divide y venceras" << endl;
            cout << "5. Generar Graficos" << endl;
            cout << "0. Salir del programa." << endl;
            cout << "Introduzca el numero correspondiente a la opcion que quiera ejecutar de las anteriores: ";

            cin >> opt;

            break;
        }
    }

    cout << "Saliendo del programa..." << endl;

    return 0;
}
