#include "calculosEstadisticos.hpp"
#include <vector>
#include <cmath>  

using namespace std;

double sumatorio(const vector<double> &n, const vector<double> &t, int expN, int expT){

    double sumatorio = 0;

    for (int i = 0; i < n.size(); i++)
    {
        sumatorio += (pow(n[i], expN) * pow(t[i], expT));
    }

    return sumatorio;
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