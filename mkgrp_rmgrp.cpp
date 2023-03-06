#include <iostream>
#include <list>
#include <regex>

#include "nodo.h"
#include "listaMount.cpp"

using namespace std;

extern ListaMount *listaMount;
extern bool loggedin;
extern Sesion sesionActual;

int getIDGrp();
void agregarUsersTXT(string);
int buscarBit(FILE *fp, char tipo, char fit);
void guardarJournal(char *operacion, int tipo, int permisos, char *nombre, char *content);
void eliminarGrupo(string name);

void MKGRP(Nodo *raiz)
{
    string name = raiz->hijos.front().valor;
    name = regex_replace(name, regex("\""), "");
    //cout << "loggedin: " << loggedin << endl;
    if (loggedin)
    {
        //cout << "dentro de sesion " << endl;
        //cout << "sesion actual id user: " << sesionActual.id_user << endl;
        //cout << "sesion actual id group: " << sesionActual.id_grp << endl;
        if (sesionActual.id_user == 1 && sesionActual.id_grp == 1)
        {
            //cout << "sesion Actual id's validos" << endl;
            if (name.length() <= 10)
            {
                //cout << "nombre de grupo valido" << endl;
                int grupo = buscarGrupo(name);
                //cout << "grupo: " << grupo << endl;
                if (grupo == -1)
                {
                    int idGRP = getIDGrp();
                    //cout << "idGRP: " << idGRP << endl;
                    string nuevoGrupo = to_string(idGRP) + ",G," + name + "\n";
                    agregarUsersTXT(nuevoGrupo);
                    cout << "Grupo creado con exito " << endl;
                    // Guardamos el registro en el journal si es un EXT3
                    if (sesionActual.tipo_sistema == 3)
                    {
                        char aux[64];
                        char operacion[10];
                        char content[2];
                        strcpy(aux, nuevoGrupo.c_str());
                        strcpy(operacion, "mkgrp");
                        memset(content, 0, 2);
                        guardarJournal(operacion, 0, 0, aux, content);
                    }
                    
                }
                else
                    cout << "ERROR ya existe un grupo con ese nombre" << endl;
            }
            else
                cout << "ERROR el nombre del grupo no puede exceder los 10 caracters" << endl;
        }
        else
            cout << "ERROR solo el usuario root puede ejecutar este comando" << endl;
    }
    else
        cout << "ERROR necesita iniciar sesion para poder ejecutar este comando" << endl;
}

void RMGRP(Nodo *raiz){
    string name = raiz->hijos.front().valor;
    name = regex_replace(name, regex("\""), "");
    if(loggedin){
        if(sesionActual.id_user == 1 && sesionActual.id_grp == 1){ //Usuario root
            int grupo = buscarGrupo(name);
            if(grupo != -1){
                eliminarGrupo(name);
            }else
                cout << "ERROR el grupo no existe" << endl;
        }else
           cout << "ERROR solo el usuario root puede ejecutar este comando" << endl;
    }else
        cout << "ERROR necesita iniciar sesion para poder ejecutar este comando" << endl;
}

// Funcion para obtener el id del nuevo grupo
int getIDGrp()
{
    //cout << "direccion Sesion Actual: " << sesionActual.direccion << endl;

    FILE *fp = fopen(sesionActual.direccion.c_str(),"rb+");

    char cadena[400] = "\0";
    int aux_id = -1;
    SuperBloque super;
    InodoTable inodo;
    fseek(fp,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);
    //Leemos el inodo del archivo users.txt
    fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)), SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,fp);

    for(int i = 0; i < 15; i++){
        if(inodo.i_block[i] != -1){
            BloqueArchivo archivo;
            fseek(fp,super.s_block_start,SEEK_SET);
            for(int j = 0; j <= inodo.i_block[i]; j++){
                fread(&archivo,sizeof(BloqueArchivo),1,fp);
            }
            strcat(cadena,archivo.b_content);
        }
    }

    fclose(fp);

    char *end_str;
    char *token = strtok_r(cadena,"\n",&end_str);
    while(token != nullptr){
        char id[2];
        char tipo[2];
        char *end_token;
        char *token2 = strtok_r(token,",",&end_token);
        strcpy(id,token2);
        if(strcmp(id,"0") != 0){//Verificar que no sea un U/G eliminado
            token2 = strtok_r(nullptr,",",&end_token);
            strcpy(tipo,token2);
            if(strcmp(tipo,"G") == 0){
                aux_id = atoi(id);
            }

        }
        token = strtok_r(nullptr,"\n",&end_str);
    }
    return ++aux_id;
}

