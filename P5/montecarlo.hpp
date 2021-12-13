#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

void generateMatrix(vector <vector <int>> &matrix);
void generateVector(vector <vector <int>> &matrix);
bool compareMatrix(vector <vector <int>> A, vector <vector <int>> B);
vector<vector<int>> multiply(vector <vector <int>> &A, vector <vector <int>> &B);
void matrixC(vector <vector <int>> &C, vector <vector <int>> &AB);
bool Montecarlo(vector <vector <int>> &A, vector <vector <int>> &B, vector <vector <int>> &C, int dimension);

#endif