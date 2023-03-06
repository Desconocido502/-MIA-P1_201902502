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

int buscarCarpetaArchivo(FILE *fp, char *path);
int byteInodoBloque(FILE *stream, int pos, char tipo);
void cambiarPermisosRecursivo(FILE *stream, int n, int permisos);
/*
                int propietario = ugo[0] - '0'; // Obtiene el valor numérico del primer carácter de la cadena
                int grupo = ugo[1] - '0'; // Obtiene el valor numérico del segundo carácter de la cadena
                int otros = ugo[2] - '0'; // Obtiene el valor numérico del tercer carácter de la cadena
*/
void CHMOD(Nodo *raiz)
{
    string path = "";
    string ugo = "";
    bool flagR = false;

    list<Nodo>::iterator it;
    for (it = raiz->hijos.begin(); it != raiz->hijos.end(); ++it)
    {

        if (it->tipo == "ugo")
        {
            ugo = it->valor;
        }
        else if (it->tipo == "path")
        {
            path = it->valor;
            path = regex_replace(path, regex("\""), "");
            // path = regex_replace(path, regex("/home/"), "/home/li/Escritorio/");
        }
        else if (it->tipo == "r")
        {
            flagR = true;
        }
    }

    cout << "path: " << path << endl;
    cout << "ugo: " << ugo << endl;
    cout << "r: " << flagR << endl;

    if (path != "")
    {
        if (ugo != "")
        {
            if (loggedin)
            {
                cout << "en sesion " << endl;
                int propietario = ugo[0] - '0'; // Obtiene el valor numérico del primer carácter de la cadena
                int grupo = ugo[1] - '0'; // Obtiene el valor numérico del segundo carácter de la cadena
                int otros = ugo[2] - '0'; // Obtiene el valor numérico del tercer carácter de la cadena
                if ((propietario >= 0 && propietario <= 7) && (grupo >= 0 && grupo <= 7) && (otros >= 0 && otros <= 7))
                {
                    char auxPath[500];
                    strcpy(auxPath, path.c_str());
                    FILE *fp = fopen(sesionActual.direccion.c_str(), "rb+");
                    SuperBloque super;
                    InodoTable inodo;
                    int existe = buscarCarpetaArchivo(fp, auxPath);
                    fseek(fp, sesionActual.inicioSuper, SEEK_SET);
                    fread(&super, sizeof(SuperBloque), 1, fp);
                    fseek(fp, super.s_inode_start + static_cast<int>(sizeof(InodoTable)) * existe, SEEK_SET);
                    fread(&inodo, sizeof(InodoTable), 1, fp);
                    if (existe != -1)
                    {
                        if ((sesionActual.id_user == 1 && sesionActual.id_grp == 1) || sesionActual.id_user == inodo.i_uid)
                        {
                            if (flagR)
                                cambiarPermisosRecursivo(fp, existe, stoi(ugo));
                            else
                            {
                                inodo.i_perm = stoi(ugo);
                                fseek(fp, super.s_inode_start + static_cast<int>(sizeof(InodoTable)) * existe, SEEK_SET);
                                fwrite(&inodo, sizeof(InodoTable), 1, fp);
                            }
                            cout << "Permisos cambiados exitosamente" << endl;
                        }
                        else
                            cout << "ERROR: Para cambiar los permisos debe ser el usuario root o ser dueno de la carpeta/archivo" << endl;
                    }
                    else
                        cout << "ERROR: La ruta no existe" << endl;
                    fclose(fp);
                }
                else
                    cout << "ERROR: alguno de los digitos se sale del rango predeterminado" << endl;
            }
            else
                cout << "ERROR: Se necesita iniciar sesion para poder ejecutar este comando" << endl;
        }
        else
            cout << "ERROR: Parametro -ugo no definido" << endl;
    }
    else
        cout << "ERROR: Parametro -path no definido" << endl;
}

