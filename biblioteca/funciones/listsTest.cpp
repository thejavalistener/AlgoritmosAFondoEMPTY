#include <cassert>
#include <iostream>

#include "lists.hpp"

using std::cout;
using std::endl;

int cmpIntInt(int a, int b)
{
   return a < b ? -1 : a > b ? 1 : 0;
}

int listSize(Node<int>* p)
{
   int n = 0;
   while( p != NULL )
   {
      n++;
      p = p->sig;
   }
   return n;
}

void assertListEquals(Node<int>* p, const int expected[], int n)
{
   for(int i = 0; i < n; i++)
   {
      assert(p != NULL);
      assert(p->info == expected[i]);
      p = p->sig;
   }
   assert(p == NULL);
}

void testAddAndAddFirst()
{
   Node<int>* p = NULL;

   Node<int>* n1 = add<int>(p, 10);
   assert(n1 != NULL);
   assert(p == n1);

   Node<int>* n2 = add<int>(p, 20);
   assert(n2 != NULL);
   assert(p->sig == n2);

   Node<int>* n0 = addFirst<int>(p, 5);
   assert(n0 != NULL);
   assert(p == n0);

   int expected[] = {5, 10, 20};
   assert(listSize(p) == 3);
   assertListEquals(p, expected, 3);

   free<int>(p);
   assert(isEmpty<int>(p));
}

void testRemoveAndRemoveFirst()
{
   Node<int>* p1 = NULL;
   add<int>(p1, 10);
   add<int>(p1, 20);
   add<int>(p1, 30);
   assert((remove<int, int>(p1, 20, cmpIntInt)) == 20);
   {
      int expected[] = {10, 30};
      assertListEquals(p1, expected, 2);
   }
   free<int>(p1);

   Node<int>* p2 = NULL;
   add<int>(p2, 10);
   add<int>(p2, 20);
   add<int>(p2, 30);
   assert((remove<int, int>(p2, 10, cmpIntInt)) == 10);
   {
      int expected[] = {20, 30};
      assertListEquals(p2, expected, 2);
   }
   free<int>(p2);

   Node<int>* p3 = NULL;
   add<int>(p3, 10);
   add<int>(p3, 20);
   add<int>(p3, 30);
   assert(removeFirst<int>(p3) == 10);
   {
      int expected[] = {20, 30};
      assertListEquals(p3, expected, 2);
   }
   free<int>(p3);
}

void testFind()
{
   Node<int>* p = NULL;
   add<int>(p, 10);
   add<int>(p, 20);
   add<int>(p, 30);

   Node<int>* n1 = find<int, int>(p, 10, cmpIntInt);
   Node<int>* n2 = find<int, int>(p, 30, cmpIntInt);
   Node<int>* n3 = find<int, int>(p, 99, cmpIntInt);

   assert(n1 != NULL && n1->info == 10);
   assert(n2 != NULL && n2->info == 30);
   assert(n3 == NULL);

   free<int>(p);
}

void testOrderedInsert()
{
   Node<int>* p = NULL;
   orderedInsert<int>(p, 20, cmpIntInt);
   orderedInsert<int>(p, 10, cmpIntInt);
   orderedInsert<int>(p, 30, cmpIntInt);
   orderedInsert<int>(p, 25, cmpIntInt);

   int expected[] = {10, 20, 25, 30};
   assertListEquals(p, expected, 4);

   free<int>(p);
}

void testSearchAndInsert()
{
   Node<int>* p = NULL;
   orderedInsert<int>(p, 10, cmpIntInt);
   orderedInsert<int>(p, 20, cmpIntInt);
   orderedInsert<int>(p, 30, cmpIntInt);

   bool enc = false;
   Node<int>* n1 = searchAndInsert<int>(p, 20, enc, cmpIntInt);
   assert(enc);
   assert(n1 != NULL && n1->info == 20);
   {
      int expected[] = {10, 20, 30};
      assertListEquals(p, expected, 3);
   }

   Node<int>* n2 = searchAndInsert<int>(p, 25, enc, cmpIntInt);
   assert(!enc);
   assert(n2 != NULL && n2->info == 25);
   {
      int expected[] = {10, 20, 25, 30};
      assertListEquals(p, expected, 4);
   }

   free<int>(p);
}

void testSortAndIsEmptyAndFree()
{
   Node<int>* p = NULL;
   assert(isEmpty<int>(p));

   add<int>(p, 40);
   add<int>(p, 10);
   add<int>(p, 30);
   add<int>(p, 20);
   assert(!isEmpty<int>(p));

   sort<int>(p, cmpIntInt);
   {
      int expected[] = {10, 20, 30, 40};
      assertListEquals(p, expected, 4);
   }

   free<int>(p);
   assert(isEmpty<int>(p));
}

void testPushAndPop()
{
   Node<int>* p = NULL;
   push<int>(p, 10);
   push<int>(p, 20);
   push<int>(p, 30);

   assert(pop<int>(p) == 30);
   assert(pop<int>(p) == 20);
   assert(pop<int>(p) == 10);
   assert(isEmpty<int>(p));
}

void testEnqueueDequeueWithTwoPointers()
{
   Node<int>* p = NULL;
   Node<int>* q = NULL;

   Node<int>* n1 = enqueue<int>(p, q, 10);
   assert(n1 != NULL);
   assert(p != NULL && q != NULL);
   assert(p->info == 10);
   assert(q->info == 10);

   enqueue<int>(p, q, 20);
   enqueue<int>(p, q, 30);

   assert(dequeue<int>(p, q) == 10);
   assert(p != NULL && q != NULL);
   assert(p->info == 20);

   assert(dequeue<int>(p, q) == 20);
   assert(dequeue<int>(p, q) == 30);
   assert(p == NULL);
   assert(q == NULL);
}

void testEnqueueDequeueCircular()
{
   Node<int>* q = NULL;

   Node<int>* n1 = enqueue<int>(q, 10);
   assert(n1 != NULL);
   assert(q != NULL);
   assert(q->sig == q);

   enqueue<int>(q, 20);
   enqueue<int>(q, 30);

   assert(dequeue<int>(q) == 10);
   assert(q != NULL);
   assert(dequeue<int>(q) == 20);
   assert(q != NULL);
   assert(dequeue<int>(q) == 30);
   assert(q == NULL);
}

int main()
{
   testAddAndAddFirst();
   testRemoveAndRemoveFirst();
   testFind();
   testOrderedInsert();
   testSearchAndInsert();
   testSortAndIsEmptyAndFree();
   testPushAndPop();
   testEnqueueDequeueWithTwoPointers();
   testEnqueueDequeueCircular();

   cout << "Todos los tests de lists pasaron correctamente." << endl;
   return 0;
}
