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
pwd ({Letra}|{Entero}|[!$@+*])+
directorio ({diagonal}{id})+

%x ComentarioSimple

%%

"#"                         {  BEGIN ComentarioSimple; }
"fdisk"                     {  return fdisk; }
"mkdisk"                    {  return mkdisk; }
"rep"                       {  return rep; }
"execute"                   {  return execute; }
"size"                      {  return sizeS; }
"unit"                      {  return unit; }
"name"                      {  return name; }
"type"                      {  return type; }
"fit"                       {  return fit; }
">"                         {  return mayor; }
"path"                      {  return path; }
"="                         {  return igual; }
"bf"                        {  return bf; }
"ff"                        {  return ff; }
"wf"                        {  return wf; }
"delete"                    {  return del_; }
"add"                       {  return add; }
"Full"                      {  return full; }
"Exit"                      {  return exitS; }
"rmdisk"                    {  return rmdisk; }
"mount"                     {  return mount; }
"unmount"                   {  return unmount; }
"id"                        {  return id; }
"fs"                        {  return fs; }
"2fs"                       {  return fs2; }
"3fs"                       {  return fs3; }
"mkfs"                      {  return mkfs; }
"login"                     {  return login; }
"logout"                    {  return logout; }
"pause"                     {  return pausa; }
"user"                      {  return usuario; }
"pass"                      {  return password; }
"ruta"                      {  return rutaRep;  }
"mbr"                       {  return mbr; }
"disk"                      {  return disk; }
"inode"                     {  return inode; }
"journaling"                {  return journaling; }
"block"                     {  return block; }
"bm_inode"                  {  return bm_inode; }
"bm_block"                  {  return bm_block; }
"tree"                      {  return tree; }
"sb"                        {  return sb; }
"file"                      {  return fileRep; }
"ls"                        {  return ls; }
"mkgrp"                     {  return mkgrp; }
"rmgrp"                     {  return rmgrp; }
"grp"                       {  return grp; }
"mkusr"                     {  return mkusr; }
"rmusr"                     {  return rmusr; }
"r"                         {  return r; }
"ugo"                       {  return ugo; }
"chmod"                     {  return Rchmod; }
"cont"                      {  return cont;}
"mkfile"                    {  return mkfile; }
"cat"                       {  return cat; }
"remove"                    {  return removeR; }
"edit"                      {  return edit; }
"rename"                    {  return renameR; }
"mkdir"                     {  return Rmkdir; }
"destino"                   {  return destino; }
"copy"                      {  return copyR; }
"move"                      {  return moveR; }
"recovery"                  {  return recovery; }
{Entero}                    {  strcpy(yylval.text, yytext); return entero;}
{Caracter}                  {  strcpy(yylval.text, yytext); return caracter;}
{Cadena}                    {  strcpy(yylval.text, yytext); return cadena;}
{extension}                 {  strcpy(yylval.text, yytext); return extension;}
{id}                        {  strcpy(yylval.text, yytext); return identificador;}
{ruta}                      {  strcpy(yylval.text, yytext); return ruta;}
{pwd}                       {  strcpy(yylval.text, yytext); return pwd;}
{directorio}                {  strcpy(yylval.text, yytext); return directorioA;}
{Espacios}                  {  /*NO se realiza nada*/}
.                           {  cout << "Error lexico, no se esperaba token: " << yytext << endl;}
<ComentarioSimple>.         {  /*NO se realiza nada*/}
<ComentarioSimple>"\n"      {  BEGIN INITIAL; }
%%