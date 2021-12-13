#include "voraces.hpp"

using namespace std;

void vorazCambio(vector <Divisa> sistemaMonetario, vector <Divisa> &solucion, vector <int> &cardinalidad, int cambioi){

    int i = 0, j = 0;

    while (cambioi > 0){

        if(cambioi / sistemaMonetario[i].getCantidad() >= 1){

            Divisa aux;
            aux.setCantidad(sistemaMonetario[i].getCantidad());
            solucion.push_back(aux);
            cardinalidad.push_back(cambioi / sistemaMonetario[i].getCantidad());
            cambioi%=sistemaMonetario[i].getCantidad(); 
        }

        i++;
    }
}


void vorazMochila(vector <Material> &listaMateriales, vector <Material> &solucion, int volumen){

    int resto = volumen;
    int i = 0;
    bool materialDisponible = true;

    do{

        Material iterador = listaMateriales[i];

        if(resto >= listaMateriales[i].getVolumen()){
            resto -= listaMateriales[i].getVolumen();
            solucion.push_back(iterador);
            listaMateriales[i].setVolumen(0);
        }

        else{

            iterador.setVolumen(resto);
            solucion.push_back(iterador);
            listaMateriales[i].setVolumen(listaMateriales[i].getVolumen() - resto);
            resto = 0;
        }

        if(i == (listaMateriales.size()-1))
        {
           materialDisponible = false; 
           cout << "No quedan mas materiales para llenar la mochila totalmente." << endl;
        }
        
        i++;

    }while(resto != 0 && materialDisponible);
}