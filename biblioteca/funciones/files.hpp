#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"

template<typename T> void write(FILE* f, T t)
{
   fseek(f,0,SEEK_CUR);
   fwrite(&t, sizeof(T), 1, f);
}

template<typename T> T read(FILE* f)
{
   T buff;
   fseek(f,0,SEEK_CUR);
   fread(&buff, sizeof(T), 1, f);
   return buff;
}

template<typename T> void seek(FILE* f, int n)
{
   fseek(f,n*sizeof(T),SEEK_SET);
}

template<typename T> int fileSize(FILE* f)
{
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

template<typename T> int filePos(FILE* f)
{
   return ftell(f)/sizeof(T);
}

// --- manejor de archivos de texto ---

bool readLine(FILE* f,string& ln)
{
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
    return readWord(f,w,"");
}

void writeString(FILE* f,string s)
{
    fwrite(s.c_str(),1,s.length(),f);
}

void writeWord(FILE* f,string w)
{
    writeString(f,w);
    writeString(f," ");
}

void writeLine(FILE* f,string ln)
{
    writeWord(f,ln);
    writeString(f,"\n");
}

#endif
