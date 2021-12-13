#include "algoritmos.hpp"

using namespace std;

void problemaCambio(){

    float cambiof;
    int cambioi, billetes = 0, monedas = 0;
    vector <Divisa> sistemaMonetario;
    vector <Divisa> solucion;
    vector <int> cardinalidad;

    cout << "Introduce la cantidad en euros a devolver (Ej. 651.34): ";
    cin >> cambiof;
    cout << endl;

    cambioi = cambiof * 100;
    
    leerDivisas(sistemaMonetario);

    sort(sistemaMonetario.begin(), sistemaMonetario.end(), greater<Divisa>());

    cout << "\nSISTEMA MONETARIO: " << endl;

    for(int i = 0; i < sistemaMonetario.size(); i++){

        cout << " Cantidad: " << sistemaMonetario[i].getCantidad() << " Tipo: " << sistemaMonetario[i].getTipo() << endl;
    }

    vorazCambio(sistemaMonetario, solucion, cardinalidad, cambioi);

    cout << "\nSOLUCION: " << endl;

    for(int i = 0; i < solucion.size(); i++){

        string tipo = (float)solucion[i].getCantidad()/100 >= 1 ? "Euro/s" : "Centimo/s";
        
        if(solucion[i].getTipo() == "Billete"){billetes+=cardinalidad[i];}
        else{monedas+=cardinalidad[i];}

        int cantidad = (float)solucion[i].getCantidad()/100 >= 1 ? (float)solucion[i].getCantidad()/100 : (float)solucion[i].getCantidad();

        cout << " Cantidad: " << cardinalidad[i] << " " << solucion[i].getTipo() << " de " << cantidad << " " << tipo << endl;
    }

    cout << "\nSe han devuelto la cantidad de " << billetes << " billetes y " << monedas << " monedas." << endl;
}

void problemaMochila(){

    int volumen, precio = 0;
    vector <Material> listaMateriales;
    vector <Material> solucion;

    cout << "Introduce el volumen de la mochila: ";
    cin >> volumen;

    leerMateriales(listaMateriales);

    sort(listaMateriales.begin(), listaMateriales.end(), greater<Material>());

    cout << "\nLISTA MATERIALES: " << endl;

    for(int i = 0; i < listaMateriales.size(); i++){

        cout << " Etiqueta: " << listaMateriales[i].getEtiqueta() << " Volumen: " << listaMateriales[i].getVolumen() << " Precio: " << listaMateriales[i].getPrecio() << endl;
    }

    vorazMochila(listaMateriales, solucion, volumen);

    cout << "\nCONTENIDO MOCHILA: " << endl;

    for(int i = 0; i < solucion.size(); i++){

        if(listaMateriales[i].getVolumen() == 0){

            cout << "Se han utilizado " << solucion[i].getVolumen() << " unidades de volumen del material con etiqueta " << solucion[i].getEtiqueta()  << " con precio " << solucion[i].getPrecio() << " por unidad." << endl;
        }

        else{

            cout << "Se han utilizado " << solucion[i].getVolumen() << " unidades de volumen (no se han usado todas) del material con etiqueta " << solucion[i].getEtiqueta()  << " con precio " << solucion[i].getPrecio() << " por unidad." << endl;
        }
    }

    for (int i = 0; i < solucion.size(); i++)
    {
        precio+=solucion[i].getVolumen()*solucion[i].getPrecio();
    }
    
    cout << "\nPRECIO TOTAL: " << endl;
    cout << precio << " unidades monetarias." << endl;
}