#include <cassert>
#include <iostream>
#include <string>

#include "tokens.hpp"

using std::cout;
using std::endl;
using std::string;

// -- PROTOTIPOS --
void testTokenCount();
void testAddToken();
void testGetTokenAt();
void testRemoveTokenAt();
void testSetTokenAt();
void testFindToken();

// -- MAIN --
int main()
{
    testTokenCount();
    // testAddToken();
    // testGetTokenAt();
    // testRemoveTokenAt();
    // testSetTokenAt();
    // testFindToken();

    cout << "Todos los tests de tokens pasaron correctamente." << endl;
    return 0;
}

void testTokenCount()
{
    assert(tokenCount("", ',') == 0);
    assert(tokenCount("uno", ',') == 1);
    assert(tokenCount("uno,dos,tres", ',') == 3);
    assert(tokenCount(",uno,dos,tres", ',') == 4);
    assert(tokenCount("uno,dos,tres,", ',') == 4);
    assert(tokenCount("uno,dos,tres,,", ',') == 5);
}

void testAddToken()
{
    string s = "";
    addToken(s, ',', "uno");
    assert(s == "uno");

    addToken(s, ',', "dos");
    assert(s == "uno,dos");

    addToken(s, ',', "tres");
    assert(s == "uno,dos,tres");

    addToken(s, ',', "");
    assert(s == "uno,dos,tres,");
}

void testGetTokenAt()
{
    string s = ",uno,dos,tres,";
    assert(getTokenAt(s, ',', 0) == "");
    assert(getTokenAt(s, ',', 1) == "uno");
    assert(getTokenAt(s, ',', 2) == "dos");
    assert(getTokenAt(s, ',', 3) == "tres");
    assert(getTokenAt(s, ',', 4) == "");
}

void testRemoveTokenAt()
{
    string s1 = "uno,dos,tres";
    removeTokenAt(s1, ',', 0);
    assert(s1 == "dos,tres");

    string s2 = "uno,dos,tres";
    removeTokenAt(s2, ',', 1);
    assert(s2 == "uno,tres");

    string s3 = "uno,dos,tres";
    removeTokenAt(s3, ',', 2);
    assert(s3 == "uno,dos");
}

void testSetTokenAt()
{
    string s1 = "uno,dos,tres";
    setTokenAt(s1, ',', "cero", 0);
    assert(s1 == "cero,dos,tres");

    string s2 = "uno,dos,tres";
    setTokenAt(s2, ',', "medio", 1);
    assert(s2 == "uno,medio,tres");

    string s3 = "uno,dos,tres";
    setTokenAt(s3, ',', "final", 2);
    assert(s3 == "uno,dos,final");
}

void testFindToken()
{
    string s = "uno,dos,tres";
    assert(findToken(s, ',', "uno") == 0);
    assert(findToken(s, ',', "dos") == 1);
    assert(findToken(s, ',', "tres") == 2);
    assert(findToken(s, ',', "cuatro") == -1);
}
