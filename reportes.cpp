#include <iostream>
#include <fstream>

#include "nodo.h"

using namespace std;

void graficarMBR(string direccion, string destino, string extension){
    FILE *fp;
    ofstream graph;

    if((fp = fopen(direccion.c_str(),"r"))){
        graph.open("reporte.dot");
        graph << "digraph G \n{ \n";
        graph << "node[shape=plaintext];\n";
        graph << "T[label=<\n<table border=\"1\" cellborder =\"1\" cellspacing=\"0\" width=\"400\" >\n";
        graph << "<tr><td bgcolor=\"yellow\" width=\"200\"><b>MBR</b></td><td bgcolor=\"yellow\" width=\"200\"></td></tr>\n";
        MBR masterBoot;
        fseek(fp, 0, SEEK_SET);
        fread(&masterBoot, sizeof(MBR), 1, fp);
        int tamano = masterBoot.mbr_size;
        graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">mbr_tamaño</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << tamano << "</td></tr>\n"; 
        struct tm *tm;
        char fecha[100];
        tm = localtime(&masterBoot.mbr_date);
        strftime(fecha,100,"%d/%m/%y %H:%S",tm);
        graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">mbr_fecha_creacion</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << fecha << "</td></tr>\n";
        graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">mbr_disk_signature</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << masterBoot.mbr_disk_signature << "</td></tr>\n";
        graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">mbr_disk_fit</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << masterBoot.mbr_disk_fit << "</td></tr>\n";  

        int indiceExtendida = -1;
        for (int i = 0; i < 4; i++){
            if(masterBoot.mbr_partition[i].part_start!=-1 && masterBoot.mbr_partition[i].part_status!='1'){
                if(masterBoot.mbr_partition[i].part_type == 'E'){
                    indiceExtendida = i;
                }
                char status[3];
                if(masterBoot.mbr_partition[i].part_status == '0')
                    strcpy(status,"0");
                else if(masterBoot.mbr_partition[i].part_status == '2')
                    strcpy(status,"2");
                
                graph << "<tr><td bgcolor=\"orange\" width=\"200\"><b>Particion</b></td><td bgcolor=\"orange\" width=\"200\"></td></tr>\n";
                graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">part_status</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << status << "</td></tr>\n";
                graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">part_type</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << masterBoot.mbr_partition[i].part_type << "</td></tr>\n";
                graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">part_fit</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << masterBoot.mbr_partition[i].part_fit << "</td></tr>\n";
                graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">part_start</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << masterBoot.mbr_partition[i].part_start << "</td></tr>\n";
                graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">part_size</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << masterBoot.mbr_partition[i].part_size << "</td></tr>\n";
                graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">part_name</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << masterBoot.mbr_partition[i].part_name << "</td></tr>\n";
            }
        }

        if(indiceExtendida != -1){
            int index_ebr = 1;
            EBR extendedBoot;
            fseek(fp, masterBoot.mbr_partition[indiceExtendida].part_start, SEEK_SET);
            while(fread(&extendedBoot,sizeof(EBR),1,fp)!=0 && (ftell(fp) < masterBoot.mbr_partition[indiceExtendida].part_start + masterBoot.mbr_partition[indiceExtendida].part_size)) {
                if(extendedBoot.part_status != '1'){
                    char status[3];
                    if(extendedBoot.part_status == '0')
                        strcpy(status,"0");
                    else if(extendedBoot.part_status == '2')
                        strcpy(status,"2");

                    graph << "<tr><td bgcolor=\"red\" width=\"200\"><b>Particion Logica</b></td><td bgcolor=\"red\" width=\"200\"></td></tr>\n";
                    graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">part_status</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << status << "</td></tr>\n";
                    graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">part_fit</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << extendedBoot.part_fit << "</td></tr>\n";
                    graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">part_start</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << extendedBoot.part_start << "</td></tr>\n";
                    graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">part_next</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << extendedBoot.part_next << "</td></tr>\n";
                    graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">part_size</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << extendedBoot.part_size << "</td></tr>\n";
                    graph << "<tr><td bgcolor=\"aquamarine\" width=\"200\">part_name</td><td bgcolor=\"darkseagreen3\" width=\"200\">" << extendedBoot.part_name << "</td></tr>\n";
                
                    index_ebr++;
                }

                if(extendedBoot.part_next == -1)
                    break;
                else
                    fseek(fp, extendedBoot.part_next, SEEK_SET);
            }
        }

        graph << "</table>>];\n";
        graph << "}\n";
        graph.close();
        fclose(fp);
        string comando = "dot -T"+ extension +" reporte.dot -o " + destino;
        system(comando.c_str());
        cout << "*Reporte MBR generado con exito*" << endl;
    } else cout <<"ERROR: reporte no generado"<<endl;
}

