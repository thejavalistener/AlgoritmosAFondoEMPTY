#include <cassert>
#include <iostream>
#include <string>

#include "Fecha.hpp"

using std::cout;
using std::endl;
using std::string;

void testConstructorsAndGetters()
{
    Fecha f1 = fecha(2024, 5, 10);
    assert(fechaGetAnio(f1) == 2024);
    assert(fechaGetMes(f1) == 5);
    assert(fechaGetDia(f1) == 10);
    assert(fechaGetHora(f1) == 0);
    assert(fechaGetMinuto(f1) == 0);
    assert(fechaGetSegundo(f1) == 0);

    Fecha f2 = fecha(2024, 5, 10, 14, 35);
    assert(fechaGetAnio(f2) == 2024);
    assert(fechaGetMes(f2) == 5);
    assert(fechaGetDia(f2) == 10);
    assert(fechaGetHora(f2) == 14);
    assert(fechaGetMinuto(f2) == 35);
    assert(fechaGetSegundo(f2) == 0);

    Fecha f3 = fecha(fechaInMillis(f2));
    assert(fechaCmp(f2, f3) == 0);
}

void testSetters()
{
    Fecha f = fecha(2024, 1, 1, 0, 0);

    fechaSetAnio(f, 2025);
    fechaSetMes(f, 12);
    fechaSetDia(f, 24);
    fechaSetHora(f, 18);
    fechaSetMinuto(f, 45);
    fechaSetSegundo(f, 50);
    fechaSetMillis(f, 123);

    assert(fechaGetAnio(f) == 2025);
    assert(fechaGetMes(f) == 12);
    assert(fechaGetDia(f) == 24);
    assert(fechaGetHora(f) == 18);
    assert(fechaGetMinuto(f) == 45);
    assert(fechaGetSegundo(f) == 50);
    assert(fechaGetMillis(f, 0) == 123);
}

void testAddersAndDiffs()
{
    Fecha base = fecha(2024, 1, 1, 0, 0);

    Fecha plusSeconds = fechaAddSegundos(base, 90);
    assert(fechaGetHora(plusSeconds) == 0);
    assert(fechaGetMinuto(plusSeconds) == 1);
    assert(fechaGetSegundo(plusSeconds) == 30);

    Fecha plusMinutes = fechaAddMinutos(base, 90);
    assert(fechaGetHora(plusMinutes) == 1);
    assert(fechaGetMinuto(plusMinutes) == 30);

    Fecha plusHours = fechaAddHoras(base, 27);
    assert(fechaGetDia(plusHours) == 2);
    assert(fechaGetHora(plusHours) == 3);

    Fecha plusDays = fechaAddDias(base, 40);
    assert(fechaGetAnio(plusDays) == 2024);
    assert(fechaGetMes(plusDays) == 2);
    assert(fechaGetDia(plusDays) == 10);

    Fecha f1 = fecha(2024, 1, 1, 0, 0);
    Fecha f2 = fecha(2024, 1, 3, 0, 0);
    assert(fechaDiffDias(f1, f2) == 2);
    assert(fechaDiffDias(f2, f1) == 2);
    assert(fechaDiffMillis(f1, f1) == 0);
    assert(fechaDiffMillis(f2, f1) == fechaDiffMillis(f1, f2));
}

void testComparisons()
{
    Fecha a = fecha(2024, 1, 1, 10, 0);
    Fecha b = fecha(2024, 1, 1, 11, 0);
    Fecha c = fecha(2024, 1, 1, 11, 0);
    Fecha d = fecha(2024, 1, 2, 0, 0);

    assert(fechaCmp(a, b) == -1);
    assert(fechaCmp(b, a) == 1);
    assert(fechaCmp(b, c) == 0);

    assert(fechaCmpDiaMesAnio(a, b) == 0);
    assert(fechaCmpDiaMesAnio(a, d) == -1);
    assert(fechaCmpDiaMesAnio(d, a) == 1);
}

void testLeapYearAndDaysInMonth()
{
    assert(fechaEsAnioBisiesto(2000));
    assert(fechaEsAnioBisiesto(2024));
    assert(!fechaEsAnioBisiesto(2023));

    Fecha feb2024 = fecha(2024, 2, 10);
    Fecha feb2023 = fecha(2023, 2, 10);
    Fecha apr2024 = fecha(2024, 4, 10);
    Fecha jan2024 = fecha(2024, 1, 10);

    assert(fechaEsAnioBisiesto(feb2024));
    assert(!fechaEsAnioBisiesto(feb2023));
    assert(fechaDiasEnMes(2, 2024) == 29);
    assert(fechaDiasEnMes(2, 2023) == 28);
    assert(fechaDiasEnMes(4, 2024) == 30);
    assert(fechaDiasEnMes(1, 2024) == 31);
    assert(fechaDiasEnMes(feb2024) == 29);
    assert(fechaDiasEnMes(feb2023) == 28);
    assert(fechaDiasEnMes(apr2024) == 30);
    assert(fechaDiasEnMes(jan2024) == 31);
}

void testDayOfYearAndValidity()
{
    Fecha f1 = fecha(2024, 1, 1);
    Fecha f2 = fecha(2024, 2, 1);
    Fecha f3 = fecha(2023, 12, 31);

    assert(fechaDiaDelAnio(f1) == 1);
    assert(fechaDiaDelAnio(f2) == 32);
    assert(fechaDiaDelAnio(f3) == 365);

    assert(fechaEsValida(f1));
    assert(fechaEsValida(fecha(2024, 2, 29)));
    assert(fechaEsValida(fecha(2024, 4, 30)));
}

void testToStringAndToday()
{
    Fecha hoy = fecha();
    string s1 = fechaToString(hoy);
    string s2 = fechaToString(fecha(fechaInMillis(hoy)));

    assert(s1 != "");
    assert(s1 == s2);
    assert(!fechaEsHoy(fechaAddDias(hoy, 1)));
    assert(!fechaEsHoy(fechaAddDias(hoy, -1)));
}

int main()
{
    testConstructorsAndGetters();
    testSetters();
    testAddersAndDiffs();
    testComparisons();
    testLeapYearAndDaysInMonth();
    testDayOfYearAndValidity();
    testToStringAndToday();

    cout << "Todos los tests de Fecha pasaron correctamente." << endl;
    return 0;
}
