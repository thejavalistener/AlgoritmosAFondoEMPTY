#include <cassert>
#include <iostream>

#include "Timer.hpp"

using std::cout;
using std::endl;

void testTimer();
void testTimerStart();
void testTimerStop();
void testTimerElapsedTime();

int main()
{
    testTimer();
    // testTimerStart();
    // testTimerStop();
    // testTimerElapsedTime();

    cout << "Todos los tests de Timer pasaron correctamente." << endl;
    return 0;
}



void testTimer()
{
    Timer t = timer();

    assert(timerElapsedTime(t) == 0);
}

void testTimerStart()
{
    Timer t = timer();

    timerStart(t);
    timerStop(t);

    assert(timerElapsedTime(t) >= 0);
}

void testTimerStop()
{
    Timer t = timer();
    timerStart(t);

    timerStop(t);

    assert(timerElapsedTime(t) >= 0);
}

void testTimerElapsedTime()
{
    Timer t = timer();
    timerStart(t);
    timerStop(t);

    assert(timerElapsedTime(t) >= 0);
}
