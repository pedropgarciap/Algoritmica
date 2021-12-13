#ifndef MISCELANEA_HPP
#define MISCELANEA_HPP

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void rellenarVector(vector<int> &v);
bool estaOrdenado(const vector<int> &v);
bool QuickSort(int iz, int de, int n, vector<int> &v);
bool QuickSortDyV(int iz, int de, int n, vector<int> &v, int limite);
bool OrdenarFusion(vector<int> &v);
bool OrdenarFusionDyV(vector<int> &v, int limite);
void fusionar(vector<int> &u, vector<int> &w, vector<int> &v);
void insertionSort(vector<int> &v);
void insertionSort(vector<int> &v, int izq, int der);

#endif
