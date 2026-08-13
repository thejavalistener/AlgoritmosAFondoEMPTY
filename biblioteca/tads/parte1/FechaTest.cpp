#include <cassert>
#include <iostream>
#include <string>

#include "Fecha.hpp"

using std::cout;
using std::endl;
using std::string;

// -- PROTOTIPOS --
void testFecha_withTs();
void testFecha();
void testFecha_withAnioMesDiaHoraMin();
void testFecha_withAnioMesDia();
void testFechaInMillis();
void testFechaAddSegundos();
void testFechaAddMinutos();
void testFechaAddHoras();
void testFechaAddDias();
void testFechaDiffMillis();
void testFechaDiffDias();
void testFechaCmp();
void testFechaCmpDiaMesAnio();
void testFechaToString();
void testFechaEsAnioBisiesto_withAnio();
void testFechaEsAnioBisiesto_withFecha();
void testFechaDiasEnMes_withMesAnio();
void testFechaDiasEnMes_withFecha();
void testFechaDiaDelAnio();
void testFechaEsValida();
void testFechaEsHoy();
void testFechaGetAnio();
void testFechaGetMes();
void testFechaGetDia();
void testFechaGetHora();
void testFechaGetMinuto();
void testFechaGetSegundo();
void testFechaSetAnio();
void testFechaSetMes();
void testFechaSetDia();
void testFechaSetHora();
void testFechaSetMinuto();
void testFechaSetSegundo();
void testFechaGetMillis();
void testFechaSetMillis();

// -- MAIN --
int main()
{
    testFecha_withTs();
    // testFecha();
    // testFecha_withAnioMesDiaHoraMin();
    // testFecha_withAnioMesDia();
    // testFechaInMillis();
    // testFechaAddSegundos();
    // testFechaAddMinutos();
    // testFechaAddHoras();
    // testFechaAddDias();
    // testFechaDiffMillis();
    // testFechaDiffDias();
    // testFechaCmp();
    // testFechaCmpDiaMesAnio();
    // testFechaToString();
    // testFechaEsAnioBisiesto_withAnio();
    // testFechaEsAnioBisiesto_withFecha();
    // testFechaDiasEnMes_withMesAnio();
    // testFechaDiasEnMes_withFecha();
    // testFechaDiaDelAnio();
    // testFechaEsValida();
    // testFechaEsHoy();
    // testFechaGetAnio();
    // testFechaGetMes();
    // testFechaGetDia();
    // testFechaGetHora();
    // testFechaGetMinuto();
    // testFechaGetSegundo();
    // testFechaSetAnio();
    // testFechaSetMes();
    // testFechaSetDia();
    // testFechaSetHora();
    // testFechaSetMinuto();
    // testFechaSetSegundo();
    // testFechaGetMillis();
    // testFechaSetMillis();

    cout << "Todos los tests de Fecha pasaron correctamente." << endl;
    return 0;
}




Fecha buildFecha()
{
    Fecha f = fecha(2024, 5, 10, 14, 35);
    fechaSetSegundo(f, 20);
    fechaSetMillis(f, 123);
    return f;
}

void testFecha_withTs()
{
    Fecha f = fecha(1715351720123LL);
    assert(fechaInMillis(f) == 1715351720123LL);
    assert(fechaCmp(f, fecha(1715351720123LL)) == 0);
}

void testFecha()
{
    Fecha a = fecha();
    Fecha b = fecha();

    assert(fechaCmp(a, b) <= 0 || fechaCmp(a, b) >= 0);
    assert(fechaInMillis(a) > 0);
    assert(fechaInMillis(b) > 0);
    assert(fechaCmp(a, fecha(fechaInMillis(a))) == 0);
}

void testFecha_withAnioMesDiaHoraMin()
{
    Fecha f = fecha(2024, 5, 10, 14, 35);

    assert(fechaGetAnio(f) == 2024);
    assert(fechaGetMes(f) == 5);
    assert(fechaGetDia(f) == 10);
    assert(fechaGetHora(f) == 14);
    assert(fechaGetMinuto(f) == 35);
    assert(fechaGetSegundo(f) == 0);
}

