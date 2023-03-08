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

int crearCarpeta(string path, bool p);

void MKDIR(Nodo *raiz){
    string path = "";
    bool flagR = false;

    list<Nodo>::iterator it;
    for (it = raiz->hijos.begin(); it != raiz->hijos.end(); ++it)
    {
        if (it->tipo == "path")
        {
            path = it->valor;
            path = regex_replace(path, regex("\""), "");
            path = regex_replace(path, regex("/home/"), "/home/li/Escritorio/");
        }
        else if (it->tipo == "r")
        {
            flagR = true;
        }
    }

    if(path != ""){
        string name = path.substr(path.find_last_of('/') + 1);
        if(name.length() <= 11){            
            if(loggedin){
                int result = crearCarpeta(path, flagR);
                if(result == 0)
                    cout << "\033[31mERROR: La carpeta ya existe\033[0m\n" << endl;
                else if(result == 1){
                    if(sesionActual.tipo_sistema == 3){
                        char aux[500];
                        char operacion[8];
                        char content[5];
                        strcpy(aux,path.c_str());
                        strcpy(operacion,"mkdir");
                        strcpy(content,"null");
                        guardarJournal(operacion,1,664,aux,content);
                    }
                    cout << "\033[32mCarpeta creada con exito\033[0m\n" << endl;
                }else if(result == 2)
                    cout << "\033[31mERROR: No se tienen permisos de escritura\033[0m\n" << endl;
                else if(result == 3){
                    cout << "\033[31mERROR: No existe el directorio y no esta el parametro -r\033[0m\n" << endl;
                }                
            }else
                cout << "\033[31mERROR: necesita iniciar sesion para poder ejecutar este comando\033[0m\n" << endl;
        }else
            cout << "\033[31mERROR: el nombre de la carpeta es mas grande de lo esperado\033[0m\n" << endl;
    }else
        cout << "\033[31mERROR: Parametro -path no definido\033[0m\n" << endl;
}


//Funcion para crear una carpeta
int crearCarpeta(string path, bool p){
    FILE *fp = fopen(sesionActual.direccion.c_str(),"rb+");

    SuperBloque super;
    fseek(fp,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);

    string aux = path;
    char auxPath[500];
    strcpy(auxPath,aux.c_str());
    int existe = buscarCarpetaArchivo(fp,auxPath);
    strcpy(auxPath,aux.c_str());
    int response = -1;

    if(existe != -1)
        response = 0;
    else
        response = nuevaCarpeta(fp,sesionActual.fit,p,auxPath,0);

    fclose(fp);

    return response;
}