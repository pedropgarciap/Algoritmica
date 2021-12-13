#include "ficheros.hpp"

void guardarFichero(vector<double> &numeroElementos, vector<double> &tiemposReales, string nombreFichero){

    ofstream fichero(nombreFichero);

    for (int i = 0; i < numeroElementos.size(); i++)
    {
        fichero << numeroElementos[i] << "\t" << tiemposReales[i] << endl;
    }
}

void guardarFicheroEstimados(vector<double> &tiemposEstimados, string nombreFichero){

    ofstream fichero(nombreFichero);

    for (int i = 0; i < tiemposEstimados.size(); i++)
    {
        fichero << tiemposEstimados[i] << endl;
    }
}

void guardarFicheroFinal(vector<double> &numeroElementos, vector<double>&tiemposReales, vector<double> &tiemposEstimados, string nombreFichero){

    ofstream fichero(nombreFichero);

    for (int i = 0; i < numeroElementos.size(); i++)
    {
        fichero << numeroElementos[i] << "\t" << tiemposReales[i] << "\t" << tiemposEstimados[i] << endl;
    }
}