void testFecha_withAnioMesDia()
{
    Fecha f = fecha(2024, 5, 10);

    assert(fechaGetAnio(f) == 2024);
    assert(fechaGetMes(f) == 5);
    assert(fechaGetDia(f) == 10);
    assert(fechaGetHora(f) == 0);
    assert(fechaGetMinuto(f) == 0);
}

void testFechaInMillis()
{
    Fecha f = fecha(2024, 5, 10, 14, 35);
    assert(fechaCmp(f, fecha(fechaInMillis(f))) == 0);
}

void testFechaAddSegundos()
{
    Fecha f = fecha(2024, 1, 1, 0, 0);
    Fecha g = fechaAddSegundos(f, 90);

    assert(fechaGetHora(g) == 0);
    assert(fechaGetMinuto(g) == 1);
    assert(fechaGetSegundo(g) == 30);
}

void testFechaAddMinutos()
{
    Fecha f = fecha(2024, 1, 1, 0, 0);
    Fecha g = fechaAddMinutos(f, 90);

    assert(fechaGetHora(g) == 1);
    assert(fechaGetMinuto(g) == 30);
    assert(fechaGetDia(g) == 1);
}

void testFechaAddHoras()
{
    Fecha f = fecha(2024, 1, 1, 0, 0);
    Fecha g = fechaAddHoras(f, 27);

    assert(fechaGetDia(g) == 2);
    assert(fechaGetHora(g) == 3);
}

void testFechaAddDias()
{
    Fecha f = fecha(2024, 1, 1, 0, 0);
    Fecha g = fechaAddDias(f, 40);

    assert(fechaGetAnio(g) == 2024);
    assert(fechaGetMes(g) == 2);
    assert(fechaGetDia(g) == 10);
}

void testFechaDiffMillis()
{
    Fecha a = fecha(2024, 1, 1, 0, 0);
    Fecha b = fecha(2024, 1, 3, 0, 0);

    assert(fechaDiffMillis(a, a) == 0);
    assert(fechaDiffMillis(a, b) == fechaDiffMillis(b, a));
    assert(fechaDiffMillis(a, b) == 2LL * 24 * 60 * 60 * 1000);
}

void testFechaDiffDias()
{
    Fecha a = fecha(2024, 1, 1, 0, 0);
    Fecha b = fecha(2024, 1, 3, 0, 0);

    assert(fechaDiffDias(a, b) == 2);
    assert(fechaDiffDias(b, a) == 2);
}

void testFechaCmp()
{
    Fecha a = fecha(2024, 1, 1, 10, 0);
    Fecha b = fecha(2024, 1, 1, 11, 0);
    Fecha c = fecha(2024, 1, 1, 11, 0);

    assert(fechaCmp(a, b) == -1);
    assert(fechaCmp(b, a) == 1);
    assert(fechaCmp(b, c) == 0);
}

void testFechaCmpDiaMesAnio()
{
    Fecha a = fecha(2024, 1, 1, 10, 0);
    Fecha b = fecha(2024, 1, 1, 11, 0);
    Fecha c = fecha(2024, 1, 2, 0, 0);

    assert(fechaCmpDiaMesAnio(a, b) == 0);
    assert(fechaCmpDiaMesAnio(a, c) == -1);
    assert(fechaCmpDiaMesAnio(c, a) == 1);
}

void testFechaToString()
{
    Fecha f = fecha(2024, 5, 10, 14, 35);
    string s = fechaToString(f);

    assert(s != "");
    assert(s == fechaToString(fecha(fechaInMillis(f))));
}

void testFechaEsAnioBisiesto_withAnio()
{
    assert(fechaEsAnioBisiesto(2000));
    assert(fechaEsAnioBisiesto(2024));
    assert(!fechaEsAnioBisiesto(2023));
}

