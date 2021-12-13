#include "algoritmos.hpp"

using namespace std;

void problemaCambio(){

    int cambioi, billetes = 0, monedas = 0;
    vector <Divisa> sistemaMonetario;

    cout << "Introduce la cantidad en centimos a devolver: ";
    cin >> cambioi;
    cout << endl;

    cout << "Ha introducido: " << cambioi << " centimos.";
    
    leerDivisas(sistemaMonetario);

    vector <vector<int>> solucion(sistemaMonetario.size(),  vector<int>(cambioi+1));
    vector <int> cardinalidad(sistemaMonetario.size());

    sort(sistemaMonetario.begin(), sistemaMonetario.end(), less<Divisa>());

    cout << "\nSISTEMA MONETARIO: " << endl;

    for(int i = 0; i < sistemaMonetario.size(); i++){

        cout << " Cantidad: " << sistemaMonetario[i].getCantidad() << " Tipo: " << sistemaMonetario[i].getTipo() << endl;
    }

    dinamicoCambio(sistemaMonetario, solucion, cambioi);
    /*
    cout << "\nSOLUCION: " << endl;

    for(int i = 0; i < solucion.size(); i++){

        for(int j = 0; j < solucion[i].size(); j++){

            cout << solucion[i][j] << "|";
        }

        cout << endl;
    }
    */
    solucionCambio(sistemaMonetario, solucion, cambioi, cardinalidad);

    cout << "----------------------------------------------------------------------------------" << endl;
    /*
    for (int i = 0; i < cardinalidad.size(); i++)
    {
        cout << cardinalidad[i] << "|";
    }
    */
    cout << "\n----------------------------------------------------------------------------------" << endl;
    cout << "\nEl cambio introducido es: " << cambioi << " centimos." << endl; 
    cout << "\n----------------------------------------------------------------------------------" << endl;
    cout << endl;

    for(int i = 0; i < cardinalidad.size(); i++){

        if(cardinalidad[i] != 0){

            string tipo = (float)sistemaMonetario[i].getCantidad()/100 >= 1 ? "Euro/s" : "Centimo/s";
        
            if(sistemaMonetario[i].getTipo() == "Billete"){billetes+=cardinalidad[i];}
            else{monedas+=cardinalidad[i];}

            int cantidad = (float)sistemaMonetario[i].getCantidad()/100 >= 1 ? (float)sistemaMonetario[i].getCantidad()/100 : (float)sistemaMonetario[i].getCantidad();

            cout << " Cantidad: " << cardinalidad[i] << " " << sistemaMonetario[i].getTipo() << " de " << cantidad << " " << tipo << endl;
        }
    }

    cout << "\nSe han devuelto la cantidad de " << billetes << " billetes y " << monedas << " monedas." << endl;
}

void problemaMochila(){

    int volumen, precio = 0, resto = 0;
    vector <Material> listaMateriales;

    cout << "Introduce el volumen de la mochila: ";
    cin >> volumen;

    leerMateriales(listaMateriales);

    vector <vector<int>> solucion(listaMateriales.size(),  vector<int>(volumen+1));
    vector <int> cardinalidad(listaMateriales.size());

    sort(listaMateriales.begin(), listaMateriales.end(), less<Material>());

    cout << "\nLISTA MATERIALES: " << endl;

    for(int i = 0; i < listaMateriales.size(); i++){

        cout << " Etiqueta: " << listaMateriales[i].getEtiqueta() << " Volumen: " << listaMateriales[i].getVolumen() << " Precio: " << listaMateriales[i].getPrecio() << endl;
    }

    dinamicoMochila(listaMateriales, solucion, volumen);
    /*
    cout << "----------------------------------------------------------------------------------" << endl;

    cout << "\nSOLUCION: " << endl;

    for(int i = 0; i < solucion.size(); i++){

        for(int j = 0; j < solucion[i].size(); j++){

            cout << solucion[i][j] << "|";
        }

        cout << endl;
    }
    */
    solucionMochila(listaMateriales, solucion, volumen, cardinalidad);

    cout << "----------------------------------------------------------------------------------" << endl;
    /*
    for (int i = 0; i < cardinalidad.size(); i++){

        cout << cardinalidad[i] << "|";
    }
    */
    cout << "\nCONTENIDO MOCHILA: " << endl;

    for(int i = cardinalidad.size()-1; i >= 0; i--){

        if(cardinalidad[i] != 0){

            cout << "Se han utilizado " << listaMateriales[i].getVolumen() << " unidades de volumen del material con etiqueta " << listaMateriales[i].getEtiqueta()  << " con precio " << listaMateriales[i].getPrecio() << " por unidad." << endl;
            precio += listaMateriales[i].getVolumen() * listaMateriales[i].getPrecio();
            resto += listaMateriales[i].getVolumen();
        }
    }
    


    cout << "\nPRECIO TOTAL: " << endl;
    cout << precio << " unidades monetarias." << endl;

    if(resto < volumen){
        
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "\nSe han dejado sin utilizar: " << endl;
        cout << volumen-resto << " unidades de volumen de la mochila." << endl;
    }
}

