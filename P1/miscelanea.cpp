#include "miscelanea.hpp"

void rellenarVector(vector<int> &v){

    for (int i = 0; i < v.size(); i++) {
        
    }
}

bool seleccion(vector<int> &v){

    for (int i = 0; i < v.size() - 1; i++) {
        
        int minimo = i;

        for (int j = i + 1; j < v.size(); j++) {
            
            if (v[minimo] > v[j]) 
                minimo = j;
        }
        
        int auxiliar = v[i];
        v[i] = v[minimo];
        v[minimo] = auxiliar;
    }

    return estaOrdenado(v);
}

bool estaOrdenado(const vector<int> &v){

    for(int i = 0; i < v.size()-1; i++){

        if(v[i] > v[i+1]){

            return false;
        }
    }       

    return true;
}

void rellenarMatrices(vector<vector<double>> &m1, vector<vector<double>> &m2){

    for (int i = 0; i < m1.size(); i++) {

        for (int j = 0; j < m1.size(); j++)
        {
            m1[i][j] = (double)(95 + rand()%11)/100;
            m2[i][j] = (double)(95 + rand()%11)/100;
        }
    }
}

int fibonacci(int x){

    if((x==1)||(x==0)) {

        return(x);
    }

    else {

        return(fibonacci(x-1)+fibonacci(x-2));
    }    
}