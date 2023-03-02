#include <iostream>
#include <list>
#include <regex>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

#include "nodo.h"

using namespace std;

string directorio_(string direccion);
string extension_(string direccion);
void leerComando(char*);
void leerEntrada(string txt);
void reporteDisco(string pathDisk, string destinationReport);
string split_txt(string text);


void EXEC(Nodo *raiz){
    string path = raiz->hijos.front().valor;
    FILE *fp = fopen(path.c_str(), "r");
    if(fp){
        char line[400] = "";
        memset(line, 0, sizeof(line));
        while (fgets(line, sizeof(line), fp))
        {
            if(line[0] != '\n'){
                cout << line << endl;
                leerComando(line);
            }
            memset(line, 0, sizeof(line));
        }   
        fclose(fp);
    }else{
        cout << "ERROR: Al intentar abrir el archivo ocurrio un error..." << endl;
    }
}

string directorio_(string direccion){
    string delimiter = "/";
    size_t pos = 0;
    string res = "";
    while((pos = direccion.find(delimiter)) != string::npos){
        res += direccion.substr(0,pos) + "/";
        direccion.erase(0,pos + delimiter.length());
    }
    return res;
}

string extension_(string direccion){
    string aux = direccion;
    string delimiter = ".";
    size_t pos = 0;
    while((pos = aux.find(delimiter)) != string::npos){
        aux.erase(0, pos+delimiter.length());
    }
    return aux;
}

void REP(Nodo *raiz){
    string path = "";

    list<Nodo> :: iterator it;
    for (it = raiz->hijos.begin(); it != raiz->hijos.end(); ++it)
    {
        if(it->tipo == "path"){
            path = it->valor;
            path = regex_replace(path, regex("\""), "");
            path = regex_replace(path, regex("/home/"), "/home/li/Escritorio/");
        }
    }
    cout << path << endl;
    
    //SI TODO ESTA BIEN
    if(path != ""){
        string namePath = split_txt(path); //Se obtiene el nombre del archivo sin extension
        reporteDisco(path, namePath);
    }else{
        cout << "ERROR: parametro >path no definido" << endl;
    }
    
}   


//Graficar DISCO
void reporteDisco(string pathDisk, string destinationReport){
    FILE* fp;
    FILE* imageDisk;

    string path_str = pathDisk;

    if((fp = fopen(path_str.c_str(), "r"))){
        string x = destinationReport + ".dot";
        imageDisk = fopen(x.c_str(), "w");
        fprintf(imageDisk, "digraph G{\n\n");
        fprintf(imageDisk, "  tbl [\n    shape=box\n    label=<\n");
        fprintf(imageDisk, "     <table border=\'0\' cellborder=\'2\' width=\'600\' height=\"200\" color=\'LIGHTSTEELBLUE\' bgcolor=\"yellow\">\n");
        fprintf(imageDisk, "     <tr>\n");
        fprintf(imageDisk, "     <td height=\'200\' width=\'100\'> MBR </td>\n");   

        MBR mbr;
        fseek(fp, 0, SEEK_SET);
        fread(&mbr, sizeof(MBR), 1, fp);
        int sizeTotal = mbr.mbr_size;
        double use_size = 0;

        //RECORRER PARTICIONES
        for (int i = 0; i < 4; i++)
        {
            int tam_par = mbr.mbr_partition[i].part_size;
            if(mbr.mbr_partition[i].part_start != -1){
                fprintf(imageDisk, "     <td bgcolor=\'lightgreen\'  height=\'200\' width=\'200'> %s <br/> TAMAÑO: %d </td>\n",mbr.mbr_partition[i].part_name,tam_par);
            }
        }

        fprintf(imageDisk, "     </tr> \n     </table>        \n>];\n\n}");
        fclose(imageDisk);
        fclose(fp);
        string command = "dot -Tpng " + destinationReport + ".dot -o " + destinationReport + ".png";
        system(command.c_str());

        cout << "Reporte generado con exito" << endl;
        
    }
}

string split_txt(string text){
    stringstream text_to_split(text);
    string segment;
    vector<string> splited;

    while(getline(text_to_split, segment, '/')){
       splited.push_back(segment);
    }
    string clearName = splited.back();
    clearName = regex_replace(clearName, regex(".dsk"), "");
    return clearName;
}