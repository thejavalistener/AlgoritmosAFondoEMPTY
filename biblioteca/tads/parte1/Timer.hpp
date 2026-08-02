
#ifndef _TTIMER_
#define _TTIMER_

#include "../../../biblioteca/funciones/millis.hpp"

struct Timer
{
    long long tsInic;
    long long tsEnd;
};

// funcion de inicializacion
Timer timer()
{
    return {0,0};
}

// instante inicial (i)
void timerStart(Timer& t)
{
    t.tsInic = currTimeMillis();
}

// instante final (f)
void timerStop(Timer& t)
{
    t.tsEnd = currTimeMillis();
}

// retorna el tiempo transcurrido entre f e i,
// expresado en milisegundos
long long timerElapsedTime(Timer t)
{
    return t.tsEnd-t.tsInic;
}

#endif
