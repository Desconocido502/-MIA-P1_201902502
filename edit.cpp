#include <iostream>
#include <list>
#include <regex>
#include <vector>

#include "nodo.h"
#include "listaMount.cpp"

using namespace std;

extern ListaMount *listaMount;
extern bool loggedin;
extern Sesion sesionActual;

void EDIT(Nodo *raiz){
    string path = "";
    string cont = "";

    list<Nodo>::iterator it;
    for (it = raiz->hijos.begin(); it != raiz->hijos.end(); ++it)
    {
        if (it->tipo == "cont")
        {
            cont = it->valor;
            cont = regex_replace(cont, regex("\""), "");
        }
        else if (it->tipo == "path")
        {
            path = it->valor;
            path = regex_replace(path, regex("\""), "");
            path = regex_replace(path, regex("/home/"), "/home/li/Escritorio/");
        }
    }

    if (path != ""){
        if (cont != ""){
           if(loggedin){
            cout << "Estamos dentro de la sesion " << endl;
           }
        }else
            cout << "ERROR parametro -cont no definido" << endl;
    }else
        cout << "ERROR parametro -path no definido"<< endl;
    
}