#ifndef REINAS_HPP
#define REINAS_HPP

#include <vector>
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

bool lugar(int k, vector <int> x);
void nreinas(int n, vector <vector <int>> &soluciones);
void nreinasBlocked(int n, vector <int> &solucion);
void nreinasLasVegas(int n, vector <int> &solucion, bool &exito);
void nreinasCoste(int n, vector <int> &solucion, int &podas);

#endif
