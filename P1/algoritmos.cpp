#include "algoritmos.hpp"
#include "sistemaEcuaciones.hpp"
#include "ClaseTiempo.cpp"

#include <vector>
#include <fstream>
#include <cmath>  

using namespace std;

int MAXRANGE=10000000;

void rellenarVector(vector<int> &v);
bool seleccion(vector<int> &v);
bool estaOrdenado(const vector<int> &v);
void tiemposOrdenacionSeleccion(int nMin, int nMax, int incremento, int repeticiones, vector<double> &tiemposReales, vector<double> &numeroElementos);
void guardarFichero(vector<double> &tiemposReales, vector<double> &numeroElementos);
void ajustePolinomico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a);
double sumatorio(const vector<double> &n, const vector<double> &t, int expN, int expT);
void calcularTiemposEstimadosPolinomico(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados);
void guardarFicheroEstimados(vector<double> &tiemposEstimados);
double calcularCoeficienteDeterminacion(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados);
void guardarFicheroFinal(vector<double> &numeroElementos, vector<double>&tiemposReales, vector<double> &tiemposEstimados);
double calcularTiempoEstimadoPolinomico(const double &n, vector <double> &a);

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

    guardarFichero(numeroElementos, tiemposReales);

    ajustePolinomico(numeroElementos, tiemposReales, a);

    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);

    guardarFicheroEstimados(tiemposEstimados);

    cout << "\nCoeficiente de determinación: " << calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    guardarFicheroFinal(numeroElementos, tiemposReales, tiemposEstimados);

    int n = 1;

    while (n != 0){

        cout << "\nIntroduce un valor de n para el cual realizar una estimación del tiempo que tardaria en procesarse (0 para salir): ";
        cin >> n;

        if(n != 0){

            cout << "\nLa estimacion de tiempo para el valor introducido es: " << calcularTiempoEstimadoPolinomico(n, a)/1000000 << " segundos.";
        }
    }
}


void rellenarVector(vector<int> &v){

    for (int i = 0; i < v.size(); i++) {
        v[i] = rand()%MAXRANGE;
    }
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

bool estaOrdenado(const vector<int> &v){

    for(int i = 0; i < v.size()-1; i++){

        if(v[i] > v[i+1]){

            return false;
        }
    }       

    return true;
}

void tiemposOrdenacionSeleccion(int nMin, int nMax, int incremento, int repeticiones, vector<double> &tiemposReales, vector<double> &numeroElementos){

    Clock reloj;
    double tiempotranscurrido = 0;

    for (int i = nMin; i <= nMax; i+=incremento){

        tiempotranscurrido = 0;

        for (int j = 0; j < repeticiones; j++){
            
            vector<int> v(i, 0);
            rellenarVector(v);

            reloj.start();
            seleccion(v);

            if(reloj.isStarted()){

                reloj.stop();
                tiempotranscurrido+=reloj.elapsed();   
            }
        }

        tiemposReales.push_back(tiempotranscurrido/repeticiones);
        numeroElementos.push_back(i);

        cout << "\nNumero de elementos: " << numeroElementos[numeroElementos.size()-1] << "\tMedia de tiempo por repeticion: " << tiemposReales[tiemposReales.size()-1]  << endl;
    }

    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
}

void guardarFichero(vector<double> &numeroElementos, vector<double> &tiemposReales){

    ofstream fichero("tiempoReales.txt");

    for (int i = 0; i < numeroElementos.size(); i++)
    {
        fichero << numeroElementos[i] << "\t" << tiemposReales[i] << endl;
    }
}

void guardarFicheroEstimados(vector<double> &tiemposEstimados){

    ofstream fichero("tiempoEstimados.txt");

    for (int i = 0; i < tiemposEstimados.size(); i++)
    {
        fichero << tiemposEstimados[i] << endl;
    }
}

void guardarFicheroFinal(vector<double> &numeroElementos, vector<double>&tiemposReales, vector<double> &tiemposEstimados){

    ofstream fichero("datosFinales.txt");

    for (int i = 0; i < numeroElementos.size(); i++)
    {
        fichero << numeroElementos[i] << "\t" << tiemposReales[i] << "\t" << tiemposEstimados[i] << endl;
    }
}

void ajustePolinomico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a){

    vector<vector<double>> matrizDatos;
    matrizDatos = vector<vector<double>>(a.size(), vector<double>(a.size()));

    vector<vector<double>> matrizDatosIndependientes;
    matrizDatosIndependientes = vector<vector<double>>(a.size(), vector<double>(1));

    vector<vector<double>> X;
    X = vector<vector<double>>(a.size(), vector<double>(1));

    for (int i = 0; i < matrizDatos.size(); i++)
    {
        for (int j = 0; j < matrizDatos[i].size(); j++)
        {
            matrizDatos[i][j] = sumatorio(numeroElementos, tiemposReales, i+j, 0);
        }

        matrizDatosIndependientes[i][0] = sumatorio(numeroElementos, tiemposReales, i, 1);
    }

    resolverSistemaEcuaciones(matrizDatos, matrizDatosIndependientes, a.size(), X);

    cout << "\nRecta: t(n) = ";

    for (int i = 0; i < a.size(); i++)
    {
        a[i] = X[i][0];

        if(i == 0){

            cout << a[i];
        }

        else if (i == 1){

            cout << " + " << a[i] << "*" << "n"; 
        }

        else{

            cout << " + " << a[i] << "*" << "n^" << i; 
        }
        
    }
    
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
}

double sumatorio(const vector<double> &n, const vector<double> &t, int expN, int expT){//preguntar por los const de aqui 

    double sumatorio = 0;

    for (int i = 0; i < n.size(); i++)
    {
        sumatorio += (pow(n[i], expN) * pow(t[i], expT));
    }

    return sumatorio;
}

void calcularTiemposEstimadosPolinomico(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados){

    for (int i = 0; i < numeroElementos.size(); i++)
    {   
        double tiempoEstimado = 0;

        for (int j = 0; j < a.size(); j++)
        {
            tiempoEstimado+=a[j]*pow(numeroElementos[i], j);
        }
        
        tiemposEstimados.push_back(tiempoEstimado);
        //tiemposEstimados.push_back(a[0] + a[1]*numeroElementos[i] + (a[2]*pow(numeroElementos[i], 2)));
    }
}

double calcularCoeficienteDeterminacion(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados){

    double varianzaReales = 0, varianzaEstimados = 0;
    double mediaReales = 0, mediaEstimados = 0;

    for (int i = 0; i < tiemposReales.size(); i++)
    {
        mediaReales+=tiemposReales[i];
        mediaEstimados+=tiemposEstimados[i];
    }

    mediaReales/=tiemposReales.size();
    mediaEstimados/=tiemposEstimados.size();
    
    for (int i = 0; i < tiemposReales.size(); i++)
    {
        varianzaReales += pow(tiemposReales[i] - mediaReales, 2);
        varianzaEstimados += pow(tiemposEstimados[i] - mediaEstimados, 2);
    }

    varianzaReales/=tiemposReales.size();
    varianzaEstimados/=tiemposEstimados.size();

    return varianzaEstimados/varianzaReales;
}

double calcularTiempoEstimadoPolinomico(const double &n, vector <double> &a){

    double estimado = 0;

    for (int i = 0; i < a.size(); i++)
    {
        estimado+=(a[i]*pow(n,i));
    }

    return estimado;
}