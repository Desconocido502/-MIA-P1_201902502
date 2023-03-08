#include <iostream>
#include <list>
#include <regex>
#include <fstream>
#include <string>
#include <vector>
#include <libgen.h>  // Incluimos la biblioteca que contiene la función dirname()

#include "nodo.h"
#include "listaMount.cpp"

using namespace std;

extern ListaMount *listaMount;
extern bool loggedin;
extern Sesion sesionActual;

int crearArchivo(string path, bool r, int size, string cont);
int nuevoArchivo(FILE *stream, char fit, bool flagR, char *path, int size, string contenido, int index,char *auxPath);
int buscarContentLibre(FILE* stream,int numInodo,InodoTable &inodo,BloqueCarpeta &carpeta, BloqueApuntadores &apuntadores,int &content,int &bloque,int &pointer);
bool permisosDeEscritura(int permisos, bool flagUser, bool flagGroup);
int nuevaCarpeta(FILE *stream, char fit, bool flagR, char *path, int index);
BloqueCarpeta crearBloqueCarpeta();
InodoTable crearInodo(int size,char type,int perm);

void MKFILE(Nodo *raiz){
    string path = "";
    string cont = "";
    int size = 0;
    bool flagR = false;

    list<Nodo>::iterator it;
    for (it = raiz->hijos.begin(); it != raiz->hijos.end(); ++it)
    {
        if (it->tipo == "size")
        {
            size = stoi(it->valor);
            if (size < 0)
            {
                cout << "ERROR: PARAMETRO >SIZE, DEBE SER UN NUMERO POSITIVO Y MAYOR A CERO" << endl;
                return;
            }
        }else
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
        else if (it->tipo == "r")
        {
            flagR = true;
        }
    }
    //cout << "path: " << path << endl;
/*
    cout << "cont: " << cont << endl;
    cout << "size: " << size << endl;
    cout << "r: " << flagR << endl;
*/

    if(path != ""){
        string name = path.substr(path.find_last_of('/') + 1);
        if(name.length() <= 11){
            if(loggedin){
                int result = crearArchivo(path, flagR, size, cont);
                if(result == 1){
                    if(sesionActual.tipo_sistema == 3){
                        char aux[500];
                        char operacion[8];
                        char content[500];
                        strcpy(aux,path.c_str());
                        strcpy(operacion,"mkfile");
                        strcpy(content,cont.c_str());
                        if(cont.length() != 0)
                            guardarJournal(operacion,0,664,aux,content);
                        else{
                            strcpy(content,to_string(size).c_str());
                            guardarJournal(operacion,0,664,aux,content);
                        }
                    }
                    cout << "Archivo creado con exito" << endl;                   
                }else if(result == 2)
                    cout << "ERROR el usuario actual no tiene permisos de escritura" << endl;
                else if(result == 3)
                    cout << "ERROR el archivo contenido no existe" << endl;
                else if(result == 4)
                    cout << "ERROR no existe la ruta y no se tiene el parametro -r" << endl;
            }else
                cout << "ERROR necesita iniciar sesion para poder ejecutar este comando" << endl;
        }else
            cout << "ERROR el nombre del archivo es mas grande de lo esperado" << endl;
    }else
        cout << "ERROR: Parametro -path no definido" << endl;
}

/*
 * Funcion para crear un archivo
 * retorna 0 = ya existe
 *       | 1 = carpeta creada exitosamente
 *       | 2 = error por permisos
 *       | 3 = error archivo contenido no existe
 *       | 4 = error no existe el la ruta y no esta el parametro -r
*/
int crearArchivo(string path, bool r, int size, string cont){
    FILE *fp = fopen(sesionActual.direccion.c_str(),"rb+");

    SuperBloque super;
    fseek(fp,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);

    char auxPath[500];
    char auxPath2[500];
    strcpy(auxPath,path.c_str());
    strcpy(auxPath2,path.c_str());
    int existe = buscarCarpetaArchivo(fp,auxPath);
    //cout << "existe(buscarCarpeta/archivo):  " << existe << endl;
    strcpy(auxPath,path.c_str());
    int response = -1;

    if(existe != -1)
        response = 0;
    else
        response = nuevoArchivo(fp,sesionActual.fit,r,auxPath,size,cont,0,auxPath2);

    fclose(fp);
    return response;
}

