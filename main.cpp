#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "nodo.h"
#include "analizador/scanner.h"
#include "analizador/parser.h"

#include "struct.cpp"
#include "mkdisk.cpp"
#include "rmdisk.cpp"
#include "fdisk.cpp"
#include "listaMount.cpp"
#include "mount_unmount.cpp"
#include "rep-exec.cpp"
#include "mkfs.cpp"
#include "login.cpp"
#include "mkgrp_rmgrp.cpp"
#include "mkusr_rmusr.cpp"
#include "chmod.cpp"
#include "mkfile.cpp"
#include "cat.cpp"
#include "remove.cpp"
#include "edit.cpp"

ListaMount *listaMount = new ListaMount();
bool loggedin = false;
Sesion sesionActual;

extern int yyparse();
extern Nodo *raiz; // Root of tree

using namespace std;

void leerComando(char *);
void reconocerComando(Nodo *root);

int main()
{
    char comando[400];
    string str;
    while (true)
    {
        cout << "[MIA]@P1:~$ ";
        fgets(comando, sizeof(comando), stdin);
        str = comando;
        if (str.compare("Exit") == 0)
            break;
        leerComando(comando);
    }
    return 0;
}

void leerComando(char comando[400])
{
    if (comando[0] != '#')
    {
        // cout << comando << endl;
        YY_BUFFER_STATE buffer = yy_scan_string(comando);

        if (yyparse() == 0)
        {
            reconocerComando(raiz);
        }
        /*else{
            cout << "ERROR: comando no reconocido\n";
        }*/
    }
}

void reconocerComando(Nodo *root)
{
    if (root->tipo == "MKDISK")
    {
        Nodo n = root->hijos.front(); // traer el primer objeto de la lista
        MKDISK(&n);
    }
    else if (root->tipo == "EXECUTE")
    {
        EXEC(root);
    }
    else if (root->tipo == "EXIT")
    {
        exit(0); // EXIT_SUCCESS
    }
    else if (root->tipo == "REP")
    {
        Nodo n = root->hijos.front();
        REP(&n);
    }
    else if (root->tipo == "FDISK")
    {
        Nodo n = root->hijos.front();
        FDISK(&n);
    }
    else if (root->tipo == "RMDISK")
    {
        RMDISK(root);
    }
    else if (raiz->tipo == "MOUNT")
    {
        Nodo n = raiz->hijos.front();
        MOUNT(&n);
    }
    else if (raiz->tipo == "UNMOUNT")
    {
        UNMOUNT(raiz);
    }
    else if (raiz->tipo == "MKFS")
    {
        Nodo n = raiz->hijos.front();
        MKFS(&n);
    }
    else if (raiz->tipo == "LOGIN")
    {
        Nodo n = raiz->hijos.front();
        LOGIN(&n);
    }
    else if (raiz->tipo == "LOGOUT")
    {
        LOGOUT();
    }
    else if (raiz->tipo == "PAUSE")
    {
        cout << "Presione Enter para continuar..." << endl;
        cin.get();
    }else if(raiz->tipo == "MKGRP"){
        MKGRP(raiz);
    }else if(raiz->tipo == "RMGRP"){
        RMGRP(raiz);
    }else if(raiz->tipo == "MKUSR"){
        Nodo n = raiz->hijos.front();
        MKUSR(&n);
    }else if(raiz->tipo == "RMUSR"){
        RMUSR(raiz);
    }else if(raiz->tipo == "CHMOD"){ //!PENDIENTE
        Nodo n = raiz->hijos.front();
        CHMOD(&n);
    }else if(raiz->tipo == "MKFILE"){
        Nodo n = raiz->hijos.front();
        MKFILE(&n);
    }else if(raiz->tipo == "CAT"){
        Nodo n = raiz->hijos.front();
        CAT(&n);
    }else if(raiz->tipo == "REMOVE"){
        REMOVE(raiz);
    }else
    {
        cout << "Comando no reconocido" << endl;
    }
}