void agregarUsersTXT(string datos)
{
    FILE *fp = fopen(sesionActual.direccion.c_str(), "rb+");

    SuperBloque super;
    InodoTable inodo;
    BloqueArchivo archivo;
    int blockIndex = 0;

    fseek(fp, sesionActual.inicioSuper, SEEK_SET);
    fread(&super, sizeof(SuperBloque), 1, fp);
    // Se lee el inodo del archivo users.txt
    fseek(fp, super.s_inode_start + static_cast<int>(sizeof(InodoTable)), SEEK_SET);
    fread(&inodo, sizeof(InodoTable), 1, fp);

    for (int i = 0; i < 12; i++)
    {
        if (inodo.i_block[i] != -1)
            blockIndex = inodo.i_block[i]; // Ultimo bloque utilizado del archivo
    }

    fseek(fp, super.s_block_start + static_cast<int>(sizeof(BloqueArchivo)) * blockIndex, SEEK_SET);
    fread(&archivo, sizeof(BloqueArchivo), 1, fp);
    int enUso = static_cast<int>(strlen(archivo.b_content));
    int libre = 63 - enUso;

    if (datos.length() <= libre)
    {
        strcat(archivo.b_content, datos.c_str());
        fseek(fp, super.s_block_start + static_cast<int>(sizeof(BloqueArchivo)) * blockIndex, SEEK_SET);
        fwrite(&archivo, sizeof(BloqueArchivo), 1, fp);
        fseek(fp, super.s_inode_start + static_cast<int>(sizeof(InodoTable)), SEEK_SET);
        fread(&inodo, sizeof(InodoTable), 1, fp);
        inodo.i_size = inodo.i_size + datos.length();
        inodo.i_mtime = time(nullptr);
        fseek(fp, super.s_inode_start + static_cast<int>(sizeof(InodoTable)), SEEK_SET);
        fwrite(&inodo, sizeof(InodoTable), 1, fp);
    }
    else
    {
        string aux = "";
        string aux2 = "";
        int i = 0;

        for (i = 0; i < libre; i++)
        {
            aux += datos.at(i);
        }

        for (; i < datos.length(); i++)
        {
            aux2 += datos.at(i);
        }

        // Guardamos lo que cabe en el primer bloque
        strcat(archivo.b_content, aux.c_str());
        fseek(fp, super.s_block_start + static_cast<int>(sizeof(BloqueArchivo)) * blockIndex, SEEK_SET);
        fwrite(&archivo, sizeof(BloqueArchivo), 1, fp);
        BloqueArchivo auxArchivo;
        strcpy(auxArchivo.b_content, aux2.c_str());
        int bit = buscarBit(fp, 'B', sesionActual.fit);
        /*Se guarda el bloque en el bitmap y en la tabla de bloques*/
        fseek(fp, super.s_bm_block_start + bit, SEEK_SET);
        fputc('2', fp);
        fseek(fp, super.s_block_start + (static_cast<int>(sizeof(BloqueArchivo)) * bit), SEEK_SET);
        fwrite(&auxArchivo, sizeof(InodoTable), 1, fp);
        /*Guardamos el modificado del nodo*/
        fseek(fp, super.s_inode_start + static_cast<int>(sizeof(InodoTable)), SEEK_SET);
        fread(&inodo, sizeof(InodoTable), 1, fp);
        inodo.i_size = inodo.i_size + datos.length();
        inodo.i_mtime = time(nullptr);
        inodo.i_block[blockIndex] = bit;
        fseek(fp, super.s_inode_start + static_cast<int>(sizeof(InodoTable)), SEEK_SET);
        fwrite(&inodo, sizeof(InodoTable), 1, fp);
        /*Guardamos la nueva cantidad de bloques libres y el primer bloque libre*/
        super.s_first_blo = super.s_first_blo + 1;
        super.s_free_blocks_count = super.s_free_blocks_count - 1;
        fseek(fp, sesionActual.inicioSuper, SEEK_SET);
        fwrite(&super, sizeof(SuperBloque), 1, fp);
    }
    fclose(fp);
}