/*
  * Funcion para crear un archivo
  * retorna 0 = ya existe
  *       | 1 = carpeta creada exitosamente
  *       | 2 = error por permisos
  *       | 3 = error archivo contenido no existe
  *       | 4 = error no existe el la ruta y no esta el parametro -r
*/
int nuevoArchivo(FILE *stream, char fit, bool flagR, char *path, int size, string contenido, int index,char *auxPath){
    SuperBloque super;
    InodoTable inodo,inodoNuevo;
    BloqueCarpeta carpeta, carpetaNueva;
    BloqueApuntadores apuntadores;
    vector<string> lista;
    char copiaPath[500];
    char directorio[500];
    char nombreCarpeta[80];
    string content = "";
    string contentSize = "0123456789";

    strcpy(copiaPath,path);
    strcpy(directorio, dirname(copiaPath));
    strcpy(copiaPath,path);
    strcpy(nombreCarpeta,basename(copiaPath));
    strcpy(copiaPath,path);
    char *token = strtok(path,"/");
    int cont = 0;
    int numInodo = index;
    int finalSize = size;

    while(token != nullptr){
        cont++;
        lista.push_back(token);
        token = strtok(nullptr,"/");
    }

    if(contenido.length() != 0){
        FILE *archivoCont;
        if((archivoCont = fopen(contenido.c_str(),"r"))){
            fseek(archivoCont,0,SEEK_END);
            finalSize = static_cast<int>(ftell(archivoCont));
            fseek(archivoCont,0,SEEK_SET);
            for (int i = 0; i < finalSize; i++)
                content += static_cast<char>(fgetc(archivoCont));
        }else
            return 3;
    }

    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,stream);

    if(cont == 1){
        int bloque = 0;
        int pointer = 0;
        int b_content = 0;
        int libre = buscarContentLibre(stream,numInodo,inodo,carpeta,apuntadores,b_content,bloque,pointer);

        if(libre == 1){
            bool permisos = permisosDeEscritura(inodo.i_perm,(inodo.i_uid == sesionActual.id_user),(inodo.i_gid == sesionActual.id_grp));
            if(permisos || (sesionActual.id_user == 1 && sesionActual.id_grp == 1)){
                char buffer = '1';
                char buffer2 = '2';
                char buffer3 = '3';
                //Agregamos el archivo al bloque correspondiente
                int bitInodo = buscarBit(stream,'I',fit);
                carpeta.b_content[b_content].b_inodo = bitInodo;
                strcpy(carpeta.b_content[b_content].b_name,nombreCarpeta);
                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[bloque],SEEK_SET);
                fwrite(&carpeta,sizeof(BloqueCarpeta),1,stream);
                //Creamos el nuevo inodo archivo
                inodoNuevo = crearInodo(0,'1',664);
                fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*bitInodo,SEEK_SET);
                fwrite(&inodoNuevo,sizeof(InodoTable),1,stream);
                //Registramos el inodo en el bitmap
                fseek(stream,super.s_bm_inode_start + bitInodo,SEEK_SET);
                fwrite(&buffer,sizeof(char),1,stream);
                //Si viene el parametro -size/-cont
                if(finalSize != 0){
                    double n = static_cast<double>(finalSize)/static_cast<double>(63);
                    int numBloques = static_cast<int>(ceil(n));
                    int caracteres = finalSize;
                    size_t charNum = 0;
                    size_t contChar = 0;
                    numInodo = buscarCarpetaArchivo(stream,auxPath);
                    for (int i = 0; i < numBloques; i++) {
                        BloqueArchivo archivo;
                        memset(archivo.b_content,0,sizeof(archivo.b_content));
                        if(i == 12){
                            int bitBloqueA = buscarBit(stream,'B',fit);//Apuntador
                            //Guardamos el bloque en el inodo archivo
                            fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                            fread(&inodo,sizeof(InodoTable),1,stream);
                            inodo.i_block[i] = bitBloqueA;
                            fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                            fwrite(&inodo,sizeof(InodoTable),1,stream);
                            //Registramos el bloque apuntador en el bitmap
                            fseek(stream,super.s_bm_block_start + bitBloqueA,SEEK_SET);
                            fwrite(&buffer3,sizeof(char),1,stream);
                            //Creamos el bloque de apuntadores como es simple solo se debe crear uno
                            int bitBloque = buscarBit(stream,'B',fit);//Primer bloque archivo
                            apuntadores.b_pointer[0] = bitBloque;
                            for(int i = 1; i < 16; i++)
                                apuntadores.b_pointer[i] = -1;
                            fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*bitBloqueA,SEEK_SET);
                            fwrite(&apuntadores,sizeof(BloqueApuntadores),1,stream);
                            //Empezamos con la creacion de bloques archivos
                            //Registramos el primer bloque en el bitmap
                            fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                            fwrite(&buffer2,sizeof(char),1,stream);
                            if(caracteres > 63){
                                for(int j = 0; j < 63; j++){
                                    if(content.length() != 0){//-cont
                                        archivo.b_content[j] = content[contChar];
                                        contChar++;
                                    }else{//-size
                                        archivo.b_content[j] = contentSize[charNum];
                                        charNum++;
                                        if(charNum == 10)
                                            charNum = 0;
                                    }
                                }
                                //Guardamos el bloque
                                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*bitBloque,SEEK_SET);
                                fwrite(&archivo,sizeof(BloqueArchivo),1,stream);
                                caracteres -= 63;
                            }else{
                                for (int j = 0; j < caracteres; j++) {
                                    if(content.length() != 0){
                                        archivo.b_content[j] = content[contChar];
                                        contChar++;
                                    }else{
                                        archivo.b_content[j] = contentSize[charNum];
                                        charNum++;
                                        if(charNum == 10)
                                            charNum = 0;
                                    }
                                }
                                //Guardamos el bloque
                                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*bitBloque,SEEK_SET);
                                fwrite(&archivo,sizeof(BloqueArchivo),1,stream);
                            }
                        }else if(i > 12 && i < 28){
                            int libre = 0;
                            fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                            fread(&inodo,sizeof(InodoTable),1,stream);
                            fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*inodo.i_block[12],SEEK_SET);
                            fread(&apuntadores,sizeof(BloqueApuntadores),1,stream);
                            for (int a = 0; a < 16; a++) {
                                if(apuntadores.b_pointer[a] == -1){
                                    libre = a;
                                    break;
                                }
                            }
                            int bitBloque = buscarBit(stream,'B',fit);
                            apuntadores.b_pointer[libre] = bitBloque;
                            fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*inodo.i_block[12],SEEK_SET);
                            fwrite(&apuntadores,sizeof(BloqueApuntadores),1,stream);
                            //Registramos el bloque en el bitmap
                            fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                            fwrite(&buffer2,sizeof(char),1,stream);
                            if(caracteres > 63){
                                for(int j = 0; j < 63; j++){
                                    if(content.length() != 0){//-cont
                                        archivo.b_content[j] = content[contChar];
                                        contChar++;
                                    }else{//-size
                                        archivo.b_content[j] = contentSize[charNum];
                                        charNum++;
                                        if(charNum == 10)
                                            charNum = 0;
                                    }
                                }
                                //Guardamos el bloque
                                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*bitBloque,SEEK_SET);
                                fwrite(&archivo,sizeof(BloqueArchivo),1,stream);
                                caracteres -= 63;
                            }else{
                                for (int j = 0; j < caracteres; j++) {
                                    if(content.length() != 0){
                                        archivo.b_content[j] = content[contChar];
                                        contChar++;
                                    }else{
                                        archivo.b_content[j] = contentSize[charNum];
                                        charNum++;
                                        if(charNum == 10)
                                            charNum = 0;
                                    }
                                }
                                //Guardamos el bloque
                                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*bitBloque,SEEK_SET);
                                fwrite(&archivo,sizeof(BloqueArchivo),1,stream);
                            }
                        }else if(i == 29){//Apuntador doble

                        }else{
                            int bitBloque = buscarBit(stream,'B',fit);
                            //Registramos el bloque en el bitmap
                            fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                            fwrite(&buffer2,sizeof(char),1,stream);
                            if(caracteres > 63){
                                for(int j = 0; j < 63; j++){
                                    if(content.length() != 0){//-cont
                                        archivo.b_content[j] = content[contChar];
                                        contChar++;
                                    }else{//-size
                                        archivo.b_content[j] = contentSize[charNum];
                                        charNum++;
                                        if(charNum == 10)
                                            charNum = 0;
                                    }
                                }
                                //Guardamos el bloque en el respectivo inodo archivo
                                fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                                fread(&inodo,sizeof(InodoTable),1,stream);
                                inodo.i_block[i] = bitBloque;
                                inodo.i_size = finalSize;
                                fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                                fwrite(&inodo,sizeof(InodoTable),1,stream);
                                //Guardamos el bloque
                                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*bitBloque,SEEK_SET);
                                fwrite(&archivo,sizeof(BloqueArchivo),1,stream);
                                caracteres -= 63;
                            }else{
                                for (int j = 0; j < caracteres; j++) {
                                    if(content.length() != 0){
                                        archivo.b_content[j] = content[contChar];
                                        contChar++;
                                    }else{
                                        archivo.b_content[j] = contentSize[charNum];
                                        charNum++;
                                        if(charNum == 10)
                                            charNum = 0;
                                    }
                                }
                                //Guardamos el bloque en el respectivo inodo archivo
                                fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                                fread(&inodo,sizeof(InodoTable),1,stream);
                                inodo.i_block[i] = bitBloque;
                                inodo.i_size = finalSize;
                                fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                                fwrite(&inodo,sizeof(InodoTable),1,stream);
                                //Guardamos el bloque
                                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*bitBloque,SEEK_SET);
                                fwrite(&archivo,sizeof(BloqueArchivo),1,stream);
                            }
                        }
                    }
                    //Modificamos el super bloque
                    super.s_free_blocks_count = super.s_free_blocks_count - numBloques;
                    super.s_free_inodes_count = super.s_free_inodes_count - 1;
                    super.s_first_ino = super.s_first_ino + 1;
                    super.s_first_blo = super.s_first_blo + numBloques;
                    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
                    fwrite(&super,sizeof(SuperBloque),1,stream);
                    return 1;
                }
                super.s_free_inodes_count = super.s_free_inodes_count - 1;
                super.s_first_ino = super.s_first_ino + 1;
                fseek(stream,sesionActual.inicioSuper,SEEK_SET);
                fwrite(&super,sizeof(SuperBloque),1,stream);
                return 1;
            }else
                return 2;
        }else{//Todos los bloques estan llenos
            fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
            fread(&inodo,sizeof(InodoTable),1,stream);
            for (int i = 0; i < 15; i++) {
                if(inodo.i_block[i] == -1){
                    bloque = i;
                    break;
                }
            }
            if(bloque == 12){//Apuntador simple indirecto
                bool permissions = permisosDeEscritura(inodo.i_perm,(inodo.i_uid == sesionActual.id_user),(inodo.i_gid == sesionActual.id_grp));
                if(permissions || (sesionActual.id_user == 1 && sesionActual.id_grp == 1) ){

                }else
                    return 2;
            }else if(bloque == 13){//Apuntador doble indirecto

            }else if(bloque == 14){//Apuntador triple indirecto

            }else{//Apuntadores directos
                bool permisos = permisosDeEscritura(inodo.i_perm,(inodo.i_uid == sesionActual.id_user),(inodo.i_gid == sesionActual.id_grp));
                if(permisos || (sesionActual.id_user == 1 && sesionActual.id_grp == 1)){
                    char buffer = '1';
                    char buffer2 = '2';
                    char buffer3 = '3';
                    int bitBloque = buscarBit(stream,'B',fit);
                    //Guardamos el bloque en el inodo
                    inodo.i_block[bloque] = bitBloque;
                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                    fwrite(&inodo,sizeof(InodoTable),1,stream);
                    //Creamos el nuevo bloque carpeta
                    int bitInodo = buscarBit(stream,'I',fit);
                    carpetaNueva.b_content[0].b_inodo = bitInodo;
                    carpetaNueva.b_content[1].b_inodo = -1;
                    carpetaNueva.b_content[2].b_inodo = -1;
                    carpetaNueva.b_content[3].b_inodo = -1;
                    strcpy(carpetaNueva.b_content[0].b_name,nombreCarpeta);
                    strcpy(carpetaNueva.b_content[1].b_name,"");
                    strcpy(carpetaNueva.b_content[2].b_name,"");
                    strcpy(carpetaNueva.b_content[3].b_name,"");
                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bitBloque,SEEK_SET);
                    fwrite(&carpetaNueva,sizeof(BloqueCarpeta),1,stream);
                    //Registramos el bloque en el bitmap
                    fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,stream);
                    //Creamos el nuevo inodo
                    inodoNuevo = crearInodo(0,'1',664);
                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*bitInodo,SEEK_SET);
                    fwrite(&inodoNuevo,sizeof(InodoTable),1,stream);
                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*bitInodo,SEEK_SET);
                    fwrite(&inodoNuevo,sizeof(InodoTable),1,stream);
                    //Registramos el inodo en el bitmap
                    fseek(stream,super.s_bm_inode_start + bitInodo,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,stream);
                    //Si viene el parametro -size/-cont
                    if(finalSize != 0){
                        double n = static_cast<double>(finalSize)/static_cast<double>(63);
                        int numBloques = static_cast<int>(ceil(n));
                        int caracteres = finalSize;
                        size_t charNum = 0;
                        size_t contChar = 0;
                        numInodo = buscarCarpetaArchivo(stream,auxPath);
                        for (int i = 0; i < numBloques; i++) {
                            BloqueArchivo archivo;
                            memset(archivo.b_content,0,sizeof(archivo.b_content));
                            if(i == 12){
                                int bitBloqueA = buscarBit(stream,'B',fit);//Apuntador
                                //Guardamos el bloque en el inodo archivo
                                fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                                fread(&inodo,sizeof(InodoTable),1,stream);
                                inodo.i_block[i] = bitBloqueA;
                                fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                                fwrite(&inodo,sizeof(InodoTable),1,stream);
                                //Registramos el bloque apuntador en el bitmap
                                fseek(stream,super.s_bm_block_start + bitBloqueA,SEEK_SET);
                                fwrite(&buffer3,sizeof(char),1,stream);
                                //Creamos el bloque de apuntadores como es simple solo se debe crear uno
                                int bitBloque = buscarBit(stream,'B',fit);//Primer bloque archivo
                                apuntadores.b_pointer[0] = bitBloque;
                                for(int i = 1; i < 16; i++)
                                    apuntadores.b_pointer[i] = -1;
                                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*bitBloqueA,SEEK_SET);
                                fwrite(&apuntadores,sizeof(BloqueApuntadores),1,stream);
                                //Empezamos con la creacion de bloques archivos
                                //Registramos el primer bloque en el bitmap
                                fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                                fwrite(&buffer2,sizeof(char),1,stream);
                                if(caracteres > 63){
                                    for(int j = 0; j < 63; j++){
                                        if(content.length() != 0){//-cont
                                            archivo.b_content[j] = content[contChar];
                                            contChar++;
                                        }else{//-size
                                            archivo.b_content[j] = contentSize[charNum];
                                            charNum++;
                                            if(charNum == 10)
                                                charNum = 0;
                                        }
                                    }
                                    //Guardamos el bloque
                                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*bitBloque,SEEK_SET);
                                    fwrite(&archivo,sizeof(BloqueArchivo),1,stream);
                                    caracteres -= 63;
                                }else{
                                    for (int j = 0; j < caracteres; j++) {
                                        if(content.length() != 0){
                                            archivo.b_content[j] = content[contChar];
                                            contChar++;
                                        }else{
                                            archivo.b_content[j] = contentSize[charNum];
                                            charNum++;
                                            if(charNum == 10)
                                                charNum = 0;
                                        }
                                    }
                                    //Guardamos el bloque
                                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*bitBloque,SEEK_SET);
                                    fwrite(&archivo,sizeof(BloqueArchivo),1,stream);
                                }
                            }else if(i > 12 && i < 28){
                                int libre = 0;
                                fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                                fread(&inodo,sizeof(InodoTable),1,stream);
                                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*inodo.i_block[12],SEEK_SET);
                                fread(&apuntadores,sizeof(BloqueApuntadores),1,stream);
                                for (int a = 0; a < 16; a++) {
                                    if(apuntadores.b_pointer[a] == -1){
                                        libre = a;
                                        break;
                                    }
                                }
                                int bitBloque = buscarBit(stream,'B',fit);
                                apuntadores.b_pointer[libre] = bitBloque;
                                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*inodo.i_block[12],SEEK_SET);
                                fwrite(&apuntadores,sizeof(BloqueApuntadores),1,stream);
                                //Registramos el bloque en el bitmap
                                fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                                fwrite(&buffer2,sizeof(char),1,stream);
                                if(caracteres > 63){
                                    for(int j = 0; j < 63; j++){
                                        if(content.length() != 0){//-cont
                                            archivo.b_content[j] = content[contChar];
                                            contChar++;
                                        }else{//-size
                                            archivo.b_content[j] = contentSize[charNum];
                                            charNum++;
                                            if(charNum == 10)
                                                charNum = 0;
                                        }
                                    }
                                    //Guardamos el bloque
                                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*bitBloque,SEEK_SET);
                                    fwrite(&archivo,sizeof(BloqueArchivo),1,stream);
                                    caracteres -= 63;
                                }else{
                                    for (int j = 0; j < caracteres; j++) {
                                        if(content.length() != 0){
                                            archivo.b_content[j] = content[contChar];
                                            contChar++;
                                        }else{
                                            archivo.b_content[j] = contentSize[charNum];
                                            charNum++;
                                            if(charNum == 10)
                                                charNum = 0;
                                        }
                                    }
                                    //Guardamos el bloque
                                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*bitBloque,SEEK_SET);
                                    fwrite(&archivo,sizeof(BloqueArchivo),1,stream);
                                }

                            }else if(i == 29){//Apuntador doble

                            }else{//Apuntadores simples
                                int bitBloque = buscarBit(stream,'B',fit);
                                //Registramos el bloque en el bitmap
                                fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                                fwrite(&buffer2,sizeof(char),1,stream);
                                if(caracteres > 63){
                                    for(int j = 0; j < 63; j++){
                                        if(content.length() != 0){//-cont
                                            archivo.b_content[j] = content[contChar];
                                            contChar++;
                                        }else{//-size
                                            archivo.b_content[j] = contentSize[charNum];
                                            charNum++;
                                            if(charNum == 10)
                                                charNum = 0;
                                        }
                                    }
                                    //Guardamos el bloque en el respectivo inodo archivo
                                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                                    fread(&inodo,sizeof(InodoTable),1,stream);
                                    inodo.i_block[i] = bitBloque;
                                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                                    fwrite(&inodo,sizeof(InodoTable),1,stream);
                                    //Guardamos el bloque
                                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*bitBloque,SEEK_SET);
                                    fwrite(&archivo,sizeof(BloqueArchivo),1,stream);
                                    caracteres -= 63;
                                }else{
                                    for (int j = 0; j < caracteres; j++) {
                                        if(content.length() != 0){
                                            archivo.b_content[j] = content[contChar];
                                            contChar++;
                                        }else{
                                            archivo.b_content[j] = contentSize[charNum];
                                            charNum++;
                                            if(charNum == 10)
                                                charNum = 0;
                                        }
                                    }
                                    //Guardamos el bloque en el respectivo inodo archivo
                                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                                    fread(&inodo,sizeof(InodoTable),1,stream);
                                    inodo.i_block[i] = bitBloque;
                                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                                    fwrite(&inodo,sizeof(InodoTable),1,stream);
                                    //Guardamos el bloque
                                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*bitBloque,SEEK_SET);
                                    fwrite(&archivo,sizeof(BloqueArchivo),1,stream);
                                }
                            }
                        }
                        //Modificamos el super bloque
                        super.s_free_blocks_count = super.s_free_blocks_count - numBloques;
                        super.s_free_inodes_count = super.s_free_inodes_count - 1;
                        super.s_first_ino = super.s_first_ino + 1;
                        super.s_first_blo = super.s_first_blo + numBloques;
                        fseek(stream,sesionActual.inicioSuper,SEEK_SET);
                        fwrite(&super,sizeof(SuperBloque),1,stream);
                        return 1;
                    }
                    super.s_free_inodes_count = super.s_free_inodes_count - 1;
                    super.s_first_ino = super.s_first_ino + 1;
                    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
                    fwrite(&super,sizeof(SuperBloque),1,stream);
                    return 1;
                }else
                    return 2;
            }
        }
    }else{//Directorio
        int existe = buscarCarpetaArchivo(stream,directorio);
        if(existe == -1){
            if(flagR){
                int index = 0;
                string aux = "";
                //Crear posibles carpetas inexistentes
                for (int i = 0; i < cont; i++) {
                    if(i == cont -1){
                        char dir[100] = "/";
                        strcat(dir,nombreCarpeta);
                        return nuevoArchivo(stream,fit,false,dir,size,contenido,index,auxPath);
                    }else{
                        aux += "/"+lista.at(i);
                        char dir[500];
                        char auxDir[500];
                        strcpy(dir,aux.c_str());
                        strcpy(auxDir,aux.c_str());
                        int carpeta = buscarCarpetaArchivo(stream,dir);
                        if(carpeta == -1){
                            nuevaCarpeta(stream,fit,false,auxDir,index);
                            strcpy(auxDir,aux.c_str());
                            index = buscarCarpetaArchivo(stream,auxDir);
                        }else
                            index = carpeta;
                    }
                }
            }else
                return 4;
        }else{//Crear el archivo en el directorio
            char dir[100] = "/";
            strcat(dir,nombreCarpeta);
            return nuevoArchivo(stream,fit,false,dir,size,contenido,existe,auxPath);
        }
    }

    return 0;
}

