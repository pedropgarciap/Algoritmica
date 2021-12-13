#ifndef CALCULOSTIEMPOS_HPP
#define CALCULOSTIEMPOS_HPP

#include "ClaseTiempo.cpp"
#include "miscelanea.hpp"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void tiemposOrdenacionQuickSort(int nMin, int nMax, int incremento, int repeticiones, vector<double> &tiemposReales, vector<double> &numeroElementos);
void calcularTiemposEstimadosPolinomico(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados);
double calcularTiempoEstimadoPolinomico(const double &n, vector <double> &a);
void tiemposOrdenacionFusion(int nMin, int nMax, int incremento, int repeticiones, vector<double> &tiemposReales, vector<double> &numeroElementos);
void tiemposOrdenacionQuickSortDyV(int elementos, int incremento, int repeticiones, int minimo, int maximo, vector<double> &tiemposReales, vector<double> &numeroElementos);
void tiemposOrdenacionFusionDyV(int elementos, int incremento, int repeticiones, int minimo, int maximo, vector<double> &tiemposReales, vector<double> &numeroElementos);

#endif