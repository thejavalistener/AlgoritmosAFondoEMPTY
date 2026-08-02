#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
using std::string;

bool isDigit(char c);
int digitCount(int n);

int length(string s)
{
   int i = 0;
   while( s[i++]!='\0' )
      ;
   return i-1;
}

int charCount(string s, char c)
{
   assert(length(s) >= 0 && "La cadena recibida debe ser valida");
   int sum = 0;
   for( int i = 0; i<length(s); i++ )
   {
      if( s[i]==c )
      {
         sum++;
      }
   }

   return sum;
}

string substring(string s, int d, int h)
{
   assert(d >= 0 && "El indice desde debe ser mayor o igual a 0");
   assert(h >= d && "El indice hasta debe ser mayor que desde");
   assert(h <= length(s) && "El indice hasta debe ser menor o igual a la longitud de la cadena");
   string x = "";
   for( int i = d; i<h; i++ )
   {
      x += s[i];
   }

   return x;
}

string substring(string s, int d) // ok
{
   assert(d >= 0 && "El indice desde debe ser mayor o igual a 0");
   assert(d <= length(s) && "El indice desde debe ser menor o igual a la longitud de la cadena");
   return substring(s,d,length(s));
}

int indexOf(string s, char c) // ok
{
   assert(length(s) >= 0 && "La cadena recibida debe ser valida");
   for( int i = 0; i<length(s); i++ )
   {
      if( s[i]==c )
      {
         return i;
      }
   }

   return -1;
}

int indexOf(string s, char c, int offSet) // ok
{
   assert(offSet >= 0 && "El offset debe ser mayor o igual a 0");
   assert(offSet <= length(s) && "El offset debe ser menor o igual a la longitud de la cadena");
   string ns = substring(s,offSet,length(s));
   return indexOf(ns,c);
}

int indexOf(string s, string toSearch) // ok
{
   assert(length(toSearch) > 0 && "La subcadena a buscar no puede ser vacia");
   assert(length(toSearch) <= length(s) && "La subcadena a buscar no puede ser mas larga que la cadena");
   int ns = length(s);
   int nts = length(toSearch);

   for( int i = 0; i<=ns-nts; i++ )
   {
      int j;
      for( j = 0; j<nts; j++ )
      {
         if( s[i+j]!=toSearch[j] )
         {
            break;
         }
      }
      if( j==nts )
      {
         return i;
      }
   }
   return -1;
}

//int indexOf(string s, string toSearch, int offset) // ok
//{
//   return 0;
//}

#include <string>

int indexOf(string s,string toSearch,int offset) {
    assert(offset >= 0 && "El offset debe ser mayor o igual a 0");
    assert(offset <= length(s) && "El offset debe ser menor o igual a la longitud de la cadena");
    assert(length(toSearch) > 0 && "La subcadena a buscar no puede ser vacia");
    int ns = s.length();
    int nts = toSearch.length();

    if (offset >= ns) {
        return -1;
    }

    // Recorrer la cadena desde el offset dado
    for (int i = offset; i <= ns - nts; i++) {
        int j;
        for (j = 0; j < nts; j++) {
            if (s[i + j] != toSearch[j]) {
                break;
            }
        }
        if (j == nts) {
            return i;
        }
    }
    return -1;
}


int lastIndexOf(string s, char c)
{
   assert(length(s) >= 0 && "La cadena recibida debe ser valida");
   for( int i = length(s)-1; i>=0; i-- )
   {
      if( s[i]==c )
         return i;
   }

   return -1;
}

int indexOfN(string s, char c, int n)
{
   assert(n > 0 && "La ocurrencia buscada debe ser mayor a 0");
   int offset = 0;
   int x = -1;
   for( int i = 0; i<n; i++ )
   {
      x = indexOf(s,c,offset);
      assert(x >= 0 && "La cadena no contiene la cantidad de ocurrencias solicitadas");
      offset += x+1;
   }
   return offset-1;
}

char toUpperCase(char);
bool isLetter(char);
int charToInt(char c)
{
   assert(isLetter(c)||isDigit(c)&&"El caracter debe ser un digito entre '0' y '9'");

   if( isDigit(c) )
   {
       return c-'0';
   }
   else
   {
       char x = toUpperCase(c);
       return c-'A'+10;
   }


}

