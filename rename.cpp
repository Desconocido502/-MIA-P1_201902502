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

void RENAME(Nodo *raiz){
    string path = "";
    string name = "";

    list<Nodo>::iterator it;
    for (it = raiz->hijos.begin(); it != raiz->hijos.end(); ++it)
    {

        if (it->tipo == "path")
        {
            path = it->valor;
            path = regex_replace(path, regex("\""), "");
            path = regex_replace(path, regex("/home/"), "/home/li/Escritorio/");
        }
        else if (it->tipo == "name")
        {
            name = it->valor;
            name = regex_replace(name, regex("\""), "");
        }
    }

    if(path != ""){
        if(name != ""){
            if(loggedin){
                cout << "estamos en sesion " << endl;
                cout << "comando rename..." << endl;
            }
        }else
            cout << "ERROR parametro -name no definido" << endl;
    }else
        cout << "ERROR parametro -path no definido" << endl;
}