void problemaCambioOpcional(){

    int cambioi, billetes = 0, monedas = 0;
    vector <Divisa> sistemaMonetario;

    cout << "Introduce la cantidad en centimos a devolver: ";
    cin >> cambioi;
    cout << endl;

    cout << "Ha introducido: " << cambioi << " centimos.";
    
    leerDivisasOpcional(sistemaMonetario);

    vector <vector<int>> solucion(sistemaMonetario.size(),  vector<int>(cambioi+1));
    vector <int> cardinalidad(sistemaMonetario.size());

    sort(sistemaMonetario.begin(), sistemaMonetario.end(), less<Divisa>());

    cout << "\nSISTEMA MONETARIO: " << endl;

    for(int i = 0; i < sistemaMonetario.size(); i++){

        cout << " Cantidad: " << sistemaMonetario[i].getCantidad() << " Tipo: " << sistemaMonetario[i].getTipo() << " Cardinalidad: " << sistemaMonetario[i].getCardinalidad() << endl;
    }

    dinamicoCambioOpcional(sistemaMonetario, solucion, cambioi);
    /*
    cout << "\nSOLUCION: " << endl;

    for(int i = 0; i < solucion.size(); i++){

        for(int j = 0; j < solucion[i].size(); j++){

            cout << solucion[i][j] << "|";
        }

        cout << endl;
    }
    */
    solucionCambioOpcional(sistemaMonetario, solucion, cambioi, cardinalidad);

    cout << "----------------------------------------------------------------------------------" << endl;
    /*
    for (int i = 0; i < cardinalidad.size(); i++)
    {
        cout << cardinalidad[i] << "|";
    }
    */
    cout << "\n----------------------------------------------------------------------------------" << endl;
    cout << "\nEl cambio introducido es: " << cambioi << " centimos." << endl; 
    cout << "\n----------------------------------------------------------------------------------" << endl;
    cout << endl;

    for(int i = 0; i < cardinalidad.size(); i++){

        if(cardinalidad[i] != 0){

            string tipo = (float)sistemaMonetario[i].getCantidad()/100 >= 1 ? "Euro/s" : "Centimo/s";
        
            if(sistemaMonetario[i].getTipo() == "Billete"){billetes+=cardinalidad[i];}
            else{monedas+=cardinalidad[i];}

            int cantidad = (float)sistemaMonetario[i].getCantidad()/100 >= 1 ? (float)sistemaMonetario[i].getCantidad()/100 : (float)sistemaMonetario[i].getCantidad();

            cout << " Cantidad: " << cardinalidad[i] << " " << sistemaMonetario[i].getTipo() << " de " << cantidad << " " << tipo << endl;
        }
    }

    cout << "\nSe han devuelto la cantidad de " << billetes << " billetes y " << monedas << " monedas." << endl;
}