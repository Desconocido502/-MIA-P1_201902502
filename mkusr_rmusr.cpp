#include <iostream>
#include <list>
#include <regex>

#include "nodo.h"
#include "listaMount.cpp"

using namespace std;

extern ListaMount *listaMount;
extern bool loggedin;
extern Sesion sesionActual;

bool buscarUsuario(string name);
int getIDUsr();
void eliminarUsuario(string name);

void MKUSR(Nodo *raiz){
    string user = "";
    string password = "";
    string grp = "";

    list<Nodo> :: iterator it;
    for(it = raiz->hijos.begin(); it != raiz->hijos.end(); ++it){

        if(it->tipo == "usuario"){
            user = it->valor;
            user = regex_replace(user, regex("\""), "");
        } else if(it->tipo == "password"){
            password = it->valor;
            password = regex_replace(password, regex("\""), "");
        } else if(it->tipo == "group"){
            grp = it->valor;
            grp = regex_replace(grp, regex("\""), "");
        } 
    }

    //cout << "usuario: " << user << endl;
    //cout << "password: " << password << endl;
    //cout << "grp: " << grp << endl;
    if(user != ""){
        if(password != ""){
            if(grp != ""){
                if(user.length() <= 10){
                    if(password.length() <= 10){
                        if(grp.length() <= 10){
                            if(loggedin){
                                if(sesionActual.id_user == 1 && sesionActual.id_grp == 1){ //Usuario root
                                    if(buscarGrupo(grp) != -1){
                                        if(!buscarUsuario(user)){
                                            int id = getIDUsr();
                                            string datos = to_string(id) + ",U,"+grp+","+user+","+password+"\n";
                                            agregarUsersTXT(datos);
                                            cout << "Usuario creado con exito" << endl;
                                            //Guardamos el registro en el journal si es un sistema EXT3
                                            if(sesionActual.tipo_sistema == 3){
                                                char aux[64];
                                                char operacion[10];
                                                char content[2];
                                                strcpy(aux, datos.c_str());
                                                strcpy(operacion,"mkusr");
                                                memset(content,0,2);
                                                guardarJournal(operacion, 0, 0, aux, content);
                                            }
                                        }else
                                            cout << "ERROR el usuario ya existe" <<endl;
                                    }else
                                        cout << "ERROR no se encuentra el grupo al que pertenecera el usuario " << endl;
                                }else
                                    cout << "ERROR solo el usuario root puede ejecutar este comando" << endl;
                            }else
                                cout << "ERROR necesita iniciar sesion para poder ejecutar este comando" << endl;
                        }else
                            cout << "ERROR grupo del usuario excede de los 10 caracteres permitidos" << endl;
                    }else
                        cout << "ERROR contrasena de usuario excede de los 10 caracteres permitidos" << endl;
                }else
                    cout << "ERROR nombre de usuario excede de los 10 caracteres permitidos" << endl;
            }else
                cout << "ERROR: parametro -grp no definido" << endl;
        }else
            cout << "ERROR: parametro -password no definido" << endl;
    }else
        cout << "ERROR: parametro -usuario no definido" << endl;
}

void RMUSR(Nodo *raiz){
    string user = raiz->hijos.front().valor;
    user = regex_replace(user, regex("\""), "");
    if(loggedin){
        if(sesionActual.id_user == 1 && sesionActual.id_grp == 1){//Usuario root
            if(buscarUsuario(user)){
                eliminarUsuario(user);
            }else
                cout << "ERROR el usuario no existe" << endl;
        }else
           cout << "ERROR solo el usuario root puede ejecutar este comando" << endl;
    }else
        cout << "ERROR necesita iniciar sesion para poder ejecutar este comando" << endl;
}

bool buscarUsuario(string name){
    FILE *fp = fopen(sesionActual.direccion.c_str(),"rb+");

    char cadena[400] = "\0";
    SuperBloque super;
    InodoTable inodo;

    fseek(fp,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);
    //Nos posicionamos en el inodo del archivo users.txt
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
        char user[12];
        char *end_token;
        char *token2 = strtok_r(token,",",&end_token);
        strcpy(id,token2);
        if(strcmp(id,"0") != 0){//Verificar que no sea un U/G eliminado
            token2 = strtok_r(nullptr,",",&end_token);
            strcpy(tipo,token2);
            if(strcmp(tipo,"U") == 0){
                token2 = strtok_r(nullptr,",",&end_token);
                token2 = strtok_r(nullptr,",",&end_token);
                strcpy(user,token2);

                if(strcmp(user,name.c_str()) == 0)
                    return true;
            }
        }
        token = strtok_r(nullptr,"\n",&end_str);
    }

    return false;
}

//Metodo para eliminar un usuario del archivo users.txt de una
void eliminarUsuario(string name){
    FILE *fp = fopen(sesionActual.direccion.c_str(),"rb+");

    SuperBloque super;
    InodoTable inodo;
    BloqueArchivo archivo;

    int col = 1;
    char actual;
    string palabra = "";
    int posicion = 0;
    int numBloque = 0;
    int id = -1;
    char tipo = '\0';
    string grupo = "";
    string usuario = "";
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
                    if(tipo == 'U'){
                        if(strcmp(usuario.c_str(),name.c_str()) == 0){
                            fseek(fp,super.s_block_start+static_cast<int>(sizeof(BloqueArchivo))*numBloque,SEEK_SET);
                            fread(&archivo,sizeof(BloqueArchivo),1,fp);
                            archivo.b_content[posicion] = '0';
                            fseek(fp,super.s_block_start+static_cast<int>(sizeof(BloqueArchivo))*numBloque,SEEK_SET);
                            fwrite(&archivo,sizeof(BloqueArchivo),1,fp);
                            cout << "Usuario eliminado con exito" << endl;
                            flag = true;
                            break;
                        }
                        usuario = "";
                        grupo = "";
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
                    else if(grupo == "")
                        grupo = palabra;
                    else if(usuario == "")
                        usuario = palabra;
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

//Funcion para obtener el id del nuevo usuario
int getIDUsr(){
    FILE *fp = fopen(sesionActual.direccion.c_str(),"rb+");

    char cadena[400] = "\0";
    int res = 0;
    SuperBloque super;
    InodoTable inodo;

    fseek(fp,sesionActual.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);
    //Nos posicionamos en el inodo del archivo users.txt
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
            if(strcmp(tipo,"U") == 0)
                res++;
        }
        token = strtok_r(nullptr,"\n",&end_str);
    }
    return ++res;
}