int buscarContentLibre(FILE* stream,int numInodo,InodoTable &inodo,BloqueCarpeta &carpeta, BloqueApuntadores &apuntadores,int &content,int &bloque,int &pointer){
    int libre = 0;
    SuperBloque super;
    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,stream);
    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,stream);
    //Buscamos un espacio libre en el bloque carpeta
    for(int i = 0; i < 15; i++){
        if(inodo.i_block[i] != -1){
            if(i == 12){//Apuntador indirecto simple
                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*inodo.i_block[i],SEEK_SET);
                fread(&apuntadores,sizeof(BloqueApuntadores),1,stream);
                for(int j = 0; j < 16; j++){
                    if(apuntadores.b_pointer[j] != -1){
                        fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*apuntadores.b_pointer[j],SEEK_SET);
                        fread(&carpeta,sizeof(BloqueCarpeta),1,stream);
                        for(int k = 0; k < 4; k++){
                            if(carpeta.b_content[k].b_inodo == -1){
                                libre = 1;
                                bloque = i;
                                pointer = j;
                                content = k;
                                break;
                            }
                        }
                    }
                    if(libre == 1)
                        break;
                }
            }else if(i == 13){//Apuntador indirecto doble

            }else if(i == 14){//Apuntador indirecto triple

            }else{//Apuntadores directos
                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[i],SEEK_SET);
                fread(&carpeta,sizeof(BloqueCarpeta),1,stream);
                for(int j = 0; j < 4; j++){
                    if(carpeta.b_content[j].b_inodo == -1){
                        libre = 1;
                        bloque = i;
                        content = j;
                        break;
                    }
                }
            }
        }
        if(libre == 1)
            break;
    }

    return libre;
}

