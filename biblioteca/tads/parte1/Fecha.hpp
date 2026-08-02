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
    long long ts;
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
    return {ts};
}

Fecha fecha()
{
    return {currTimeMillis()};
}

Fecha fecha(int anio, int mes, int dia, int hora, int min)
{
    return {attributesToMillis(anio, mes, dia, hora, min, 0, 0)};
}

Fecha fecha(int anio, int mes, int dia)
{
    return fecha(anio, mes, dia, 0, 0);
}

long long fechaInMillis(Fecha f)
{
    return f.ts;
}

Fecha fechaAddSegundos(Fecha f, int n)
{
    long long x = f.ts + n * 1000;
    return {x};
}

Fecha fechaAddMinutos(Fecha f, int n)
{
    return fechaAddSegundos(f, n * 60);
}

Fecha fechaAddHoras(Fecha f, int n)
{
    return fechaAddMinutos(f, n * 60);
}

Fecha fechaAddDias(Fecha f, int n)
{
    return fechaAddHoras(f, n * 24);
}

long long fechaDiffMillis(Fecha a, Fecha b)
{
    long long x = a.ts - b.ts;
    return x < 0 ? x * -1 : x;
}

int fechaDiffDias(Fecha a, Fecha b)
{
    int dias = fechaDiffMillis(a, b) / (1000 * 60 * 60 * 24);
    return dias;
}

int fechaCmp(Fecha a, Fecha b)
{
    long long x = a.ts - b.ts;
    return x < 0 ? -1 : x > 0 ? 1 : 0;
}

int fechaCmpDiaMesAnio(Fecha a, Fecha b)
{
    long long la = attributesToMillis(fechaGetAnio(a),fechaGetMes(a),fechaGetDia(a),0,0,0,0);
    long long lb = attributesToMillis(fechaGetAnio(b),fechaGetMes(b),fechaGetDia(b),0,0,0,0);
    long long x = la-lb;
    return x < 0 ? -1 : x > 0 ? 1 : 0;
}

string fechaToString(Fecha f)
{
    return millisToString(f.ts);
}

bool fechaEsAnioBisiesto(int anio)
{
    return anio % 100 == 100 || anio % 400 == 0 && anio % 100 != 0;
}

bool fechaEsAnioBisiesto(Fecha f)
{
    int a = fechaGetAnio(f);
    return fechaEsAnioBisiesto(a);
}

int fechaDiasEnMes(int m, int a)
{
    if(m == 2 && fechaEsAnioBisiesto(a)) return 29;
    if(m == 2 && !fechaEsAnioBisiesto(a)) return 28;
    if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

int fechaDiasEnMes(Fecha f)
{
    return fechaDiasEnMes(fechaGetMes(f), fechaGetAnio(f));
}

int fechaDiaDelAnio(Fecha f)
{
    int d = fechaGetDia(f);
    int m = fechaGetMes(f);
    int a = fechaGetAnio(f);

    int total = d;

    for(int i = 1; i < m; i++)
    {
        total += fechaDiasEnMes(i, a);
    }

    return total;
}

bool fechaEsValida(Fecha f)
{
    int d = fechaGetDia(f);
    int m = fechaGetMes(f);
    int a = fechaGetAnio(f);

    if( d>=1 && d<=fechaDiasEnMes(f) )
    {
        if( m>=1 && m<=12)
        {
            if( a>=0 )
            {
                return true;
            }
        }
    }

    return false;
}

bool fechaEsHoy(Fecha f)
{
    Fecha hoy = fecha();
    return fechaCmp(f,hoy)==0;
}

// =================
// Setters y getters
// =================

int fechaGetAnio(Fecha f)
{
    return _getYear(f.ts);
}

int fechaGetMes(Fecha f)
{
    return _getMonth(f.ts);
}

int fechaGetDia(Fecha f)
{
    return _getDay(f.ts);
}

int fechaGetHora(Fecha f)
{
    return _getHour(f.ts);
}

int fechaGetMinuto(Fecha f)
{
    return _getMinute(f.ts);
}

int fechaGetSegundo(Fecha f)
{
    return _getSecond(f.ts);
}

void fechaSetAnio(Fecha& f, int anio)
{
    _setYear(f.ts, anio);
}

void fechaSetMes(Fecha& f, int mes)
{
    _setMonth(f.ts, mes);
}

void fechaSetDia(Fecha& f, int dia)
{
    _setDay(f.ts, dia);
}

void fechaSetHora(Fecha& f, int hora)
{
    _setHour(f.ts, hora);
}

void fechaSetMinuto(Fecha& f, int minuto)
{
    _setMinute(f.ts, minuto);
}

void fechaSetSegundo(Fecha& f, int segundo)
{
    _setSecond(f.ts, segundo);
}

int fechaGetMillis(Fecha& f,int millis)
{
    return _getMillis(f.ts);
}

void fechaSetMillis(Fecha& f,int millis)
{
    _setMillis(f.ts,millis);
}

#endif  // FECHA_H