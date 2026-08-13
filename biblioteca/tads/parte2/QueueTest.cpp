#include <cassert>
#include <iostream>

#include "Queue.hpp"

using std::cout;
using std::endl;

// -- PROTOTIPOS --
void testQueue();
void testQueueEnqueue();
void testQueueDequeue();
void testQueueIsEmpty();
void testQueueSize();

// -- MAIN --
int main()
{
   testQueue();
//    testQueueEnqueue();
//    testQueueDequeue();
//    testQueueIsEmpty();
//    testQueueSize();

   cout << "Todos los tests de Queue pasaron correctamente." << endl;
   return 0;
}



Queue<int> buildQueue()
{
   Queue<int> q = queue<int>();
   queueEnqueue<int>(q, 10);
   queueEnqueue<int>(q, 20);
   queueEnqueue<int>(q, 30);
   return q;
}

void testQueue()
{
   Queue<int> q = queue<int>();

   assert(q.p == NULL);
   assert(q.q == NULL);
   assert(q.size == 0);
}

void testQueueEnqueue()
{
   Queue<int> q = queue<int>();

   int* p1 = queueEnqueue<int>(q, 10);
   int* p2 = queueEnqueue<int>(q, 20);

   assert(p1 != NULL);
   assert(p2 != NULL);
   assert(*p1 == 10);
   assert(*p2 == 20);
   assert(q.p != NULL);
   assert(q.q != NULL);
   assert(q.size == 2);
}

void testQueueDequeue()
{
   Queue<int> q = buildQueue();

   int v1 = queueDequeue<int>(q);
   int v2 = queueDequeue<int>(q);
   int v3 = queueDequeue<int>(q);

   assert(v1 == 10);
   assert(v2 == 20);
   assert(v3 == 30);
   assert(q.size == 0);
   assert(q.p == NULL);
   assert(q.q == NULL);
}

void testQueueIsEmpty()
{
   Queue<int> q = queue<int>();
   assert(queueIsEmpty<int>(q));

   queueEnqueue<int>(q, 1);
   assert(!queueIsEmpty<int>(q));
}

void testQueueSize()
{
   Queue<int> q = buildQueue();
   assert(queueSize<int>(q) == 3);
}

