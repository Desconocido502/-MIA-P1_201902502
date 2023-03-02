#include <iostream>
#include <list>
#include <regex>

#include "nodo.h"
// #include "struct.cpp"

using namespace std;

void crearArchivo(string path);
string directorio(string direccion);
int getSignature();
string timeToString(time_t &t);

void MKDISK(Nodo *raiz)
{

    //valores
    int size = 0;
    char unit = 0;
    string path = "";

    list<Nodo>::iterator it;
    for (it = raiz->hijos.begin(); it != raiz->hijos.end(); ++it)
    {
        if (it->tipo == "size")
        {   
            size = stoi(it->valor);
            if(size < 0){
                cout << "ERROR: EL TAMAÑO DEL DISCO DEBE SER UN NUMERO POSITIVO Y MAYOR A CERO" << endl;
                return;
            }
        }
        else if (it->tipo == "unit")
        {
            unit = it->valor[0];
            if (unit == 'k' || unit == 'K')
            {
                unit = 'k';
            }
            else if (unit == 'm' || unit == 'M')
            {
                unit = 'm';
            }
            else
            {
                cout << "Error: Unidad indicada erronea\n";
                return;
            }
        }
        else if (it->tipo == "path")
        {
            path = it->valor;
            path = regex_replace(path, regex("\""), "");
            path = regex_replace(path, regex("/home/"), "/home/li/Escritorio/");
        }
    }

    MBR masterboot;
    int totalSize = 0;
    //Creacion del archivo
    crearArchivo(path);

    //FECHA MBR
    masterboot.mbr_date = time(nullptr);
    //ID MBR
    masterboot.mbr_disk_signature = getSignature();

    if (unit != 0)
    { // SI EXISTE EL PARAMETRO >unit<
        if (unit == 'm')
        {
            masterboot.mbr_size = size * 1048576;
            totalSize = size * 1024;
        }
        else
        {
            masterboot.mbr_size = size * 1024;
            totalSize = size;
        }
    }
    else
    {
        masterboot.mbr_size = size * 1048576;
        totalSize = size * 1024;
    }

    // Inicializar las particiones en el MBR
    for (int i = 0; i < 4; i++)
    {
        masterboot.mbr_partition[i].part_start = -1; //-1 como valor por default sin particion
        masterboot.mbr_partition[i].part_size = 0;
        strcpy(masterboot.mbr_partition[i].part_name, "");
    }

    //Se escribe en el disco

    string comando = "dd if=/dev/zero of=\"" + path + "\" bs=1024 count=" + to_string(totalSize);
    system(comando.c_str());

    FILE *fp = fopen(path.c_str(), "rb+");
    fseek(fp, 0, SEEK_SET);
    fwrite(&masterboot, sizeof(MBR), 1, fp);
    fclose(fp);

    cout << "*Disco creado con exito*" << endl;
}

void crearArchivo(string path)
{
    string aux = directorio(path);
    string comando = "sudo mkdir -p \'" + aux + "\'"; //crea directorio
    system(comando.c_str());
    string comando2 = "sudo chmod -R 777 \'" + aux + "\'";//da permisos y legible por todas carpetas
    system(comando2.c_str());
    string arch = path;
    FILE *fp = fopen(arch.c_str(), "wb");
    if ((fp = fopen(arch.c_str(), "wb")))
    {
        fclose(fp);
    }
    else
    {
        cout << "Error al crear el archivo" << endl;
    }
}

string directorio(string direccion)
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


string timeToString(time_t &t)
{
    // time_t time = std::chrono::system_clock::to_time_t(t);
    string time_str = std::ctime(&t);
    time_str.resize(time_str.size() - 1);
    return time_str;
}

// FUNCION QUE DEVUELVE UN NUMERO RANDOM QUE IDENTIFICARA EL DISCO
int getSignature()
{
    // pasar el tiempo actual a la funcion srand para inicializar la semilla
    srand(time(NULL));
    // guardar el numero random en una variable
    int ran = rand();
    // agregar mas probabilidad de aleatorizacion al random generado como identificador entre 1 y 1000000
    ran = 1 + rand() % (1000);
    return ran;
}