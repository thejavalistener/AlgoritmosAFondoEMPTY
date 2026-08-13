#include <cassert>
#include <iostream>

#include "Array.hpp"

using std::cout;
using std::endl;

// -- PROTOTIPOS --
void testArray();
void testArrayAdd();
void testArrayGet();
void testArraySet();
void testArrayInsert();
void testArraySize();
void testArrayRemove();
void testArrayRemoveAll();
void testArrayFind();
void testArrayOrderedInsert();
void testArrayDiscover();
void testArraySort();
void testArrayReset();
void testArrayHasNext();
void testArrayNext();

// -- MAIN --
int main()
{
   testArray();
//    testArrayAdd();
//    testArrayGet();
//    testArraySet();
//    testArrayInsert();
//    testArraySize();
//    testArrayRemove();
//    testArrayRemoveAll();
//    testArrayFind();
//    testArrayOrderedInsert();
//    testArrayDiscover();
//    testArraySort();
//    testArrayReset();
//    testArrayHasNext();
//    testArrayNext();

   cout << "Todos los tests de Array pasaron correctamente." << endl;
   return 0;
}


int cmpIntInt(int a, int b)
{
   return a < b ? -1 : a > b ? 1 : 0;
}

Array<int> buildArray()
{
   Array<int> a = array<int>();
   arrayAdd<int>(a, 10);
   arrayAdd<int>(a, 20);
   arrayAdd<int>(a, 30);
   return a;
}

void testArray()
{
   Array<int> a = array<int>();

   assert(a.a != NULL);
   assert(a.len == 0);
   assert(a.cap == 100);
   assert(a.curr == 0);
}

void test_arrayResize()
{
   Array<int> a = buildArray();
   int oldCap = a.cap;

   _arrayResize<int>(a, 200);

   assert(a.cap == 200);
   assert(a.len == 3);
   assert(a.cap > oldCap);
   assert(a.a[0] == 10);
   assert(a.a[1] == 20);
   assert(a.a[2] == 30);
}

void testArrayAdd()
{
   Array<int> a = array<int>();

   int p0 = arrayAdd<int>(a, 10);
   int p1 = arrayAdd<int>(a, 20);

   assert(p0 == 0);
   assert(p1 == 1);
   assert(a.len == 2);
   assert(a.a[0] == 10);
   assert(a.a[1] == 20);
}

void testArrayGet()
{
   Array<int> a = buildArray();
   int* p = arrayGet<int>(a, 1);

   assert(p != NULL);
   assert(*p == 20);
}

void testArraySet()
{
   Array<int> a = buildArray();

   arraySet<int>(a, 1, 99);

   assert(a.a[0] == 10);
   assert(a.a[1] == 99);
   assert(a.a[2] == 30);
}

void testArrayInsert()
{
   Array<int> a = buildArray();

   arrayInsert<int>(a, 15, 1);

   assert(a.len == 4);
   assert(a.a[0] == 10);
   assert(a.a[1] == 15);
   assert(a.a[2] == 20);
   assert(a.a[3] == 30);
}

void testArraySize()
{
   Array<int> a = buildArray();
   assert(arraySize<int>(a) == 3);
}

void testArrayRemove()
{
   Array<int> a = buildArray();

   int removed = arrayRemove<int>(a, 1);

   assert(removed == 20);
   assert(a.len == 2);
   assert(a.a[0] == 10);
   assert(a.a[1] == 30);
}

void testArrayRemoveAll()
{
   Array<int> a = buildArray();
   a.curr = 2;

   arrayRemoveAll<int>(a);

   assert(a.len == 0);
   assert(a.curr == 0);
}

void testArrayFind()
{
   Array<int> a = buildArray();

   assert((arrayFind<int, int>(a, 10, cmpIntInt) == 0));
   assert((arrayFind<int, int>(a, 20, cmpIntInt) == 1));
   assert((arrayFind<int, int>(a, 99, cmpIntInt) == -1));
}

void testArrayOrderedInsert()
{
   Array<int> a = array<int>();
   arrayAdd<int>(a, 10);
   arrayAdd<int>(a, 20);
   arrayAdd<int>(a, 40);

   int p = arrayOrderedInsert<int>(a, 30, cmpIntInt);

   assert(p == 2);
   assert(a.len == 4);
   assert(a.a[0] == 10);
   assert(a.a[1] == 20);
   assert(a.a[2] == 30);
   assert(a.a[3] == 40);
}

void testArrayDiscover()
{
   Array<int> a = buildArray();

   int* p1 = arrayDiscover<int>(a, 20, cmpIntInt);
   int* p2 = arrayDiscover<int>(a, 40, cmpIntInt);

   assert(p1 != NULL);
   assert(*p1 == 20);
   assert(p2 != NULL);
   assert(*p2 == 40);
   assert(a.len == 4);
   assert(a.a[3] == 40);
}

void testArraySort()
{
   Array<int> a = array<int>();
   arrayAdd<int>(a, 40);
   arrayAdd<int>(a, 10);
   arrayAdd<int>(a, 30);
   arrayAdd<int>(a, 20);

   arraySort<int>(a, cmpIntInt);

   assert(a.a[0] == 10);
   assert(a.a[1] == 20);
   assert(a.a[2] == 30);
   assert(a.a[3] == 40);
}

void testArrayReset()
{
   Array<int> a = buildArray();
   a.curr = 2;

   arrayReset<int>(a);

   assert(a.curr == 0);
}

void testArrayHasNext()
{
   Array<int> a = buildArray();

   assert(arrayHasNext<int>(a));
   a.curr = 3;
   assert(!arrayHasNext<int>(a));
}

void testArrayNext()
{
   Array<int> a = buildArray();

   int* p = arrayNext<int>(a);

   assert(p != NULL);
   assert(*p == 10);
   assert(a.curr == 1);
}