void graficarDisk(string direccion, string destino, string extension){
    FILE *fp;
    FILE *graphDot;

    if((fp = fopen(direccion.c_str(),"r"))){
        graphDot = fopen("reporte.dot","w");
        fprintf(graphDot,"digraph G{\n\n");
        fprintf(graphDot, "  tbl [\n    shape=box\n    label=<\n");
        fprintf(graphDot, "     <table border=\'0\' cellborder=\'2\' width=\'600\' height=\"200\" color=\'orange\'>\n");
        fprintf(graphDot, "     <tr>\n");
        fprintf(graphDot, "     <td height=\'200\' width=\'100\'> <b>MBR</b> </td>\n");
        MBR masterboot;
        fseek(fp, 0, SEEK_SET);
        fread(&masterboot,sizeof(MBR),1,fp);
        int total = masterboot.mbr_size;
        double espacioUsado = 0;
        for(int i = 0; i < 4; i++){
            int parcial = masterboot.mbr_partition[i].part_size;
            if(masterboot.mbr_partition[i].part_start != -1){   //Particion vacia
                double porcentaje_real = (parcial*100)/total;
                double porcentaje_aux = (porcentaje_real*500)/100;
                espacioUsado += porcentaje_real;
                if(masterboot.mbr_partition[i].part_status != '1'){
                    if(masterboot.mbr_partition[i].part_type == 'P'){
                        fprintf(graphDot, "     <td height=\'200\' width=\'%.1f\'>Primaria <br/> Ocupa: %.1f%c</td>\n", porcentaje_aux, porcentaje_real,'%');
                        //Verificar que no haya espacio fragmentado
                        if(i!=3){
                            int p1 = masterboot.mbr_partition[i].part_start + masterboot.mbr_partition[i].part_size;
                            int p2 = masterboot.mbr_partition[i+1].part_start;
                            if(masterboot.mbr_partition[i+1].part_start != -1){
                                if((p2-p1)!=0){//Hay fragmentacion
                                    int fragmentacion = p2-p1;
                                    double porcentaje_real = (fragmentacion*100)/total;
                                    double porcentaje_aux = (porcentaje_real*500)/100;
                                    fprintf(graphDot,"     <td height=\'200\' width=\'%.1f\'>Libre<br/> Ocupa: %.1f%c</td>\n", porcentaje_aux, porcentaje_real,'%');
                                }
                            }

                        }else{
                            int p1 = masterboot.mbr_partition[i].part_start + masterboot.mbr_partition[i].part_size;
                            int mbr_size = total + (int)sizeof(MBR);
                            if((mbr_size-p1)!=0){//Libre
                                double libre = (mbr_size - p1) + sizeof(MBR);
                                double porcentaje_real = (libre*100)/total;
                                double porcentaje_aux = (porcentaje_real*500)/100;
                                fprintf(graphDot, "     <td height=\'200\' width=\'%.1f\'>Libre<br/> Ocupa: %.1f%c</td>\n", porcentaje_aux, porcentaje_real,'%');
                            }
                        }
                    }else{//Extendida
                        EBR extendedBoot;
                        fprintf(graphDot,"     <td  height=\'200\' width=\'%.1f\'>\n     <table border=\'0\'  height=\'200\' WIDTH=\'%.1f\' cellborder=\'1\'>\n", porcentaje_real, porcentaje_real);
                        fprintf(graphDot,"     <tr>  <td height=\'60\' colspan=\'15\'>Extendida</td>  </tr>\n     <tr>\n");
                        fseek(fp, masterboot.mbr_partition[i].part_start,SEEK_SET);
                        fread(&extendedBoot,sizeof(EBR),1,fp);
                        if(extendedBoot.part_size != 0){//Si hay mas de alguna logica
                            fseek(fp, masterboot.mbr_partition[i].part_start,SEEK_SET);
                            while(fread(&extendedBoot,sizeof (EBR),1,fp)!=0 && (ftell(fp) < (masterboot.mbr_partition[i].part_start + masterboot.mbr_partition[i].part_size))){
                                parcial = extendedBoot.part_size;
                                porcentaje_real = (parcial*100)/total;
                                if(porcentaje_real!=0){
                                    if(extendedBoot.part_status != '1'){
                                        fprintf(graphDot, "     <td height=\'140\'>EBR</td>\n");
                                        fprintf(graphDot, "     <td height=\'140\'>Logica<br/>Ocupa: %.1f%c</td>\n",porcentaje_real,'%');
                                    }else{//Espacio no asignado
                                        fprintf(graphDot, "      <td height=\'150\'>Libre <br/> Ocupa: %.1f%c</td>\n", porcentaje_real,'%');
                                    }
                                    if(extendedBoot.part_next==-1){
                                        parcial = (masterboot.mbr_partition[i].part_start + masterboot.mbr_partition[i].part_size) - (extendedBoot.part_start + extendedBoot.part_size);
                                        porcentaje_real = (parcial*100)/total;
                                        if(porcentaje_real!=0){
                                            fprintf(graphDot, "     <td height=\'150\'>Libre <br/> Ocupa: %.1f%c </td>\n",porcentaje_real,'%');
                                        }
                                        break;
                                    }else
                                        fseek(fp,extendedBoot.part_next, SEEK_SET);
                                }
                            }
                        }else{
                            fprintf(graphDot,"     <td height=\'140\'> Ocupa: %.1f%c</td>", porcentaje_real,'%');
                        }
                        fprintf(graphDot,"     </tr>\n     </table>\n     </td>\n");
                        //Verificar que no haya espacio fragmentado
                        if(i!=3){
                            int p1 = masterboot.mbr_partition[i].part_start + masterboot.mbr_partition[i].part_size;
                            int p2 = masterboot.mbr_partition[i+1].part_start;
                            if(masterboot.mbr_partition[i+1].part_start != -1){
                                if((p2-p1)!=0){//Hay fragmentacion
                                    int fragmentacion = p2-p1;
                                    double porcentaje_real = (fragmentacion*100)/total;
                                    double porcentaje_aux = (porcentaje_real*500)/100;
                                    fprintf(graphDot,"     <td height=\'200\' width=\'%.1f\'>Libre<br/> Ocupa: %.1f%c</td>\n", porcentaje_aux, porcentaje_real,'%');
                                }
                            }
                        }else{
                            int p1 = masterboot.mbr_partition[i].part_start + masterboot.mbr_partition[i].part_size;
                            int mbr_size = total + (int)sizeof(MBR);
                            if((mbr_size-p1)!=0){//Libre
                                double libre = (mbr_size - p1) + sizeof(MBR);
                                double porcentaje_real = (libre*100)/total;
                                double porcentaje_aux = (porcentaje_real*500)/100;
                                fprintf(graphDot, "     <td height=\'200\' width=\'%.1f\'>Libre<br/> Ocupa: %.1f%c</td>\n",porcentaje_aux, porcentaje_real, '%');
                            }
                        }
                    }
                }else{  //Espacio no asignado
                     fprintf(graphDot,"     <td height=\'200\' width=\'%.1f\'>Libre <br/> Ocupa: %.1f%c</td>\n", porcentaje_aux, porcentaje_real,'%');
                }
            }
        }

        fprintf(graphDot,"     </tr> \n     </table>        \n>];\n\n}");
        fclose(graphDot);
        fclose(fp);
        string comando = "dot -T" + extension + " reporte.dot -o " + destino;
        system(comando.c_str());
        cout << "*Reporte Disk generado con exito*" << endl;
    } else{
        cout << "ERROR: disco no encontrado" << endl;
    }
}

