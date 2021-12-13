#include "ficheros.hpp"

using namespace std;

void leerDivisas(vector <Divisa> &sistemaMonetario){

    ifstream fichero ("sistemamonetario.txt");
    string line;

    if (fichero.is_open()){

        while (getline(fichero, line)){

            Divisa aux;
            aux.setCantidad(stoi(line));
            sistemaMonetario.push_back(aux);
        }
        
        fichero.close();
    }
}

void leerMateriales(vector <Material> &listaMateriales){

    ifstream fichero ("materialesmochila.txt");
    
    if (fichero.is_open()){

        while (!fichero.eof()){

            string etiqueta;
            int volumen;
            int precio;

            fichero >> etiqueta >> volumen >> precio;
            Material aux(etiqueta, volumen, precio);
            listaMateriales.push_back(aux);
        }
        
        fichero.close();
    }
}