char intToChar(int i)
{
   assert(i >= 0 && i <= 15 && "El entero debe estar entre 0 y 15");
   
   return i<10?'0'+i:'A'+i-10;
}

int poww(int x, int y)
{
   assert(y >= 0 && "El exponente debe ser mayor o igual a 0");
   int p = 1;
   for( int i = 0; i<y; i++ )
   {
      p *= x;
   }

   return p;
}

int getDigit(int n, int i)
{
   assert(n >= 0 && "El numero debe ser mayor o igual a 0");
   assert(i >= 0 && "La posicion del digito debe ser mayor o igual a 0");
   assert(i < digitCount(n) && "La posicion del digito debe existir dentro del numero");
   int r1 = n%(int)poww(10,i+1);
   return r1/(pow(10,i));
}

int digitCount(int n)
{
   assert(n >= 0 && "El numero debe ser mayor o igual a 0");
   if( n==0 )
   {
      return 1;
   }

   int x = 0;
   double d = n;
   while( d>=1 )
   {
      d = d/10;
      x++;
   }

   return x;
}

string intToString(int i)
{
   assert(i >= 0 && "El numero debe ser mayor o igual a 0");
   string x = "";
   int n = digitCount(i);
   for( int j = 0; j<n; j++ )
   {
      x = intToChar(getDigit(i,j))+x;
   }

   return x;
}

int stringToInt(string s, int b) // ok
{
   assert(length(s) > 0 && "La cadena no puede ser vacia");
   assert(b > 1 && "La base debe ser mayor a 1");
   int n = length(s);
   int sum = 0;
   for( int i = 0; i<n; i++ )
   {
      //    int d = s[n-i-1]-'0';
      int d = charToInt((char)s[n-i-1]);
      assert(d < b && "Todos los digitos de la cadena deben ser menores que la base");
      sum += d*poww(b,i);
   }

   return sum;
}

int stringToInt(string s) // ok
{
   assert(length(s) > 0 && "La cadena no puede ser vacia");
   return stringToInt(s,10);
}

string charToString(char c)
{
   assert(c != '\0' && "El caracter no puede ser nulo");
   string s = "";

   s+=c;

   return s;
}

char stringToChar(string s)
{
   assert(length(s) == 1 && "La cadena debe tener exactamente un caracter");
   return s[0];
}

string stringToString(string s)
{
   assert(length(s) >= 0 && "La cadena recibida debe ser valida");
   return s;
}

string doubleToString(double d,int prec)
{
   assert(prec >= 0 && "La precision debe ser mayor o igual a 0");
   return "";
}

string doubleToString(double d)
{
   assert(true && "El valor double recibido debe ser valido");
   return "";
}

double stringToDouble(string s)
{
   assert(length(s) > 0 && "La cadena no puede ser vacia");
   return 1.1;
}

bool isEmpty(string s)
{
   assert(length(s) >= 0 && "La cadena recibida debe ser valida");
   return s[0]=='\0';
}

bool startsWith(string s, string x)
{
   assert(length(x) <= length(s) && "El prefijo no puede ser mas largo que la cadena");
   return substring(s,0,length(x))==x;
}

bool endsWith(string s, string x)
{
   assert(length(x) <= length(s) && "El sufijo no puede ser mas largo que la cadena");
   return substring(s,length(s)-length(x))==x;
}

bool contains(string s, char c)
{
   assert(length(s) >= 0 && "La cadena recibida debe ser valida");
   return indexOf(s,c)>=0;
}

string replace(string s, char oldChar, char newChar)
{
   assert(length(s) >= 0 && "La cadena recibida debe ser valida");
   for( int i = 0; s[i]!='\0'; i++ )
   {
      s[i] = (s[i]==oldChar)?newChar:s[i];
   }
   return s;
}

string insertAt(string s, int pos, char c)
{
   assert(pos >= 0 && "La posicion debe ser mayor o igual a 0");
   assert(pos <= length(s) && "La posicion debe ser menor o igual a la longitud de la cadena");
   return substring(s,0,pos)+c+substring(s,pos);
}

