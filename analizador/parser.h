/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    mkdisk = 258,                  /* mkdisk  */
    rep = 259,                     /* rep  */
    execute = 260,                 /* execute  */
    fdisk = 261,                   /* fdisk  */
    mayor = 262,                   /* mayor  */
    path = 263,                    /* path  */
    igual = 264,                   /* igual  */
    entero = 265,                  /* entero  */
    txt = 266,                     /* txt  */
    sizeS = 267,                   /* sizeS  */
    unit = 268,                    /* unit  */
    type = 269,                    /* type  */
    name = 270,                    /* name  */
    caracter = 271,                /* caracter  */
    identificador = 272,           /* identificador  */
    extension = 273,               /* extension  */
    ruta = 274,                    /* ruta  */
    cadena = 275,                  /* cadena  */
    exitS = 276,                   /* exitS  */
    fit = 277,                     /* fit  */
    bf = 278,                      /* bf  */
    ff = 279,                      /* ff  */
    wf = 280,                      /* wf  */
    del_ = 281,                    /* del_  */
    add = 282,                     /* add  */
    full = 283,                    /* full  */
    rmdisk = 284,                  /* rmdisk  */
    mount = 285,                   /* mount  */
    unmount = 286,                 /* unmount  */
    id = 287,                      /* id  */
    mkfs = 288,                    /* mkfs  */
    fs = 289,                      /* fs  */
    fs2 = 290,                     /* fs2  */
    fs3 = 291,                     /* fs3  */
    login = 292,                   /* login  */
    logout = 293,                  /* logout  */
    pausa = 294,                   /* pausa  */
    usuario = 295,                 /* usuario  */
    password = 296,                /* password  */
    pwd = 297,                     /* pwd  */
    rutaRep = 298,                 /* rutaRep  */
    disk = 299,                    /* disk  */
    inode = 300,                   /* inode  */
    journaling = 301,              /* journaling  */
    block = 302,                   /* block  */
    bm_inode = 303,                /* bm_inode  */
    bm_block = 304,                /* bm_block  */
    tree = 305,                    /* tree  */
    sb = 306,                      /* sb  */
    fileRep = 307,                 /* fileRep  */
    ls = 308,                      /* ls  */
    mbr = 309                      /* mbr  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "ASintactico.y"

    char text[400];
    class Nodo *nodo;

#line 123 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
