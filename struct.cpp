#include <iostream>

using namespace std;

/*
    Structs necesarios para guardar la informacion de los discos
    Los discos tendran informacion del MBR y el MBR tendra el espacio de las particiones
*/

typedef struct {
    int part_start; //Indica en que byte del disco inicia la particion
    int part_size; //Contiene el tamano de la particion en bytes
    char part_name[16]; //Nombre de la particion
} Partition;

typedef struct{
    int mbr_size; //Tamano total del disco en bytes
    time_t mbr_date; //Fecha y hora de creacion del disco
    int mbr_disk_signature; //Numero random, que identifica de forma unica cada disco
    Partition mbr_partition[4]; //4 particiones
} MBR;