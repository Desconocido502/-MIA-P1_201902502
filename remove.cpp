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

void bloqueCarpetaArchivo(FILE *stream, char* path, int &block, int &posicion,int &pointer,int &posPointer);
void eliminarCarpetaArchivo(FILE *stream, int n);
bool permisosEscrituraRecursivo(FILE* stream, int n);

void REMOVE(Nodo *raiz){
    string path = raiz->hijos.front().valor;
    path = regex_replace(path, regex("\""), "");
    path = regex_replace(path, regex("/home/"), "/home/li/Escritorio/");

    char auxPath[500];
    strcpy(auxPath,path.c_str());
    if(loggedin){
        FILE *fp = fopen(sesionActual.direccion.c_str(),"rb+");
        int existe = buscarCarpetaArchivo(fp,auxPath);
        strcpy(auxPath,path.c_str());
        if(existe != -1){
            bool permisos = permisosEscrituraRecursivo(fp,existe);
            if(permisos){
                SuperBloque super;
                BloqueCarpeta carpeta;
                BloqueApuntadores apuntador;
                int bloque = 0;
                int posicion = 0;
                int pointer = -1;
                int posPointer = 0;
                fseek(fp,sesionActual.inicioSuper,SEEK_SET);
                fread(&super,sizeof(SuperBloque),1,fp);
                //Se obtiene el bloque y la posicion de la carpeta/archivo a eliminar
                bloqueCarpetaArchivo(fp,auxPath,bloque,posicion,pointer,posPointer);
                if(pointer == -1){
                    //Eliminar la referencia carpeta/archivo del bloque carpeta
                    fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bloque,SEEK_SET);
                    fread(&carpeta,sizeof(BloqueCarpeta),1,fp);
                    memset(carpeta.b_content[posicion].b_name,0,sizeof(carpeta.b_content[posicion].b_name));
                    carpeta.b_content[posicion].b_inodo = -1;
                    fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bloque,SEEK_SET);
                    fwrite(&carpeta,sizeof(BloqueCarpeta),1,fp);
                }else{
                    fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*pointer,SEEK_SET);
                    fread(&apuntador,sizeof(BloqueApuntadores),1,fp);
                    apuntador.b_pointer[posPointer] = -1;
                    fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*pointer,SEEK_SET);
                    fwrite(&apuntador,sizeof(BloqueApuntadores),1,fp);
                }
                //Eliminar la carpeta/archivo
                eliminarCarpetaArchivo(fp,existe);
                cout << "\033[1;32mRemovido con exito\033[0m" << endl;
            }else
                cout << "\033[1;31mERROR: alguna carpeta hijo no posee permisos de escritura\033[0m" << endl;
        }else
            cout << "\033[1;31mERROR: no se encuentra la direccion\033[0m" << endl;
        fclose(fp);
    }else
        cout << "\033[1;31mERROR: para ejecutar este comando necesita iniciar sesion\033[0m" << endl;
}

//Metodo para obtener el bloque y la posicion en el bloque donde se encuentra la carpeta/archivo
void bloqueCarpetaArchivo(FILE *stream, char* path, int &block, int &posicion,int &pointer,int &posPointer){
    SuperBloque super;
    InodoTable inodo;
    BloqueCarpeta carpeta;
    BloqueApuntadores apuntador;

    vector<string> lista;
    char *token = strtok(path,"/");
    int cont = 0;
    int numInodo = 0;

    while(token != nullptr){
        lista.push_back(token);
        cont++;
        token = strtok(nullptr,"/");
    }

    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,stream);
    numInodo = super.s_inode_start;//Inodo 0 '/'

    for (int cont2 = 0; cont2 < cont; cont2++) {
        fseek(stream,numInodo,SEEK_SET);
        fread(&inodo,sizeof(InodoTable),1,stream);
        int siguiente = 0;
        for(int i = 0; i < 12; i++){
            if(inodo.i_block[i] != -1){
                int byteBloque = byteInodoBloque(stream,inodo.i_block[i],'2');
                fseek(stream,byteBloque,SEEK_SET);
                if(i < 12){
                    fread(&carpeta,sizeof(BloqueCarpeta),1,stream);
                    for (int j = 0; j < 4; j++) {
                        if((cont2 == cont - 1) && (strcasecmp(carpeta.b_content[j].b_name,lista.at(cont2).c_str()) == 0)){//Tendria que ser la carpeta
                            block = inodo.i_block[i];
                            posicion = j;
                        }else if((cont2 != cont - 1) && (strcasecmp(carpeta.b_content[j].b_name,lista.at(cont2).c_str()) == 0)){
                            numInodo = byteInodoBloque(stream,carpeta.b_content[j].b_inodo,'1');
                            siguiente = 1;
                            break;
                        }
                    }
                }else if(i == 12){
                    fread(&apuntador,sizeof(BloqueApuntadores),1,stream);
                    for(int j = 0; j < 16; j++){
                        if(apuntador.b_pointer[j] != -1){
                            byteBloque = byteInodoBloque(stream,apuntador.b_pointer[j],'2');
                            fseek(stream,byteBloque,SEEK_SET);
                            fread(&carpeta,sizeof(BloqueCarpeta),1,stream);
                            for (int k = 0; k < 4; k++) {
                                if((cont2 == cont - 1) && (strcasecmp(carpeta.b_content[k].b_name,lista.at(cont2).c_str()) == 0)){//Tendria que ser la carpeta
                                    pointer = inodo.i_block[i];
                                    posPointer = j;
                                    block = apuntador.b_pointer[j];
                                    posicion = k;
                                }else if((cont2 != cont - 1) && (strcasecmp(carpeta.b_content[k].b_name,lista.at(cont2).c_str()) == 0)){
                                    numInodo = byteInodoBloque(stream,carpeta.b_content[k].b_inodo,'1');
                                    siguiente = 1;
                                    break;
                                }
                            }
                            if(siguiente == 1)
                                break;
                        }
                    }
                }
                if(siguiente == 1)
                    break;
            }
        }
    }


}

