#include <iostream>
#include <list>
#include <regex>
#include <fstream>
#include <string>
#include <vector>

#include "nodo.h"
#include "listaMount.cpp"

using namespace std;

extern ListaMount *listaMount;
extern bool loggedin;
extern Sesion sesionActual;

void COPY(Nodo *raiz){
    string path = "";
    string destino = "";

    list<Nodo>::iterator it;
    for (it = raiz->hijos.begin(); it != raiz->hijos.end(); ++it)
    {
        if (it->tipo == "path")
        {
            path = it->valor;
            path = regex_replace(path, regex("\""), "");
            path = regex_replace(path, regex("/home/"), "/home/li/Escritorio/");
        }
        else if (it->tipo == "destino")
        {
            destino = it->valor;
            destino = regex_replace(destino, regex("\""), "");
            destino = regex_replace(destino, regex("/home/"), "/home/li/Escritorio/");
        }
    }  

    if(path != ""){
        if(destino != ""){
            if(loggedin){
                cout << "estamos en sesion" << endl;
                
            }else
                cout << "ERROR: Para poder ejecutar este comando necesita iniciar sesion" << endl;
        }else
            cout << "\033[31mERROR: Parametro -destino no definido\033[0m\n" << endl;
    }else
        cout << "\033[31mERROR: Parametro -path no definido\033[0m\n" << endl;
}