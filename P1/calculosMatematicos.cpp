#include "calculosMatematicos.hpp"

using namespace std;

void ajustePolinomico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a){

    vector<vector<double>> matrizDatos;
    matrizDatos = vector<vector<double>>(a.size(), vector<double>(a.size()));

    vector<vector<double>> matrizDatosDependientes;
    matrizDatosDependientes = vector<vector<double>>(a.size(), vector<double>(1));

    vector<vector<double>> X;
    X = vector<vector<double>>(a.size(), vector<double>(1));

    for (int i = 0; i < matrizDatos.size(); i++)
    {
        for (int j = 0; j < matrizDatos[i].size(); j++)
        {
            matrizDatos[i][j] = sumatorio(numeroElementos, tiemposReales, i+j, 0);
        }

        matrizDatosDependientes[i][0] = sumatorio(numeroElementos, tiemposReales, i, 1);
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

            cout << " + " << a[i] << "*" << "n"; 
        }

        else{

            cout << " + " << a[i] << "*" << "n^" << i; 
        }
        
    }
    
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
}

void productoMatrices(vector<vector<double>> &m1, vector<vector<double>> &m2){

    vector<vector<double>> m3(m1.size(), vector<double>(m1.size()));

    for (int i = 0; i < m1.size(); i++)
    {
        for (int j = 0; j < m1.size(); j++)
        {
            for (int k = 0; k < m1.size(); k++)
            {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void ajusteExponencial(const vector <double> &n, const vector <double> &tiemposReales, vector <double> &a){

    vector<vector<double>> matrizDatos;
    matrizDatos = vector<vector<double>>(a.size(), vector<double>(a.size()));

    vector<vector<double>> matrizDatosDependientes;
    matrizDatosDependientes = vector<vector<double>>(a.size(), vector<double>(1));

    vector<vector<double>> X;
    X = vector<vector<double>>(a.size(), vector<double>(1));

    for (int i = 0; i < matrizDatos.size(); i++)
    {
        for (int j = 0; j < matrizDatos[i].size(); j++)
        {
            matrizDatos[i][j] = sumatorioExponencial(n, tiemposReales, i+j, 0);
        }

        matrizDatosDependientes[i][0] = sumatorioExponencial(n, tiemposReales, i, 1);
    }

    cout << "Matriz independientes: " << endl;

    for (int i = 0; i < matrizDatos.size(); i++)
    {
        for (int j = 0; j < matrizDatos.size(); j++)
        {
            cout << "[" << matrizDatos[i][j] << "]";
        }
        
        cout << endl;
    }

    cout << "Matriz dependientes: " << endl;

    for (int i = 0; i < matrizDatosDependientes.size(); i++)
    {
        for (int j = 0; j < matrizDatosDependientes[i].size(); j++)
        {
            cout << "[" << matrizDatosDependientes[i][j] << "]";
        }
    }
    

    resolverSistemaEcuaciones(matrizDatos, matrizDatosDependientes, matrizDatos.size(), X);

    a[0] = X[0][0];
    a[1] = X[1][0];
 

    cout << "\nRecta: t(n) = " << a[0] << " + " << a[1] << "*2^n";
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
}
