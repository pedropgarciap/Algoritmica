#ifndef DINAMICOS_HPP
#define DINAMICOS_HPP

#include <vector>
#include <iostream>
#include <limits>

#include "Divisa.hpp"
#include "Material.hpp"

void dinamicoCambio(vector <Divisa> sistemaMonetario, vector <vector<int>> &solucion, int cambioi);
void solucionCambio(vector <Divisa> sistemaMonetario, vector <vector<int>> solucion, int cambioi, vector<int> &cardinalidad);

void dinamicoMochila(vector <Material> listaMateriales, vector <vector<int>> &solucion, int volumen);
void solucionMochila(vector <Material> listaMateriales, vector <vector<int>> solucion, int volumen, vector<int> &cardinalidad);

void dinamicoCambioOpcional(vector <Divisa> sistemaMonetario, vector <vector<int>> &solucion, int cambioi);
void solucionCambioOpcional(vector <Divisa> sistemaMonetario, vector <vector<int>> solucion, int cambioi, vector<int> &cardinalidad);

#endif