void graficarSuperBloque(string direccion, string destino, string extension, int startSuper){
    FILE* fp = fopen(direccion.c_str(),"r");

    SuperBloque super;

    fseek(fp, startSuper, SEEK_SET);
    fread(&super, sizeof(super), 1, fp);

    FILE *graph = fopen("reporte.dot","w");
    fprintf(graph,"digraph G{\n");
    fprintf(graph, "    nodo [shape=none, fontname=\"Century Gothic\" label=<");
    fprintf(graph, "   <table border=\'0\' cellborder='1\' cellspacing=\'0\' bgcolor=\"yellow\">");
    fprintf(graph, "    <tr> <td COLSPAN=\'2\'> <b>SuperBloque</b> </td></tr>\n");
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_filesystem_type </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_filesystem_type);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_inodes_count </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_inodes_count);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_blocks_count </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_blocks_count);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_free_block_count </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_free_blocks_count);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_free_inodes_count </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_free_inodes_count);
    struct tm *tm;
    char fecha[100];
    tm = localtime(&super.s_mtime);
    strftime(fecha,100,"%d/%m/%y %H:%S",tm);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_mtime </td> <td bgcolor=\"white\"> %s </td></tr>\n",fecha);
    tm = localtime(&super.s_umtime);
    strftime(fecha, 100,"%d/%m/%y %H:%S",tm);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_umtime </td> <td bgcolor=\"white\"> %s </td> </tr>\n",fecha);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_mnt_count </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_mnt_count);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_magic </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_magic);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_inode_size </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_inode_size);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_block_size </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_block_size);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_first_ino </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_first_ino);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_first_blo </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_first_blo);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_bm_inode_start </td> <td bgcolor=\"white\"> %d </td></tr>\n",super.s_bm_inode_start);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_bm_block_start </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_bm_block_start);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_inode_start </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_inode_start);
    fprintf(graph, "    <tr> <td bgcolor=\"aquamarine\"> s_block_start </td> <td bgcolor=\"white\"> %d </td> </tr>\n",super.s_block_start);
    fprintf(graph, "   </table>>]\n");
    fprintf(graph,"\n}");
    fclose(graph);

    fclose(fp);

    string comando = "dot -T" + extension + " reporte.dot -o " + destino;
    system(comando.c_str());
    cout << "*Reporte SuperBloque generado con exito*" << endl;
}

