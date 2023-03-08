#include <iostream>
#include <list>
#include <regex>
#include <fstream>
#include <string>
#include <vector>
#include <libgen.h> // Incluimos la biblioteca que contiene la función dirname()

#include "nodo.h"
#include "listaMount.cpp"

using namespace std;

extern ListaMount *listaMount;
extern bool loggedin;
extern Sesion sesionActual;

bool permisosLecturaRecursivo(FILE* stream, int n);
void moverCarpetaArchivo(FILE *stream, int carpeta, char* path,int destino);

void MOVE(Nodo *raiz)
{
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

    if (path != "")
    {
        if (destino != "")
        {
            if (loggedin)
            {
                //cout << "estamos en sesion" << endl;
                FILE *fp = fopen(sesionActual.direccion.c_str(), "rb+");
                char auxPath[500];
                char auxDest[500];
                strcpy(auxPath, path.c_str());
                strcpy(auxDest, destino.c_str());
                int carpeta = buscarCarpetaArchivo(fp, auxPath); // Carpeta/archivo a mover
                int destino = buscarCarpetaArchivo(fp, auxDest);
                if (carpeta != -1)
                {
                    if (destino != -1)
                    {
                        bool permisos = permisosLecturaRecursivo(fp, carpeta);
                        if (permisos)
                        {
                            SuperBloque super;
                            InodoTable inodo;
                            fseek(fp, sesionActual.inicioSuper, SEEK_SET);
                            fread(&super, sizeof(SuperBloque), 1, fp);
                            fseek(fp, super.s_inode_start + static_cast<int>(sizeof(InodoTable)) * destino, SEEK_SET);
                            fread(&inodo, sizeof(InodoTable), 1, fp);
                            bool permisos2 = permisosDeEscritura(inodo.i_perm, (inodo.i_uid == sesionActual.id_user), (inodo.i_gid == sesionActual.id_grp));
                            if (permisos2)
                            {
                                char auxP[500];
                                strcpy(auxP, path.c_str());
                                moverCarpetaArchivo(fp, carpeta, auxP, destino);
                            }
                            else
                                cout << "\033[31mERROR: El usuario actual no tiene permisos de escritura en la carpeta destino\033[0m\n" << endl;
                        }
                        else
                            cout << "\033[31mERROR: El usuario actual no tiene permisos en alguna de las carpetas hijas\033[0m\n" << endl;
                    }
                    else
                        cout << "\033[31mERROR: No existe la ruta a donde se movera la carpeta/archivo\033[0m\n" << endl;
                }
                else
                    cout << "\033[31mERROR: La carpeta/archivo a mover no existe\033[0m\n" << endl;
                fclose(fp);
            }
            else
                cout << "\033[31mERROR: Para poder ejecutar este comando necesita iniciar sesion\033[0m\n" << endl;
        }
        else
            cout << "\033[31mERROR: Parametro -destino no definido\033[0m\n"
                 << endl;
    }
    else
        cout << "\033[31mERROR: Parametro -path no definido\033[0m\n"
             << endl;
}

//Funcion para verificar si el usuario actual tiene permisos de lectura en una carpeta/archivo
bool permisosLecturaRecursivo(FILE* stream, int n){
    SuperBloque super;
    InodoTable inodo;

    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,stream);
    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*n,SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,stream);

    bool permisos = permisosDeLectura(inodo.i_perm,(inodo.i_uid == sesionActual.id_user),(inodo.i_gid == sesionActual.id_grp));
    if(permisos){
        bool response = true;
        if(inodo.i_type == '0'){//carpeta
            for (int i = 0; i < 12; i++) {//Solo apuntadores directos-falta revisar indirectos
                if(inodo.i_block[i] != -1){
                    char byte = '0';
                    fseek(stream,super.s_bm_block_start + inodo.i_block[i],SEEK_SET);
                    byte = static_cast<char>(fgetc(stream));
                    if(byte == '1'){//Carpeta
                        BloqueCarpeta carpeta;
                        fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[i],SEEK_SET);
                        fread(&carpeta,sizeof(BloqueCarpeta),1,stream);
                        for (int j = 0; j < 4; j++) {
                            if(carpeta.b_content[j].b_inodo != -1){
                                if(strcmp(carpeta.b_content[j].b_name,".")!=0 && strcmp(carpeta.b_content[j].b_name,"..")!=0)
                                    response = permisosLecturaRecursivo(stream,carpeta.b_content[j].b_inodo);
                            }
                        }
                    }else{//Archivo
                        InodoTable inodoAux;
                        fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*inodo.i_block[i],SEEK_SET);
                        fread(&inodoAux,sizeof(InodoTable),1,stream);
                        response = permisosDeLectura(inodoAux.i_perm,(inodoAux.i_uid == sesionActual.id_user),(inodoAux.i_gid == sesionActual.id_grp));
                    }
                }
            }
            return response;
        }else //archivo
            return true;
    }else
        return false;
}

