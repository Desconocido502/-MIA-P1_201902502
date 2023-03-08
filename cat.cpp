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

bool buscarOcurrencia(string input);
void ejecutarCAT(string path);
bool permisosDeLectura(int permisos, bool flagUser, bool flagGroup);

void CAT(Nodo *raiz){
    
    //vector<string> paths;
    string path = "";

    list<Nodo> :: iterator it;
    for(it = raiz->hijos.begin(); it != raiz->hijos.end(); ++it){
        //Ocurrencias -> fileN donde N es un numero entero positivo
        if(buscarOcurrencia(it->tipo)){
            path = regex_replace(it->valor, regex("\""), "");
            path = regex_replace(path, regex("/home/"), "/home/li/Escritorio/");
            cout << "mostrando archivo: " << path << endl;
            ejecutarCAT(path);
            //paths.push_back(path);
        }
    }
/*
    for(string patH: paths){
        //cout << "path: " << patH << endl;
        ejecutarCAT(patH);
        cout<<endl;
    }
*/

}

void ejecutarCAT(string path){
   char auxPath[500];
   strcpy(auxPath,path.c_str());
   if(loggedin){
       FILE *fp = fopen(sesionActual.direccion.c_str(),"rb+");
       int carpeta = buscarCarpetaArchivo(fp,auxPath);
       if(carpeta != -1){
           SuperBloque super;
           InodoTable inodo;
           string cadena = "";
           fseek(fp,sesionActual.inicioSuper,SEEK_SET);
           fread(&super,sizeof(SuperBloque),1,fp);
           fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*carpeta,SEEK_SET);
           fread(&inodo,sizeof(InodoTable),1,fp);
           bool permisos = permisosDeLectura(inodo.i_perm,(inodo.i_uid == sesionActual.id_user),(inodo.i_gid == sesionActual.id_grp));
           if(permisos || (sesionActual.id_user == 1 && sesionActual.id_grp == 1)){
               for (int i = 0; i < 15; i++) {
                   if(inodo.i_block[i] != -1){
                       if(i < 12){
                           BloqueArchivo archivo;
                           fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[i],SEEK_SET);
                           fread(&archivo,sizeof(BloqueCarpeta),1,fp);
                           cadena += archivo.b_content;
                       }else if(i == 12){//Apuntador indirecto simple
                            BloqueApuntadores apuntador;
                            fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[i],SEEK_SET);
                            fread(&apuntador,sizeof(BloqueApuntadores),1,fp);
                            for(int j = 0; j < 16; j++){
                                if(apuntador.b_pointer[j] != -1){
                                    BloqueArchivo archivo;
                                    fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*apuntador.b_pointer[j],SEEK_SET);
                                    fread(&archivo,sizeof(BloqueArchivo),1,fp);
                                    cadena += archivo.b_content;
                                }

                            }
                       }
                   }
               }
               cout << "\033[1;34m" << cadena << "\033[0m" << endl;
            }else
               cout << "ERROR el usuario no tiene permisos de lectura" << endl;
        }else
           cout << "ERROR no se encuentra el archivo: " << path << endl;
       fclose(fp);
    }else
       cout << "ERROR para ejecutar este comando necesita iniciar sesion" << endl;
}

bool buscarOcurrencia(string input){
    regex pattern("file\\d+");
    smatch match;
    return (regex_search(input, match, pattern)) ? true : false;
}

//Funcion para verificar si el usuario actual tiene permisos para leer
bool permisosDeLectura(int permisos, bool flagUser, bool flagGroup){
    string aux = to_string(permisos);
    int propietario = aux[0] - '0';
    int grupo = aux[1] - '0';
    int otros = aux[2] - '0';

    if((propietario >= 3) && flagUser)
        return true;
    else if((grupo >= 3) && flagGroup)
        return true;
    else if(otros >= 3)
        return true;

    return false;
}