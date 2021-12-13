#ifndef DIVISA_HPP
#define DIVISA_HPP

#include <string>

using namespace std;

class Divisa{

    private:

        int cantidad;
        string tipo;

    public:

        Divisa(){};

        inline void setCantidad(int cantidad){this->cantidad = cantidad; this->tipo = (cantidad >= 500) ? "Billete" : "Moneda";}
        inline int getCantidad(){return this->cantidad;}
        inline string getTipo(){return this->tipo;}

        inline friend bool operator< (const Divisa &lhs, const Divisa &rhs){return lhs.cantidad < rhs.cantidad;}
        inline friend bool operator> (const Divisa &lhs, const Divisa &rhs){return lhs.cantidad > rhs.cantidad;}
};

#endif