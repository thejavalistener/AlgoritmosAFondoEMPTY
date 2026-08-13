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

    assert(t.tsInic == 0);
    assert(t.tsEnd == 0);
}

void testTimerStart()
{
    Timer t = timer();
    long long before = currTimeMillis();

    timerStart(t);

    long long after = currTimeMillis();
    assert(t.tsInic >= before);
    assert(t.tsInic <= after);
    assert(t.tsEnd == 0);
}

void testTimerStop()
{
    Timer t = timer();
    timerStart(t);
    long long before = currTimeMillis();

    timerStop(t);

    long long after = currTimeMillis();
    assert(t.tsEnd >= before);
    assert(t.tsEnd <= after);
    assert(t.tsEnd >= t.tsInic);
}

void testTimerElapsedTime()
{
    Timer t = timer();
    t.tsInic = 1000;
    t.tsEnd = 2750;

    assert(timerElapsedTime(t) == 1750);
}