//Metodo para generar el reporte de inodos de una particion
void graficarInodos(string direccion, string destino, string extension, int bm_inode_start, int inode_start, int bm_block_start ){
    FILE *fp = fopen(direccion.c_str(), "r");

    InodoTable inodo;
    int aux = bm_inode_start;
    int i = 0;
    char buffer;

    FILE *graph = fopen("grafica.dot","w");
    fprintf(graph,"digraph G{\n\n");

    while(aux < bm_block_start){
        fseek(fp,bm_inode_start + i,SEEK_SET);
        buffer = static_cast<char>(fgetc(fp));
        aux++;
        if(buffer == '1'){
            fseek(fp,inode_start + static_cast<int>(sizeof(InodoTable))*i,SEEK_SET);
            fread(&inodo,sizeof(InodoTable),1,fp);
            fprintf(graph, "    nodo_%d [ shape=none fontname=\"Century Gothic\" label=<\n",i);
            fprintf(graph, "   <table border=\'0\' cellborder=\'1\' cellspacing=\'0\' bgcolor=\"royalblue\">");
            fprintf(graph, "    <tr> <td colspan=\'2\'> <b>Inodo %d</b> </td></tr>\n",i);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_uid </td> <td bgcolor=\"white\"> %d </td>  </tr>\n",inodo.i_uid);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_gid </td> <td bgcolor=\"white\"> %d </td>  </tr>\n",inodo.i_gid);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_size </td> <td bgcolor=\"white\"> %d </td> </tr>\n",inodo.i_size);
            struct tm *tm;
            char fecha[100];
            tm=localtime(&inodo.i_atime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_atime </td> <td bgcolor=\"white\"> %s </td>  </tr>\n",fecha);
            tm=localtime(&inodo.i_ctime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_ctime </td> <td bgcolor=\"white\"> %s </td>  </tr>\n",fecha);
            tm=localtime(&inodo.i_mtime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_mtime </td> <td bgcolor=\"white\"> %s </td></tr>\n",fecha);
            for(int b = 0; b < 15; b++)
                fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_block_%d </td> <td bgcolor=\"white\"> %d </td> </tr>\n",b,inodo.i_block[b]);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_type </td> <td bgcolor=\"white\"> %c </td> </tr>\n",inodo.i_type);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_perm </td> <td bgcolor=\"white\"> %d </td> </tr>\n",inodo.i_perm);
            fprintf(graph, "   </table>>]\n");
        }
        i++;
    }
    fprintf(graph,"\n}");
    fclose(graph);

    fclose(fp);

    string comando = "dot -T"+extension+" grafica.dot -o "+destino;
    system(comando.c_str());
    cout << "Reporte de inodos generado con exito " << endl;
}