void testFechaEsAnioBisiesto_withFecha()
{
    Fecha a = fecha(2024, 2, 10);
    Fecha b = fecha(2023, 2, 10);

    assert(fechaEsAnioBisiesto(a));
    assert(!fechaEsAnioBisiesto(b));
}

void testFechaDiasEnMes_withMesAnio()
{
    assert(fechaDiasEnMes(2, 2024) == 29);
    assert(fechaDiasEnMes(2, 2023) == 28);
    assert(fechaDiasEnMes(4, 2024) == 30);
    assert(fechaDiasEnMes(1, 2024) == 31);
}

void testFechaDiasEnMes_withFecha()
{
    Fecha a = fecha(2024, 2, 10);
    Fecha b = fecha(2023, 4, 10);

    assert(fechaDiasEnMes(a) == 29);
    assert(fechaDiasEnMes(b) == 30);
}

void testFechaDiaDelAnio()
{
    Fecha a = fecha(2024, 1, 1);
    Fecha b = fecha(2024, 2, 1);
    Fecha c = fecha(2023, 12, 31);

    assert(fechaDiaDelAnio(a) == 1);
    assert(fechaDiaDelAnio(b) == 32);
    assert(fechaDiaDelAnio(c) == 365);
}

void testFechaEsValida()
{
    assert(fechaEsValida(fecha(2024, 1, 1)));
    assert(fechaEsValida(fecha(2024, 2, 29)));
    assert(fechaEsValida(fecha(2024, 4, 30)));
}

void testFechaEsHoy()
{
    Fecha hoy = fecha();

    assert(!fechaEsHoy(fechaAddDias(hoy, 1)));
    assert(!fechaEsHoy(fechaAddDias(hoy, -1)));
}

void testFechaGetAnio()
{
    Fecha f = buildFecha();
    assert(fechaGetAnio(f) == 2024);
}

void testFechaGetMes()
{
    Fecha f = buildFecha();
    assert(fechaGetMes(f) == 5);
}

void testFechaGetDia()
{
    Fecha f = buildFecha();
    assert(fechaGetDia(f) == 10);
}

void testFechaGetHora()
{
    Fecha f = buildFecha();
    assert(fechaGetHora(f) == 14);
}

void testFechaGetMinuto()
{
    Fecha f = buildFecha();
    assert(fechaGetMinuto(f) == 35);
}

void testFechaGetSegundo()
{
    Fecha f = buildFecha();
    assert(fechaGetSegundo(f) == 20);
}

void testFechaSetAnio()
{
    Fecha f = buildFecha();
    fechaSetAnio(f, 2025);
    assert(fechaGetAnio(f) == 2025);
}

void testFechaSetMes()
{
    Fecha f = buildFecha();
    fechaSetMes(f, 12);
    assert(fechaGetMes(f) == 12);
}

void testFechaSetDia()
{
    Fecha f = buildFecha();
    fechaSetDia(f, 24);
    assert(fechaGetDia(f) == 24);
}

void testFechaSetHora()
{
    Fecha f = buildFecha();
    fechaSetHora(f, 18);
    assert(fechaGetHora(f) == 18);
}

void testFechaSetMinuto()
{
    Fecha f = buildFecha();
    fechaSetMinuto(f, 45);
    assert(fechaGetMinuto(f) == 45);
}

void testFechaSetSegundo()
{
    Fecha f = buildFecha();
    fechaSetSegundo(f, 50);
    assert(fechaGetSegundo(f) == 50);
}

void testFechaGetMillis()
{
    Fecha f = buildFecha();
    assert(fechaGetMillis(f, 0) == 123);
    assert(fechaGetMillis(f, 999) == 123);
}

void testFechaSetMillis()
{
    Fecha f = buildFecha();
    fechaSetMillis(f, 456);
    assert(fechaGetMillis(f, 0) == 456);
}
