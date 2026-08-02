#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include <cassert>
#include "../../funciones/strings.hpp"

using std::string;

template<typename T>
struct Coll
{
   string s;
   char sep;
   int curr;
};

template<typename T>
Coll<T> coll(char sep)
{
   assert(sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   Coll<T> c;
   c.s = "";
   c.sep=sep;
   c.curr = 0;
   return c;}

template<typename T>
Coll<T> coll()
{
   return coll<T>('|');
}

template<typename T>
int collSize(Coll<T> c)
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   assert(c.curr >= 0 && "El cursor actual de la coleccion debe ser mayor o igual a 0");
   assert(c.curr <= tokenCount(c.s,c.sep) && "El cursor actual de la coleccion debe estar dentro de sus limites");
   return tokenCount(c.s,c.sep);
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   c.s="";
   c.curr=0;
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   assert(p >= 0 && "La posicion a remover debe ser mayor o igual a 0");
   assert(p < collSize(c) && "La posicion a remover debe existir dentro de la coleccion");
   removeTokenAt(c.s,c.sep,p);
   if( c.curr > collSize(c) )
   {
      c.curr = collSize(c);
   }
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   assert(tToString != nullptr && "La funcion tToString no puede ser nula");
   addToken(c.s,c.sep,tToString(t));
   return tokenCount(c.s,c.sep)-1;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   assert(tToString != nullptr && "La funcion tToString no puede ser nula");
   assert(p >= 0 && "La posicion a asignar debe ser mayor o igual a 0");
   assert(p < collSize(c) && "La posicion a asignar debe existir dentro de la coleccion");
   string sI = tToString(t);
   setTokenAt(c.s,c.sep,sI,p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   assert(tFromString != nullptr && "La funcion tFromString no puede ser nula");
   assert(p >= 0 && "La posicion a obtener debe ser mayor o igual a 0");
   assert(p < collSize(c) && "La posicion a obtener debe existir dentro de la coleccion");
   return tFromString(getTokenAt(c.s,c.sep,p));
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   assert(cmpTK != nullptr && "La funcion cmpTK no puede ser nula");
   assert(tFromString != nullptr && "La funcion tFromString no puede ser nula");
   int i=0;
   bool existe = false;
   while( i<collSize<T>(c) && !existe )
   {
      T t = collGetAt<T>(c,i,tFromString);
      if( cmpTK(t,k)==0 )
      {
         existe = true;
      }

      i++;
   }

   return existe?i-1:-1;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   assert(cmpTT != nullptr && "La funcion cmpTT no puede ser nula");
   assert(tFromString != nullptr && "La funcion tFromString no puede ser nula");
   assert(tToString != nullptr && "La funcion tToString no puede ser nula");
   Coll<T> cAux = coll<T>();

   while( collSize(c)>0 )
   {
      // busco el menor
      T tMin = collGetAt<T>(c,0,tFromString);
      int pMin = 0;
      for(int i=1; i<collSize<T>(c); i++)
      {
         T t1 = collGetAt<T>(c,i,tFromString);
         int cmp = cmpTT(t1,tMin);
         tMin = cmp<=0?t1:tMin;
         pMin = cmp<=0?i:pMin;
      }

      // remuevo el mimono
      collRemoveAt<T>(c,pMin);

      // agrego a aux
      collAdd<T>(cAux,tMin,tToString);
   }

   c = cAux;
}

template<typename T>
bool collHasNext(Coll<T> c)
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   assert(c.curr >= 0 && "El cursor actual de la coleccion debe ser mayor o igual a 0");
   assert(c.curr <= collSize(c) && "El cursor actual de la coleccion debe estar dentro de sus limites");
   return c.curr<collSize(c);
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   assert(tFromString != nullptr && "La funcion tFromString no puede ser nula");
   assert(collHasNext<T>(c) && "No existe un siguiente elemento en la coleccion");
   return collGetAt<T>(c,c.curr++,tFromString);
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   assert(tFromString != nullptr && "La funcion tFromString no puede ser nula");
   endOfColl = !collHasNext<T>(c);
   if( endOfColl )
   {
      return {};
   }
   else
   {
      return collGetAt<T>(c,c.curr++,tFromString);
   }
}

template<typename T>
void collReset(Coll<T>& c)
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   c.curr=0;
}

template<typename T>
string collToString(Coll<T> c)
{
   assert(c.sep != '\0' && "El separador de la coleccion no puede ser el caracter nulo");
   assert(c.curr >= 0 && "El cursor actual de la coleccion debe ser mayor o igual a 0");
   assert(c.curr <= collSize(c) && "El cursor actual de la coleccion debe estar dentro de sus limites");
   return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
   assert(length(s) > 0 && "La representacion serializada de la coleccion no puede ser vacia");
   assert(s[0] != '\0' && "El separador serializado de la coleccion no puede ser el caracter nulo");
   Coll<T> c;
   c.sep=s[0];
   c.s=substring(s,1);
   c.curr = 0;
   return c;
}


#endif