//Metodo para generar el reporte del arbol de inodos con bloques de un sistema de archivos
void graficarTree(string direccion,string destino, string extension, int start_super){
    FILE *fp = fopen(direccion.c_str(),"r");

    SuperBloque super;
    InodoTable inodo;
    BloqueCarpeta carpeta;
    BloqueArchivo archivo;
    BloqueApuntadores apuntador;

    fseek(fp,start_super,SEEK_SET);
    fread(&super,sizeof(SuperBloque),1,fp);

    int aux = super.s_bm_inode_start;
    int i = 0;

    char buffer;

    FILE *graph = fopen("grafica.dot", "w");
    fprintf(graph, "digraph G{\n\n");
    fprintf(graph, "    rankdir=\"LR\" \n");

    //Creamos los inodos
    while(aux < super.s_bm_block_start){
        fseek(fp,super.s_bm_inode_start + i,SEEK_SET);
        buffer = static_cast<char>(fgetc(fp));
        aux++;
        int port = 0;
        if(buffer == '1'){
            fseek(fp,super.s_inode_start + static_cast<int>(sizeof(InodoTable))*i,SEEK_SET);
            fread(&inodo,sizeof(InodoTable),1,fp);
            fprintf(graph, "    inodo_%d [ shape=plaintext fontname=\"Century Gothic\" label=<\n",i);
            fprintf(graph, "   <table bgcolor=\"royalblue\" border=\'0\' >");
            fprintf(graph, "    <tr> <td colspan=\'2\'><b>Inode %d</b></td></tr>\n",i);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_uid </td> <td bgcolor=\"white\"> %d </td>  </tr>\n",inodo.i_uid);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_gid </td> <td bgcolor=\"white\"> %d </td>  </tr>\n",inodo.i_gid);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_size </td><td bgcolor=\"white\"> %d </td> </tr>\n",inodo.i_size);
            struct tm *tm;
            char fecha[100];
            tm=localtime(&inodo.i_atime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_atime </td> <td bgcolor=\"white\"> %s </td> </tr>\n",fecha);
            tm=localtime(&inodo.i_ctime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_ctime </td> <td bgcolor=\"white\"> %s </td> </tr>\n",fecha);
            tm=localtime(&inodo.i_mtime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_mtime </td> <td bgcolor=\"white\"> %s </td> </tr>\n",fecha);
            for(int b = 0; b < 15; b++){
                fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_block_%d </td> <td bgcolor=\"white\" port=\"f%d\"> %d </td></tr>\n",port,b,inodo.i_block[b]);
                port++;
            }
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_type </td> <td bgcolor=\"white\"> %c </td>  </tr>\n",inodo.i_type);
            fprintf(graph, "    <tr> <td bgcolor=\"lightsteelblue\"> i_perm </td> <td bgcolor=\"white\"> %d </td>  </tr>\n",inodo.i_perm);
            fprintf(graph, "   </table>>]\n\n");
            //Creamos los bloques relacionados al inodo
            for (int j = 0; j < 15; j++) {
                port = 0;
                if(inodo.i_block[j] != -1){
                    fseek(fp,super.s_bm_block_start + inodo.i_block[j],SEEK_SET);
                    buffer = static_cast<char>(fgetc(fp));
                    if(buffer == '1'){//Bloque carpeta
                        fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*inodo.i_block[j],SEEK_SET);
                        fread(&carpeta,sizeof(BloqueCarpeta),1,fp);
                        fprintf(graph, "    bloque_%d [shape=plaintext fontname=\"Century Gothic\" label=< \n",inodo.i_block[j]);
                        fprintf(graph, "   <table bgcolor=\"seagreen\" border=\'0\'>\n");
                        fprintf(graph, "    <tr> <td colspan=\'2\'><b>Folder block %d</b></td></tr>\n",inodo.i_block[j]);
                        fprintf(graph, "    <tr> <td bgcolor=\"mediumseagreen\"> b_name </td> <td bgcolor=\"mediumseagreen\"> b_inode </td></tr>\n");
                        for(int c = 0;c < 4; c++){
                            fprintf(graph, "    <tr> <td bgcolor=\"white\" > %s </td> <td bgcolor=\"white\"  port=\"f%d\"> %d </td></tr>\n",carpeta.b_content[c].b_name,port,carpeta.b_content[c].b_inodo);
                            port++;
                        }
                        fprintf(graph, "   </table>>]\n\n");
                        //Relacion de bloques a inodos
                        for(int c = 0; c < 4; c++){
                            if(carpeta.b_content[c].b_inodo !=-1){
                                if(strcmp(carpeta.b_content[c].b_name,".")!=0 && strcmp(carpeta.b_content[c].b_name,"..")!=0)
                                    fprintf(graph, "    bloque_%d:f%d -> inodo_%d;\n",inodo.i_block[j],c,carpeta.b_content[c].b_inodo);
                            }
                        }
                    }else if(buffer == '2'){//Bloque archivo
                        fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*inodo.i_block[j],SEEK_SET);
                        fread(&archivo,sizeof(BloqueArchivo),1,fp);
                        fprintf(graph, "    bloque_%d [shape=plaintext fontname=\"Century Gothic\" label=< \n",inodo.i_block[j]);
                        fprintf(graph, "   <table border=\'0\' bgcolor=\"sandybrown\">\n");
                        fprintf(graph, "    <tr> <td> <b>File block %d</b></td></tr>\n",inodo.i_block[j]);
                        fprintf(graph, "    <tr> <td bgcolor=\"white\"> %s </td></tr>\n",archivo.b_content);
                        fprintf(graph, "   </table>>]\n\n");
                    }else if(buffer == '3'){//Bloque apuntador
                        fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueApuntadores))*inodo.i_block[j],SEEK_SET);
                        fread(&apuntador,sizeof(BloqueApuntadores),1,fp);
                        fprintf(graph, "    bloque_%d [shape=plaintext fontname=\"Century Gothic\" label=< \n",inodo.i_block[j]);
                        fprintf(graph, "   <table border=\'0\' bgcolor=\"khaki\">\n");
                        fprintf(graph, "    <tr> <td> <b>Pointer block %d</b></td></tr>\n",inodo.i_block[j]);
                        for(int a = 0; a < 16; a++){
                            fprintf(graph, "    <tr> <td bgcolor=\"white\" port=\"f%d\">%d</td> </tr>\n",port,apuntador.b_pointer[a]);
                            port++;
                        }
                        fprintf(graph, "   </table>>]\n\n");
                        //Bloques carpeta/archivos del bloque de apuntadores
                        for (int x = 0; x < 16; x++) {
                            port = 0;
                            if(apuntador.b_pointer[x] != -1){
                                fseek(fp,super.s_bm_block_start + apuntador.b_pointer[x],SEEK_SET);
                                buffer = static_cast<char>(fgetc(fp));
                                if(buffer == '1'){
                                    fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueCarpeta))*apuntador.b_pointer[x],SEEK_SET);
                                    fread(&carpeta,sizeof(BloqueCarpeta),1,fp);
                                    fprintf(graph, "    bloque_%d [shape=plaintext fontname=\"Century Gothic\" label=< \n",apuntador.b_pointer[x]);
                                    fprintf(graph, "   <table border=\'0\' bgcolor=\"seagreen\" >\n");
                                    fprintf(graph, "    <tr> <td colspan=\'2\'> <b>Folder block %d</b> </td></tr>\n",apuntador.b_pointer[x]);
                                    fprintf(graph, "    <tr> <td bgcolor=\"mediumseagreen\"> b_name </td> <td bgcolor=\"mediumseagreen\"> b_inode </td></tr>\n");
                                    for(int c = 0;c < 4; c++){
                                        fprintf(graph, "    <tr> <td bgcolor=\"white\"> %s </td> <td bgcolor=\"white\" port=\"f%d\"> %d </td></tr>\n",carpeta.b_content[c].b_name,port,carpeta.b_content[c].b_inodo);
                                        port++;
                                    }
                                    fprintf(graph, "   </table>>]\n\n");
                                    //Relacion de bloques a inodos
                                    for(int c = 0; c < 4; c++){
                                        if(carpeta.b_content[c].b_inodo !=-1){
                                            if(strcmp(carpeta.b_content[c].b_name,".")!=0 && strcmp(carpeta.b_content[c].b_name,"..")!=0)
                                                fprintf(graph, "    bloque_%d:f%d -> inodo_%d;\n",apuntador.b_pointer[x],c,carpeta.b_content[c].b_inodo);
                                        }
                                    }
                                }else if(buffer == '2'){
                                    fseek(fp,super.s_block_start + static_cast<int>(sizeof(BloqueArchivo))*apuntador.b_pointer[x],SEEK_SET);
                                    fread(&archivo,sizeof(BloqueArchivo),1,fp);
                                    fprintf(graph, "    bloque_%d [shape=plaintext fontname=\"Century Gothic\" label=< \n",apuntador.b_pointer[x]);
                                    fprintf(graph, "   <table border=\'0\' bgcolor=\"sandybrown\">\n");
                                    fprintf(graph, "    <tr> <td> <b>File block %d</b></td></tr>\n",apuntador.b_pointer[x]);
                                    fprintf(graph, "    <tr> <td bgcolor=\"white\"> %s </td></tr>\n",archivo.b_content);
                                    fprintf(graph, "   </table>>]\n\n");
                                }else if(buffer == '3'){

                                }
                            }
                        }

                        //Relacion de bloques apuntador a bloques archivos/carpetas
                        for(int b = 0; b < 16; b++){
                            if(apuntador.b_pointer[b] != -1)
                                fprintf(graph, "    bloque_%d:f%d -> bloque_%d;\n",inodo.i_block[j],b,apuntador.b_pointer[b]);
                        }
                    }
                    //Relacion de inodos a bloques
                    fprintf(graph, "    inodo_%d:f%d -> bloque_%d; \n",i,j,inodo.i_block[j]);
                }
            }
        }
        i++;
    }

    fprintf(graph,"\n\n}");
    fclose(graph);

    fclose(fp);

    string comando = "dot -T"+extension+" grafica.dot -o "+destino;
    system(comando.c_str());
    cout << "Reporte Tree generado con exito " << endl;
}