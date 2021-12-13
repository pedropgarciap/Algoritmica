#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <string>

using namespace std;

class Material{

    private:

        string etiqueta;
        int volumen;
        int precio;

    public:

        Material(string etiqueta, int volumen, int precio){

            this->etiqueta = etiqueta;
            this->volumen = volumen;
            this->precio = precio;
        }

        inline void setEtiqueta(string etiqueta){this->etiqueta = etiqueta;}
        inline void setVolumen(int volumen){this->volumen = volumen;}
        inline void setPrecio(int precio){this->precio = precio;}

        inline string getEtiqueta(){return this->etiqueta;}
        inline int getVolumen(){return this->volumen;}
        inline int getPrecio(){return this->precio;}

        inline friend bool operator< (const Material &lhs, const Material &rhs){return lhs.precio < rhs.precio;}
        inline friend bool operator> (const Material &lhs, const Material &rhs){return lhs.precio > rhs.precio;}
};

#endif