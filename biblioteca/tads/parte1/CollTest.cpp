#include <cassert>
#include <iostream>
#include <string>

#include "../../funciones/tokens.hpp"
#include "Coll.hpp"

using std::cout;
using std::endl;
using std::string;

string intToStringColl(int x)
{
   return intToString(x);
}

int intFromStringColl(string s)
{
   return stringToInt(s);
}

int cmpIntInt(int a, int b)
{
   return a < b ? -1 : a > b ? 1 : 0;
}

void testCreateAndSize()
{
   Coll<int> c1 = coll<int>();
   assert(collSize(c1) == 0);

   Coll<int> c2 = coll<int>(',');
   assert(collSize(c2) == 0);
}

void testAddGetAndSet()
{
   Coll<int> c = coll<int>();

   assert(collAdd<int>(c, 10, intToStringColl) == 0);
   assert(collAdd<int>(c, 20, intToStringColl) == 1);
   assert(collAdd<int>(c, 30, intToStringColl) == 2);

   assert(collSize(c) == 3);
   assert(collGetAt<int>(c, 0, intFromStringColl) == 10);
   assert(collGetAt<int>(c, 1, intFromStringColl) == 20);
   assert(collGetAt<int>(c, 2, intFromStringColl) == 30);

   collSetAt<int>(c, 99, 1, intToStringColl);
   assert(collGetAt<int>(c, 1, intFromStringColl) == 99);
   assert(collGetAt<int>(c, 0, intFromStringColl) == 10);
   assert(collGetAt<int>(c, 2, intFromStringColl) == 30);


   Coll<int> x = coll<int>('*');

   assert(collAdd<int>(x, 10, intToStringColl) == 0);
   assert(collAdd<int>(x, 20, intToStringColl) == 1);
   assert(collAdd<int>(x, 30, intToStringColl) == 2);

   assert(collSize(x) == 3);
   assert(collGetAt<int>(x, 0, intFromStringColl) == 10);
   assert(collGetAt<int>(x, 1, intFromStringColl) == 20);
   assert(collGetAt<int>(x, 2, intFromStringColl) == 30);

   collSetAt<int>(x, 99, 1, intToStringColl);
   assert(collGetAt<int>(x, 1, intFromStringColl) == 99);
   assert(collGetAt<int>(x, 0, intFromStringColl) == 10);
   assert(collGetAt<int>(x, 2, intFromStringColl) == 30);
}

void testRemoveAndRemoveAll()
{
   Coll<int> c1 = coll<int>(',');
   collAdd<int>(c1, 10, intToStringColl);
   collAdd<int>(c1, 20, intToStringColl);
   collAdd<int>(c1, 30, intToStringColl);
   collRemoveAt<int>(c1, 0);
   assert(collSize(c1) == 2);
   assert(collGetAt<int>(c1, 0, intFromStringColl) == 20);
   assert(collGetAt<int>(c1, 1, intFromStringColl) == 30);

   Coll<int> c2 = coll<int>(',');
   collAdd<int>(c2, 10, intToStringColl);
   collAdd<int>(c2, 20, intToStringColl);
   collAdd<int>(c2, 30, intToStringColl);
   collRemoveAt<int>(c2, 1);
   assert(collSize(c2) == 2);
   assert(collGetAt<int>(c2, 0, intFromStringColl) == 10);
   assert(collGetAt<int>(c2, 1, intFromStringColl) == 30);

   Coll<int> c3 = coll<int>(',');
   collAdd<int>(c3, 10, intToStringColl);
   collAdd<int>(c3, 20, intToStringColl);
   collAdd<int>(c3, 30, intToStringColl);
   collRemoveAt<int>(c3, 2);
   assert(collSize(c3) == 2);
   assert(collGetAt<int>(c3, 0, intFromStringColl) == 10);
   assert(collGetAt<int>(c3, 1, intFromStringColl) == 20);

   collRemoveAll<int>(c3);
   assert(collSize(c3) == 0);
}

void testFind()
{
   Coll<int> c = coll<int>(',');
   collAdd<int>(c, 7, intToStringColl);
   collAdd<int>(c, 3, intToStringColl);
   collAdd<int>(c, 9, intToStringColl);

   assert((collFind<int, int>(c, 7, cmpIntInt, intFromStringColl) == 0));
   assert((collFind<int, int>(c, 3, cmpIntInt, intFromStringColl) == 1));
   assert((collFind<int, int>(c, 9, cmpIntInt, intFromStringColl) == 2));
   assert((collFind<int, int>(c, 4, cmpIntInt, intFromStringColl) == -1));
}

void testSort()
{
   Coll<int> c = coll<int>(',');
   collAdd<int>(c, 40, intToStringColl);
   collAdd<int>(c, 10, intToStringColl);
   collAdd<int>(c, 30, intToStringColl);
   collAdd<int>(c, 20, intToStringColl);

   collSort<int>(c, cmpIntInt, intFromStringColl, intToStringColl);

   assert(collSize(c) == 4);
   assert(collGetAt<int>(c, 0, intFromStringColl) == 10);
   assert(collGetAt<int>(c, 1, intFromStringColl) == 20);
   assert(collGetAt<int>(c, 2, intFromStringColl) == 30);
   assert(collGetAt<int>(c, 3, intFromStringColl) == 40);
}

void testIteration()
{
   Coll<int> c = coll<int>(',');
   collAdd<int>(c, 5, intToStringColl);
   collAdd<int>(c, 6, intToStringColl);
   collAdd<int>(c, 7, intToStringColl);

   assert(collHasNext<int>(c));
   assert(collNext<int>(c, intFromStringColl) == 5);
   assert(collHasNext<int>(c));
   assert(collNext<int>(c, intFromStringColl) == 6);
   assert(collHasNext<int>(c));
   assert(collNext<int>(c, intFromStringColl) == 7);
   assert(!collHasNext<int>(c));

   collReset<int>(c);
   assert(collHasNext<int>(c));
}

void testIterationWithEndFlag()
{
   Coll<int> c = coll<int>(',');
   collAdd<int>(c, 11, intToStringColl);
   collAdd<int>(c, 22, intToStringColl);

   bool endOfColl = false;
   assert(collNext<int>(c, endOfColl, intFromStringColl) == 11);
   assert(!endOfColl);
   assert(collNext<int>(c, endOfColl, intFromStringColl) == 22);
   assert(!endOfColl);

   int value = collNext<int>(c, endOfColl, intFromStringColl);
   assert(endOfColl);
   assert(value == 0);
}

int main()
{
   testCreateAndSize();
   testAddGetAndSet();
   testRemoveAndRemoveAll();
   testFind();
   testSort();
   testIteration();
   testIterationWithEndFlag();

   cout << "Todos los tests de Coll pasaron correctamente." << endl;
   return 0;
}