//Metodo para mover una carpeta o archivo
void moverCarpetaArchivo(FILE *stream, int carpeta, char* path,int destino){
    SuperBloque super;
    InodoTable inodo;

    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,stream);
    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*carpeta,SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,stream);

    if(inodo.i_type == '0'){
        BloqueCarpeta carp;
        fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[0],SEEK_SET);
        fread(&carp,sizeof(BloqueCarpeta),1,stream);
        carp.b_content[1].b_inodo = destino;
        fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[0],SEEK_SET);
        fwrite(&carp,sizeof(BloqueCarpeta),1,stream);
    }

    BloqueCarpeta carpet;
    //Bloque y posicion de la carpeta/archivo a mover
    int bloque = 0;
    int posicion = 0;
    int pointer = -1;
    int posPointer = 0;
    bloqueCarpetaArchivo(stream,path,bloque,posicion,pointer,posPointer);
    //Nombre de la carpeta/archivo a mover y el inodo al que apunta
    char tempNombre[15];
    int aux = 0;
    bool flag = false;

    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bloque,SEEK_SET);
    fread(&carpet,sizeof(BloqueCarpeta),1,stream);
    strcpy(tempNombre,carpet.b_content[posicion].b_name);
    aux = carpet.b_content[posicion].b_inodo;
    //Borramos la referencia de esa carpeta/archivo
    memset(carpet.b_content[posicion].b_name,0,sizeof(carpet.b_content[posicion].b_name));
    carpet.b_content[posicion].b_inodo = -1;
    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bloque,SEEK_SET);
    fwrite(&carpet,sizeof(BloqueCarpeta),1,stream);

    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*destino,SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,stream);

    for(int i = 0; i < 12; i++){
        if(inodo.i_block[i] != -1){
            BloqueCarpeta carp;
            char byte = '0';
            fseek(stream,super.s_bm_block_start + inodo.i_block[i],SEEK_SET);
            byte = static_cast<char>(fgetc(stream));
            if(byte == '1'){
                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[i],SEEK_SET);
                fread(&carp,sizeof(BloqueCarpeta),1,stream);
                for(int j = 0; j < 4; j++){
                    if(carp.b_content[j].b_inodo == -1){
                        strcpy(carp.b_content[j].b_name,tempNombre);
                        carp.b_content[j].b_inodo = aux;
                        fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[i],SEEK_SET);
                        fwrite(&carp,sizeof(BloqueCarpeta),1,stream);
                        flag = true;
                        cout << "\033[32mCarpeta/archivo movido con exito\033[0m\n" << endl;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }else{//Se tiene que crear una carpeta
            char buffer = '1';
            //Guardamos registramos el bloque en el inodo
            int bitBloque = buscarBit(stream,'B',sesionActual.fit);
            inodo.i_block[i] = bitBloque;
            fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*destino,SEEK_SET);
            fwrite(&inodo,sizeof(InodoTable),1,stream);
            //Creamos la nueva carpeta
            BloqueCarpeta nuevaCarpeta;
            nuevaCarpeta.b_content[0].b_inodo = aux;
            nuevaCarpeta.b_content[1].b_inodo = -1;
            nuevaCarpeta.b_content[2].b_inodo = -1;
            nuevaCarpeta.b_content[3].b_inodo = -1;
            strcpy(nuevaCarpeta.b_content[0].b_name,tempNombre);
            strcpy(nuevaCarpeta.b_content[1].b_name,"");
            strcpy(nuevaCarpeta.b_content[2].b_name,"");
            strcpy(nuevaCarpeta.b_content[3].b_name,"");
            fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bitBloque,SEEK_SET);
            fwrite(&nuevaCarpeta,sizeof(BloqueCarpeta),1,stream);
            //Registramos el bloque en el bitmap
            fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
            fwrite(&buffer,sizeof(char),1,stream);
            //Modificamos el superbloque
            super.s_free_blocks_count = super.s_free_blocks_count - 1;
            super.s_first_blo = super.s_first_blo + 1;
            fseek(stream,sesionActual.inicioSuper,SEEK_SET);
            fwrite(&super,sizeof(SuperBloque),1,stream);
            cout << "Carpeta/archivo movido con exito" << endl;
            break;
        }
    }

}