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
#include "listaMount.cpp"
#include "reportes.cpp"

using namespace std;

string directorio_(string direccion);
string extension_(string direccion);
void leerComando(char *);
void leerEntrada(string txt);
string fileName(string direccion);


void reporteDisco(string pathDisk, string destinationReport);
string split_txt(string text);

void EXEC(Nodo *raiz)
{
    string path = raiz->hijos.front().valor;
    FILE *fp = fopen(path.c_str(), "r");
    if (fp)
    {
        char line[400] = "";
        memset(line, 0, sizeof(line));
        while (fgets(line, sizeof(line), fp))
        {
            if (line[0] != '\n')
            {
                cout << line << endl;
                leerComando(line);
            }
            memset(line, 0, sizeof(line));
        }
        fclose(fp);
    }
    else
    {
        cout << "ERROR: Al intentar abrir el archivo ocurrio un error..." << endl;
    }
}

string directorio_(string direccion)
{
    string delimiter = "/";
    size_t pos = 0;
    string res = "";
    while ((pos = direccion.find(delimiter)) != string::npos)
    {
        res += direccion.substr(0, pos) + "/";
        direccion.erase(0, pos + delimiter.length());
    }
    return res;
}

string extension_(string direccion)
{
    string aux = direccion;
    string delimiter = ".";
    size_t pos = 0;
    while ((pos = aux.find(delimiter)) != string::npos)
    {
        aux.erase(0, pos + delimiter.length());
    }
    return aux;
}

