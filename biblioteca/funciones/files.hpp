#ifndef _TFILES_T_
#define _TFILES_T_

#include <stdio.h>

#include <cassert>
#include <iostream>

#include "strings.hpp"

template <typename T>
void write(FILE* f, T t)
{
}

template <typename T>
T read(FILE* f)
{
    T t;
    return t;
}

template <typename T>
int fileSize(FILE* f)
{
    return 0;
}

template <typename T>
void seek(FILE* f, int n)
{
}

template <typename T>
int filePos(FILE* f)
{
    return 0;
}

// --- manejor de archivos de texto ---

bool readLine(FILE* f, string& ln, long long& byteNo)
{
    return false;
}

bool readLine(FILE* f, string& ln)
{
    return false;
}

// -- ATENCION: IMPLEMENTAR DESPUES DE LA LECCION 13 --
bool readLine(FILE* f,string*& fields,int& len,char sep)
{
    return false;
}


bool readWord(FILE* f, string& w, string alsoAllowed)
{
    return false;
}

bool readWord(FILE* f, string& w)
{
    return false;
}

void writeString(FILE* f, string s)
{
}

void writeWord(FILE* f, string w)
{
}

void writeLine(FILE* f, string ln)
{
}

#endif
