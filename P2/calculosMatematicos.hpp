#ifndef CALCULOSMATEMATICOS_HPP
#define CALCULOSMATEMATICOS_HPP

#include "sistemaEcuaciones.hpp"
#include "calculosEstadisticos.hpp"
#include <vector>
#include <iostream>


using namespace std;

void ajustePolinomico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a);

#endif