// Funcion que devuelve el bit libre en el bitmap de inodos/bloques segun el ajuste
// retroan -1 si ya no hay bloques libres, o # bit libre en el bitmap
int buscarBit(FILE *fp, char tipo, char fit)
{
    SuperBloque super;
    int inicio_bm = 0;
    char tempBit = '0';
    int bit_libre = -1;
    int tam_bm = 0;

    fseek(fp, sesionActual.inicioSuper, SEEK_SET);
    fread(&super, sizeof(SuperBloque), 1, fp);

    if (tipo == 'I')
    {
        tam_bm = super.s_inodes_count;
        inicio_bm = super.s_bm_inode_start;
    }
    else if (tipo == 'B')
    {
        tam_bm = super.s_blocks_count;
        inicio_bm = super.s_bm_block_start;
    }

    /*----------------Tipo de ajuste a utilizar----------------*/
    if (fit == 'F')
    { // Primer ajuste
        for (int i = 0; i < tam_bm; i++)
        {
            fseek(fp, inicio_bm + i, SEEK_SET);
            tempBit = static_cast<char>(fgetc(fp));
            if (tempBit == '0')
            {
                bit_libre = i;
                return bit_libre;
            }
        }

        if (bit_libre == -1)
            return -1;
    }
    else if (fit == 'B')
    { // Mejor ajuste
        int libres = 0;
        int auxLibres = -1;

        for (int i = 0; i < tam_bm; i++)
        { // Primer recorrido
            fseek(fp, inicio_bm + i, SEEK_SET);
            tempBit = static_cast<char>(fgetc(fp));
            if (tempBit == '0')
            {
                libres++;
                if (i + 1 == tam_bm)
                {
                    if (auxLibres == -1 || auxLibres == 0)
                        auxLibres = libres;
                    else
                    {
                        if (auxLibres > libres)
                            auxLibres = libres;
                    }
                    libres = 0;
                }
            }
            else if (tempBit == '1')
            {
                if (auxLibres == -1 || auxLibres == 0)
                    auxLibres = libres;
                else
                {
                    if (auxLibres > libres)
                        auxLibres = libres;
                }
                libres = 0;
            }
        }

        for (int i = 0; i < tam_bm; i++)
        {
            fseek(fp, inicio_bm + i, SEEK_SET);
            tempBit = static_cast<char>(fgetc(fp));
            if (tempBit == '0')
            {
                libres++;
                if (i + 1 == tam_bm)
                    return ((i + 1) - libres);
            }
            else if (tempBit == '1')
            {
                if (auxLibres == libres)
                    return ((i + 1) - libres);
                libres = 0;
            }
        }

        return -1;
    }
    else if (fit == 'W')
    { // Peor ajuste
        int libres = 0;
        int auxLibres = -1;

        for (int i = 0; i < tam_bm; i++)
        { // Primer recorrido
            fseek(fp, inicio_bm + i, SEEK_SET);
            tempBit = static_cast<char>(fgetc(fp));
            if (tempBit == '0')
            {
                libres++;
                if (i + 1 == tam_bm)
                {
                    if (auxLibres == -1 || auxLibres == 0)
                        auxLibres = libres;
                    else
                    {
                        if (auxLibres < libres)
                            auxLibres = libres;
                    }
                    libres = 0;
                }
            }
            else if (tempBit == '1')
            {
                if (auxLibres == -1 || auxLibres == 0)
                    auxLibres = libres;
                else
                {
                    if (auxLibres < libres)
                        auxLibres = libres;
                }
                libres = 0;
            }
        }

        for (int i = 0; i < tam_bm; i++)
        {
            fseek(fp, inicio_bm + i, SEEK_SET);
            tempBit = static_cast<char>(fgetc(fp));
            if (tempBit == '0')
            {
                libres++;
                if (i + 1 == tam_bm)
                    return ((i + 1) - libres);
            }
            else if (tempBit == '1')
            {
                if (auxLibres == libres)
                    return ((i + 1) - libres);
                libres = 0;
            }
        }

        return -1;
    }

    return 0;
}

