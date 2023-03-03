%{
    #include <iostream>
    #include <stdlib.h>
    #include "scanner.h"
    #include "../nodo.h"

    using namespace std;

    extern int yylineno;
    extern char *yytext;
    extern int yyfila;
    extern int yycolum;
    extern Nodo *raiz; //raiz del arbol

    int yyerror(const char* mensaje){
        cout<<yytext<<" "<<mensaje<<" "<<yyfila<<" "<<yycolum<<std::endl;
        return 0;
    }

    Nodo* getRaiz(){
        return raiz;
    }
%}
%defines
%define parse.error verbose

%union{
    char text[400];
    class Nodo *nodo;
}

%token<text> mkdisk
%token<text> rep
%token<text> execute
%token<text> fdisk
%token<text> mayor
%token<text> path
%token<text> igual
%token<text> entero
%token<text> txt
%token<text> sizeS
%token<text> unit
%token<text> type
%token<text> name
%token<text> caracter
%token<text> identificador
%token<text> extension
%token<text> ruta
%token<text> cadena
%token<text> exitS
%token <text> fit
%token <text> bf
%token <text> ff
%token <text> wf
%token <text> del_
%token <text> add
%token <text> full
%token <text> rmdisk

%type <nodo> INICIO
%type <nodo> COMANDO
%type <nodo> MKDISK
%type <nodo> FDISK
%type <nodo> REP
%type <nodo> SCRIPT
%type <nodo> PARAMETRO_MK
%type <nodo> AJUSTE
%type <nodo> PARAMETRO_FK
%type <nodo> PARAMETRO_R
%type <nodo> RMDISK

%start INICIO
%%

INICIO:COMANDO { raiz = $$; };

COMANDO:mkdisk MKDISK 
    {
        $$ = new Nodo("MKDISK", "");
        $$->add(*$2);
    }
    |fdisk FDISK {
        $$ = new Nodo("FDISK", "");
        $$->add(*$2);
    }
    |execute SCRIPT  //Execute
    {
        $$ = $2;
    }
    |rep REP
    {
        $$ = new Nodo("REP", "");
        $$->add(*$2);
    }
    |exitS{
        $$ = new Nodo("EXIT", "");
    }
    |RMDISK
    {
        $$ = $1;
    };
    

MKDISK: MKDISK PARAMETRO_MK {
        $$ = $1;
        $$->add(*$2);
    }
    | PARAMETRO_MK {
        $$ = new Nodo("PARAMETRO", "");
        $$->add(*$1);
    };

PARAMETRO_MK:mayor sizeS igual entero
    {
        $$ = new Nodo("size", $4);
    }
    |mayor unit igual caracter
    {
        $$ = new Nodo("unit", $4);
    }
    |mayor path igual cadena
    {
        $$ = new Nodo("path", $4);
    }
    |mayor path igual ruta
    {
        $$ = new Nodo("path", $4);
    } 
    |mayor fit igual AJUSTE 
    {
        $$ = new Nodo("fit", "");
        $$->add(*$4);
    };

AJUSTE: bf 
    {
        $$ = new Nodo("ajuste", "bf");
    }
    | ff 
    {
        $$ = new Nodo("ajuste", "ff");
    }
    | wf 
    {
        $$ = new Nodo("ajuste", "wf");
    };

FDISK: FDISK PARAMETRO_FK {
        $$ = $1;
        $$->add(*$2);
    }
    | PARAMETRO_FK {
        $$ = new Nodo("PARAMETRO", "");
        $$->add(*$1);
    };

PARAMETRO_FK: PARAMETRO_MK 
    { 
        $$ = $1; 
    }
    |mayor name igual identificador 
    {
        $$ = new Nodo("name", $4);
    }
    |mayor name igual cadena
    {
        $$ = new Nodo("name", $4);
    }
    |mayor type igual caracter
    {
        $$ = new Nodo("type", $4);
    }
    |mayor del_ igual full
    {
        $$ = new Nodo("delete", "full");
    }
    |mayor add igual entero
    {
        $$ = new Nodo("add", $4);
    };

SCRIPT: mayor path igual cadena {
        $$ = new Nodo("EXECUTE", "");
        Nodo *path = new Nodo("path", $4);
        $$->add(*path);
    }
    | mayor path igual ruta {
        $$ = new Nodo("EXECUTE", "");
        Nodo *path = new Nodo("path", $4);
        $$->add(*path);
    }; 

REP: REP PARAMETRO_R{
    $$ = $1;
    $$->add(*$2);
    }
    | PARAMETRO_R {
        $$ = new Nodo("PARAMETRO", "");
        $$->add(*$1);
    };

PARAMETRO_R: mayor path igual cadena 
    {
        $$ = new Nodo("path", $4);
    }
    |mayor path igual ruta
    {
        $$ = new Nodo("path", $4);    
    };

RMDISK: rmdisk mayor path igual ruta
    {
        $$ = new Nodo("RMDISK", "");
        Nodo *ruta = new Nodo("path", $5);
        $$->add(*ruta);
    }
    | rmdisk mayor path igual cadena 
    {
        $$ = new Nodo("RMDISK", "");
        Nodo *ruta = new Nodo("path", $5);
        $$->add(*ruta);
    };