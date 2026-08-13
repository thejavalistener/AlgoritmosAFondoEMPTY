#include <cassert>
#include <iostream>
#include <string>

#include "../../funciones/tokens.hpp"
#include "Coll.hpp"

using std::cout;
using std::endl;
using std::string;

// -- PROTOTIPOS --
void testColl();
void testColl_withDefaultSeparator();
void testCollSize();
void testCollRemoveAll();
void testCollRemoveAt();
void testCollAdd();
void testCollSetAt();
void testCollGetAt();
void testCollFind();
void testCollSort();
void testCollHasNext();
void testCollNext();
void testCollNext_withEndOfColl();
void testCollReset();
void testCollToString();
void testCollFromString();

// -- MAIN --
int main()
{
   testColl();
//    testColl_withDefaultSeparator();
//    testCollSize();
//    testCollRemoveAll();
//    testCollRemoveAt();
//    testCollAdd();
//    testCollSetAt();
//    testCollGetAt();
//    testCollFind();
//    testCollSort();
//    testCollHasNext();
//    testCollNext();
//    testCollNext_withEndOfColl();
//    testCollReset();
//    testCollToString();
//    testCollFromString();

   cout << "Todos los tests de Coll pasaron correctamente." << endl;
   return 0;
}




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

Coll<int> buildIntColl(char sep = ',')
{
   Coll<int> c = coll<int>(sep);
   collAdd<int>(c, 10, intToStringColl);
   collAdd<int>(c, 20, intToStringColl);
   collAdd<int>(c, 30, intToStringColl);
   return c;
}

void testColl()
{
   Coll<int> c = coll<int>(',');

   assert(collSize<int>(c) == 0);
   assert(!collHasNext<int>(c));
   assert(collToString<int>(c) == ",");
}

void testColl_withDefaultSeparator()
{
   Coll<int> c = coll<int>();

   assert(collSize<int>(c) == 0);
   assert(!collHasNext<int>(c));
   assert(collToString<int>(c) == "|");
}

void testCollSize()
{
   Coll<int> c = buildIntColl(',');

   assert(collSize<int>(c) == 3);
}

void testCollRemoveAll()
{
   Coll<int> c = buildIntColl(',');

   collRemoveAll<int>(c);

   assert(collSize<int>(c) == 0);
   assert(!collHasNext<int>(c));
   assert(collToString<int>(c) == ",");
}

void testCollRemoveAt()
{
   Coll<int> c = buildIntColl(',');

   collRemoveAt<int>(c, 1);

   assert(collSize<int>(c) == 2);
   assert(collGetAt<int>(c, 0, intFromStringColl) == 10);
   assert(collGetAt<int>(c, 1, intFromStringColl) == 30);
   assert(collHasNext<int>(c));
}

void testCollAdd()
{
   Coll<int> c = coll<int>(',');

   int p0 = collAdd<int>(c, 10, intToStringColl);
   int p1 = collAdd<int>(c, 20, intToStringColl);

   assert(p0 == 0);
   assert(p1 == 1);
    assert(collSize<int>(c) == 2);
    assert(collGetAt<int>(c, 0, intFromStringColl) == 10);
    assert(collGetAt<int>(c, 1, intFromStringColl) == 20);
}

void testCollSetAt()
{
   Coll<int> c = buildIntColl(',');

   collSetAt<int>(c, 99, 1, intToStringColl);

   assert(collGetAt<int>(c, 0, intFromStringColl) == 10);
   assert(collGetAt<int>(c, 1, intFromStringColl) == 99);
   assert(collGetAt<int>(c, 2, intFromStringColl) == 30);
}

void testCollGetAt()
{
   Coll<int> c = buildIntColl(',');

   assert(collGetAt<int>(c, 0, intFromStringColl) == 10);
   assert(collGetAt<int>(c, 1, intFromStringColl) == 20);
   assert(collGetAt<int>(c, 2, intFromStringColl) == 30);
}

void testCollFind()
{
   Coll<int> c = buildIntColl(',');

   assert((collFind<int, int>(c, 10, cmpIntInt, intFromStringColl) == 0));
   assert((collFind<int, int>(c, 20, cmpIntInt, intFromStringColl) == 1));
   assert((collFind<int, int>(c, 99, cmpIntInt, intFromStringColl) == -1));
}

void testCollSort()
{
   Coll<int> c = coll<int>(',');
   collAdd<int>(c, 40, intToStringColl);
   collAdd<int>(c, 10, intToStringColl);
   collAdd<int>(c, 30, intToStringColl);
   collAdd<int>(c, 20, intToStringColl);

   collSort<int>(c, cmpIntInt, intFromStringColl, intToStringColl);

   assert(collGetAt<int>(c, 0, intFromStringColl) == 10);
   assert(collGetAt<int>(c, 1, intFromStringColl) == 20);
   assert(collGetAt<int>(c, 2, intFromStringColl) == 30);
   assert(collGetAt<int>(c, 3, intFromStringColl) == 40);
}

void testCollHasNext()
{
   Coll<int> c = buildIntColl(',');

   assert(collHasNext<int>(c));
   collNext<int>(c, intFromStringColl);
   collNext<int>(c, intFromStringColl);
   collNext<int>(c, intFromStringColl);
   assert(!collHasNext<int>(c));
}

void testCollNext()
{
   Coll<int> c = buildIntColl(',');

   int value1 = collNext<int>(c, intFromStringColl);
   int value2 = collNext<int>(c, intFromStringColl);

   assert(value1 == 10);
   assert(value2 == 20);
}

void testCollNext_withEndOfColl()
{
   Coll<int> c = buildIntColl(',');
   bool endOfColl = false;

   int v1 = collNext<int>(c, endOfColl, intFromStringColl);
   int v2 = collNext<int>(c, endOfColl, intFromStringColl);
   int v3 = collNext<int>(c, endOfColl, intFromStringColl);
   int v4 = collNext<int>(c, endOfColl, intFromStringColl);

   assert(v1 == 10);
   assert(v2 == 20);
   assert(v3 == 30);
   assert(v4 == 0);
   assert(endOfColl);
}

void testCollReset()
{
   Coll<int> c = buildIntColl(',');
   collNext<int>(c, intFromStringColl);
   collNext<int>(c, intFromStringColl);

   collReset<int>(c);

   assert(collHasNext<int>(c));
   assert(collNext<int>(c, intFromStringColl) == 10);
}

void testCollToString()
{
   Coll<int> c = buildIntColl(',');

   assert(collToString<int>(c) == ",10,20,30");
}

void testCollFromString()
{
   Coll<int> c = collFromString<int>(";7;8;9");

   assert(collSize<int>(c) == 3);
   assert(collGetAt<int>(c, 0, intFromStringColl) == 7);
   assert(collGetAt<int>(c, 1, intFromStringColl) == 8);
   assert(collGetAt<int>(c, 2, intFromStringColl) == 9);
   assert(collToString<int>(c) == ";7;8;9");
}
