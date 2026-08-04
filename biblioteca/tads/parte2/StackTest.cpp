#include <cassert>
#include <iostream>

#include "Stack.hpp"

using std::cout;
using std::endl;

void testCreateEmptyAndSize()
{
   Stack<int> st = stack<int>();
   assert(stackIsEmpty<int>(st));
   assert(stackSize<int>(st) == 0);
}

void testPush()
{
   Stack<int> st = stack<int>();

   int* p1 = stackPush<int>(st, 10);
   assert(p1 != NULL && *p1 == 10);
   assert(!stackIsEmpty<int>(st));
   assert(stackSize<int>(st) == 1);

   int* p2 = stackPush<int>(st, 20);
   assert(p2 != NULL && *p2 == 20);
   assert(stackSize<int>(st) == 2);

   int* p3 = stackPush<int>(st, 30);
   assert(p3 != NULL && *p3 == 30);
   assert(stackSize<int>(st) == 3);
}

void testPopLIFO()
{
   Stack<int> st = stack<int>();
   stackPush<int>(st, 10);
   stackPush<int>(st, 20);
   stackPush<int>(st, 30);

   assert(stackPop<int>(st) == 30);
   assert(stackSize<int>(st) == 2);
   assert(stackPop<int>(st) == 20);
   assert(stackSize<int>(st) == 1);
   assert(stackPop<int>(st) == 10);
   assert(stackSize<int>(st) == 0);
   assert(stackIsEmpty<int>(st));
}

void testInterleavedOperations()
{
   Stack<int> st = stack<int>();
   stackPush<int>(st, 1);
   stackPush<int>(st, 2);
   assert(stackPop<int>(st) == 2);
   stackPush<int>(st, 3);
   assert(stackPop<int>(st) == 3);
   assert(stackPop<int>(st) == 1);
   assert(stackIsEmpty<int>(st));
   assert(stackSize<int>(st) == 0);
}

int main()
{
   testCreateEmptyAndSize();
   testPush();
   testPopLIFO();
   testInterleavedOperations();

   cout << "Todos los tests de Stack pasaron correctamente." << endl;
   return 0;
}
