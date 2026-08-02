
#include "principal.hpp"

#include <cassert>
#include <iostream>

#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/millis.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte1/Fecha.hpp"
#include "biblioteca/tads/parte1/Timer.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;


int main()
{
    Coll<int> c = coll<int>();
    collAdd<int>(c,1,intToString);
    collAdd<int>(c,2,intToString);
    collAdd<int>(c,3,intToString);

    collReset<int>(c);
    while( collHasNext<int>(c) )
    {
        int x = collNext<int>(c,stringToInt);
        cout << x << endl;
    }

    for(int i=0; i<collSize<int>(c); i++)
    {
        int x = collGetAt<int>(c,i,stringToInt);
        cout << x << endl;
    }

    return 0;
}
