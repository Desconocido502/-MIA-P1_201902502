#ifndef LISTAMOUNT
#define LISTAMOUNT

#include <iostream>
#include "nodoMount.cpp"

using namespace std;

class ListaMount{
    public:
        NodoMount *primero;
        ListaMount();
        void insertar(string, string, int);
        void mostrar();
        bool buscar(string, string);
        void eliminar(string);
        //int buscarLetra(string, string);
        int buscarNumero(string, string);
        string direccion(string);
        NodoMount* getMount(string id);
        int buscarID(string, string);
        string split_txt(string , char);
};

ListaMount:: ListaMount(){
    primero = NULL;
}

//Inserta al final de la lista
void ListaMount:: insertar(string direccion, string nombre, int num){
    NodoMount *nuevo = new NodoMount(direccion, nombre, num);
    NodoMount *aux = primero;
    if(primero == NULL){
        primero = nuevo;
    } else{
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

//Muestra las particiones montadas
void ListaMount:: mostrar(){
    cout << "|----- Particiones montadas -----|" << endl;
    cout << "|------ Nombre    |    ID -------|" << endl;
    cout << "__________________________________" << endl;
    NodoMount *aux = primero;
    while(aux != NULL){
        cout << "    " << aux->nombre << "          " << "02" << aux->num << split_txt(aux->direccion, '/') << endl;
        cout << "---------------------------------" << endl;
        aux = aux->siguiente;
    }
}

bool ListaMount:: buscar(string direccion, string nombre){
    NodoMount *aux = primero;
    while(aux != NULL){
        if((aux->direccion == direccion) && (aux->nombre == nombre)){
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

//elimina un nodo de la lista
void ListaMount:: eliminar(string id){
    NodoMount *aux = primero;
    string tempID = "02";     //201902502
    bool eliminado = false;

    if(primero != NULL) tempID += to_string(aux->num) + split_txt(aux->direccion, '/'); //nombreDisco

    if(id == tempID){
        primero = aux->siguiente;
        eliminado = true;
    }else{
        NodoMount *aux2 = NULL;
        while(aux != NULL){
            tempID = "02";
            tempID += to_string(aux->num) + split_txt(aux->direccion, '/'); // nombreDisco
            if(id == tempID){
                aux2->siguiente = aux->siguiente;
                eliminado = true;
            }
            aux2 = aux;
            aux = aux->siguiente;
        }
    }
    if(eliminado) cout<< "*Particion desmontada con exito*" <<endl;
    else cout<< "ERROR: no se encuentra la partición montada" <<endl;
}

//Verifica que numero asignarle al id de un nodo
int ListaMount:: buscarNumero(string direccion, string nombre){
    NodoMount *aux = primero;
    int num = 1;
    while(aux != NULL){
        if((direccion == aux->direccion) && (nombre == aux->nombre)){
            return -1;
        }else{
            if(direccion == aux->direccion){
                return aux->num;
            }else if(num == aux->num){
                num++;
            }
        }
        aux = aux->siguiente;
    }
    return num;
}

/*
//Verifica que letra asignarle al id de un nodo
int ListaMount:: buscarLetra(string direccion, string nombre){
    int letra = 'a';
    NodoMount *aux = primero;
    while(aux != NULL){
        if((direccion == aux->direccion) && (letra <= aux->letra)){
            letra++;
        }
        aux = aux->siguiente;
    }
    return letra;
}
*/


string ListaMount:: direccion(string id){
    NodoMount *aux = primero;
    while(aux != NULL){
        string tempID = "02";
        tempID += to_string(aux->num) + split_txt(aux->direccion, '/'); //nombreDisco
        if(id == tempID){
            return aux->direccion;
        }
        aux = aux->siguiente;
    }
    return "NULL";
}

NodoMount* ListaMount:: getMount(string id){
    NodoMount *aux = primero;
    while(aux != NULL){
        string tempID = "02" + to_string(aux->num) + split_txt(aux->direccion, '/'); //nombreDisco
        if(id == tempID){
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}

string ListaMount::split_txt(string text, char delimiter)
{ // Split para separar tipo de comando y parametros
    stringstream text_to_split(text);
    string segment;
    vector<string> splited;
    while (std::getline(text_to_split, segment, delimiter))
        splited.push_back(segment);

    if (delimiter == '/')
    {
        string val = splited[splited.size() - 1];
        val = regex_replace(val, regex(".dsk"), "");
        return val;
    }
    else if(delimiter == 'p')
    {
        return splited[splited.size() - 1]; // En caso de que se hable de la particion
    }
    return "-1";
}

#endif // LISTAMOUNT