//Metodo para eliminar una carpeta o archivo
void eliminarCarpetaArchivo(FILE *stream, int n){
    SuperBloque super;
    InodoTable inodo;
    char buffer = '0';

    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,stream);
    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*n,SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,stream);

    if(inodo.i_type == '0'){//Carpeta
        for (int i = 0; i < 12; i++) {
            if(inodo.i_block[i] != -1){
                char byte = '0';
                fseek(stream,super.s_bm_block_start + inodo.i_block[i],SEEK_SET);
                byte = static_cast<char>(fgetc(stream));
                if(byte == '1'){//Bloque carpeta
                    BloqueCarpeta carpeta;
                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[i],SEEK_SET);
                    fread(&carpeta,sizeof(BloqueCarpeta),1,stream);
                    for (int j = 0; j < 4; j++) {
                        if(carpeta.b_content[j].b_inodo != -1){
                            if(strcmp(carpeta.b_content[j].b_name,".")!=0 && strcmp(carpeta.b_content[j].b_name,"..")!=0)
                                eliminarCarpetaArchivo(stream,carpeta.b_content[j].b_inodo);
                        }
                    }
                    fseek(stream,super.s_bm_block_start + inodo.i_block[i],SEEK_SET);
                    fputc(buffer,stream);
                }
            }
        }
        //Eliminar inodo del bitmap
        fseek(stream,super.s_bm_inode_start + n,SEEK_SET);
        fputc(buffer,stream);
    }else{//Archivo
        //Eliminar bloques del bitmap
        for (int i = 0; i < 15; i++) {
            if(inodo.i_block[i] != -1){
                fseek(stream,super.s_bm_block_start + inodo.i_block[i],SEEK_SET);
                fputc(buffer,stream);
            }
        }
        //Eliminar inodo del bitmap
        fseek(stream,super.s_bm_inode_start + n,SEEK_SET);
        fputc(buffer,stream);
    }

}

//Funcion para verificar si el usuario actual tiene permisos para de escritura en una carpeta/archivo,
//Si es una carpeta padre tiene que tener permisos en todas las hijas
bool permisosEscrituraRecursivo(FILE* stream, int n){
    SuperBloque super;
    InodoTable inodo;

    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,stream);
    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*n,SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,stream);

    bool permisos = permisosDeEscritura(inodo.i_perm,(inodo.i_uid == sesionActual.id_user),(inodo.i_gid == sesionActual.id_grp));
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
                                    response = permisosEscrituraRecursivo(stream,carpeta.b_content[j].b_inodo);
                            }
                        }
                    }else{//Archivo
                        InodoTable inodoAux;
                        fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*inodo.i_block[i],SEEK_SET);
                        fread(&inodoAux,sizeof(InodoTable),1,stream);
                        response = permisosDeEscritura(inodoAux.i_perm,(inodoAux.i_uid == sesionActual.id_user),(inodoAux.i_gid == sesionActual.id_grp));
                    }
                }
            }
            return response;
        }else //archivo
            return true;
    }else
        return false;
}