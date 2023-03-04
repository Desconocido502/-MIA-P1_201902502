#ifndef NODOMOUNT
#define NODOMOUNT

#include <iostream>

using namespace std;

class NodoMount{
    public: 
        string direccion, nombre;
        int num;
        NodoMount *siguiente;
        NodoMount(string, string, int);
};

NodoMount:: NodoMount(string direccion_, string nombre_, int num_){
    direccion = direccion_;
    nombre = nombre_;
    num = num_;
    siguiente = NULL;
}
//gsbbgssbgsbgs
#endif // NODOMOUNT