void REP(Nodo *raiz)
{
    string name = "";
    string path = "";
    string id = "";
    string ruta = "";

    list<Nodo>::iterator it;
    for (it = raiz->hijos.begin(); it != raiz->hijos.end(); ++it)
    {

        if (it->tipo == "name")
        {
            name = it->valor;
        }
        else if (it->tipo == "path")
        {
            path = it->valor;
            path = regex_replace(path, regex("\""), "");
            path = regex_replace(path, regex("/home/"), "/home/li/Escritorio/");
        }
        else if (it->tipo == "id")
        {
            id = it->valor;
        }
        else if (it->valor == "ruta")
        {
            ruta = it->valor;
            ruta = regex_replace(ruta, regex("\""), "");
            ruta = regex_replace(ruta, regex("/home/"), "/home/li/Escritorio/");
        }
    }

    if (path != "")
    {
        if (name != "")
        {
            if (id != "")
            {
                string direccion = listaMount->direccion(id);
                string nombre = listaMount->nombre(id);
                string ext = extension_(path);
                if (direccion != "NULL")
                {
                    string direct_ = directorio_(path);
                    string comando = "sudo mkdir -p \'" + direct_ + "\'";
                    system(comando.c_str());
                    string comando2 = "sudo chmod -R 777 \'" + direct_ + "\'";
                    system(comando2.c_str());
                    if (name == "mbr")
                    {
                        graficarMBR(direccion, path, ext);
                    }
                    else if (name == "disk")
                    {
                        graficarDisk(direccion, path, ext);
                    }
                    else if (name == "inode")
                    {
                        int index = buscarParticionPE(direccion, nombre);
                        if (index != -1)
                        { // Primaria|Extendida
                            MBR masterboot;
                            SuperBloque super;
                            FILE *fp = fopen(direccion.c_str(), "rb+");
                            fread(&masterboot, sizeof(MBR), 1, fp);
                            fseek(fp, masterboot.mbr_partition[index].part_start, SEEK_SET);
                            fread(&super, sizeof(SuperBloque), 1, fp);
                            fclose(fp);
                            graficarInodos(direccion, path, ext, super.s_bm_inode_start, super.s_inode_start, super.s_bm_block_start);
                        }
                        else
                        { // Logica
                            int index = buscarParticionL(direccion, nombre);
                            if (index != -1)
                            {
                                EBR extendedBoot;
                                SuperBloque super;
                                FILE *fp = fopen(direccion.c_str(), "rb+");
                                fseek(fp, index, SEEK_SET);
                                fread(&extendedBoot, sizeof(EBR), 1, fp);
                                fread(&super, sizeof(SuperBloque), 1, fp);
                                fclose(fp);
                                graficarInodos(direccion, path, ext, super.s_bm_inode_start, super.s_inode_start, super.s_bm_block_start);
                            }
                        }
                    }
                    else if (name == "sb")
                    {
                        NodoMount *aux = listaMount->getMount(id);
                        int indice = buscarParticionPE(aux->direccion, aux->nombre);
                        if (indice != -1)
                        { // Primaria|Extendida
                            MBR masterboot;
                            FILE *fp = fopen(aux->direccion.c_str(), "rb+");
                            fread(&masterboot, sizeof(MBR), 1, fp);
                            fseek(fp, masterboot.mbr_partition[indice].part_start, SEEK_SET);
                            fclose(fp);
                            graficarSuperBloque(aux->direccion, path, ext, masterboot.mbr_partition[indice].part_start);
                        }
                        else
                        {
                            int indice = buscarParticionL(aux->direccion, aux->nombre);
                            if (indice != -1)
                            {
                                EBR extendedBoot;
                                FILE *fp = fopen(aux->direccion.c_str(), "rb+");
                                fseek(fp, indice, SEEK_SET);
                                fread(&extendedBoot, sizeof(EBR), 1, fp);
                                int start = static_cast<int>(ftell(fp));
                                fclose(fp);
                                graficarSuperBloque(aux->direccion, path, ext, start);
                            }
                        }
                    }
                    else if (name == "tree")
                    {
                        int index = buscarParticionPE(direccion, nombre);
                        string destino = directorio_(path) + fileName(path) + ".pdf";
                        if (index != -1)
                        {
                            MBR masterboot;
                            FILE *fp = fopen(direccion.c_str(), "rb+");
                            fread(&masterboot, sizeof(MBR), 1, fp);
                            fseek(fp, masterboot.mbr_partition[index].part_start, SEEK_SET);
                            fclose(fp);
                            graficarTree(direccion, path, ext, masterboot.mbr_partition[index].part_start);
                        }
                        else
                        {
                            int index = buscarParticionL(direccion, nombre);
                            if (index != -1)
                            {
                                EBR extendedBoot;
                                FILE *fp = fopen(direccion.c_str(), "rb+");
                                fseek(fp, index, SEEK_SET);
                                fread(&extendedBoot, sizeof(EBR), 1, fp);
                                int start = static_cast<int>(ftell(fp));
                                fclose(fp);
                                graficarTree(direccion, path, ext, start);
                            }
                        }
                    }else if(name == "Journaling"){
                        cout << "Reporte Journaling" << endl;
                    }else if(name == "block"){
                        cout << "Reporte Block" << endl;
                    }else if(name == "bm_inode"){
                        cout << "Reporte bm_inode" << endl;
                    }else if(name == "bm_block"){                     
                        cout << "Reporte bm_block" << endl;
                    }else if(name == "file"){
                        cout << "Reporte file" << endl;
                    }else if(name == "ls"){
                        cout << "Reporte ls" << endl;
                    }
                }
                else
                {
                    cout << "ERROR: no se encuentra la particion" << endl;
                }
            }
            else
            {
                cout << "ERROR: parametro -id no definido" << endl;
            }
        }
        else
        {
            cout << "ERROR: parametro -name no definido" << endl;
        }
    }
    else
    {
        cout << "ERROR: parametro -path no definido" << endl;
    }
}

// Graficar DISCO
void reporteDisco(string pathDisk, string destinationReport)
{
    FILE *fp;
    FILE *imageDisk;

    string path_str = pathDisk;

    if ((fp = fopen(path_str.c_str(), "r")))
    {
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

        // RECORRER PARTICIONES
        for (int i = 0; i < 4; i++)
        {
            int tam_par = mbr.mbr_partition[i].part_size;
            if (mbr.mbr_partition[i].part_start != -1)
            {
                fprintf(imageDisk, "     <td bgcolor=\'lightgreen\'  height=\'200\' width=\'200'> %s <br/> TAMAÑO: %d </td>\n", mbr.mbr_partition[i].part_name, tam_par);
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

string split_txt(string text)
{
    stringstream text_to_split(text);
    string segment;
    vector<string> splited;

    while (getline(text_to_split, segment, '/'))
    {
        splited.push_back(segment);
    }
    string clearName = splited.back();
    clearName = regex_replace(clearName, regex(".dsk"), "");
    return clearName;
}

string fileName(string direccion){
    string aux = direccion;
    string delimiter = "/";
    size_t pos = 0;
    string res = "";
    while((pos = aux.find(delimiter))!=string::npos){
        aux.erase(0,pos + delimiter.length());
    }
    delimiter = ".";
    pos = aux.find(delimiter);
    res = aux.substr(0,pos);
    return res;
}