#include <iostream>
#include <list>
#include <regex>

#include "nodo.h"

using namespace std;

void crearParticion(string path, string name, int size, char unit);
bool particionRepetida(string name, string path);

void FDISK(Nodo *raiz){

    int size = 0;
    char unit = 0;
    string path = "";
    string name = "";

    list<Nodo> :: iterator it;
    for(it = raiz->hijos.begin(); it != raiz->hijos.end(); it++){
        if(it->tipo == "size"){
            size = stoi(it->valor);
            if(size < 0){
                cout << "ERROR: EL TAM DE LA PARTICION DEBE SER UN NUMERO POSITIVO Y MAYOR A CERO" << endl;
                return;
            }
        }else if(it->tipo == "unit"){
            unit = it->valor[0];
            if(unit == 'b' || unit == 'B'){
                unit = 'b';
            }else if(unit == 'k' || unit == 'K'){
                unit = 'k';
            }else if(unit == 'm' || unit == 'M'){
                unit = 'm';
            }else{
                cout << "ERROR, UNIDAD INCORRECTA (CORRECTAS M, K y B)";
                return;
            }
        }else if(it->tipo == "path"){
            path = it->valor;
            //LIMPIEZA PATH
            path = regex_replace(path, regex("\""), "");
            path = regex_replace(path, regex("/home/"), "/home/li/Escritorio/");
        }else if (it->tipo == "name"){
            name = it->valor;
            //LIMPIEZA NAME
            name = regex_replace(name, regex("\""), "");
        }
    }
    //CREACION DE LA PARTICION
    crearParticion(path, name, size, unit);

}

void crearParticion(string path, string name, int size, char unit){
    int sizeByte = 1024;
    int count = 0;
    int available = 0;
    char unitCopy;

    string pathCopy = path;
    MBR mbr;

    char temp = '1';

    if(unit != 0){
        unitCopy = unit;
        if(unitCopy == 'b') sizeByte = size;
        else if(unitCopy == 'k') sizeByte = size * 1024;
        else sizeByte = size * 1048576;
    }else{
        sizeByte = size * 1024; //kb se estable por Default
    }

    bool existeParticion = false;
    int numParticion = 0;
    FILE *file;

    //Se abre el disco, Si existe
    if((file = fopen(pathCopy.c_str(), "rb+"))){
        fseek(file, 0, SEEK_SET); //posicion cursor en estructura MBR
        fread(&mbr, sizeof(MBR), 1, file); //Se obtiene el Struct MBR
        //Deben de existir como MAX 4 particiones primarias
        //Toca verificar que todavia se pueda particionar

        for(int i=0; i < 4; i++){
            if(mbr.mbr_partition[i].part_start == -1){
                existeParticion = true;
                numParticion = i;
                break; //Se sale del ciclo ya que aun se puede particionar el disco
            }
        }

        count = 0;
        for (int i = 0; i < 4; i++)
        {
            if(mbr.mbr_partition[i].part_start != -1){
                count += mbr.mbr_partition[i].part_size; //Es para saber cuanto espacio se encuentra disponible
            }
        }

        available = mbr.mbr_size - count;
        //Si hay espacio para particionar
        //se valida que el espacio sea necesario
        if(available >= sizeByte){
            if(existeParticion){
                if(!particionRepetida(name, path)){
                    //POsicion de inicio
                    if(numParticion == 0) mbr.mbr_partition[numParticion].part_start = sizeof(mbr);
                    //Tiene que ir a -1 para obtener la pos de inicio de memoria y sumarle el tam del mismo para no escribir encima
                    else mbr.mbr_partition[numParticion].part_start = mbr.mbr_partition[numParticion - 1].part_start + mbr.mbr_partition[numParticion - 1].part_size;
                
                    mbr.mbr_partition[numParticion].part_size = sizeByte;

                    //name
                    strcpy(mbr.mbr_partition[numParticion].part_name, name.c_str());
                    //Actualizacion del MBR
                    fseek(file, 0, SEEK_SET);
                    //Escritura en el MBR
                    fwrite(&mbr, sizeof(MBR), 1, file);

                    fseek(file, mbr.mbr_partition[numParticion].part_start, SEEK_SET);
                    for (int i = 0; i < sizeByte; i++)
                    {
                        fwrite(&temp,1,1, file);
                    }
                    cout << "INFORMACION, PARTICION FUE CREADA EXITOSAMENTE" << endl;
                }else cout << "ERROR, NOMBRE PARA PARTICION YA EXISTE. VERIFIQUE" << endl;//se actualiza el mbr
            }else cout << "ERROR, DISCO YA LLEGO AL LIMITE DE PARTICIONES" << endl;
        }else cout << "INFORMACION, ESPACIO REQUERIDO PARA PARTICION ES MAYOR AL ESPACIO DISPONIBLE" << endl;
        fclose(file);
    }else cout << "INFORMACION, RUTA O DISCO NO EXISTE, VERIFIQUE" << endl; 
}

//VALIDA SI LA PARTICION A CREAR YA EXISTE O ES EXTENDIDA Y YA HAY UNA
bool particionRepetida(string name, string path){
    FILE* file;
    MBR mbr2;
    if((file = fopen(path.c_str(), "rb+"))){
        fseek(file, 0, SEEK_SET);
        fread(&mbr2, sizeof(MBR), 1, file);
        for (int i = 0; i < 4; i++)
        {   
            if(strcmp(mbr2.mbr_partition[i].part_name, name.c_str()) == 0){
                fclose(file);
                return true;
            }
        }
        fclose(file);
    }
    return false;
}