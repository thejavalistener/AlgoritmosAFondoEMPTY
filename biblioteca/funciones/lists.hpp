#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>
#include <cassert>

template <typename T>
struct Node
{
   T info;       // valor que contiene el nodo
   Node<T>* sig; // puntero al siguiente nodo
};

template <typename T>
Node<T>* add(Node<T>*& p, T e)
{
   // creo un nodo nuevo
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = NULL;

   if( p==NULL )
   {
      p = nuevo;
   }
   else
   {
      Node<T>* aux = p;
      while( aux->sig!=NULL )
      {
         aux = aux->sig;
      }

      aux->sig = nuevo;
   }

   return nuevo;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p, T e)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = p;
   p = nuevo;
   return nuevo;
}

template <typename T, typename K>
T remove(Node<T>*& p, K k, int cmpTK(T, K))
{
   assert(p != NULL && "La lista no puede estar vacia");
   assert(cmpTK != nullptr && "La funcion cmpTK no puede ser nula");
   Node<T>* aux = p;
   Node<T>* ant = NULL;

   while( aux!=NULL&&cmpTK(aux->info,k)!=0 )
   {
      ant = aux;
      aux = aux->sig;
   }

   assert(aux != NULL && "El elemento a remover debe existir en la lista");
   if( ant!=NULL )
   {
      ant->sig = aux->sig;
   }
   else
   {
      p = aux->sig;
   }

   T x = aux->info;
   delete aux;

   return x;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   assert(p != NULL && "La lista no puede estar vacia");
   T ret = p->info;
   Node<T>* aux = p->sig;

   delete p;
   p = aux;

   return ret;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p, K k, int cmpTK(T, K))
{
   assert(cmpTK != nullptr && "La funcion cmpTK no puede ser nula");
   Node<T>* aux = p;
   while( aux!=NULL&&cmpTK(aux->info,k)!=0 )
   {
      aux = aux->sig;
   }

   return aux;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p, T e, int cmpTT(T, T))
{
   assert(cmpTT != nullptr && "La funcion cmpTT no puede ser nula");
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = NULL;

   Node<T>* aux = p;
   Node<T>* ant = NULL;
   while( aux!=NULL&&cmpTT(aux->info,e)<=0 )
   {
      ant = aux;
      aux = aux->sig;
   }

   if( ant==NULL )
   {
      p = nuevo;
   }
   else
   {
      ant->sig = nuevo;
   }

   nuevo->sig = aux;

   return nuevo;
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p, T e, bool& enc, int cmpTT(T, T))
{
   assert(cmpTT != nullptr && "La funcion cmpTT no puede ser nula");
   Node<T>* x = find<T, T>(p,e,cmpTT);
   enc = x!=NULL;

   if( !enc )
   {
      x = orderedInsert<T>(p,e,cmpTT);
   }

   return x;
}

template <typename T>
void sort(Node<T>*& p, int cmpTT(T, T))
{
   assert(cmpTT != nullptr && "La funcion cmpTT no puede ser nula");
   Node<T>* q = NULL;
   while( p!=NULL )
   {
      T v = removeFirst<T>(p);
      orderedInsert<T>(q,v,cmpTT);
   }

   p = q;
}

template <typename T>
bool isEmpty(Node<T>* p)
{
   return p==NULL;
}

template <typename T>
void free(Node<T>*& p)
{
   Node<T>* sig;
   while( p!=NULL )
   {
      sig = p->sig;
      delete p;
      p = sig;
   }
}

template <typename T>
Node<T>* push(Node<T>*& p, T e)
{
   return addFirst<T>(p,e);
}

template <typename T> T pop(Node<T>*& p)
{
   assert(p != NULL && "La pila no puede estar vacia");
   return removeFirst(p);
}

template <typename T>
Node<T>* enqueue(Node<T>*& p, Node<T>*& q, T e)
{
   assert((p == NULL && q == NULL) || (p != NULL && q != NULL) && "Los punteros de la cola deben ser ambos nulos o ambos validos");
   Node<T>* aux = add<T>(q,e);
   if( p==NULL )
   {
      p = q;
   }
   else
   {
      q = q->sig;
   }

   return aux;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q, T e)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   if( q!=NULL )
   {
      nuevo->sig = q->sig;
      q->sig = nuevo;
   }
   else
   {
      nuevo->sig = nuevo;
   }
   q = nuevo;
   return nuevo;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   assert(p != NULL && "La cola no puede estar vacia");
   assert(q != NULL && "La cola no puede estar vacia");
   T v = removeFirst<T>(p);

   if( p==NULL )
   {
      q = NULL;
   }

   return v;
}

template <typename T>
T dequeue(Node<T>*& q)
{
   assert(q != NULL && "La cola circular no puede estar vacia");
   Node<T>* aux = q->sig;
   q->sig = aux->sig;
   T ret = aux->info;
   if( aux==q )
   {
      q = NULL;
   }
   delete aux;
   return ret;
}

#endif
