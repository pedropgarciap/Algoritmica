#include "calculosTiempos.hpp"

using namespace std;

void tiemposOrdenacionQuickSort(int nMin, int nMax, int incremento, int repeticiones, vector<double> &tiemposReales, vector<double> &numeroElementos){

    Clock reloj;
    double tiempotranscurrido = 0;

    for (int i = nMin; i <= nMax; i+=incremento){

        tiempotranscurrido = 0;

        for (int j = 0; j < repeticiones; j++){
            
            vector<int> v(i);
            rellenarVector(v);

            reloj.start();
            
            QuickSort(0, v.size()-1, v.size(), v);

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

void tiemposOrdenacionFusion(int nMin, int nMax, int incremento, int repeticiones, vector<double> &tiemposReales, vector<double> &numeroElementos){

    Clock reloj;
    double tiempotranscurrido = 0;

    for (int i = nMin; i <= nMax; i+=incremento){

        tiempotranscurrido = 0;

        for (int j = 0; j < repeticiones; j++){
            
            vector<int> v(i);
            rellenarVector(v);

            reloj.start();

            OrdenarFusion(v);

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
            tiempoEstimado+=a[j]*pow((numeroElementos[i]*log(numeroElementos[i])), j);
        }
        
        tiemposEstimados.push_back(tiempoEstimado);
    }
}

double calcularTiempoEstimadoPolinomico(const double &n, vector <double> &a){

    double estimado = 0;

    for (int i = 0; i < a.size(); i++)
    {
        estimado+=(a[i]*pow((n*log(n)),i));
    }

    return estimado;
}

void tiemposOrdenacionQuickSortDyV(int elementos, int incremento, int repeticiones, int minimo, int maximo, vector<double> &tiemposReales, vector<double> &numeroElementos){

    Clock reloj;
    double tiempotranscurrido = 0;

    for (int i = minimo; i <= maximo; i+=incremento){

        tiempotranscurrido = 0;

        for (int j = 0; j < repeticiones; j++){
            
            vector<int> v(elementos);

            rellenarVector(v);

            reloj.start();
            
            QuickSortDyV(0, v.size()-1, v.size(), v, i);

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

void tiemposOrdenacionFusionDyV(int elementos, int incremento, int repeticiones, int minimo, int maximo, vector<double> &tiemposReales, vector<double> &numeroElementos){

    Clock reloj;
    double tiempotranscurrido = 0;

    for (int i = minimo; i <= maximo; i+=incremento){

        tiempotranscurrido = 0;

        for (int j = 0; j < repeticiones; j++){
            
            vector<int> v(elementos);

            rellenarVector(v);

            reloj.start();

            if(i==0){

                OrdenarFusionDyV(v, 1);
            }

            else{

                OrdenarFusionDyV(v, i);
            }

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