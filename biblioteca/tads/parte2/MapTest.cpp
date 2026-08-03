#include <cassert>
#include <iostream>

#include "Map.hpp"

using std::cout;
using std::endl;

int cmpIntInt(int a, int b)
{
   return a < b ? -1 : a > b ? 1 : 0;
}

void testCreateAndSize()
{
   Map<int, int> m = map<int, int>();
   assert((mapSize<int, int>(m)) == 0);
   assert(!(mapHasNext<int, int>(m)));
}

void testPutGetAndContains()
{
   Map<int, int> m = map<int, int>();

   int* p1 = mapPut<int, int>(m, 10, 100);
   assert(p1 != NULL);
   assert(*p1 == 100);
   assert((mapSize<int, int>(m)) == 1);

   int* p2 = mapPut<int, int>(m, 20, 200);
   assert(p2 != NULL);
   assert(*p2 == 200);
   assert((mapSize<int, int>(m)) == 2);

   int* g1 = mapGet<int, int>(m, 10);
   int* g2 = mapGet<int, int>(m, 20);
   int* g3 = mapGet<int, int>(m, 99);
   assert(g1 != NULL && *g1 == 100);
   assert(g2 != NULL && *g2 == 200);
   assert(g3 == NULL);

   assert((mapContains<int, int>(m, 10)));
   assert((mapContains<int, int>(m, 20)));
   assert((!mapContains<int, int>(m, 99)));
}

void testPutReplace()
{
   Map<int, int> m = map<int, int>();
   mapPut<int, int>(m, 10, 100);
   assert((mapSize<int, int>(m)) == 1);

   int* p = mapPut<int, int>(m, 10, 999);
   assert(p != NULL);
   assert(*p == 999);
   assert((mapSize<int, int>(m)) == 1);
   assert(*(mapGet<int, int>(m, 10)) == 999);
}

void testRemoveAndRemoveAll()
{
   Map<int, int> m = map<int, int>();
   mapPut<int, int>(m, 10, 100);
   mapPut<int, int>(m, 20, 200);
   mapPut<int, int>(m, 30, 300);

   assert((mapRemove<int, int>(m, 20)) == 200);
   assert((mapSize<int, int>(m)) == 2);
   assert((!mapContains<int, int>(m, 20)));
   assert((mapContains<int, int>(m, 10)));
   assert((mapContains<int, int>(m, 30)));

   mapRemoveAll<int, int>(m);
   assert((mapSize<int, int>(m)) == 0);
   assert(!(mapHasNext<int, int>(m)));
}

void testDiscover()
{
   Map<int, int> m = map<int, int>();

   int* p1 = mapDiscover<int, int>(m, 10, 100);
   assert(p1 != NULL);
   assert(*p1 == 100);
   assert((mapSize<int, int>(m)) == 1);

   int* p2 = mapDiscover<int, int>(m, 10, 999);
   assert(p2 != NULL);
   assert(*p2 == 100);
   assert((mapSize<int, int>(m)) == 1);

   int* p3 = mapDiscover<int, int>(m, 20, 200);
   assert(p3 != NULL);
   assert(*p3 == 200);
   assert((mapSize<int, int>(m)) == 2);
}

void testIterationKeys()
{
   Map<int, int> m = map<int, int>();
   mapPut<int, int>(m, 10, 100);
   mapPut<int, int>(m, 20, 200);
   mapPut<int, int>(m, 30, 300);

   mapReset<int, int>(m);
   assert((mapHasNext<int, int>(m)));
   assert((mapNextKey<int, int>(m)) == 10);
   assert((mapHasNext<int, int>(m)));
   assert((mapNextKey<int, int>(m)) == 20);
   assert((mapHasNext<int, int>(m)));
   assert((mapNextKey<int, int>(m)) == 30);
   assert(!(mapHasNext<int, int>(m)));
}

void testIterationValues()
{
   Map<int, int> m = map<int, int>();
   mapPut<int, int>(m, 10, 100);
   mapPut<int, int>(m, 20, 200);
   mapPut<int, int>(m, 30, 300);

   mapReset<int, int>(m);
   assert((mapHasNext<int, int>(m)));
   assert(*(mapNextValue<int, int>(m)) == 100);
   assert((mapHasNext<int, int>(m)));
   assert(*(mapNextValue<int, int>(m)) == 200);
   assert((mapHasNext<int, int>(m)));
   assert(*(mapNextValue<int, int>(m)) == 300);
   assert(!(mapHasNext<int, int>(m)));
}

void testSortByKeys()
{
   Map<int, int> m = map<int, int>();
   mapPut<int, int>(m, 30, 300);
   mapPut<int, int>(m, 10, 100);
   mapPut<int, int>(m, 20, 200);

   mapSortByKeys<int, int>(m, cmpIntInt);
   mapReset<int, int>(m);

   assert((mapNextKey<int, int>(m)) == 10);
   assert((mapNextKey<int, int>(m)) == 20);
   assert((mapNextKey<int, int>(m)) == 30);

   assert(*(mapGet<int, int>(m, 10)) == 100);
   assert(*(mapGet<int, int>(m, 20)) == 200);
   assert(*(mapGet<int, int>(m, 30)) == 300);
}

void testSortByValues()
{
   Map<int, int> m = map<int, int>();
   mapPut<int, int>(m, 10, 300);
   mapPut<int, int>(m, 20, 100);
   mapPut<int, int>(m, 30, 200);

   mapSortByValues<int, int>(m, cmpIntInt);
   mapReset<int, int>(m);

   assert(*(mapNextValue<int, int>(m)) == 100);
   assert(*(mapNextValue<int, int>(m)) == 200);
   assert(*(mapNextValue<int, int>(m)) == 300);

   assert(*(mapGet<int, int>(m, 10)) == 300);
   assert(*(mapGet<int, int>(m, 20)) == 100);
   assert(*(mapGet<int, int>(m, 30)) == 200);
}

int main()
{
   testCreateAndSize();
   testPutGetAndContains();
   testPutReplace();
   testRemoveAndRemoveAll();
   testDiscover();
   testIterationKeys();
   testIterationValues();
   testSortByKeys();
   testSortByValues();

   cout << "Todos los tests de Map pasaron correctamente." << endl;
   return 0;
}
