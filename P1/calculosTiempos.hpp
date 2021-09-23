#ifndef CALCULOSTIEMPOS_HPP
#define CALCULOSTIEMPOS_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include "miscelanea.hpp"
#include "sistemaEcuaciones.hpp"
#include "calculosMatematicos.hpp"

using namespace std;

void tiemposOrdenacionSeleccion(int nMin, int nMax, int incremento, int repeticiones, vector<double> &tiemposReales, vector<double> &numeroElementos);
void calcularTiemposEstimadosPolinomico(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados);
double calcularTiempoEstimadoPolinomico(const double &n, vector <double> &a);
void tiemposProductoMatrices(int nMin, int nMax, int incremento, int repeticiones, vector<double> &tiemposReales, vector<double> &numeroElementos);
void calcularTiemposEstimadosExponencial(const vector <double> &n, const vector <double> &a, vector <double> &tiemposEstimados);
double calcularTiempoEstimadoExponencial(const double &numeroElementos, const vector <double> &a);
void tiemposFibonacci(int nMin, int nMax, int incremento, vector<double> &tiemposReales, vector<double> &numeroElementos);

#endif