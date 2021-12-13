#include "algoritmos.hpp"

using namespace std;

double CONVERSION=86400000000;

void ordenacionQuickSort(){

    int nMin, nMax, incremento, repeticiones;
    vector <double> tiemposReales, numeroElementos, tiemposEstimados;
    vector<double> a(2);

    cout << "\nIntroduce el numero minimo de elementos: ";
    cin >> nMin;

    cout << "\nIntroduce el numero maximo de elementos: ";
    cin >> nMax;

    cout << "\nIntroduce el numero de incremento de elementos: ";
    cin >> incremento;

    cout << "\nIntroduce el numero de repeticiones de elementos: ";
    cin >> repeticiones;
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    tiemposOrdenacionQuickSort(nMin, nMax, incremento, repeticiones, tiemposReales, numeroElementos);

    guardarFichero(numeroElementos, tiemposReales, "tiempoRealesQuickSort.txt");

    ajustePolinomico(numeroElementos, tiemposReales, a);

    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);

    guardarFicheroEstimados(tiemposEstimados, "tiempoEstimaciónQuickSort.txt");

    cout << "\nCoeficiente de determinación: " << calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    guardarFicheroFinal(numeroElementos, tiemposReales, tiemposEstimados, "datosFinalesQuickSort.txt");

    double n = 1;

    while (n != 0){

        cout << "\nIntroduce un valor de n para el cual realizar una estimación del tiempo que tardaria en procesarse (0 para salir): ";
        cin >> n;

        if(n != 0){

            cout << "\nLa estimacion de tiempo para el valor introducido es: " << calcularTiempoEstimadoPolinomico(n, a)/CONVERSION << " dias.";
        }
    }
}

void ordenacionFusion(){

    int nMin, nMax, incremento, repeticiones;
    vector <double> tiemposReales, numeroElementos, tiemposEstimados;
    vector<double> a(2);

    cout << "\nIntroduce el numero minimo de elementos: ";
    cin >> nMin;

    cout << "\nIntroduce el numero maximo de elementos: ";
    cin >> nMax;

    cout << "\nIntroduce el numero de incremento de elementos: ";
    cin >> incremento;

    cout << "\nIntroduce el numero de repeticiones de elementos: ";
    cin >> repeticiones;
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    tiemposOrdenacionFusion(nMin, nMax, incremento, repeticiones, tiemposReales, numeroElementos);

    guardarFichero(numeroElementos, tiemposReales, "tiempoRealesFusion.txt");

    ajustePolinomico(numeroElementos, tiemposReales, a);

    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);

    guardarFicheroEstimados(tiemposEstimados, "tiempoEstimaciónFusion.txt");

    cout << "\nCoeficiente de determinación: " << calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    guardarFicheroFinal(numeroElementos, tiemposReales, tiemposEstimados, "datosFinalesFusion.txt");

    double n = 1;

    while (n != 0){

        cout << "\nIntroduce un valor de n para el cual realizar una estimación del tiempo que tardaria en procesarse (0 para salir): ";
        cin >> n;

        if(n != 0){

            cout << "\nLa estimacion de tiempo para el valor introducido es: " << calcularTiempoEstimadoPolinomico(n, a)/CONVERSION << " dias.";
        }
    }
}

void ordenacionQuickSortDyV(){

    int elementos, incremento, repeticiones, minimo, maximo;
    vector <double> tiemposReales, numeroElementos, tiemposEstimados;
    vector<double> a(2);

    cout << "\nIntroduce el numero de elementos: ";
    cin >> elementos;

    cout << "\nIntroduce el minimo de elementos para usar divide y venceras con QuickSort usando ordenación por Insercion: ";
    cin >> minimo;

    cout << "\nIntroduce el maximo de elementos para usar divide y venceras con QuickSort usando ordenación por Insercion: ";
    cin >> maximo;

    cout << "\nIntroduce el numero de incremento de elementos: ";
    cin >> incremento;

    cout << "\nIntroduce el numero de repeticiones de elementos: ";
    cin >> repeticiones;
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    tiemposOrdenacionQuickSortDyV(elementos, incremento, repeticiones, minimo, maximo, tiemposReales, numeroElementos);

    guardarFichero(numeroElementos, tiemposReales, "tiempoRealesQuickSortDyV.txt");
}

void ordenacionFusionDyV(){

    int elementos, incremento, repeticiones, minimo, maximo;
    vector <double> tiemposReales, numeroElementos, tiemposEstimados;
    vector<double> a(2);

    cout << "\nIntroduce el numero de elementos: ";
    cin >> elementos;

    cout << "\nIntroduce el minimo de elementos para usar divide y venceras con QuickSort usando ordenación por Insercion: ";
    cin >> minimo;

    cout << "\nIntroduce el maximo de elementos para usar divide y venceras con QuickSort usando ordenación por Insercion: ";
    cin >> maximo;

    cout << "\nIntroduce el numero de incremento de elementos: ";
    cin >> incremento;

    cout << "\nIntroduce el numero de repeticiones de elementos: ";
    cin >> repeticiones;
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    tiemposOrdenacionFusionDyV(elementos, incremento, repeticiones, minimo, maximo, tiemposReales, numeroElementos);

    guardarFichero(numeroElementos, tiemposReales, "tiempoRealesFusionDyV.txt");
}