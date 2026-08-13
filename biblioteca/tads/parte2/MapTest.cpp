#include <cassert>
#include <iostream>

#include "Map.hpp"

using std::cout;
using std::endl;

// -- PROTOTIPOS --
void testMap();
void testMapGet();
void testMapPut();
void testMapContains();
void testMapRemove();
void testMapRemoveAll();
void testMapSize();
void testMapHasNext();
void testMapNextKey();
void testMapNextValue();
void testMapReset();
void testMapDiscover();
void testMapSortByKeys();
void testMapSortByValues();

// -- MAIN --
int main()
{
   testMap();
//    testMapGet();
//    testMapPut();
//    testMapContains();
//    testMapRemove();
//    testMapRemoveAll();
//    testMapSize();
//    testMapHasNext();
//    testMapNextKey();
//    testMapNextValue();
//    testMapReset();
//    testMapDiscover();
//    testMapSortByKeys();
//    testMapSortByValues();

   cout << "Todos los tests de Map pasaron correctamente." << endl;
   return 0;
}


int cmpIntInt(int a, int b)
{
   return a < b ? -1 : a > b ? 1 : 0;
}

Map<int, int> buildMap()
{
   Map<int, int> m = map<int, int>();
   mapPut<int, int>(m, 10, 100);
   mapPut<int, int>(m, 20, 200);
   mapPut<int, int>(m, 30, 300);
   return m;
}

void testMap()
{
   Map<int, int> m = map<int, int>();

   assert(arraySize<int>(m.keys) == 0);
   assert(arraySize<int>(m.values) == 0);
   assert(m.curr == 0);
}

void testMapGet()
{
   Map<int, int> m = buildMap();

   int* p1 = mapGet<int, int>(m, 10);
   int* p2 = mapGet<int, int>(m, 30);
   int* p3 = mapGet<int, int>(m, 99);

   assert(p1 != NULL && *p1 == 100);
   assert(p2 != NULL && *p2 == 300);
   assert(p3 == NULL);
}

void testMapPut()
{
   Map<int, int> m = map<int, int>();

   int* p1 = mapPut<int, int>(m, 10, 100);
   int* p2 = mapPut<int, int>(m, 10, 999);

   assert(p1 != NULL);
   assert(p2 != NULL);
   assert(*p2 == 999);
   assert((mapSize<int, int>(m) == 1));
   assert((*mapGet<int, int>(m, 10) == 999));
}

void testMapContains()
{
   Map<int, int> m = buildMap();

   assert((mapContains<int, int>(m, 10)));
   assert((mapContains<int, int>(m, 20)));
   assert((!mapContains<int, int>(m, 99)));
}

void testMapRemove()
{
   Map<int, int> m = buildMap();

   int value = mapRemove<int, int>(m, 20);

   assert(value == 200);
   assert((mapSize<int, int>(m) == 2));
   assert((!mapContains<int, int>(m, 20)));
   assert((mapContains<int, int>(m, 10)));
   assert((mapContains<int, int>(m, 30)));
}

void testMapRemoveAll()
{
   Map<int, int> m = buildMap();
   m.curr = 2;

   mapRemoveAll<int, int>(m);

   assert((mapSize<int, int>(m) == 0));
   assert(m.curr == 0);
}

void testMapSize()
{
   Map<int, int> m = buildMap();
   assert((mapSize<int, int>(m) == 3));
}

void testMapHasNext()
{
   Map<int, int> m = buildMap();

   assert((mapHasNext<int, int>(m)));
   m.curr = 3;
   assert((!mapHasNext<int, int>(m)));
}

void testMapNextKey()
{
   Map<int, int> m = buildMap();

   int key = mapNextKey<int, int>(m);

   assert(key == 10);
   assert(m.curr == 1);
}

void testMapNextValue()
{
   Map<int, int> m = buildMap();

   int* value = mapNextValue<int, int>(m);

   assert(value != NULL);
   assert(*value == 100);
   assert(m.curr == 1);
}

void testMapReset()
{
   Map<int, int> m = buildMap();
   m.curr = 2;

   mapReset<int, int>(m);

   assert(m.curr == 0);
}

void testMapDiscover()
{
   Map<int, int> m = buildMap();

   int* p1 = mapDiscover<int, int>(m, 20, 999);
   int* p2 = mapDiscover<int, int>(m, 40, 400);

   assert(p1 != NULL && *p1 == 200);
   assert(p2 != NULL && *p2 == 400);
   assert((mapSize<int, int>(m) == 4));
}

void testMapSortByKeys()
{
   Map<int, int> m = map<int, int>();
   mapPut<int, int>(m, 30, 300);
   mapPut<int, int>(m, 10, 100);
   mapPut<int, int>(m, 20, 200);

   mapSortByKeys<int, int>(m, cmpIntInt);

   assert(*arrayGet<int>(m.keys, 0) == 10);
   assert(*arrayGet<int>(m.keys, 1) == 20);
   assert(*arrayGet<int>(m.keys, 2) == 30);
   assert(*arrayGet<int>(m.values, 0) == 100);
   assert(*arrayGet<int>(m.values, 1) == 200);
   assert(*arrayGet<int>(m.values, 2) == 300);
}

void testMapSortByValues()
{
   Map<int, int> m = map<int, int>();
   mapPut<int, int>(m, 10, 300);
   mapPut<int, int>(m, 20, 100);
   mapPut<int, int>(m, 30, 200);

   mapSortByValues<int, int>(m, cmpIntInt);

   assert(*arrayGet<int>(m.values, 0) == 100);
   assert(*arrayGet<int>(m.values, 1) == 200);
   assert(*arrayGet<int>(m.values, 2) == 300);
   assert(*arrayGet<int>(m.keys, 0) == 20);
   assert(*arrayGet<int>(m.keys, 1) == 30);
   assert(*arrayGet<int>(m.keys, 2) == 10);
}

