#ifndef VORACES_HPP
#define VORACES_HPP

#include <vector>
#include <iostream>
#include "Divisa.hpp"
#include "Material.hpp"

void vorazCambio(vector <Divisa> sistemaMonetario, vector <Divisa> &solucion, vector <int> &cardinalidad, int cambioi);
void vorazMochila(vector <Material> &listaMateriales, vector <Material> &solucion, int volumen);

#endif