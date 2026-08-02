#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include <cassert>
#include "strings.hpp"
using std::string;

int tokenCount(string s,char sep)
{
   assert(sep != '\0' && "El separador no puede ser el caracter nulo");
   if(length(s)==0)
   {
      return 0;
   }
   else
   {
      return charCount(s,sep)+1;
   }
}

void addToken(string& s,char sep,string t)
{
   assert(sep != '\0' && "El separador no puede ser el caracter nulo");
   assert(indexOf(t,sep) == -1 && "El token a agregar no puede contener el separador");
   if(tokenCount(s,sep)==0)
   {
      s=t;
   }
   else
   {
      s+=sep+t;
   }
}

string getTokenAt(string s,char sep, int i)
{
   assert(sep != '\0' && "El separador no puede ser el caracter nulo");
   assert(i >= 0 && "El indice del token debe ser mayor o igual a 0");
   assert(i < tokenCount(s,sep) && "El indice del token debe existir dentro de la cadena");
   int d=(i==0)?0:indexOfN(s,sep,i)+1;
   int h=(i==tokenCount(s,sep)-1)?length(s):indexOfN(s,sep,i+1);
   return substring(s,d,h);
}

void removeTokenAt(string& s,char sep, int i)
{
   assert(sep != '\0' && "El separador no puede ser el caracter nulo");
   assert(i >= 0 && "El indice del token debe ser mayor o igual a 0");
   assert(i < tokenCount(s,sep) && "El indice del token debe existir dentro de la cadena");
   string ret="";
   string ns="";
   int n=tokenCount(s,sep);
   for(int k=0; k<n; k++)
   {
      string tk = getTokenAt(s,sep,k);

      if( k!=i )
      {
         addToken(ns,sep,tk);
      }
      else
      {
         ret=tk;
      }
   }

   s=ns;
}

void setTokenAt(string& s,char sep, string t,int i)
{
   assert(sep != '\0' && "El separador no puede ser el caracter nulo");
   assert(indexOf(t,sep) == -1 && "El token a asignar no puede contener el separador");
   assert(i >= 0 && "El indice del token debe ser mayor o igual a 0");
   assert(i < tokenCount(s,sep) && "El indice del token debe existir dentro de la cadena");
   string ret="";
   string ns="";
   int n=tokenCount(s,sep);
   for(int x=0; x<n; x++)
   {

      if( x!=i )
      {
         string tk = getTokenAt(s,sep,x);
         addToken(ns,sep,tk);
      }
      else
      {
         addToken(ns,sep,t);
      }
   }

   s=ns;
}

int findToken(string s,char sep, string t)
{
   assert(sep != '\0' && "El separador no puede ser el caracter nulo");
   assert(indexOf(t,sep) == -1 && "El token a buscar no puede contener el separador");
   int n=tokenCount(s,sep);
   for(int i=0;i<n;i++)
   {
      if( t==getTokenAt(s,sep,i) )
      {
         return i;
      }
   }

   return -1;
}

#endif
