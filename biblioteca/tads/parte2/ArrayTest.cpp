#include <cassert>
#include <iostream>

#include "Array.hpp"

using std::cout;
using std::endl;

int cmpIntInt(int a, int b)
{
   return a < b ? -1 : a > b ? 1 : 0;
}

void testCreateAndSize()
{
   Array<int> a = array<int>();
   assert(arraySize<int>(a) == 0);
   assert(!arrayHasNext<int>(a));
}

void testAddGetAndSet()
{
   Array<int> a = array<int>();

   assert(arrayAdd<int>(a, 10) == 0);
   assert(arrayAdd<int>(a, 20) == 1);
   assert(arrayAdd<int>(a, 30) == 2);
   assert(arraySize<int>(a) == 3);

   assert(*arrayGet<int>(a, 0) == 10);
   assert(*arrayGet<int>(a, 1) == 20);
   assert(*arrayGet<int>(a, 2) == 30);

   arraySet<int>(a, 1, 99);
   assert(*arrayGet<int>(a, 1) == 99);
   assert(*arrayGet<int>(a, 0) == 10);
   assert(*arrayGet<int>(a, 2) == 30);
}

void testInsert()
{
   Array<int> a = array<int>();
   arrayAdd<int>(a, 10);
   arrayAdd<int>(a, 30);
   arrayAdd<int>(a, 40);

   arrayInsert<int>(a, 20, 1);
   assert(arraySize<int>(a) == 4);
   assert(*arrayGet<int>(a, 0) == 10);
   assert(*arrayGet<int>(a, 1) == 20);
   assert(*arrayGet<int>(a, 2) == 30);
   assert(*arrayGet<int>(a, 3) == 40);

   arrayInsert<int>(a, 5, 0);
   assert(*arrayGet<int>(a, 0) == 5);
   assert(*arrayGet<int>(a, 1) == 10);

   arrayInsert<int>(a, 50, arraySize<int>(a));
   assert(*arrayGet<int>(a, arraySize<int>(a)-1) == 50);
}

void testRemoveAndRemoveAll()
{
   Array<int> a1 = array<int>();
   arrayAdd<int>(a1, 10);
   arrayAdd<int>(a1, 20);
   arrayAdd<int>(a1, 30);
   assert(arrayRemove<int>(a1, 0) == 10);
   assert(arraySize<int>(a1) == 2);
   assert(*arrayGet<int>(a1, 0) == 20);
   assert(*arrayGet<int>(a1, 1) == 30);

   Array<int> a2 = array<int>();
   arrayAdd<int>(a2, 10);
   arrayAdd<int>(a2, 20);
   arrayAdd<int>(a2, 30);
   assert(arrayRemove<int>(a2, 1) == 20);
   assert(arraySize<int>(a2) == 2);
   assert(*arrayGet<int>(a2, 0) == 10);
   assert(*arrayGet<int>(a2, 1) == 30);

   Array<int> a3 = array<int>();
   arrayAdd<int>(a3, 10);
   arrayAdd<int>(a3, 20);
   arrayAdd<int>(a3, 30);
   assert(arrayRemove<int>(a3, 2) == 30);
   assert(arraySize<int>(a3) == 2);
   assert(*arrayGet<int>(a3, 0) == 10);
   assert(*arrayGet<int>(a3, 1) == 20);

   arrayRemoveAll<int>(a3);
   assert(arraySize<int>(a3) == 0);
   assert(!arrayHasNext<int>(a3));
}

void testFind()
{
   Array<int> a = array<int>();
   arrayAdd<int>(a, 10);
   arrayAdd<int>(a, 20);
   arrayAdd<int>(a, 30);

   assert((arrayFind<int, int>(a, 10, cmpIntInt) == 0));
   assert((arrayFind<int, int>(a, 20, cmpIntInt) == 1));
   assert((arrayFind<int, int>(a, 30, cmpIntInt) == 2));
   assert((arrayFind<int, int>(a, 99, cmpIntInt) == -1));
}

void testOrderedInsert()
{
   Array<int> a = array<int>();
   arrayAdd<int>(a, 10);
   arrayAdd<int>(a, 20);
   arrayAdd<int>(a, 40);
   arrayAdd<int>(a, 50);

   assert(arrayOrderedInsert<int>(a, 30, cmpIntInt) == 2);
   assert(arraySize<int>(a) == 5);
   assert(*arrayGet<int>(a, 0) == 10);
   assert(*arrayGet<int>(a, 1) == 20);
   assert(*arrayGet<int>(a, 2) == 30);
   assert(*arrayGet<int>(a, 3) == 40);
   assert(*arrayGet<int>(a, 4) == 50);
}

void testDiscover()
{
   Array<int> a = array<int>();
   arrayAdd<int>(a, 10);
   arrayAdd<int>(a, 20);

   int* p1 = arrayDiscover<int>(a, 20, cmpIntInt);
   assert(p1 != NULL);
   assert(*p1 == 20);
   assert(arraySize<int>(a) == 2);

   int* p2 = arrayDiscover<int>(a, 30, cmpIntInt);
   assert(p2 != NULL);
   assert(*p2 == 30);
   assert(arraySize<int>(a) == 3);
   assert(*arrayGet<int>(a, 2) == 30);
}

void testSort()
{
   Array<int> a = array<int>();
   arrayAdd<int>(a, 40);
   arrayAdd<int>(a, 10);
   arrayAdd<int>(a, 30);
   arrayAdd<int>(a, 20);
   arrayAdd<int>(a, 20);

   arraySort<int>(a, cmpIntInt);
   assert(*arrayGet<int>(a, 0) == 10);
   assert(*arrayGet<int>(a, 1) == 20);
   assert(*arrayGet<int>(a, 2) == 20);
   assert(*arrayGet<int>(a, 3) == 30);
   assert(*arrayGet<int>(a, 4) == 40);
}

void testIteration()
{
   Array<int> a = array<int>();
   arrayAdd<int>(a, 5);
   arrayAdd<int>(a, 6);
   arrayAdd<int>(a, 7);

   arrayReset<int>(a);
   assert(arrayHasNext<int>(a));
   assert(*arrayNext<int>(a) == 5);
   assert(arrayHasNext<int>(a));
   assert(*arrayNext<int>(a) == 6);
   assert(arrayHasNext<int>(a));
   assert(*arrayNext<int>(a) == 7);
   assert(!arrayHasNext<int>(a));

   arrayReset<int>(a);
   assert(arrayHasNext<int>(a));
   assert(*arrayNext<int>(a) == 5);
}

void testManyAdds()
{
   Array<int> a = array<int>();
   for(int i = 0; i < 150; i++)
   {
      assert(arrayAdd<int>(a, i) == i);
   }

   assert(arraySize<int>(a) == 150);
   assert(*arrayGet<int>(a, 0) == 0);
   assert(*arrayGet<int>(a, 149) == 149);
}

int main()
{
   testCreateAndSize();
   testAddGetAndSet();
   testInsert();
   testRemoveAndRemoveAll();
   testFind();
   testOrderedInsert();
   testDiscover();
   testSort();
   testIteration();
   testManyAdds();

   cout << "Todos los tests de Array pasaron correctamente." << endl;
   return 0;
}
