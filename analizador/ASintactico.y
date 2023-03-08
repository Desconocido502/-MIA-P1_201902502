%{
    #include <iostream>
    #include <stdlib.h>
    #include <string>
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
%token <text> mount
%token <text> unmount
%token <text> id
%token <text> mkfs
%token <text> fs
%token <text> fs2
%token <text> fs3
%token <text> login
%token <text> logout
%token <text> pausa
%token <text> usuario
%token <text> password
%token <text> pwd
%token <text> rutaRep
%token <text> disk
%token <text> inode
%token <text> journaling
%token <text> block
%token <text> bm_inode
%token <text> bm_block
%token <text> tree
%token <text> sb
%token <text> fileRep
%token <text> ls
%token <text> mbr
%token <text> mkgrp
%token <text> rmgrp
%token <text> grp
%token <text> mkusr
%token <text> rmusr
%token <text> r
%token <text> ugo
%token <text> Rchmod
%token <text> directorioA
%token <text> mkfile
%token <text> cont
%token <text> cat
%token <text> removeR
%token <text> edit
%token <text> renameR

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
%type <nodo> MOUNT
%type <nodo> UNMOUNT
%type <nodo> PARAMETRO_M
%type <nodo> MKFS
%type <nodo> PARAM_MKFS
%type <nodo> LOGIN
%type <nodo> PARAM_LOGIN
%type <nodo> MKGRP
%type <nodo> RMGRP
%type <nodo> MKUSR
%type <nodo> PARAM_MKUSR
%type <nodo> RMUSR
%type <nodo> CHMOD
%type <nodo> PARAM_CHMOD
%type <nodo> MKFILE
%type <nodo> PARAM_MKFILE
%type <nodo> CAT
%type <nodo> LTS_FILE 
%type <nodo> REMOVE
%type <nodo> EDIT
%type <nodo> PARAM_EDIT
%type <nodo> RENAME
%type <nodo> PARAM_RENAME

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
    |execute SCRIPT { $$ = $2; } //Execute
    |rep REP
    {
        $$ = new Nodo("REP", "");
        $$->add(*$2);
    }
    |exitS { $$ = new Nodo("EXIT", ""); }
    |RMDISK { $$ = $1; }
    |UNMOUNT { $$ = $1; }
    |mount MOUNT
    {
        $$ = new Nodo("MOUNT", "");
        $$->add(*$2);
    }
    |mkfs MKFS
    {
        $$ = new Nodo("MKFS", "");
        $$->add(*$2);
    }
    |login LOGIN
    {
        $$ = new Nodo("LOGIN", "");
        $$->add(*$2);
    }
    |logout { $$ = new Nodo("LOGOUT", ""); }
    |pausa { $$ = new Nodo("PAUSE", ""); }
    |MKGRP { $$=$1; }
    |RMGRP { $$=$1; }
    |mkusr MKUSR {
        $$ = new Nodo("MKUSR", "");
        $$->add(*$2);
    }
    |RMUSR { $$ = $1; }
    |Rchmod CHMOD
    {
        $$ = new Nodo("CHMOD", "");
        $$->add(*$2);
    }
    |mkfile MKFILE 
    {
        $$ = new Nodo("MKFILE","");
        $$->add(*$2);
    }
    |cat CAT
    {
        $$ = new Nodo("CAT", "");
        $$->add(*$2);
    }
    |REMOVE { $$=$1; }
    |edit EDIT 
    {
        $$ = new Nodo("EDIT","");
        $$->add(*$2);
    }
    |renameR RENAME
    {
        $$ = new Nodo("REN","");
        $$->add(*$2);
    };
    

MKDISK: MKDISK PARAMETRO_MK {
        $$ = $1;
        $$->add(*$2);
    }
    | PARAMETRO_MK {
        $$ = new Nodo("PARAMETRO", "");
        $$->add(*$1);
    };

PARAMETRO_MK:mayor sizeS igual entero { $$ = new Nodo("size", $4); }
    |mayor unit igual caracter { $$ = new Nodo("unit", $4); }
    |mayor path igual cadena { $$ = new Nodo("path", $4); }
    |mayor path igual ruta { $$ = new Nodo("path", $4); } 
    |mayor fit igual AJUSTE {
        $$ = new Nodo("fit", "");
        $$->add(*$4);
    };

AJUSTE: bf { $$ = new Nodo("ajuste", "bf"); }
    | ff { $$ = new Nodo("ajuste", "ff"); }
    | wf { $$ = new Nodo("ajuste", "wf"); };

FDISK: FDISK PARAMETRO_FK {
        $$ = $1;
        $$->add(*$2);
    }
    | PARAMETRO_FK {
        $$ = new Nodo("PARAMETRO", "");
        $$->add(*$1);
    };

PARAMETRO_FK: PARAMETRO_MK { $$ = $1; }
    |mayor name igual identificador { $$ = new Nodo("name", $4); }
    |mayor name igual cadena { $$ = new Nodo("name", $4); }
    |mayor type igual caracter { $$ = new Nodo("type", $4); }
    |mayor del_ igual full { $$ = new Nodo("delete", "full"); }
    |mayor add igual entero { $$ = new Nodo("add", $4); };

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

PARAMETRO_R: mayor path igual cadena { $$ = new Nodo("path", $4); }
    |mayor path igual ruta { $$ = new Nodo("path", $4); }
    |mayor rutaRep igual cadena { $$ = new Nodo("ruta", $4); }
    |mayor rutaRep igual ruta { $$ = new Nodo("ruta", $4); }
    |mayor id igual identificador { $$ = new Nodo("id", $4); }
    |mayor name igual mbr { $$ = new Nodo("name","mbr"); }
    |mayor name igual disk { $$ = new Nodo("name","disk"); }
    |mayor name igual inode { $$ = new Nodo("name", "inode"); }
    |mayor name igual journaling { $$ = new Nodo("name", "journaling"); }
    |mayor name igual block { $$ = new Nodo("name", "block"); }
    |mayor name igual bm_inode { $$ = new Nodo("name", "bm_inode"); }
    |mayor name igual bm_block { $$ = new Nodo("name", "bm_block"); }
    |mayor name igual tree { $$ = new Nodo("name", "tree"); }
    |mayor name igual sb { $$ = new Nodo("name", "sb"); }
    |mayor name igual fileRep { $$ = new Nodo("name", "file"); }
    |mayor name igual ls { $$ = new Nodo("name", "ls"); };

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

MOUNT: MOUNT PARAMETRO_M 
    {
        $$ = $1;
        $$->add(*$2);
    }
    | PARAMETRO_M {
        $$ = new Nodo("PARAMETRO", "");
        $$->add(*$1);
    };

PARAMETRO_M:mayor path igual cadena { $$ = new Nodo("path", $4); }
    |mayor path igual ruta { $$ = new Nodo("path", $4); }
    |mayor name igual identificador { $$ = new Nodo("name", $4); }
    |mayor name igual cadena { $$ = new Nodo("name", $4); };

UNMOUNT:unmount mayor id igual identificador
    {
        $$ = new Nodo("UNMOUNT", "");
        Nodo *n = new Nodo("id", $5);
        $$->add(*n);
    };

MKFS: MKFS PARAM_MKFS {
        $$ = $1;
        $$->add(*$2);
    }
    | PARAM_MKFS {
        $$ = new Nodo("PARAMETRO", "");
        $$->add(*$1);
    };

PARAM_MKFS:mayor id igual identificador { $$ = new Nodo("id", $4); }
    |mayor type igual full { $$ = new Nodo("type", "full"); }
    |mayor fs igual fs2 { $$ = new Nodo("fs", "2fs"); }
    |mayor fs igual fs3 { $$ = new Nodo("fs", "3fs"); };

LOGIN: LOGIN PARAM_LOGIN
    {
        $$ = $1;
        $$->add(*$2);
    }
    |PARAM_LOGIN
    {
        $$ = new Nodo("PARAMETRO", "");
        $$->add(*$1);
    };

PARAM_LOGIN:mayor usuario igual identificador { $$ = new Nodo("usuario", $4); }
    |mayor usuario igual cadena { $$ = new Nodo("usuario", $4); }
    |mayor password igual entero { $$ = new Nodo("password", $4); }
    | mayor password igual identificador { $$ = new Nodo("password", $4); }
    | mayor password igual pwd { $$ = new Nodo("password", $4); }
    | mayor password igual cadena { $$ = new Nodo("password", $4); }
    | mayor id igual identificador { $$ = new Nodo("id", $4); };

MKGRP: mkgrp mayor name igual identificador {
                                        $$ = new Nodo("MKGRP","");
                                        Nodo *n = new Nodo("name",$5);
                                        $$->add(*n);
                                      }
       | mkgrp mayor name igual cadena {
                                    $$ = new Nodo("MKGRP","");
                                    Nodo *n = new Nodo("name",$5);
                                    $$->add(*n);
                                 };

RMGRP:rmgrp mayor name igual identificador 
    {
        $$ = new Nodo("RMGRP","");
        Nodo *n = new Nodo("name", $5);
        $$->add(*n);
    }
    |rmgrp mayor name igual cadena 
    {
        $$ = new Nodo("RMGRP", "");
        Nodo *n = new Nodo("name",$5);
        $$->add(*n);
    };

MKUSR: MKUSR PARAM_MKUSR 
    {
        $$ = $1;
        $$->add(*$2);
    }
    |PARAM_MKUSR 
    {
        $$ = new Nodo("PARAMETRO", "");
        $$->add(*$1);
    };

PARAM_MKUSR:mayor usuario igual identificador { $$ = new Nodo("usuario", $4); }
            |mayor usuario igual cadena { $$ = new Nodo("usuario", $4); }
            |mayor password igual entero { $$ = new Nodo("password", $4); }
            |mayor password igual identificador { $$ = new Nodo("password", $4); }
            |mayor password igual pwd { $$ = new Nodo("password", $4); }
            |mayor password igual cadena { $$ = new Nodo("password", $4); }
            |mayor grp igual identificador { $$ = new Nodo("group", $4); }
            |mayor grp igual cadena { $$ = new Nodo("group",$4); };

RMUSR:rmusr mayor usuario igual identificador 
    {
        $$ = new Nodo("RMUSR","");
        Nodo *n = new Nodo("user",$5);
        $$->add(*n);
    }
    |rmusr mayor usuario igual cadena 
    {
        $$ = new Nodo("RMUSR", "");
        Nodo *n = new Nodo("user",$5);
        $$->add(*n);
    };

CHMOD: CHMOD PARAM_CHMOD 
    {
        $$ = $1;
        $$->add(*$2);
    }
    | PARAM_CHMOD 
    {
       $$ = new Nodo("PARAMETRO","");
        $$->add(*$1);
    };

PARAM_CHMOD:mayor path igual cadena { $$ = new Nodo("path",$4); }
            |mayor path igual directorioA { $$ = new Nodo("path",$4); }
            |mayor ugo igual entero { $$ = new Nodo("ugo",$4); }
            |mayor r { $$ = new Nodo("r",""); };

MKFILE: MKFILE PARAM_MKFILE 
    {
        $$ = $1;
        $$->add(*$2);
    }
    | PARAM_MKFILE{
        $$ = new Nodo("PARAMETRO","");
        $$->add(*$1);
    };


PARAM_MKFILE:mayor path igual ruta { $$ = new Nodo("path",$4); }
            |mayor path igual cadena { $$ = new Nodo("path",$4); }
            |mayor sizeS igual entero { $$ = new Nodo("size",$4); }
            |mayor cont igual ruta { $$ = new Nodo("cont",$4); }
            |mayor cont igual cadena { $$ = new Nodo("cont",$4); }
            |mayor r { $$ = new Nodo("r",""); };

CAT: CAT LTS_FILE
    {
        $$ = $1;
        $$->add(*$2);
    }
    | LTS_FILE
    {
        $$ = new Nodo("PARAMETRO", "");
        $$->add(*$1);
    };

LTS_FILE:mayor identificador igual ruta { $$ = new Nodo($2, $4); }
        |mayor identificador igual cadena { $$ = new Nodo($2, $4); };

REMOVE:removeR mayor path igual ruta 
    {
        $$ = new Nodo("REMOVE", "");
        Nodo *n = new Nodo("path", $5);
        $$->add(*n);
    }
    |removeR mayor path igual cadena
    {
        $$ = new Nodo("REMOVE", "");
        Nodo *n = new Nodo("path", $5);
        $$->add(*n);
    }
    |removeR mayor path igual directorioA
    {
        $$ = new Nodo("REMOVE", "");
        Nodo *n = new Nodo("path", $5);
        $$->add(*n);
    };

EDIT: EDIT PARAM_EDIT 
        {
            $$ = $1;
            $$->add(*$2);
        }
        |PARAM_EDIT 
        {
            $$ = new Nodo("PARAMETRO","");
            $$->add(*$1);
        };

PARAM_EDIT:mayor path igual ruta { $$ = new Nodo("path",$4); }
            |mayor path igual cadena { $$ = new Nodo("path",$4); }
            |mayor cont igual cadena { $$ = new Nodo("cont", $4); };

RENAME: RENAME PARAM_RENAME 
    {
        $$ = $1;
        $$->add(*$2);
    }
    |PARAM_RENAME 
    {
        $$ = new Nodo("PARAMETRO","");
        $$->add(*$1);
    };

PARAM_RENAME:mayor path igual ruta { $$ = new Nodo("path", $4); }
        |mayor path igual cadena { $$ = new Nodo("path",$4); }
        |mayor name igual identificador extension 
        {
            $$ = new Nodo("name","");
            Nodo *n = new Nodo($4,$5);
            $$->add(*n);
        }
        |mayor name igual cadena { $$ = new Nodo("name",$4); };