//Funcion para verificar si el usuario actual tiene permisos para crear una carpeta o archivo en la carpeta padre
/*
* int permisos = permisos del inodo
* bool flagUser = bandera que indica si es el propietario de la carpeta padre
* bool flagGroup = bandera que indica si el usuario actual pertenece al grupo de la carpeta padre
* retorna true = si tiene permisos | false = no tiene permisos
*/
bool permisosDeEscritura(int permisos, bool flagUser, bool flagGroup){
    string aux = to_string(permisos);
    char propietario = aux[0];
    char grupo = aux[1];
    char otros = aux[2];

    if((propietario == '2' || propietario == '3' || propietario == '6' || propietario || '7') && flagUser)
        return true;
    else if((grupo == '2' || grupo == '3' || grupo == '6' || grupo == '7') && flagGroup)
        return true;
    else if(otros == '2' || otros == '3' || otros == '6' || otros == '7')
        return true;

    return false;
}

/*
 ** Funcion para crear un inodo
 * int size = tamano en bytes (para un inodo archivo)
 * char type = tipo de inodo (carpeta/archivo)
 * int perm = permisos del inodo
*/
InodoTable crearInodo(int size,char type,int perm){
    InodoTable inodo ;
    inodo.i_uid = sesionActual.id_user;
    inodo.i_gid = sesionActual.id_grp;
    inodo.i_size = size;
    inodo.i_atime = time(nullptr);
    inodo.i_ctime = time(nullptr);
    inodo.i_mtime = time(nullptr);
    for(int i = 0; i < 15; i++)
        inodo.i_block[i] = -1;
    inodo.i_type = type;
    inodo.i_perm = perm;
    return inodo;
}

