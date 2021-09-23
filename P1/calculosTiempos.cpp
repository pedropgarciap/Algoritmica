#include "calculosTiempos.hpp"
#include "ClaseTiempo.cpp"

using namespace std;

void tiemposOrdenacionSeleccion(int nMin, int nMax, int incremento, int repeticiones, vector<double> &tiemposReales, vector<double> &numeroElementos){

    Clock reloj;
    double tiempotranscurrido = 0;

    for (int i = nMin; i <= nMax; i+=incremento){

        tiempotranscurrido = 0;

        for (int j = 0; j < repeticiones; j++){
            
            vector<int> v(i, 0);
            rellenarVector(v);

            reloj.start();
            seleccion(v);

            if(reloj.isStarted()){

                reloj.stop();
                tiempotranscurrido+=reloj.elapsed();   
            }
        }

        tiemposReales.push_back(tiempotranscurrido/repeticiones);
        numeroElementos.push_back(i);

        cout << "\nNumero de elementos: " << numeroElementos[numeroElementos.size()-1] << "\tMedia de tiempo por repeticion: " << tiemposReales[tiemposReales.size()-1]  << endl;
    }

    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
}

void calcularTiemposEstimadosPolinomico(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados){

    for (int i = 0; i < numeroElementos.size(); i++)
    {   
        double tiempoEstimado = 0;

        for (int j = 0; j < a.size(); j++)
        {
            tiempoEstimado+=a[j]*pow(numeroElementos[i], j);
        }
        
        tiemposEstimados.push_back(tiempoEstimado);
    }
}

double calcularTiempoEstimadoPolinomico(const double &n, vector <double> &a){

    double estimado = 0;

    for (int i = 0; i < a.size(); i++)
    {
        estimado+=(a[i]*pow(n,i));
    }

    return estimado;
}

void tiemposProductoMatrices(int nMin, int nMax, int incremento, int repeticiones, vector<double> &tiemposReales, vector<double> &numeroElementos){

    Clock reloj;
    double tiempotranscurrido = 0;

    for (int i = nMin; i <= nMax; i+=incremento){

        tiempotranscurrido = 0;

        for (int j = 0; j < repeticiones; j++){
            
            vector<vector<double>> m1(i, vector<double>(i));
            vector<vector<double>> m2(i, vector<double>(i));
            rellenarMatrices(m1, m2);

            reloj.start();
            productoMatrices(m1, m2);

            if(reloj.isStarted()){

                reloj.stop();
                tiempotranscurrido+=reloj.elapsed();   
            }
        }

        tiemposReales.push_back(tiempotranscurrido/repeticiones);
        numeroElementos.push_back(i);

        cout << "\nNumero de elementos: " << numeroElementos[numeroElementos.size()-1] << "\tMedia de tiempo por repeticion: " << tiemposReales[tiemposReales.size()-1]  << endl;
    }

    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void calcularTiemposEstimadosExponencial(const vector <double> &n, const vector <double> &a, vector <double> &tiemposEstimados){

    for (int i = 0; i < n.size(); i++)
    {   
        double tiempoEstimado = 0;

        for (int j = 0; j < a.size(); j++)
        {
            tiempoEstimado+=a[j]*pow(pow(2, n[i]), j);
        }
        
        tiemposEstimados.push_back(tiempoEstimado);
    }
}

double calcularTiempoEstimadoExponencial(const double &numeroElementos, const vector <double> &a){

    double estimado = 0;

    for (int i = 0; i < a.size(); i++)
    {
        estimado+=(a[i]*pow(pow(2, numeroElementos), i));
    }

    return estimado;
}

void tiemposFibonacci(int nMin, int nMax, int incremento, vector<double> &tiemposReales, vector<double> &numeroElementos){

    Clock reloj;
    double tiempotranscurrido = 0;

    for (int i = nMin; i <= nMax; i+=incremento){

        tiempotranscurrido = 0;

        reloj.start();
        
        fibonacci(i);

        if(reloj.isStarted()){

            reloj.stop();
            tiempotranscurrido+=reloj.elapsed();   
        }

        tiemposReales.push_back(tiempotranscurrido);
        numeroElementos.push_back(i);

        cout << "\nTermino: " << numeroElementos[numeroElementos.size()-1] << "\tMedia de tiempo por repeticion: " << tiemposReales[tiemposReales.size()-1]  << endl;
    }

    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}