// Funcion para verificar la existencia de una carpeta o archivo
int buscarCarpetaArchivo(FILE *stream, char *path)
{
    SuperBloque super;
    InodoTable inodo;
    BloqueCarpeta carpeta;
    BloqueApuntadores apuntador;

    vector<string> lista;
    char *token = strtok(path, "/");
    int cont = 0;
    int numInodo = 0;

    while (token != nullptr)
    {
        lista.push_back(token);
        cont++;
        token = strtok(nullptr, "/");
    }

    fseek(stream, sesionActual.inicioSuper, SEEK_SET);
    fread(&super, sizeof(SuperBloque), 1, stream);
    numInodo = super.s_inode_start; // Byte donde inicia el inodo

    for (int cont2 = 0; cont2 < cont; cont2++)
    {
        fseek(stream, numInodo, SEEK_SET);
        fread(&inodo, sizeof(InodoTable), 1, stream);
        int siguiente = 0;
        for (int i = 0; i < 15; i++)
        {
            if (inodo.i_block[i] != -1)
            { // Apuntadores directos
                int byteBloque = byteInodoBloque(stream, inodo.i_block[i], '2');
                fseek(stream, byteBloque, SEEK_SET);
                if (i < 12)
                {
                    fread(&carpeta, sizeof(BloqueCarpeta), 1, stream);
                    for (int j = 0; j < 4; j++)
                    {
                        if ((cont2 == cont - 1) && (strcasecmp(carpeta.b_content[j].b_name, lista.at(cont2).c_str()) == 0))
                        { // Tendria que ser la carpeta
                            return carpeta.b_content[j].b_inodo;
                        }
                        else if ((cont2 != cont - 1) && (strcasecmp(carpeta.b_content[j].b_name, lista.at(cont2).c_str()) == 0))
                        {
                            numInodo = byteInodoBloque(stream, carpeta.b_content[j].b_inodo, '1');
                            siguiente = 1;
                            break;
                        }
                    }
                }
                else if (i == 12)
                { // Apuntador indirecto
                    fread(&apuntador, sizeof(BloqueApuntadores), 1, stream);
                    for (int j = 0; j < 16; j++)
                    {
                        if (apuntador.b_pointer[j] != -1)
                        {
                            byteBloque = byteInodoBloque(stream, apuntador.b_pointer[j], '2');
                            fseek(stream, byteBloque, SEEK_SET);
                            fread(&carpeta, sizeof(BloqueCarpeta), 1, stream);
                            for (int k = 0; k < 4; k++)
                            {
                                if ((cont2 == cont - 1) && (strcasecmp(carpeta.b_content[k].b_name, lista.at(cont2).c_str()) == 0))
                                { // Tendria que ser la carpeta
                                    return carpeta.b_content[k].b_inodo;
                                }
                                else if ((cont2 != cont - 1) && (strcasecmp(carpeta.b_content[k].b_name, lista.at(cont2).c_str()) == 0))
                                {
                                    numInodo = byteInodoBloque(stream, carpeta.b_content[k].b_inodo, '1');
                                    siguiente = 1;
                                    break;
                                }
                            }
                            if (siguiente == 1)
                                break;
                        }
                    }
                }
                else if (i == 13)
                {
                }
                else if (i == 14)
                {
                }
                if (siguiente == 1)
                    break;
            }
        }
    }

    return -1;
}

/* Funcion que retorna el byte donde inicia un bloque o inodo */
int byteInodoBloque(FILE *stream, int pos, char tipo)
{
    SuperBloque super;
    fseek(stream, sesionActual.inicioSuper, SEEK_SET);
    fread(&super, sizeof(SuperBloque), 1, stream);
    if (tipo == '1')
    {
        return (super.s_inode_start + static_cast<int>(sizeof(InodoTable)) * pos);
    }
    else if (tipo == '2')
        return (super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta)) * pos);
    return 0;
}

/*
 * Metodo que sirve para cambiar los permisos de carpetas/archivos cuando se hace de manera recursiva
*/
void cambiarPermisosRecursivo(FILE* stream, int n, int permisos){
    SuperBloque super;
    InodoTable inodo;
    BloqueCarpeta carpeta;
    char byte ='0';

    fseek(stream,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,stream);
    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*n,SEEK_SET);
    fread(&inodo,sizeof(InodoTable),1,stream);
    inodo.i_perm = permisos;
    fseek(stream,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*n,SEEK_SET);
    fwrite(&inodo,sizeof(InodoTable),1,stream);

    for(int i = 0; i < 15; i++){
        if(inodo.i_block[i] != -1){
            fseek(stream,super.s_bm_block_start + inodo.i_block[i],SEEK_SET);
            byte = static_cast<char>(fgetc(stream));
            if(byte == '1'){
                fseek(stream,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[i],SEEK_SET);
                fread(&carpeta,sizeof(BloqueCarpeta),1,stream);
                for(int j = 0; j < 4; j++){
                    if(carpeta.b_content[j].b_inodo != -1){
                        if(strcmp(carpeta.b_content[j].b_name,".")!=0 &&  strcmp(carpeta.b_content[j].b_name,"..")!=0)
                            cambiarPermisosRecursivo(stream,carpeta.b_content[j].b_inodo,permisos);
                    }
                }
            }
        }
    }
}