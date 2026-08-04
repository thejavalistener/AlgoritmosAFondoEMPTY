
#ifndef _TTIMER_
#define _TTIMER_

#include "../../../biblioteca/funciones/millis.hpp"

struct Timer
{
};

// funcion de inicializacion
Timer timer()
{
    Timer t;
    return t;
}

// instante inicial (i)
void timerStart(Timer& t)
{
}

// instante final (f)
void timerStop(Timer& t)
{
}

// retorna el tiempo transcurrido entre f e i,
// expresado en milisegundos
long long timerElapsedTime(Timer t)
{
    return 0;
}

#endif
