#include "dinamicos.hpp"

using namespace std;

void dinamicoCambio(vector <Divisa> sistemaMonetario, vector <vector<int>> &solucion, int cambioi){

    for(int i = 0; i < sistemaMonetario.size(); i++){

        solucion[i][0] = 0;
    }

    for (int i = 0; i < sistemaMonetario.size(); i++){
        
        for (int j = 0; j <= cambioi; j++){
            
            if(i == 0 && j < sistemaMonetario[i].getCantidad()){

                solucion[i][j] = std::numeric_limits<int>::infinity();
            }

            else{

                if(i == 0){

                    solucion[i][j] = 1 + solucion[i][j-sistemaMonetario[0].getCantidad()];
                }

                else{

                    if(j < sistemaMonetario[i].getCantidad()){
                        
                        solucion[i][j] = solucion[i-1][j];
                    }

                    else{

                        solucion[i][j] = min(solucion[i - 1][j], 1 + solucion[i][j - sistemaMonetario[i].getCantidad()]);
                    }
                }
            }
        }
    }
}

void solucionCambio(vector <Divisa> sistemaMonetario, vector <vector<int>> solucion, int cambioi, vector<int> &cardinalidad){

    int i, j;

    i = sistemaMonetario.size()-1;
    j = cambioi;

    while (j>0)
    {
        if(i >= 1 && solucion[i][j]==solucion[i-1][j]){

            i--;
        }

        else{
            cardinalidad[i]++;
            j = j - sistemaMonetario[i].getCantidad();
        }
    }
}

void dinamicoMochila(vector <Material> listaMateriales, vector <vector<int>> &solucion, int volumen){

    for (int i = listaMateriales[0].getVolumen(); i <= volumen; i++){
        
        solucion[0][i] = listaMateriales[0].getVolumen() * listaMateriales[0].getPrecio();
    }

    for (int i = 0; i < listaMateriales.size(); i++){

        solucion[i][0] = 0;
    }
    
    for (int i = 1; i < listaMateriales.size(); i++){

        for (int j = 1; j <= volumen; j++){

            if(j < listaMateriales[i].getVolumen()){

                solucion[i][j] = solucion[i - 1][j]; 
            }

            else{

                solucion[i][j] = max(solucion[i - 1][j], (listaMateriales[i].getPrecio() * listaMateriales[i].getVolumen()) + solucion[i - 1][j - listaMateriales[i].getVolumen()]);
            }
        }
        
    }
    
}

void solucionMochila(vector <Material> listaMateriales, vector <vector<int>> solucion, int volumen, vector<int> &cardinalidad){

    int i, j;

    i = listaMateriales.size()-1;
    j = solucion[0].size()-1;

    while (j>0 && i>=0)
    {
        if(i > 0 && solucion[i][j]==solucion[i-1][j] ){

            i--;
        }

        else{
            
            if(j >= listaMateriales[i].getVolumen()){

                cardinalidad[i]++;
                j = j - listaMateriales[i].getVolumen();
            }
            
            i--;
        }


    }
}

void dinamicoCambioOpcional(vector <Divisa> sistemaMonetario, vector <vector<int>> &solucion, int cambioi){

    for(int i = 0; i < sistemaMonetario.size(); i++){

        solucion[i][0] = 0;
    }

    for (int i = 0; i < sistemaMonetario.size(); i++){
        
        for (int j = 0; j <= cambioi; j++){
            
            if(i == 0 && j < sistemaMonetario[i].getCantidad()){

                solucion[i][j] = std::numeric_limits<int>::infinity();
            }

            else{

                if(i == 0){

                    solucion[i][j] = 1 + solucion[i][j-sistemaMonetario[0].getCantidad()];
                }

                else{

                    if(j < sistemaMonetario[i].getCantidad()){
                        
                        solucion[i][j] = solucion[i-1][j];
                    }

                    else{

                        if(sistemaMonetario[i].getCardinalidad()!=0){

                            solucion[i][j] = min(solucion[i - 1][j], 1 + solucion[i][j - sistemaMonetario[i].getCantidad()]);
                            sistemaMonetario[i].setCardinalidad(sistemaMonetario[i].getCardinalidad()-1);
                        }

                        else{

                            solucion[i][j] = solucion[i-1][j-sistemaMonetario[i].getCantidad()]+1;
                        }
                    }
                }
            }
        }
    }
}

void solucionCambioOpcional(vector <Divisa> sistemaMonetario, vector <vector<int>> solucion, int cambioi, vector<int> &cardinalidad){

    int i, j;

    i = sistemaMonetario.size()-1;
    j = cambioi;

    while (j>0)
    {
        if(i >= 1 && solucion[i][j]==solucion[i-1][j]){

            i--;
        }

        else{

            if(sistemaMonetario[i].getCardinalidad() > 0){

                cardinalidad[i]++;
                j = j - sistemaMonetario[i].getCantidad();
                sistemaMonetario[i].setCardinalidad(sistemaMonetario[i].getCardinalidad()-1);
            }

            else{

                i--;
            }
        }
    }
}

