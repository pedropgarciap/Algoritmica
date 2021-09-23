#include "algoritmos.hpp"

using namespace std;

double CONVERSION=86400000000;

void ordenacionSeleccion(){

    int nMin, nMax, incremento, repeticiones, orden;
    vector <double> tiemposReales, numeroElementos, tiemposEstimados;

    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << "\nIntroduce el orden de la matriz de soluciones: (3 para cuadrático): ";
    cin >> orden;

    vector<double> a(orden);

    cout << "\nIntroduce el numero minimo de elementos: ";
    cin >> nMin;

    cout << "\nIntroduce el numero maximo de elementos: ";
    cin >> nMax;

    cout << "\nIntroduce el numero de incremento de elementos: ";
    cin >> incremento;

    cout << "\nIntroduce el numero de repeticiones de elementos: ";
    cin >> repeticiones;
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    tiemposOrdenacionSeleccion(nMin, nMax, incremento, repeticiones, tiemposReales, numeroElementos);

    guardarFichero(numeroElementos, tiemposReales, "tiempoRealesSeleccion.txt");

    ajustePolinomico(numeroElementos, tiemposReales, a);

    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);

    guardarFicheroEstimados(tiemposEstimados, "tiempoEstimaciónSeleccion.txt");

    cout << "\nCoeficiente de determinación: " << calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    guardarFicheroFinal(numeroElementos, tiemposReales, tiemposEstimados, "datosFinalesSeleccion.txt");

    double n = 1;

    while (n != 0){

        cout << "\nIntroduce un valor de n para el cual realizar una estimación del tiempo que tardaria en procesarse (0 para salir): ";
        cin >> n;

        if(n != 0){

            cout << "\nLa estimacion de tiempo para el valor introducido es: " << calcularTiempoEstimadoPolinomico(n, a)/CONVERSION << " dias.";
        }
    }
}

void productoMatricesCuadradas(){

    int nMin, nMax, incremento, repeticiones, orden;
    vector <double> tiemposReales, numeroElementos, tiemposEstimados;

    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << "\nIntroduce el orden de la matriz de soluciones: (4 para polinomio de grado 3): ";
    cin >> orden;

    vector<double> a(orden);

    cout << "\nIntroduce el numero minimo de elementos: ";
    cin >> nMin;

    cout << "\nIntroduce el numero maximo de elementos: ";
    cin >> nMax;

    cout << "\nIntroduce el numero de incremento de elementos: ";
    cin >> incremento;

    cout << "\nIntroduce el numero de repeticiones de elementos: ";
    cin >> repeticiones;
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    tiemposProductoMatrices(nMin, nMax, incremento, repeticiones, tiemposReales, numeroElementos);

    guardarFichero(numeroElementos, tiemposReales, "tiempoRealesMatrices.txt");

    ajustePolinomico(numeroElementos, tiemposReales, a);

    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);

    guardarFicheroEstimados(tiemposEstimados, "tiempoEstimadosMatrices.txt");

    cout << "\nCoeficiente de determinación: " << calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    guardarFicheroFinal(numeroElementos, tiemposReales, tiemposEstimados, "datosFinalesMatrices.txt");

    double n = 1;

    while (n != 0){

        cout << "\nIntroduce un valor de n para el cual realizar una estimación del tiempo que tardaria en procesarse (0 para salir): ";
        cin >> n;

        if(n != 0){

            cout << "\nLa estimacion de tiempo para el valor introducido es: " << calcularTiempoEstimadoPolinomico(n, a)/CONVERSION << " dias.";
        }
    }
}

void fibonacciRecursivo(){

    int nMin, nMax, incremento = 1;
    vector <double> tiemposReales, numeroElementos, tiemposEstimados;
    vector<double> a(2);

    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << "\nIntroduce el termino minimo de la sucesion de fibonacci a calcular: ";
    cin >> nMin;

    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << "\nIntroduce el termino maximo de la sucesion de fibonacci a calcular: ";
    cin >> nMax;

    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    tiemposFibonacci(nMin, nMax, incremento, tiemposReales, numeroElementos);

    guardarFichero(numeroElementos, tiemposReales, "tiempoRealesFibanacci.txt");

    ajusteExponencial(numeroElementos, tiemposReales, a);

    calcularTiemposEstimadosExponencial(numeroElementos, a, tiemposEstimados);

    guardarFicheroEstimados(tiemposEstimados, "tiempoEstimadosFibonacci.txt");

    cout << "\nCoeficiente de determinación: " << calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    guardarFicheroFinal(numeroElementos, tiemposReales, tiemposEstimados, "datosFinalesFibonacci.txt");

    double n = 1;

    while (n != 0){

        cout << "\nIntroduce un valor de n para el cual realizar una estimación del tiempo que tardaria en procesarse (0 para salir): ";
        cin >> n;

        if(n != 0){

            cout << "\nLa estimacion de tiempo para el valor introducido es: " << calcularTiempoEstimadoExponencial(n, a)/CONVERSION << " dias.";
        }
    }
}