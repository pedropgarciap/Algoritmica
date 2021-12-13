#include "montecarlo.hpp"

void generateMatrix(vector <vector <int>> &matrix){

    for(int i = 0; i < matrix.size(); i++){

        for(int j = 0; j < matrix.size(); j++){

            matrix[i][j] = (rand()%3) - 1;
        }
    }
}

void generateVector(vector <vector <int>> &matrix){

    for(int i = 0; i < matrix.size(); i++){

        for(int j = 0; j < matrix[0].size(); j++){

            matrix[i][j] = (rand()%2);
        }
    }
}

bool compareMatrix(vector <vector <int>> A, vector <vector <int>> B){

    for(int i=0; i < A.size(); i++){

        for(int j = 0; j < A[0].size(); j++){

            if(A[i][j]!=B[i][j]){

                return false;
            }
        }
    }
    return true;  
}

vector<vector<int>> multiply(vector <vector <int>> &A, vector <vector <int>> &B){

    vector <vector <int>> AB(A.size(), vector<int>(B[0].size()));

    for(int i = 0; i < A.size(); i++){

        for(int j = 0; j < B[0].size(); j++){

            for(int z = 0; z < A[0].size(); z++){

                AB[i][j] += A[i][z] * B[z][j];
            }
        }
    }

    return AB;
}

void matrixC(vector <vector <int>> &C, vector <vector <int>> &AB){

    int dice = (rand()%6)+1;

    vector <vector <int>> matrix;
    
    matrix = AB;
    
    if(dice%2 == 0){

        C = matrix;
    }
    
    else{

        matrix[matrix.size()/2][matrix.size()/2]++;
        C = matrix;
    }
}



bool Montecarlo(vector <vector <int>> &A, vector <vector <int>> &B, vector <vector <int>> &C, int dimension){

    vector <vector <int>> X(1,vector<int>(A.size()));

    generateVector(X);

    vector <vector <int>> matrix = multiply(X,A);

    if(compareMatrix(multiply(matrix, B), multiply(X,C))){

        return true;
    }

    else{

        return false;
    }
}

