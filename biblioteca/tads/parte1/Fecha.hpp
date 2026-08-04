#ifndef FECHA_H
#define FECHA_H

#include <string>

#include "../../funciones/millis.hpp"

using std::string;
using std::to_string;

// ============================
// Estructura
// ============================

struct Fecha
{
};

// prototipos de 
int fechaGetAnio(Fecha f);
int fechaGetMes(Fecha f);
int fechaGetDia(Fecha f);
int fechaGetHora(Fecha f);
int fechaGetMinuto(Fecha f);
int fechaGetSegundo(Fecha f);
void fechaSetAnio(Fecha& f, int anio);
void fechaSetMes(Fecha& f, int mes);
void fechaSetDia(Fecha& f, int dia);
void fechaSetHora(Fecha& f, int hora);
void fechaSetMinuto(Fecha& f, int minuto);
void fechaSetSegundo(Fecha& f, int segundo);
int fechaGetMillis(Fecha& f,int millis);
void fechaSetMillis(Fecha& f,int millis);

Fecha fecha(long long ts)
{
    Fecha f;
    return f;
}

Fecha fecha()
{
    Fecha f;
    return f;
}

Fecha fecha(int anio, int mes, int dia, int hora, int min)
{
    Fecha f;
    return f;
}

Fecha fecha(int anio, int mes, int dia)
{
    Fecha f;
    return f;
}

long long fechaInMillis(Fecha f)
{
    return 0;
}

Fecha fechaAddSegundos(Fecha f, long long n)
{
    Fecha x;
    return x;
}

Fecha fechaAddMinutos(Fecha f, long long n)
{
    Fecha x;
    return x;
}

Fecha fechaAddHoras(Fecha f, long long n)
{
    Fecha x;
    return x;
}

Fecha fechaAddDias(Fecha f, long long n)
{
    Fecha x;
    return x;
}

long long fechaDiffMillis(Fecha a, Fecha b)
{
    return 0;
}

int fechaDiffDias(Fecha a, Fecha b)
{
    return 0;
}

int fechaCmp(Fecha a, Fecha b)
{
    return 0;
}

int fechaCmpDiaMesAnio(Fecha a, Fecha b)
{
    return 0;
}

string fechaToString(Fecha f)
{
    return "";
}

bool fechaEsAnioBisiesto(int anio)
{
    return false;
}

bool fechaEsAnioBisiesto(Fecha f)
{
    return false;
}

int fechaDiasEnMes(int m, int a)
{
    return 0;
}

int fechaDiasEnMes(Fecha f)
{
    return 0;
}

int fechaDiaDelAnio(Fecha f)
{
    return 0;
}

bool fechaEsValida(Fecha f)
{
    return false;
}

bool fechaEsHoy(Fecha f)
{
    return false;
}

// =================
// Setters y getters
// =================

int fechaGetAnio(Fecha f)
{
    return 0;
}

int fechaGetMes(Fecha f)
{
    return 0;
}

int fechaGetDia(Fecha f)
{
    return 0;
}

int fechaGetHora(Fecha f)
{
    return 0;
}

int fechaGetMinuto(Fecha f)
{
    return 0;
}

int fechaGetSegundo(Fecha f)
{
    return 0;
}

void fechaSetAnio(Fecha& f, int anio)
{
}

void fechaSetMes(Fecha& f, int mes)
{
}

void fechaSetDia(Fecha& f, int dia)
{
}

void fechaSetHora(Fecha& f, int hora)
{
}

void fechaSetMinuto(Fecha& f, int minuto)
{
}

void fechaSetSegundo(Fecha& f, int segundo)
{
}

int fechaGetMillis(Fecha& f,int millis)
{
    return 0;
}

void fechaSetMillis(Fecha& f,int millis)
{
}

#endif  // FECHA_H