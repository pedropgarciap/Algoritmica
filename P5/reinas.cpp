#include "reinas.hpp"

bool lugar(int k, vector <int> x){

    for (int i = 1; i < k; i++)
    {
        if(x[i] == x[k] || abs(x[i]-x[k]) == abs(i-k)){

            return false;
        }
    }
    
    return true;
}

int uniforme(vector<int> ok){

    return rand()%ok.size();
}

void nreinas(int n, vector <vector <int>> &soluciones){

    vector <int> x(n+1);
    int k = 1;

    while (k > 0){

        x[k] = x[k] + 1;

        while (x[k] <= n && !lugar(k, x)){

            x[k] = x[k] + 1;
        }

        if(x[k] <= n){

            if(k == n){

                soluciones.push_back(x);
            }

            else{

                k++;

                x[k] = 0;
            }
        }

        else{

            k--;
        }
    }
}

void nreinasBlocked(int n, vector <int> &solucion){

    vector <int> x(n+1);
    int k = 2;
    x[1] = n/2;

    while (k > 1){

        x[k] = x[k] + 1;

        while (x[k] <= n && !lugar(k, x)){

            x[k] = x[k] + 1;
        }

        if(x[k] <= n){
            
            if(k == n){

                solucion = x;
                return;
            }

            else{

                k++;
                x[k] = 0;
            }
        }

        else{

            k--;
        }
    }
}

void nreinasLasVegas(int n, vector <int> &solucion, bool &exito){
    
    solucion.resize(n+1, 0);
    vector <int> ok;
    int contador;
    int columna;

    for(int k = 1; k <= n; k++){

        contador = 0;
        ok.clear();

        for(int j = 1; j <= n; j++){

            solucion[k] = j;

            if(lugar(k,solucion)){

                contador++;
                ok.push_back(j);
            }
        }

        if(contador == 0){
    
            break;
        }

        int columna = ok[uniforme(ok)];
        solucion[k] = columna;
    }
    
    if(contador == 0){

        exito = false;
    }

    else{

        exito = true;
    }
}

void nreinasCoste(int n, vector <int> &solucion, int &podas){

    vector <int> x(n+1);
    int minimum_cost = numeric_limits<int>::max();
    int cost = 0;
    int k = 1;

    while (k > 0){

        x[k] = x[k] + 1;

        while (x[k] <= n && !lugar(k, x)){

            x[k] = x[k] + 1;
        }

        //posicion correcta
        if(x[k] <= n) {

            //ultima reina
            if (k == n) {
                /*
                int coste = 0;

                for(int i = 1; i < x.size(); i++){

                    cout << "[" << x[i] << "]";
                    coste = coste + x[i]*i;
                }

                cout << "Coste: " << coste;
                cout << "Coste acumulado: " << cost;
                cout << endl;*/

                if (cost + x[k] * k < minimum_cost) {

                    minimum_cost = cost + x[k] * k;
                    solucion = x;
                } 
                /*
                else {

                    podas++;
                }
                */
            }

                //no ultima reina
            else {

                if (cost + x[k] * k < minimum_cost) {

                    cost = cost + x[k] * k;
                    k++;
                    x[k] = 0;
                }

                else {

                    podas++;
                    k--;
                    cost = cost - x[k] * k;
                }

            }
        }
        //posicion incorrecta
        else{

            k--;
            cost = cost - x[k]*k;
        }
    }
}