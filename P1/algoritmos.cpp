#include "algoritmos.hpp"
#include <vector>

using namespace std;

int MAXRANGE=10000000;

void rellenarVector(vector<int> &v);
bool seleccion(vector<int> &v);
bool estaOrdenado(const vector<int> &v);
void tiemposOrdenacionSeleccion(int nMin, int nMax, int repeticiones, vector<double> &tiemposReales, vector<double> &numeroElementos);


void ordenacionSeleccion(){

    cout << "Introduzca el numero de elementos con el que quiere instanciar el vector: ";

    int n;
    cin >> n;

    vector<int> v(n, 0);

    rellenarVector(v);

    cout << "¿Esta ordenado? " << seleccion(v) << endl;

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}


void rellenarVector(vector<int> &v){

    for (int i = 0; i < v.size(); i++) {
        v[i] = rand()%MAXRANGE;
    }
}

bool estaOrdenado(const vector<int> &v){

    for(int i = 0; i < v.size()-1; i++){

        if(v[i] > v[i+1]){

            return false;
        }
    }       

    return true;
}

bool seleccion(vector<int> &v){

    for (int i = 0; i < v.size() - 1; i++) {
        
        int minimo = i;

        for (int j = i + 1; j < v.size(); j++) {
            
            if (v[minimo] > v[j]) 
                minimo = j;
        }
        
        int auxiliar = v[i];
        v[i] = v[minimo];
        v[minimo] = auxiliar;
    }

    return estaOrdenado(v);
}

