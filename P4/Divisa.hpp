#ifndef DIVISA_HPP
#define DIVISA_HPP

#include <string>

using namespace std;

class Divisa{

    private:

        int cantidad;
        int cardinalidad;
        string tipo;

    public:

        Divisa(){};

        Divisa(int cantidad, int cardinalidad){

            this->cantidad = cantidad; 
            this->cardinalidad = cardinalidad;
            this->tipo = (cantidad >= 500) ? "Billete" : "Moneda";
        };

        inline void setCantidad(int cantidad){this->cantidad = cantidad; this->tipo = (cantidad >= 500) ? "Billete" : "Moneda";}
        inline void setCardinalidad(int cardinalidad){this->cardinalidad = cardinalidad;}
        inline int getCantidad(){return this->cantidad;}
        inline string getTipo(){return this->tipo;}
        inline int getCardinalidad(){return this->cardinalidad;}

        inline friend bool operator< (const Divisa &lhs, const Divisa &rhs){return lhs.cantidad < rhs.cantidad;}
        inline friend bool operator> (const Divisa &lhs, const Divisa &rhs){return lhs.cantidad > rhs.cantidad;}
};

#endif