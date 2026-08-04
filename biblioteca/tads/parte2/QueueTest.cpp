#include <cassert>
#include <iostream>

#include "Queue.hpp"

using std::cout;
using std::endl;

void testCreateEmptyAndSize()
{
   Queue<int> q = queue<int>();
   assert(queueIsEmpty<int>(q));
   assert(queueSize<int>(q) == 0);
}

void testEnqueue()
{
   Queue<int> q = queue<int>();

   int* p1 = queueEnqueue<int>(q, 10);
   assert(p1 != NULL && *p1 == 10);
   assert(!queueIsEmpty<int>(q));
   assert(queueSize<int>(q) == 1);

   int* p2 = queueEnqueue<int>(q, 20);
   assert(p2 != NULL && *p2 == 20);
   assert(queueSize<int>(q) == 2);

   int* p3 = queueEnqueue<int>(q, 30);
   assert(p3 != NULL && *p3 == 30);
   assert(queueSize<int>(q) == 3);
}

void testDequeueFIFO()
{
   Queue<int> q = queue<int>();
   queueEnqueue<int>(q, 10);
   queueEnqueue<int>(q, 20);
   queueEnqueue<int>(q, 30);

   assert(queueDequeue<int>(q) == 10);
   assert(queueSize<int>(q) == 2);
   assert(queueDequeue<int>(q) == 20);
   assert(queueSize<int>(q) == 1);
   assert(queueDequeue<int>(q) == 30);
   assert(queueSize<int>(q) == 0);
   assert(queueIsEmpty<int>(q));
}

void testInterleavedOperations()
{
   Queue<int> q = queue<int>();
   queueEnqueue<int>(q, 1);
   queueEnqueue<int>(q, 2);
   assert(queueDequeue<int>(q) == 1);
   queueEnqueue<int>(q, 3);
   assert(queueDequeue<int>(q) == 2);
   assert(queueDequeue<int>(q) == 3);
   assert(queueIsEmpty<int>(q));
   assert(queueSize<int>(q) == 0);
}

int main()
{
   testCreateEmptyAndSize();
   testEnqueue();
   testDequeueFIFO();
   testInterleavedOperations();

   cout << "Todos los tests de Queue pasaron correctamente." << endl;
   return 0;
}
