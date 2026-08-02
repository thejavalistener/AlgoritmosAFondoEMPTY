#ifndef _TFRACCION_T_
#define _TFRACCION_T_

#include <iostream>

using std::string;
using std::to_string;

struct Fraccion
{
    int numerador;
    int denominador;
};

Fraccion fraccion(int n,int d)
{
    Fraccion ret;
    ret.numerador = n;
    ret.denominador = d;
    return ret;
}

string fraccionToString(Fraccion f)
{
   string sNum = to_string(f.numerador); 
   string sDen = to_string(f.denominador);
   return sNum+"/"+sDen;
}

Fraccion fraccionSumar(Fraccion a,Fraccion b)
{
   Fraccion ret;

   int numA = a.numerador;
   int denA = a.denominador;
   int numB = b.numerador;
   int denB = b.denominador;

   int num = numA*denB + numB*denA;
   int den = denA*denB;

   ret.numerador = num;
   ret.denominador = den;

   return ret;
}

Fraccion fraccionSimplificar(Fraccion f)
{
   Fraccion ret;
   int n = f.numerador;
   int d = f.denominador;
   int i=2;

   while( i<=n && i<=d )
   {
      if( n%i==0 && d%i==0 )
      {


         n = n/i;
         d = d/i;
      }
      else
      {
         i = i+1;
      }
   }

   ret.numerador = n;
   ret.denominador = d;
   return ret;
}

bool fraccionEsEntera(Fraccion f)
{
   return f.numerador%f.denominador==0;
}

int fraccionGetNumerador(Fraccion f)
{
    return f.numerador;
}

void fraccionSetNumerador(Fraccion& f,int n)
{
    f.numerador = n;
}

int fraccionGetDenominador(Fraccion f)
{
    return f.denominador;
}

void fraccionSetDenominador(Fraccion& f,int d)
{
    f.denominador = d;
}

#endif