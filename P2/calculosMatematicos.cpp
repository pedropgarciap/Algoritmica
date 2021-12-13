#include "calculosMatematicos.hpp"

using namespace std;

void ajustePolinomico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a){

    vector<vector<double> > matrizDatos;
    matrizDatos = vector<vector<double> >(a.size(), vector<double>(a.size()));

    vector<vector<double> > matrizDatosDependientes;
    matrizDatosDependientes = vector<vector<double> >(a.size(), vector<double>(1));

    vector<vector<double> > X;
    X = vector<vector<double> >(a.size(), vector<double>(1));

    vector<double> cambioVariable(numeroElementos.size());

    for(int i = 0; i < cambioVariable.size(); i++){

        cambioVariable[i] = numeroElementos[i]*(log(numeroElementos[i]));
    }

    for (int i = 0; i < matrizDatos.size(); i++)
    {
        for (int j = 0; j < matrizDatos[i].size(); j++)
        {
            matrizDatos[i][j] = sumatorio(cambioVariable, tiemposReales, i+j, 0);
        }

        matrizDatosDependientes[i][0] = sumatorio(cambioVariable, tiemposReales, i, 1);
    }

    resolverSistemaEcuaciones(matrizDatos, matrizDatosDependientes, a.size(), X);

    cout << "\nRecta: t(n) = ";

    for (int i = 0; i < a.size(); i++)
    {
        a[i] = X[i][0];

        if(i == 0){

            cout << a[i];
        }

        else if (i == 1){

            cout << " + " << a[i] << "*" << "n*log(n)"; 
        }

        else{

            cout << " + " << a[i] << "*" << "n^" << i; 
        }
        
    }
    
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
}
