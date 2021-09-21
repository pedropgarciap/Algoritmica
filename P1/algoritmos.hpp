#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include "sistemaEcuaciones.hpp"
#include "ClaseTiempo.cpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>  

using namespace std;

void ordenacionSeleccion();
void productoMatricesCuadradas();
void fibonacciRecursivo();

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

void rellenarMatrices(vector<vector<double>> &m1, vector<vector<double>> &m2);
void productoMatrices(vector<vector<double>> &m1, vector<vector<double>> &m2);
void tiemposProductoMatrices(int nMin, int nMax, int incremento, int repeticiones, vector<double> &tiemposReales, vector<double> &numeroElementos);

int fibonacci(int x);
void ajusteExponencial(const vector <double> &n, const vector <double> &tiemposReales, vector <double> &a);
double sumatorioExponencial(const vector<double> &n, const vector<double> &t, int expN, int expT);
void calcularTiemposEstimadosExponencial(const vector <double> &n, const vector <double> &a, vector <double> &tiemposEstimados);
double calcularTiempoEstimadoExponencial(const double &numeroElementos, const vector <double> &a);
void tiemposFibonacci(int nMin, int nMax, int incremento, vector<double> &tiemposReales, vector<double> &numeroElementos);

#endif
