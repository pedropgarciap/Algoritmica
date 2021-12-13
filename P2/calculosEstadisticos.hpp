#ifndef CALCULOSESTADISTICOS_HPP
#define CALCULOSESTADISTICOS_HPP

#include <vector>

using namespace std;

double sumatorio(const vector<double> &n, const vector<double> &t, int expN, int expT);
double calcularCoeficienteDeterminacion(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados);

#endif