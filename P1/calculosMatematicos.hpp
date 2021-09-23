#ifndef CALCULOSMATEMATICOS_HPP
#define CALCULOSMATEMATICOS_HPP

#include "sistemaEcuaciones.hpp"
#include "calculosEstadisticos.hpp"
#include <vector>
#include <iostream>


using namespace std;

void ajustePolinomico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a);//m
void productoMatrices(vector<vector<double>> &m1, vector<vector<double>> &m2);//m
void ajusteExponencial(const vector <double> &n, const vector <double> &tiemposReales, vector <double> &a);//m

#endif