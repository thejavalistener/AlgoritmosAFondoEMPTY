#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>
#include <cassert>
#include "strings.hpp"

template<typename T> void write(FILE* f, T t)
{
   assert(f != NULL && "El puntero al archivo no puede ser nulo");
   fseek(f,0,SEEK_CUR);
   fwrite(&t, sizeof(T), 1, f);
}

template<typename T> T read(FILE* f)
{
   assert(f != NULL && "El puntero al archivo no puede ser nulo");
   T buff;
   fseek(f,0,SEEK_CUR);
   fread(&buff, sizeof(T), 1, f);
   return buff;
}

template<typename T> int fileSize(FILE* f)
{
   assert(f != NULL && "El puntero al archivo no puede ser nulo");
   // tomo la posicion actual
   int curr=ftell(f);

   // muevo el puntero al final del archivo
   fseek(f,0,SEEK_END);  // SEEK_END hace referencia al final del archivo

   // tomo la posicion actual (ubicado al final)
   int ultimo=ftell(f);

   // vuelvo a donde estaba al principio
   fseek(f,curr,SEEK_SET);

   return ultimo/sizeof(T);
}

template<typename T> void seek(FILE* f, int n)
{
   assert(f != NULL && "El puntero al archivo no puede ser nulo");
   assert(n >= 0 && "El numero de registro debe ser mayor o igual a 0");
   assert(n < fileSize<T>(f) && "El numero de registro debe ser menor que la cantidad de registros del archivo");
   fseek(f,n*sizeof(T),SEEK_SET);
}

template<typename T> int filePos(FILE* f)
{
   assert(f != NULL && "El puntero al archivo no puede ser nulo");
   return ftell(f)/sizeof(T);
}

// --- manejor de archivos de texto ---

bool readLine(FILE* f,string& ln)
{
    assert(f != NULL && "El puntero al archivo no puede ser nulo");
    ln = "";
    char c;
    int n = fread(&c,1,1,f);
    while( n!=0 && c!='\n' )
    {
        if( c!='\r' )
        {
            ln+=c;
        }
    
        n = fread(&c,1,1,f);
    }

    return n != 0 || ln != "";
}

bool readWord(FILE* f,string& w,string alsoAllowed)
{
    assert(f != NULL && "El puntero al archivo no puede ser nulo");
    char c;
    int n = fread(&c,1,1,f);
    while( n>0 && (!isDigit(c) && !isLetter(c) && indexOf(alsoAllowed,c)<0) )
    {
        n = fread(&c,1,1,f);
    }

    w = "";
    while( n!=0 && (isDigit(c) || isLetter(c) || indexOf(alsoAllowed,c)>=0) )
    {
        w+=c;
        n = fread(&c,1,1,f);
    }

    return n!=0 && w!="";
}

bool readWord(FILE* f,string& w)
{
    assert(f != NULL && "El puntero al archivo no puede ser nulo");
    return readWord(f,w,"");
}

void writeString(FILE* f,string s)
{
    assert(f != NULL && "El puntero al archivo no puede ser nulo");
    fwrite(s.c_str(),1,s.length(),f);
}

void writeWord(FILE* f,string w)
{
    assert(f != NULL && "El puntero al archivo no puede ser nulo");
    writeString(f,w);
    writeString(f," ");
}

void writeLine(FILE* f,string ln)
{
    assert(f != NULL && "El puntero al archivo no puede ser nulo");
    writeWord(f,ln);
    writeString(f,"\n");
}

#endif