/*
 * Funcion para crear una carpeta
 * FILE *stream;
 * char fit;
 * bool flagR;
 * char *path;
 * int index = numero de inodo
 * retorna 1 = carpeta creada
 *       | 2 = no se tienen permisos de escritura
 *       | 3 = no existe el directorio y no esta el parametro -r
*/
int nuevaCarpeta(FILE *stream, char fit, bool flagR, char *path, int index){
    SuperBloque super;
    InodoTable inodo,inodoNuevo;
    BloqueCarpeta carpeta, carpetaNueva, carpetaAux;
    BloqueApuntadores apuntadores;
    vector<string> lista;
    char copiaPath[500];
    char directorio[500];
    char nombreCarpeta[80];

    strcpy(copiaPath,path);
    strcpy(directorio,dirname(copiaPath));
    strcpy(copiaPath,path);
    strcpy(nombreCarpeta,basename(copiaPath));
    char *token = strtok(path,"/");
    int cont = 0;
    int numInodo = index;
    int response = 0;

    while(token != nullptr){
        cont++;
        lista.push_back(token);
        token = strtok(nullptr,"/");
    }

    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,stream);

    if(cont == 1){//Solo es una carpeta '/home' | '/archivos'
        int content = 0;
        int bloque = 0;
        int pointer = 0;
        int libre = buscarContentLibre(stream,numInodo,inodo,carpeta,apuntadores,content,bloque,pointer);
        if(libre == 1){
            if(bloque == 12){//Apuntador indirecto simple
                bool permissions = permisosDeEscritura(inodo.i_perm,(inodo.i_uid == sesionActual.id_user),(inodo.i_gid == sesionActual.id_grp));
                if(permissions || (sesionActual.id_user == 1 && sesionActual.id_grp == 1) ){
                    char buffer = '1';
                    int bitInodo = buscarBit(stream,'I',fit);
                    //Agregamos la carpeta al espacio libre en el bloque
                    carpeta.b_content[content].b_inodo = bitInodo;
                    strcpy(carpeta.b_content[content].b_name,nombreCarpeta);
                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*apuntadores.b_pointer[pointer],SEEK_SET);
                    fwrite(&carpeta,sizeof(BloqueCarpeta),1,stream);
                    //Creamos el nuevo inodo carpeta
                    inodoNuevo = crearInodo(0,'0',664);
                    int bitBloque = buscarBit(stream,'B',fit);
                    inodoNuevo.i_block[0] = bitBloque;
                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*bitInodo,SEEK_SET);
                    fwrite(&inodoNuevo,sizeof(InodoTable),1,stream);
                    //Guardamos el bit del inodo en el bitmap
                    fseek(stream,super.s_bm_inode_start + bitInodo,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,stream);
                    //Creamos el nuevo bloque carpeta
                    carpetaNueva = crearBloqueCarpeta();
                    carpetaNueva.b_content[0].b_inodo = bitInodo;
                    carpetaNueva.b_content[1].b_inodo = numInodo;
                    strcpy(carpetaNueva.b_content[0].b_name,".");
                    strcpy(carpetaNueva.b_content[1].b_name,"..");
                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bitBloque,SEEK_SET);
                    fwrite(&carpetaNueva,sizeof(BloqueCarpeta),1,stream);
                    //Guardamos el bit del bloque en el bitmap
                    fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,stream);
                    //Sobreescribimos el super bloque
                    super.s_free_inodes_count = super.s_free_inodes_count - 1;
                    super.s_free_blocks_count = super.s_free_blocks_count - 1;
                    super.s_first_ino = super.s_first_ino + 1;
                    super.s_first_blo = super.s_first_blo + 1;
                    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
                    fwrite(&super,sizeof(SuperBloque),1,stream);
                    return 1;
                }else
                    return 2;
            }else if(bloque == 13){//Apuntador indirecto doble

            }else if(bloque == 14){//Apuntador indirecto triple

            }else{//Apuntadores directos
                bool permisos = permisosDeEscritura(inodo.i_perm,(inodo.i_uid == sesionActual.id_user),(inodo.i_gid == sesionActual.id_grp));
                if(permisos || (sesionActual.id_user == 1 && sesionActual.id_grp == 1) ){
                    char buffer = '1';
                    int bitInodo = buscarBit(stream,'I',fit);
                    //Agregamos la carpeta al espacio libre en el bloque
                    carpeta.b_content[content].b_inodo = bitInodo;
                    strcpy(carpeta.b_content[content].b_name,nombreCarpeta);
                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[bloque],SEEK_SET);
                    fwrite(&carpeta,sizeof(BloqueCarpeta),1,stream);
                    //Creamos el nuevo inodo
                    inodoNuevo = crearInodo(0,'0',664);
                    int bitBloque = buscarBit(stream,'B',fit);
                    inodoNuevo.i_block[0] = bitBloque;
                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*bitInodo,SEEK_SET);
                    fwrite(&inodoNuevo,sizeof(InodoTable),1,stream);
                    //Creamos el nuevo bloque carpeta
                    carpetaNueva = crearBloqueCarpeta();
                    carpetaNueva.b_content[0].b_inodo = bitInodo;
                    carpetaNueva.b_content[1].b_inodo = numInodo;
                    strcpy(carpetaNueva.b_content[0].b_name,".");
                    strcpy(carpetaNueva.b_content[1].b_name,"..");
                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bitBloque,SEEK_SET);
                    fwrite(&carpetaNueva,sizeof(BloqueCarpeta),1,stream);
                    //Guardamos los bits en los bitmaps
                    fseek(stream,super.s_bm_inode_start + bitInodo,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,stream);
                    fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,stream);
                    //Sobreescribimos el super bloque
                    super.s_free_inodes_count = super.s_free_inodes_count - 1;
                    super.s_free_blocks_count = super.s_free_blocks_count - 1;
                    super.s_first_ino = super.s_first_ino + 1;
                    super.s_first_blo = super.s_first_blo + 1;
                    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
                    fwrite(&super,sizeof(SuperBloque),1,stream);
                    return 1;
                }else
                    return 2;
            }
        }else if(libre == 0){//Todos bloques estan llenos
            bool flag = false;//Primera vez
            pointer = -1;
            fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
            fread(&inodo,sizeof(InodoTable),1,stream);
            for (int i = 0; i < 15; i++) {
                if(i == 12){//Apuntador indirecto simple
                    if(inodo.i_block[i] == -1){//Primera vez
                        bloque = 12;
                        flag = true;
                        break;
                    }else{
                        fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*inodo.i_block[12],SEEK_SET);
                        fread(&apuntadores,sizeof(BloqueApuntadores),1,stream);
                        for(int j = 0; j < 16; j++){
                            if(apuntadores.b_pointer[j] == -1){
                                bloque = 12;
                                pointer = j;
                                break;
                            }
                        }
                    }
                    if(flag || pointer!= -1)
                        break;
                }else if(i == 13){

                }else if(i == 14){

                }else{
                    if(inodo.i_block[i] == -1){
                        bloque = i;
                        break;
                    }
                }
            }

            if(bloque == 12 && flag){//Apuntador indirecto simple
                bool permissions = permisosDeEscritura(inodo.i_perm,(inodo.i_uid == sesionActual.id_user),(inodo.i_gid == sesionActual.id_grp));
                if(permissions || (sesionActual.id_user == 1 && sesionActual.id_grp == 1) ){
                    char buffer = '1';
                    char buffer3 = '3';
                    //Guardamos el bloque en el inodo
                    int bitBloque = buscarBit(stream,'B',fit);//Apuntador
                    inodo.i_block[bloque] = bitBloque;
                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                    fwrite(&inodo,sizeof(InodoTable),1,stream);
                    //Escribimos el bit del bloque apuntador en el bitmap
                    fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                    fwrite(&buffer3,sizeof(char),1,stream);
                    //Creamos el bloque de apuntadores como es simple solo se debe crear uno
                    int bitBloqueCarpeta = buscarBit(stream,'B',fit);//Carpeta
                    apuntadores.b_pointer[0] = bitBloqueCarpeta;
                    for(int i = 1; i < 16; i++)
                        apuntadores.b_pointer[i] = -1;
                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*bitBloque,SEEK_SET);
                    fwrite(&apuntadores,sizeof(BloqueApuntadores),1,stream);
                    //Creamos la carpeta del apuntador
                    int bitInodo = buscarBit(stream,'I',fit);
                    carpetaAux = crearBloqueCarpeta();
                    carpetaAux.b_content[0].b_inodo = bitInodo;
                    strcpy(carpetaAux.b_content[0].b_name,nombreCarpeta);
                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bitBloqueCarpeta,SEEK_SET);
                    fwrite(&carpetaAux,sizeof(BloqueCarpeta),1,stream);
                    //Escribimos el bit del bloque carpeta en el bitmap
                    fseek(stream,super.s_bm_block_start + bitBloqueCarpeta,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,stream);
                    //Creamos el nuevo inodo carpeta
                    inodoNuevo = crearInodo(0,'0',664);
                    bitBloque = buscarBit(stream,'B',fit);//Carpeta
                    inodoNuevo.i_block[0] = bitBloque;
                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*bitInodo,SEEK_SET);
                    fwrite(&inodoNuevo,sizeof(InodoTable),1,stream);
                    //Escribimos el bit del inodo en el bitmap
                    fseek(stream,super.s_bm_inode_start + bitInodo,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,stream);
                    //Creamos el nuevo bloque carpeta
                    carpetaNueva = crearBloqueCarpeta();
                    carpetaNueva.b_content[0].b_inodo = bitInodo;
                    carpetaNueva.b_content[1].b_inodo = numInodo;
                    strcpy(carpetaNueva.b_content[0].b_name,".");
                    strcpy(carpetaNueva.b_content[1].b_name,"..");
                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bitBloque,SEEK_SET);
                    fwrite(&carpetaNueva,sizeof(BloqueCarpeta),1,stream);
                    //Guardamos el bit en el bitmap de bloques
                    fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,stream);
                    //Sobreescribimos el super bloque
                    super.s_free_inodes_count = super.s_free_inodes_count - 1;
                    super.s_free_blocks_count = super.s_free_blocks_count - 3;
                    super.s_first_ino = super.s_first_ino + 1;
                    super.s_first_blo = super.s_first_blo + 3;
                    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
                    fwrite(&super,sizeof(SuperBloque),1,stream);
                    return 1;
                }else
                    return 2;
            }else if(bloque == 12 && !flag){
                char buffer = '1';
                //Escribir el numero de bloque en el bloque de apuntadores
                int bitBloque = buscarBit(stream,'B',fit);
                apuntadores.b_pointer[pointer] = bitBloque;
                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*inodo.i_block[12],SEEK_SET);
                fwrite(&apuntadores,sizeof(BloqueApuntadores),1,stream);
                //Creamos el bloque auxiliar
                int bitInodo = buscarBit(stream,'I',fit);
                carpetaAux = crearBloqueCarpeta();
                carpetaAux.b_content[0].b_inodo = bitInodo;
                strcpy(carpetaAux.b_content[0].b_name,nombreCarpeta);
                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bitBloque,SEEK_SET);
                fwrite(&carpetaAux,sizeof(BloqueCarpeta),1,stream);
                //Escribimos el bit del bloque carpeta en el bitmap
                fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                fwrite(&buffer,sizeof(char),1,stream);
                //Creamos el nuevo inodo carpeta
                inodoNuevo = crearInodo(0,'0',664);
                inodoNuevo.i_uid = sesionActual.id_user;
                inodoNuevo.i_gid = sesionActual.id_grp;
                bitBloque = buscarBit(stream,'B',fit);//Carpeta
                inodoNuevo.i_block[0] = bitBloque;
                fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*bitInodo,SEEK_SET);
                fwrite(&inodoNuevo,sizeof(InodoTable),1,stream);
                //Escribimos el bit del inodo en el bitmap
                fseek(stream,super.s_bm_inode_start + bitInodo,SEEK_SET);
                fwrite(&buffer,sizeof(char),1,stream);
                //Creamos el nuevo bloque carpeta
                carpetaNueva = crearBloqueCarpeta();
                carpetaNueva.b_content[0].b_inodo = bitInodo;
                carpetaNueva.b_content[1].b_inodo = numInodo;
                strcpy(carpetaNueva.b_content[0].b_name,".");
                strcpy(carpetaNueva.b_content[1].b_name,"..");
                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bitBloque,SEEK_SET);
                fwrite(&carpetaNueva,sizeof(BloqueCarpeta),1,stream);
                //Guardamos el bit en el bitmap de bloques
                fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                fwrite(&buffer,sizeof(char),1,stream);
                //Sobreescribimos el super bloque
                super.s_free_inodes_count = super.s_free_inodes_count - 1;
                super.s_free_blocks_count = super.s_free_blocks_count - 2;
                super.s_first_ino = super.s_first_ino + 1;
                super.s_first_blo = super.s_first_blo + 2;
                fseek(stream,sesionActual.inicioSuper,SEEK_SET);
                fwrite(&super,sizeof(SuperBloque),1,stream);
                return 1;
            }
            else if(bloque == 13){//Apuntador indirecto doble

            }else if(bloque == 14){//Apuntador indirecto triple

            }else{//Apuntadores directos
                bool permissions = permisosDeEscritura(inodo.i_perm,(inodo.i_uid == sesionActual.id_user),(inodo.i_gid == sesionActual.id_grp));
                if(permissions || (sesionActual.id_user == 1 && sesionActual.id_grp == 1) ){
                    char buffer = '1';
                    int bitBloque = buscarBit(stream,'B',fit);
                    inodo.i_block[bloque] = bitBloque;
                    //Sobreescribimos el inodo
                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*numInodo,SEEK_SET);
                    fwrite(&inodo,sizeof(InodoTable),1,stream);
                    //Bloque carpeta auxiliar
                    int bitInodo = buscarBit(stream,'I',fit);
                    carpetaAux = crearBloqueCarpeta();
                    carpetaAux.b_content[0].b_inodo = bitInodo;
                    strcpy(carpetaAux.b_content[0].b_name,nombreCarpeta);
                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bitBloque,SEEK_SET);
                    fwrite(&carpetaAux,sizeof(BloqueCarpeta),1,stream);
                    //Escribimos el bit en el bitmap de blqoues
                    fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,stream);
                    //Creamos el nuevo inodo
                    inodoNuevo = crearInodo(0,'0',664);
                    bitBloque = buscarBit(stream,'B',fit);
                    inodoNuevo.i_block[0] = bitBloque;
                    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*bitInodo,SEEK_SET);
                    fwrite(&inodoNuevo,sizeof(InodoTable),1,stream);
                    //Escribimos el bit en el bitmap de inodos
                    fseek(stream,super.s_bm_inode_start + bitInodo,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,stream);
                    //Creamos el nuevo bloque carpeta
                    carpetaNueva = crearBloqueCarpeta();
                    carpetaNueva.b_content[0].b_inodo = bitInodo;
                    carpetaNueva.b_content[1].b_inodo = numInodo;
                    strcpy(carpetaNueva.b_content[0].b_name,".");
                    strcpy(carpetaNueva.b_content[1].b_name,"..");
                    fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*bitBloque,SEEK_SET);
                    fwrite(&carpetaNueva,sizeof(BloqueCarpeta),1,stream);
                    //Guardamos el bit en el bitmap de bloques
                    fseek(stream,super.s_bm_block_start + bitBloque,SEEK_SET);
                    fwrite(&buffer,sizeof(char),1,stream);
                    //Sobreescribimos el super bloque
                    super.s_free_inodes_count = super.s_free_inodes_count - 1;
                    super.s_free_blocks_count = super.s_free_blocks_count - 2;
                    super.s_first_ino = super.s_first_ino + 1;
                    super.s_first_blo = super.s_first_blo + 2;
                    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
                    fwrite(&super,sizeof(SuperBloque),1,stream);
                    return 1;
                }else
                    return 2;
            }

        }
    }else{//Es un directorio '/home/usac/archivos'
        //Verificar que exista el directorio
        int existe = buscarCarpetaArchivo(stream,directorio);
        if(existe == -1){
            if(flagR){
                int index = 0;
                string aux = "";
                //Crear posibles carpetas inexistentes
                for(int i = 0; i < cont; i++){
                    aux += "/"+lista.at(i);
                    char dir[500];
                    char auxDir[500];
                    strcpy(dir,aux.c_str());
                    strcpy(auxDir,aux.c_str());
                    int carpeta = buscarCarpetaArchivo(stream,dir);
                    if(carpeta == -1){
                        response = nuevaCarpeta(stream,fit,false,auxDir,index);
                        if(response == 2)
                            break;
                        strcpy(auxDir,aux.c_str());
                        index = buscarCarpetaArchivo(stream,auxDir);
                    }else
                        index = carpeta;
                }
            }else
                return 3;
        }else{//Solo crear la carpeta en el directorio
            char dir[100] = "/";
            strcat(dir,nombreCarpeta);
            return nuevaCarpeta(stream,fit,false,dir,existe);
        }
    }

    return response;
}

/* Funcion para crear un bloque carpeta vacia */
BloqueCarpeta crearBloqueCarpeta(){
    BloqueCarpeta carpeta;

    for(int i = 0; i < 4; i++){
        strcpy(carpeta.b_content[i].b_name,"");
        carpeta.b_content[i].b_inodo = -1;
    }

    return carpeta;
}