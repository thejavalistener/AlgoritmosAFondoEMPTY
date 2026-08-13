#include <cassert>
#include <iostream>

#include "Stack.hpp"

using std::cout;
using std::endl;

// -- PROTOTIPOS --
void testStack();
void testStackPush();
void testStackPop();
void testStackIsEmpty();
void testStackSize();

// -- MAIN --
int main()
{
   testStack();
//    testStackPush();
//    testStackPop();
//    testStackIsEmpty();
//    testStackSize();

   cout << "Todos los tests de Stack pasaron correctamente." << endl;
   return 0;
}



Stack<int> buildStack()
{
   Stack<int> st = stack<int>();
   stackPush<int>(st, 10);
   stackPush<int>(st, 20);
   stackPush<int>(st, 30);
   return st;
}

void testStack()
{
   Stack<int> st = stack<int>();

   assert(st.p == NULL);
   assert(st.size == 0);
}

void testStackPush()
{
   Stack<int> st = stack<int>();

   int* p1 = stackPush<int>(st, 10);
   int* p2 = stackPush<int>(st, 20);

   assert(p1 != NULL);
   assert(p2 != NULL);
   assert(*p1 == 10);
   assert(*p2 == 20);
   assert(st.p != NULL);
   assert(st.size == 2);
   assert(st.p->info == 20);
}

void testStackPop()
{
   Stack<int> st = buildStack();

   int v1 = stackPop<int>(st);
   int v2 = stackPop<int>(st);
   int v3 = stackPop<int>(st);

   assert(v1 == 30);
   assert(v2 == 20);
   assert(v3 == 10);
   assert(st.size == 0);
   assert(st.p == NULL);
}

void testStackIsEmpty()
{
   Stack<int> st = stack<int>();
   assert(stackIsEmpty<int>(st));

   stackPush<int>(st, 1);
   assert(!stackIsEmpty<int>(st));
}

void testStackSize()
{
   Stack<int> st = buildStack();
   assert(stackSize<int>(st) == 3);
}

