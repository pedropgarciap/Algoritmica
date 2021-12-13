#ifndef FICHEROS_HPP
#define FICHEROS_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Divisa.hpp"
#include "Material.hpp"

void leerDivisas(vector <Divisa> &sistemaMonetario);
void leerDivisasOpcional(vector <Divisa> &sistemaMonetario);
void leerMateriales(vector <Material> &listaMateriales);

#endif