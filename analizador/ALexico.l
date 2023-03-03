%option case-insensitive
%option noyywrap
%option nounput

%{
    #include <iostream>
    #include "parser.h"
    #include "../nodo.h"
    Nodo *raiz;

    using namespace std;

    int yyfila = 1;
    int yycolum = 0;
%}

Letra [a-zñA-ZÑ]
Entero -?[0-9]+
/*Palabra "."?"/"{Letra}({Letra}|{Entero}|"_"|"/"|".")* */
diagonal "/"
id ({Letra}|{Entero}|"_"|".")+
extension "."{id}
Caracter ({Letra}|{Entero})
/*Texto -> (Palabra | ruta) */
ruta "."?({diagonal}{id})*({diagonal}{id}{extension})
Cadena "\""[^"\""]*"\""
Espacios (" "|"\r"|"\t"|"n")

%x ComentarioSimple

%%

"#"                         {  BEGIN ComentarioSimple; }
"fdisk"                     {  return fdisk;}
"mkdisk"                    {  return mkdisk;}
"rep"                       {  return rep;}
"execute"                   {  return execute;}
"size"                      {  return sizeS;}
"unit"                      {  return unit;}
"name"                      {  return name;}
"type"                      {  return type;}
"fit"                       {  return fit;}
">"                         {  return mayor;}
"path"                      {  return path;}
"="                         {  return igual;}
"bf"                        {  return bf;}
"ff"                        {  return ff;}
"wf"                        {  return wf;}
"delete"                    {  return del_;}
"add"                       {  return add;}
"Full"                      {  return full;}
"Exit"                      {  return exitS;}
"rmdisk"                    {  return rmdisk;}
{Entero}                    {  strcpy(yylval.text, yytext); return entero;}
{Caracter}                  {  strcpy(yylval.text, yytext); return caracter;}
{Cadena}                    {  strcpy(yylval.text, yytext); return cadena;}
{extension}                 {  strcpy(yylval.text, yytext); return extension;}
{id}                        {  strcpy(yylval.text, yytext); return identificador;}
{ruta}                      {  strcpy(yylval.text, yytext); return ruta;}
{Espacios}                  {  /*NO se realiza nada*/}
.                           {  cout << "Error lexico, no se esperaba token: " << yytext << endl;}
<ComentarioSimple>.         {  /*NO se realiza nada*/}
<ComentarioSimple>"\n"      {  BEGIN INITIAL; }
%%