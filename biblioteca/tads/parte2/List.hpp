#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <cassert>
#include <iostream>

#include "../../funciones/lists.hpp"

using std::string;

template <typename T>
struct List
{
    T info;
    int size;
    Node<T>* p;
    Node<T>* curr;
};

template <typename T>
List<T> list()
{
    List<T> lst;
    lst.size = 0;
    lst.p = NULL;
    lst.curr = NULL;
    return lst;
}

template <typename T> int listSize(List<T> lst);


template <typename T>
T* listAdd(List<T>& lst, T e)
{
    Node<T>* aux = add<T>(lst.p, e);

    // si agregue el primer nodo de la lista...
    if(lst.p->sig == NULL)
    {
        lst.curr = lst.p;
    }

    lst.size++;
    return &aux->info;
}

template <typename T>
T* listAddFirst(List<T>& lst, T e)
{
    lst.size++;
    T* ret = &addFirst<T>(lst.p, e)->info;
    if(lst.size == 1)
    {
        lst.curr = lst.p;
    }
    return ret;
}


template <typename T, typename K>
T listRemove(List<T>& lst, K k, int cmpTK(T, K))
{
    assert((listSize<T>(lst)) > 0 && "La lista no puede estar vacia");
    assert(cmpTK != nullptr && "La funcion cmpTK no puede ser nula");
    lst.size--;
    T ret = remove<T, K>(lst.p, k, cmpTK);
    if(lst.size == 0)
    {
        lst.curr = NULL;
    }
    return ret;
}



template <typename T>
T listRemoveFirst(List<T>& lst)
{
    assert((listSize<T>(lst)) > 0 && "La lista no puede estar vacia");
    lst.size--;
    T ret = removeFirst(lst.p);
    if(lst.size == 0)
    {
        lst.curr = NULL;
    }
    return ret;
}

template <typename T, typename K>
T* listFind(List<T> lst, K k, int cmpTK(T, K))
{
    assert(cmpTK != nullptr && "La funcion cmpTK no puede ser nula");
    Node<T>* n = find<T, K>(lst.p, k, cmpTK);
    return n != NULL ? &n->info : NULL;
}

template <typename T>
bool listIsEmpty(List<T> lst)
{
    return lst.p == NULL;
}

template <typename T>
int listSize(List<T> lst)
{
    return lst.size;
}

template <typename T>
void listFree(List<T>& lst)
{
    lst.size = 0;
    lst.curr = NULL;
    free<T>(lst.p);
}

template <typename T>
T* listDiscover(List<T>& lst, T t, int cmpTT(T, T))
{
    assert(cmpTT != nullptr && "La funcion cmpTT no puede ser nula");
    T* x = listFind<T, T>(lst, t, cmpTT);
    return x != NULL ? x : listAdd<T>(lst, t);
}

template <typename T>
T* listOrderedInsert(List<T>& lst, T t, int cmpTT(T, T))
{
    assert(cmpTT != nullptr && "La funcion cmpTT no puede ser nula");
    lst.size++;
    T* ret = &orderedInsert<T>(lst.p, t, cmpTT)->info;
    if(lst.size == 1)
    {
        lst.curr = lst.p;
    }
    return ret;
}

template <typename T>
void listSort(List<T>& lst, int cmpTT(T, T))
{
    assert(cmpTT != nullptr && "La funcion cmpTT no puede ser nula");
    sort<T>(lst.p, cmpTT);
}

template <typename T>
void listReset(List<T>& lst)
{
    lst.curr = lst.p;
}

template <typename T>
bool listHasNext(List<T> lst)
{
    return lst.curr != NULL;
}

template <typename T>
T* listNext(List<T>& lst)
{
    Node<T>* aux = lst.curr;
    lst.curr = lst.curr->sig;
    return &aux->info;
}

template <typename T>
T* listNext(List<T>& lst, bool& endOfList)
{
    if(!listHasNext<T>(lst))
    {
        endOfList = true;
        return NULL;
    }
    else
    {
        endOfList = false;
        return listNext<T>(lst);
    }
}

#endif
