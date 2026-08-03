#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include <cassert>
#include "../../funciones/arrays.hpp"

using std::string;

template<typename T>
struct Array
{
   T* a;
   int len;
   int cap;
   int curr;
};

template<typename T>
Array<T> array()
{
   Array<T> a;
   a.len=0;
   a.cap = 100;
   a.a = new T[a.cap];
   a.curr = 0;
   return a;
}

template<typename T>
void _arrayResize(Array<T>& a,int size)
{
   assert(a.a != NULL && "El arreglo interno no puede ser nulo");
   assert(a.len >= 0 && "La longitud del arreglo debe ser mayor o igual a 0");
   assert(a.cap > 0 && "La capacidad del arreglo debe ser mayor a 0");
   assert(a.len <= a.cap && "La longitud del arreglo no puede superar la capacidad");
   assert(size >= a.len && "El nuevo tamano debe ser mayor o igual a la longitud actual");
   assert(size > 0 && "El nuevo tamano debe ser mayor a 0");
   T* b=new T[size];
   for(int i=0;i<a.len;i++)
   {
      b[i]=a.a[i];
   }

   delete a.a;

   a.a = b;
   a.cap = size;
}


template<typename T>
int arrayAdd(Array<T>& a,T t)
{
   assert(a.a != NULL && "El arreglo interno no puede ser nulo");
   assert(a.len >= 0 && "La longitud del arreglo debe ser mayor o igual a 0");
   assert(a.cap > 0 && "La capacidad del arreglo debe ser mayor a 0");
   assert(a.len <= a.cap && "La longitud del arreglo no puede superar la capacidad");
   assert(a.curr >= 0 && a.curr <= a.len && "El cursor actual debe estar dentro de los limites del arreglo");
   if( a.len>=a.cap )
    {
       _arrayResize(a,a.cap*2);
    }

    return add<T>(a.a,a.len,t);
}

template<typename T>
T* arrayGet(Array<T> a,int p)
{
   assert(a.a != NULL && "El arreglo interno no puede ser nulo");
   assert(p >= 0 && "La posicion a obtener debe ser mayor o igual a 0");
   assert(p < a.len && "La posicion a obtener debe existir dentro del arreglo");
   return &(a.a[p]);
}

template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
   assert(a.a != NULL && "El arreglo interno no puede ser nulo");
   assert(p >= 0 && "La posicion a asignar debe ser mayor o igual a 0");
   assert(p < a.len && "La posicion a asignar debe existir dentro del arreglo");
   a.a[p]=t;
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
   assert(a.a != NULL && "El arreglo interno no puede ser nulo");
   assert(a.len >= 0 && "La longitud del arreglo debe ser mayor o igual a 0");
   assert(a.cap > 0 && "La capacidad del arreglo debe ser mayor a 0");
   assert(a.len <= a.cap && "La longitud del arreglo no puede superar la capacidad");
   assert(p >= 0 && "La posicion de insercion debe ser mayor o igual a 0");
   assert(p <= a.len && "La posicion de insercion debe estar entre 0 y la longitud del arreglo");
   if( a.len>=a.cap )
   {
      _arrayResize(a,a.cap*2);
   }

   insert<T>(a.a,a.len,t,p);
}

template<typename T>
int arraySize(Array<T> a)
{
   assert(a.a != NULL && "El arreglo interno no puede ser nulo");
   assert(a.len >= 0 && "La longitud del arreglo debe ser mayor o igual a 0");
   assert(a.cap > 0 && "La capacidad del arreglo debe ser mayor a 0");
   assert(a.len <= a.cap && "La longitud del arreglo no puede superar la capacidad");
   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   assert(a.a != NULL && "El arreglo interno no puede ser nulo");
   assert(a.len > 0 && "El arreglo no puede estar vacio");
   assert(p >= 0 && "La posicion a remover debe ser mayor o igual a 0");
   assert(p < a.len && "La posicion a remover debe existir dentro del arreglo");
   return remove<T>(a.a,a.len,p);
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
   assert(a.a != NULL && "El arreglo interno no puede ser nulo");
   a.len=0;
   a.curr=0;
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   assert(a.a != NULL && "El arreglo interno no puede ser nulo");
   assert(cmpTK != nullptr && "La funcion cmpTK no puede ser nula");
   return find<T,K>(a.a,a.len,k,cmpTK);
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
   assert(a.a != NULL && "El arreglo interno no puede ser nulo");
   assert(cmpTT != nullptr && "La funcion cmpTT no puede ser nula");
   assert(a.len >= 0 && "La longitud del arreglo debe ser mayor o igual a 0");
   assert(a.cap > 0 && "La capacidad del arreglo debe ser mayor a 0");
   assert(a.len <= a.cap && "La longitud del arreglo no puede superar la capacidad");
   if( a.len>=a.cap )
   {
      _arrayResize(a,a.cap*2);
   }
   return orderedInsert<T>(a.a,a.len,t,cmpTT);
}

template<typename T>
T* arrayDiscover(Array<T>& a,T t,int cmpTT(T,T))
{
   assert(a.a != NULL && "El arreglo interno no puede ser nulo");
   assert(cmpTT != nullptr && "La funcion cmpTT no puede ser nula");
   int p = arrayFind<T,T>(a,t,cmpTT);
   if( p<0 )
   {
      p = arrayAdd<T>(a,t);
   }

   return arrayGet<T>(a,p);
}

template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   assert(a.a != NULL && "El arreglo interno no puede ser nulo");
   assert(cmpTT != nullptr && "La funcion cmpTT no puede ser nula");
   sort<T>(a.a,a.len,cmpTT);
}


template<typename T>
void arrayReset(Array<T>& a)
{
    assert(a.a != NULL && "El arreglo interno no puede ser nulo");
    a.curr = 0;
}

template<typename T>
bool arrayHasNext(Array<T>& a)
{
    assert(a.a != NULL && "El arreglo interno no puede ser nulo");
    assert(a.curr >= 0 && a.curr <= a.len && "El cursor actual debe estar dentro de los limites del arreglo");
    return a.curr<a.len;
}

template<typename T>
T* arrayNext(Array<T>& a)
{
    assert(a.a != NULL && "El arreglo interno no puede ser nulo");
    assert(a.curr >= 0 && a.curr < a.len && "Debe existir un siguiente elemento en el arreglo");
    T* x = arrayGet<T>(a,a.curr);
    a.curr++;
    return x;
}

#endif
