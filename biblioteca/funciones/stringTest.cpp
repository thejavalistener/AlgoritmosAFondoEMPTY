#include <cassert>
#include <iostream>
#include <string>

#include "strings.hpp"

using std::cout;
using std::endl;
using std::string;

void testLength()
{
    assert(length("hola") == 4);
    assert(length("") == 0);
}

void testCharCount()
{
    assert(charCount("banana", 'a') == 3);
    assert(charCount("banana", 'z') == 0);
    assert(charCount("", 'x') == 0);
}

void testSubstring()
{
    assert(substring("hola", 0, 2) == "ho");
    assert(substring("hola", 2, 4) == "la");
    assert(substring("hola", 1) == "ola");
}

void testIndexOf()
{
    assert(indexOf("banana", 'b') == 0);
    assert(indexOf("banana", 'a') == 1);
    assert(indexOf("banana", 'z') < 0);
    assert(indexOf("banana", 'a', 1) == 0);
    assert(indexOf("banana", "ana") == 1);
    assert(indexOf("banana", "ana", 2) == 3);
    assert(lastIndexOf("banana", 'a') == 5);
    assert(indexOfN("banana", 'a', 2) == 3);
}

void testNumericConversions()
{
    assert(charToInt('0') == 0);
    assert(charToInt('7') == 7);
    assert(charToInt('A') == 10);
    assert(charToInt('F') == 15);
    assert(intToChar(0) == '0');
    assert(intToChar(9) == '9');
    assert(intToChar(10) == 'A');
    assert(intToChar(15) == 'F');

    assert(getDigit(1234, 0) == 4);
    assert(getDigit(1234, 2) == 2);
    assert(digitCount(0) == 1);
    assert(digitCount(9876) == 4);
    assert(intToString(1234) == "1234");
    assert(stringToInt("1234") == 1234);
    assert(stringToInt("1011", 2) == 11);
}

void testStringConversions()
{
    assert(charToString('A') == "A");
    assert(stringToChar("Z") == 'Z');
    assert(stringToString("hola") == "hola");
}

void testPredicatesAndTransforms()
{
    assert(isEmpty(""));
    assert(!isEmpty("hola"));
    assert(startsWith("hola", "ho"));
    assert(endsWith("hola", "la"));
    assert(contains("hola", 'o'));
    assert(replace("banana", 'a', 'o') == "bonono");
    assert(isDigit('5'));
    assert(!isDigit('x'));
    assert(isLetter('A'));
    assert(isLetter('z'));
    assert(!isLetter('9'));
    assert(isUpperCase('A'));
    assert(!isUpperCase('a'));
    assert(isLowerCase('z'));
    assert(!isLowerCase('Z'));
    assert(toUpperCase('b') == 'B');
    assert(toUpperCase('B') == 'B');
    assert(toLowerCase('d') == 'd');
    assert(toUpperCase("Hola") == "HOLA");
    assert(toLowerCase("Hola") == "hola");
}

void testPaddingAndTrim()
{
    assert(insertAt("hola", 2, 'X') == "hoXla");
    assert(removeAt("hola", 1) == "hla");
    assert(ltrim("   hola") == "hola");
    assert(rtrim("hola   ") == "hola");
    assert(trim("   hola   ") == "hola");
    assert(trim("") == "");
    assert(replicate('x', 4) == "xxxx");
    assert(spaces(3) == "   ");
    assert(lpad("abc", 5, '_') == "__abc");
    assert(lpad("abcdefg", 5, '_') == "abcdefg");
    assert(rpad("abc", 5, '_') == "abc__");
    assert(rpad("abcdefg", 5, '_') == "abcdefg");
    assert(cpad("abc", 7, '_') == "__abc__");
    assert(cpad("abcdefg", 5, '_') == "abcdefg");
}

void testComparisonsAndCString()
{
    assert(cmpString("abc", "abc") == 0);
    assert(cmpString("abc", "abd") == -1);
    assert(cmpString("abd", "abc") == 1);
    assert(cmpString("", "") == 0);
    assert(cmpDouble(1.5, 1.5) == 0);
    assert(cmpDouble(1.5, 2.0) == -1);
    assert(cmpDouble(2.0, 1.5) == 1);

    char* c = stringToCString("hola");
    assert(cStringToString(c) == "hola");
    delete[] c;
}

int main()
{
    testLength();
    testCharCount();
    testSubstring();
    testIndexOf();
    testNumericConversions();
    testStringConversions();
    testPredicatesAndTransforms();
    testPaddingAndTrim();
    testComparisonsAndCString();

    cout << "Todos los tests de strings pasaron correctamente." << endl;
    return 0;
}
