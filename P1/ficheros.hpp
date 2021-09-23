#ifndef FICHEROS_HPP
#define FICHEROS_HPP

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

void guardarFichero(vector<double> &tiemposReales, vector<double> &numeroElementos, string nombreFichero);
void guardarFicheroEstimados(vector<double> &tiemposEstimados, string nombreFichero);
void guardarFicheroFinal(vector<double> &numeroElementos, vector<double>&tiemposReales, vector<double> &tiemposEstimados, string nombreFichero);

#endif