/* Metodo para guardar el registro de cada operacion que se realiza en el sistema */
void guardarJournal(char *operacion, int tipo, int permisos, char *nombre, char *content)
{
    SuperBloque super;
    Journal registro;
    strcpy(registro.journal_operation_type, operacion);
    registro.journal_type = tipo;
    strcpy(registro.journal_name, nombre);
    strcpy(registro.journal_content, content);
    registro.journal_date = time(nullptr);
    registro.journal_owner = sesionActual.id_user;
    registro.journal_permissions = permisos;
    FILE *fp = fopen(sesionActual.direccion.c_str(), "rb+");
    // Buscar el ultimo journal
    Journal registroAux;
    bool ultimo = false;
    fseek(fp, sesionActual.inicioSuper, SEEK_SET);
    fread(&super, sizeof(SuperBloque), 1, fp);
    int inicio_journal = sesionActual.inicioSuper + static_cast<int>(sizeof(SuperBloque));
    int final_journal = super.s_bm_inode_start;
    fseek(fp, inicio_journal, SEEK_SET);
    while ((ftell(fp) < final_journal) && !ultimo)
    {
        fread(&registroAux, sizeof(Journal), 1, fp);
        if (registroAux.journal_type != 0 && registroAux.journal_type != 1)
            ultimo = true;
    }
    fseek(fp, ftell(fp) - static_cast<int>(sizeof(Journal)), SEEK_SET);
    fwrite(&registro, sizeof(Journal), 1, fp);
    fclose(fp);
}

/*Metodo para borrar un grupo del archivo users.txt de una particion*/
void eliminarGrupo(string name){
    FILE *fp = fopen(sesionActual.direccion.c_str(),"rb+");

    SuperBloque super;
    InodoTable inodo;
    BloqueArchivo archivo;

    int col = 1;
    char actual;
    int posicion = 0;
    int numBloque = 0;
    int id = -1;
    char tipo = '\0';
    string grupo = "";
    string palabra = "";
    bool flag = false;


    fseek(fp,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);
    //Nos posicionamos en el inodo del archivo users.txt
    fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable)),SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,fp);

    for (int i = 0; i < 12; i++) {
        if(inodo.i_block[i] != -1){
            fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*inodo.i_block[i],SEEK_SET);
            fread(&archivo,sizeof(BloqueArchivo),1,fp);
            for(int j = 0; j < 63; j++){
                actual = archivo.b_content[j];
                if(actual=='\n'){
                    if(tipo == 'G'){
                        grupo = palabra;
                        if(strcmp(grupo.c_str(),name.c_str()) == 0){
                            fseek(fp,super.s_block_start+static_cast<int>(sizeof(BloqueArchivo))*numBloque,SEEK_SET);
                            fread(&archivo,sizeof(BloqueCarpeta),1,fp);
                            archivo.b_content[posicion] = '0';
                            fseek(fp,super.s_block_start+static_cast<int>(sizeof(BloqueArchivo))*numBloque,SEEK_SET);
                            fwrite(&archivo,sizeof(BloqueArchivo),1,fp);
                            cout << "Grupo eliminado con exito" << endl;
                            flag = true;
                            break;
                        }
                    }
                    col = 1;
                    palabra = "";
                }else if(actual != ','){
                    palabra += actual;
                    col++;
                }else if(actual == ','){
                    if(col == 2){
                        id = atoi(palabra.c_str());
                        posicion = j-1;
                        numBloque = inodo.i_block[i];
                    }
                    else if(col == 4)
                        tipo = palabra[0];
                    col++;
                    palabra = "";
                }
            }
            if(flag)
                break;
        }
    }

    fclose(fp);
}