#include <cassert>
#include <iostream>

#include "List.hpp"

using std::cout;
using std::endl;

int cmpIntInt(int a, int b)
{
    return a < b ? -1 : a > b ? 1 : 0;
}

void testCreateIsEmptyAndSize()
{
    List<int> lst = list<int>();
    assert(listIsEmpty<int>(lst));
    assert((listSize<int>(lst)) == 0);
    assert(!(listHasNext<int>(lst)));
}

void testAddAndAddFirst()
{
    List<int> lst = list<int>();

    int* p1 = listAdd<int>(lst, 10);
    assert(p1 != NULL && *p1 == 10);
    int* p2 = listAdd<int>(lst, 20);
    assert(p2 != NULL && *p2 == 20);
    int* p0 = listAddFirst<int>(lst, 5);
    assert(p0 != NULL && *p0 == 5);

    assert((listSize<int>(lst)) == 3);

    listReset<int>(lst);
    assert(*listNext<int>(lst) == 5);
    assert(*listNext<int>(lst) == 10);
    assert(*listNext<int>(lst) == 20);
    assert(!listHasNext<int>(lst));
}

void testFind()
{
    List<int> lst = list<int>();
    listAdd<int>(lst, 10);
    listAdd<int>(lst, 20);
    listAdd<int>(lst, 30);

    int* p1 = listFind<int, int>(lst, 10, cmpIntInt);
    int* p2 = listFind<int, int>(lst, 30, cmpIntInt);
    int* p3 = listFind<int, int>(lst, 99, cmpIntInt);

    assert(p1 != NULL && *p1 == 10);
    assert(p2 != NULL && *p2 == 30);
    assert(p3 == NULL);
}

void testRemoveAndRemoveFirst()
{
    List<int> lst1 = list<int>();
    listAdd<int>(lst1, 10);
    listAdd<int>(lst1, 20);
    listAdd<int>(lst1, 30);
    assert((listRemove<int, int>(lst1, 20, cmpIntInt)) == 20);
    assert(listSize<int>(lst1) == 2);
    listReset<int>(lst1);
    assert(*listNext<int>(lst1) == 10);
    assert(*listNext<int>(lst1) == 30);

    List<int> lst2 = list<int>();
    listAdd<int>(lst2, 10);
    listAdd<int>(lst2, 20);
    listAdd<int>(lst2, 30);
    assert(listRemoveFirst<int>(lst2) == 10);
    assert(listSize<int>(lst2) == 2);
    listReset<int>(lst2);
    assert(*listNext<int>(lst2) == 20);
    assert(*listNext<int>(lst2) == 30);
}

void testDiscover()
{
    List<int> lst = list<int>();
    listAdd<int>(lst, 10);
    listAdd<int>(lst, 20);

    int* p1 = listDiscover<int>(lst, 20, cmpIntInt);
    assert(p1 != NULL && *p1 == 20);
    assert(listSize<int>(lst) == 2);

    int* p2 = listDiscover<int>(lst, 30, cmpIntInt);
    assert(p2 != NULL && *p2 == 30);
    assert(listSize<int>(lst) == 3);

    listReset<int>(lst);
    assert(*listNext<int>(lst) == 10);
    assert(*listNext<int>(lst) == 20);
    assert(*listNext<int>(lst) == 30);
}

void testOrderedInsert()
{
    List<int> lst = list<int>();
    listOrderedInsert<int>(lst, 20, cmpIntInt);
    listOrderedInsert<int>(lst, 10, cmpIntInt);
    listOrderedInsert<int>(lst, 30, cmpIntInt);
    listOrderedInsert<int>(lst, 25, cmpIntInt);

    assert(listSize<int>(lst) == 4);
    listReset<int>(lst);
    assert(*listNext<int>(lst) == 10);
    assert(*listNext<int>(lst) == 20);
    assert(*listNext<int>(lst) == 25);
    assert(*listNext<int>(lst) == 30);
}

void testSort()
{
    List<int> lst = list<int>();
    listAdd<int>(lst, 40);
    listAdd<int>(lst, 10);
    listAdd<int>(lst, 30);
    listAdd<int>(lst, 20);

    listSort<int>(lst, cmpIntInt);
    listReset<int>(lst);
    assert(*listNext<int>(lst) == 10);
    assert(*listNext<int>(lst) == 20);
    assert(*listNext<int>(lst) == 30);
    assert(*listNext<int>(lst) == 40);
}

void testResetHasNextAndNext()
{
    List<int> lst = list<int>();
    listAdd<int>(lst, 5);
    listAdd<int>(lst, 6);
    listAdd<int>(lst, 7);

    listReset<int>(lst);
    assert(listHasNext<int>(lst));
    assert(*listNext<int>(lst) == 5);
    assert(listHasNext<int>(lst));
    assert(*listNext<int>(lst) == 6);
    assert(listHasNext<int>(lst));
    assert(*listNext<int>(lst) == 7);
    assert(!listHasNext<int>(lst));

    listReset<int>(lst);
    assert(*listNext<int>(lst) == 5);
}

void testNextWithEndFlag()
{
    List<int> lst = list<int>();
    listAdd<int>(lst, 11);
    listAdd<int>(lst, 22);

    listReset<int>(lst);
    bool endOfList = false;
    int* p1 = listNext<int>(lst, endOfList);
    assert(!endOfList);
    assert(p1 != NULL && *p1 == 11);

    int* p2 = listNext<int>(lst, endOfList);
    assert(!endOfList);
    assert(p2 != NULL && *p2 == 22);

    int* p3 = listNext<int>(lst, endOfList);
    assert(endOfList);
    assert(p3 == NULL);
}

void testFree()
{
    List<int> lst = list<int>();
    listAdd<int>(lst, 10);
    listAdd<int>(lst, 20);
    listAddFirst<int>(lst, 5);

    listFree<int>(lst);
    assert(listIsEmpty<int>(lst));
    assert(listSize<int>(lst) == 0);
    assert(!listHasNext<int>(lst));
}

int main()
{
    testCreateIsEmptyAndSize();
    testAddAndAddFirst();
    testFind();
    testRemoveAndRemoveFirst();
    testDiscover();
    testOrderedInsert();
    testSort();
    testResetHasNextAndNext();
    testNextWithEndFlag();
    testFree();

    cout << "Todos los tests de List pasaron correctamente." << endl;
    return 0;
}