string removeAt(string s, int pos)
{
   assert(pos >= 0 && "La posicion debe ser mayor o igual a 0");
   assert(pos < length(s) && "La posicion debe ser menor que la longitud de la cadena");
   return substring(s,0,pos)+substring(s,pos+1);
}

string ltrim(string s)
{
   assert(length(s) > 0 && "La cadena no puede ser vacia");
   int i = 0;
   while( s[i++]==' ' )
      ;
   return substring(s,i-1);
}

string rtrim(string s)
{
   assert(length(s) > 0 && "La cadena no puede ser vacia");
   int i = length(s);
   while( s[--i]==' ' )
      ;
   return substring(s,0,i+1);
}

string trim(string s)
{
   assert(length(s) > 0 && "La cadena no puede ser vacia");
   return ltrim(rtrim(s));
}

string replicate(char c, int n)
{
   assert(n >= 0 && "La cantidad de repeticiones debe ser mayor o igual a 0");
   string s = "";
   for( int i = 0; i<n; i++ )
   {
      s += c;
   }
   return s;
}

string spaces(int n)
{
   assert(n >= 0 && "La cantidad de espacios debe ser mayor o igual a 0");
   return replicate(' ',n);
}

string lpad(string s, int n, char c)
{
   assert(n >= length(s) && "El largo destino debe ser mayor o igual al largo de la cadena");
   return replicate(c,n-length(s))+s;
}

string rpad(string s, int n, char c)
{
   assert(n >= length(s) && "El largo destino debe ser mayor o igual al largo de la cadena");
   return s+replicate(c,n-length(s));
}

string cpad(string s, int n, char c)
{
   assert(n >= length(s) && "El largo destino debe ser mayor o igual al largo de la cadena");
   int dif = (n-length(s))/2;
   int res = (n-length(s))%2;
   return replicate(c,dif)+s+replicate(c,dif+res);
}

bool isDigit(char c)
{
   assert(c != '\0' && "El caracter no puede ser nulo");
   return c>='0'&&c<='9';
}

bool isLetter(char c)
{
   assert(c != '\0' && "El caracter no puede ser nulo");
   return (c>='A'&&c<='Z')||(c>='a'&&c<='z');
}

bool isUpperCase(char c)
{
   assert(c != '\0' && "El caracter no puede ser nulo");
   return c>='A'&&c<='Z';
}

bool isLowerCase(char c)
{
   assert(c != '\0' && "El caracter no puede ser nulo");
   return c>='a'&&c<='z';
}

char toUpperCase(char c)
{
   assert(c != '\0' && "El caracter no puede ser nulo");
   return isLowerCase(c)?'A'+c-'a':c;
}

char toLowerCase(char c)
{
   assert(c != '\0' && "El caracter no puede ser nulo");
   return isUpperCase(c)?'a'+c-'A':c;
}

string toUpperCase(string s)
{
   assert(length(s) >= 0 && "La cadena recibida debe ser valida");
   string x = "";
   for( int i = 0; i<length(s); i++ )
   {
      x += toUpperCase((char)s[i]);
   }
   return x;
}

string toLowerCase(string s)
{
   assert(length(s) >= 0 && "La cadena recibida debe ser valida");
   string x = "";
   for( int i = 0; i<length(s); i++ )
   {
      x += toLowerCase((char)s[i]);
   }
   return x;
}

int cmpString(string a, string b)
{
   assert(length(a) >= 0 && length(b) >= 0 && "Las cadenas recibidas deben ser validas");
   return a<b?-1:a>b?1:0;
}

int cmpDouble(double a, double b)
{
   assert(true && "Los valores double recibidos deben ser validos");
   return a<b?-1:a>b?1:0;
}

char* stringToCString(string s)
{
   assert(length(s) >= 0 && "La cadena recibida debe ser valida");
   char* ret = new char[length(s)+1];

   int i = 0;
   while( s[i]!='\0' )
   {
      ret[i] = (char)s[i];
      i++;
   }

   ret[i] = '\0';
   return ret;
}

string cStringToString(char c[])
{
   assert(c != NULL && "El puntero al arreglo de caracteres no puede ser nulo");
   return string(c);
}

#endif
