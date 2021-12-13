#include "algoritmos.hpp"

void reinasBacktracking(){

    int reinas;

    cout << "Introduzca el numero n de reinas que quiere colocar en un tablero de nxn: ";
    cin >> reinas;

    vector <vector <int>> soluciones;

    nreinas(reinas, soluciones);

    cout << "\n----------------------------------------------------------------------------------------------------" << endl;

    int coste = 0;
    int minimo = numeric_limits<int>::max();

    for(int i = 0; i < soluciones.size(); i++){

        coste = 0;

        for(int j = 1; j < soluciones[i].size(); j++){

            cout << "[" << soluciones[i][j] << "]";
            coste = coste + (soluciones[i][j] * j);
        }

        cout << "Coste: " << coste;

        if(coste < minimo){

            minimo = coste;
            cout << " <---- MINIMO";
        }

        cout << endl;
    }

    cout << "Numero soluciones = " << soluciones.size() << endl;
} 

void reinasBacktrackingBlocked(){

    int reinas;

    cout << "Introduzca el numero n de reinas que quiere colocar en un tablero de nxn: ";
    cin >> reinas;

    vector <int> solucion(1);

    Clock tiempo;
    tiempo.start();

    nreinasBlocked(reinas, solucion);

    if(tiempo.isStarted()){
        
        tiempo.stop();
    }

    cout << "\n----------------------------------------------------------------------------------------------------" << endl;
    cout << "Solucion: " << endl;

    for(int i = 1; i < solucion.size(); i++){

        cout << "[" << solucion[i] << "]";
    }

    cout << "\nTiempo transcurrido = " << tiempo.elapsed() << " microsegundos." << endl;
} 

void reinasLasVegas(){

    int reinas;

    cout << "Introduzca el numero n de reinas que quiere colocar en un tablero de nxn: ";
    cin >> reinas;

    vector <int> solucion(1);

    Clock tiempo;
    tiempo.start();

    bool exito = false;
    int i = 0;

    while(!exito){

        nreinasLasVegas(reinas, solucion, exito);
        i++;
    }

    if(tiempo.isStarted()){

        tiempo.stop();
    }

    cout << "\n----------------------------------------------------------------------------------------------------" << endl;
    cout << "Solucion: " << endl;

    for(int i = 1; i < solucion.size(); i++){

        cout << "[" << solucion[i] << "]";
    }

    cout << "\nTiempo transcurrido = " << tiempo.elapsed() << "microsegundos." << endl;
    cout << "Numero de intentos = " << i << "intentos." << endl;
}

void reinasCoste(){

    int reinas, podas = 0;

    cout << "Introduzca el numero n de reinas que quiere colocar en un tablero de nxn: ";
    cin >> reinas;

    vector <int> solucion(reinas+1);

    Clock tiempo;
    tiempo.start();

    nreinasCoste(reinas, solucion, podas);

    tiempo.stop();

    cout << "\n----------------------------------------------------------------------------------------------------" << endl;
    cout << "Solucion: " << endl;

    int coste = 0;

    for(int i = 1; i < solucion.size(); i++){

        cout << "[" << solucion[i] << "]";
        coste = coste + solucion[i]*i;
    }

    cout << " Coste: " << coste << endl;
    cout << "Podas: " << podas << endl;

    cout << "\nTiempo transcurrido = " << tiempo.elapsed() << " microsegundos." << endl;
}

void montecarlo(){

    int dimension, tests;
    cout << "Introduzca la dimension de las matrices a crear: ";
    cin >> dimension;
    cout << "Introduzca el numero de test de montecarlo: ";
    cin >> tests;

    vector <vector <int>> A(dimension, vector<int>(dimension));
    vector <vector <int>> B(dimension, vector<int>(dimension));
    vector <vector <int>> C(dimension, vector<int>(dimension));
    vector <vector <int>> AB(dimension, vector<int>(dimension));

    generateMatrix(A);
    generateMatrix(B);

    Clock tiempo;
    tiempo.start();

    AB=multiply(A, B);
            
    if(tiempo.isStarted()){

        tiempo.stop();
    }

    cout << "\n----------------------------------------------------------------------------------------------------" << endl;
    cout<<"El tiempo de la multiplicacion es de " << tiempo.elapsed() << " microsegundos." <<endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;

    matrixC(C, AB);

    bool found = true;
    int i;

    tiempo.start();
        
    for(i = 0; (i < tests) && found; i++){
        
        found = Montecarlo(A, B, C, dimension);
    }   

    if(tiempo.isStarted()){

        tiempo.stop();
    }

    cout<<"El tiempo de las pruebas es de " << tiempo.elapsed() << " microsegundos." <<endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;

    if(found){

        float probablityIndex;
        probablityIndex = 1 - pow(0.5, tests);
        cout<<"La probabilidad de que el producto sea correcto es de: "<< probablityIndex <<endl;
        
    }
    else{

        cout<<"Se han realizado " << i << " pruebas hasta no verificar." << endl;
    }

    cout << "----------------------------------------------------------------------------------------------------" << endl;
}