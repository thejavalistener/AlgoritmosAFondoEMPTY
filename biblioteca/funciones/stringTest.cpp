#include <cassert>
#include <iostream>
#include <string>

#include "strings.hpp"

using std::cout;
using std::endl;
using std::string;

// -- PROTOTIPOS --
void testLength();
void testCharCount();
void testSubstring();
void testSubstring_withDesde();
void testIndexOf();
void testIndexOf_withOffset();
void testIndexOf_withToSearch();
void testIndexOf_withToSearchAndOffset();
void testLastIndexOf();
void testIndexOfN();
void testCharToInt();
void testIntToChar();
void testGetDigit();
void testDigitCount();
void testIntToString();
void testStringToInt_withBase();
void testStringToInt();
void testCharToString();
void testStringToChar();
void testStringToString();
void testDoubleToString_withPrecision();
void testDoubleToString();
void testStringToDouble();
void testIsEmpty();
void testStartsWith();
void testEndsWith();
void testContains();
void testReplace();
void testInsertAt();
void testRemoveAt();
void testLtrim();
void testRtrim();
void testTrim();
void testReplicate();
void testSpaces();
void testLpad();
void testRpad();
void testCpad();
void testIsDigit();
void testIsLetter();
void testIsUpperCase();
void testIsLowerCase();
void testToUpperCase();
void testToLowerCase();
void testToUpperCase_withString();
void testToLowerCase_withString();
void testCmpString();
void testCmpDouble();
void testStringToCString();
void testCStringToString();

// -- MAIN --
int main()
{
    testLength();
    // testCharCount();
    // testSubstring();
    // testSubstring_withDesde();
    // testIndexOf();
    // testIndexOf_withOffset();
    // testIndexOf_withToSearch();
    // testIndexOf_withToSearchAndOffset();
    // testLastIndexOf();
    // testIndexOfN();
    // testCharToInt();
    // testIntToChar();
    // testGetDigit();
    // testDigitCount();
    // testIntToString();
    // testStringToInt_withBase();
    // testStringToInt();
    // testCharToString();
    // testStringToChar();
    // testStringToString();
    // testDoubleToString_withPrecision();
    // testDoubleToString();
    // testStringToDouble();
    // testIsEmpty();
    // testStartsWith();
    // testEndsWith();
    // testContains();
    // testReplace();
    // testInsertAt();
    // testRemoveAt();
    // testLtrim();
    // testRtrim();
    // testTrim();
    // testReplicate();
    // testSpaces();
    // testLpad();
    // testRpad();
    // testCpad();
    // testIsDigit();
    // testIsLetter();
    // testIsUpperCase();
    // testIsLowerCase();
    // testToUpperCase();
    // testToLowerCase();
    // testToUpperCase_withString();
    // testToLowerCase_withString();
    // testCmpString();
    // testCmpDouble();
    // testStringToCString();
    // testCStringToString();

    cout << "Todos los tests de strings pasaron correctamente." << endl;
    return 0;
}




void testLength()
{
    assert(length("hola") == 4);
    assert(length("") == 0);
}

void testCharCount()
{
    assert(charCount("banana", 'a') == 3);
    assert(charCount("banana", 'z') == 0);
}

void testSubstring()
{
    assert(substring("hola", 0, 2) == "ho");
    assert(substring("hola", 2, 4) == "la");
}

void testSubstring_withDesde()
{
    assert(substring("hola", 1) == "ola");
    assert(substring("hola", 4) == "");
}

void testIndexOf()
{
    assert(indexOf("banana", 'b') == 0);
    assert(indexOf("banana", 'a') == 1);
    assert(indexOf("banana", 'z') == -1);
}

void testIndexOf_withOffset()
{
    assert(indexOf("banana", 'a', 0) == 1);
    assert(indexOf("banana", 'a', 2) == 1);
    assert(indexOf("banana", 'z', 3) == -1);
}

void testIndexOf_withToSearch()
{
    assert(indexOf("banana", "ana") == 1);
    assert(indexOf("banana", "na") == 2);
    assert(indexOf("banana", "xyz") == -1);
}

void testIndexOf_withToSearchAndOffset()
{
    assert(indexOf("banana", "ana", 0) == 1);
    assert(indexOf("banana", "ana", 2) == 3);
    assert(indexOf("banana", "ana", 6) == -1);
}

void testLastIndexOf()
{
    assert(lastIndexOf("banana", 'a') == 5);
    assert(lastIndexOf("banana", 'b') == 0);
    assert(lastIndexOf("banana", 'z') == -1);
}

void testIndexOfN()
{
    assert(indexOfN("banana", 'a', 1) == 1);
    assert(indexOfN("banana", 'a', 2) == 3);
    assert(indexOfN("banana", 'a', 3) == 5);
}

void testCharToInt()
{
    assert(charToInt('0') == 0);
    assert(charToInt('7') == 7);
    assert(charToInt('A') == 10);
    assert(charToInt('F') == 15);
}

void testIntToChar()
{
    assert(intToChar(0) == '0');
    assert(intToChar(9) == '9');
    assert(intToChar(10) == 'A');
    assert(intToChar(15) == 'F');
}

void testPoww()
{
    assert(poww(2, 0) == 1);
    assert(poww(2, 3) == 8);
    assert(poww(5, 2) == 25);
}

void testGetDigit()
{
    assert(getDigit(1234, 0) == 4);
    assert(getDigit(1234, 1) == 3);
    assert(getDigit(1234, 3) == 1);
}

void testDigitCount()
{
    assert(digitCount(0) == 1);
    assert(digitCount(9) == 1);
    assert(digitCount(9876) == 4);
}

void testIntToString()
{
    assert(intToString(0) == "0");
    assert(intToString(7) == "7");
    assert(intToString(1234) == "1234");
}

void testStringToInt_withBase()
{
    assert(stringToInt("1011", 2) == 11);
    assert(stringToInt("77", 8) == 63);
    assert(stringToInt("1A", 16) == 26);
}

void testStringToInt()
{
    assert(stringToInt("0") == 0);
    assert(stringToInt("1234") == 1234);
}

void testCharToString()
{
    assert(charToString('A') == "A");
    assert(charToString('z') == "z");
}

void testStringToChar()
{
    assert(stringToChar("A") == 'A');
    assert(stringToChar("z") == 'z');
}

void testStringToString()
{
    assert(stringToString("hola") == "hola");
    assert(stringToString("") == "");
}

void testDoubleToString_withPrecision()
{
    assert(doubleToString(1.5, 0) == "");
    assert(doubleToString(3.14159, 2) == "");
}

void testDoubleToString()
{
    assert(doubleToString(1.5) == "");
    assert(doubleToString(0.0) == "");
}

void testStringToDouble()
{
    assert(stringToDouble("1.5") == 1.1);
    assert(stringToDouble("999") == 1.1);
}

void testIsEmpty()
{
    assert(isEmpty(""));
    assert(!isEmpty("hola"));
}

void testStartsWith()
{
    assert(startsWith("hola", "ho"));
    assert(!startsWith("hola", "la"));
}

void testEndsWith()
{
    assert(endsWith("hola", "la"));
    assert(!endsWith("hola", "ho"));
}

void testContains()
{
    assert(contains("hola", 'o'));
    assert(!contains("hola", 'x'));
}

void testReplace()
{
    assert(replace("banana", 'a', 'o') == "bonono");
    assert(replace("hola", 'x', 'y') == "hola");
}

void testInsertAt()
{
    assert(insertAt("hola", 0, 'X') == "Xhola");
    assert(insertAt("hola", 2, 'X') == "hoXla");
}

void testRemoveAt()
{
    assert(removeAt("hola", 0) == "ola");
    assert(removeAt("hola", 1) == "hla");
}

void testLtrim()
{
    assert(ltrim("   hola") == "hola");
    assert(ltrim("hola") == "hola");
}

void testRtrim()
{
    assert(rtrim("hola   ") == "hola");
    assert(rtrim("") == "");
}

void testTrim()
{
    assert(trim("   hola   ") == "hola");
    assert(trim("") == "");
}

void testReplicate()
{
    assert(replicate('x', 0) == "");
    assert(replicate('x', 4) == "xxxx");
}

void testSpaces()
{
    assert(spaces(0) == "");
    assert(spaces(3) == "   ");
}

void testLpad()
{
    assert(lpad("abc", 5, '_') == "__abc");
    assert(lpad("abcdef", 3, '_') == "abcdef");
}

void testRpad()
{
    assert(rpad("abc", 5, '_') == "abc__");
    assert(rpad("abcdef", 3, '_') == "abcdef");
}

void testCpad()
{
    assert(cpad("abc", 7, '_') == "__abc__");
    assert(cpad("abc", 6, '_') == "_abc__");
}

void testIsDigit()
{
    assert(isDigit('0'));
    assert(isDigit('9'));
    assert(!isDigit('a'));
}

void testIsLetter()
{
    assert(isLetter('A'));
    assert(isLetter('z'));
    assert(!isLetter('5'));
}

void testIsUpperCase()
{
    assert(isUpperCase('A'));
    assert(!isUpperCase('a'));
}

void testIsLowerCase()
{
    assert(isLowerCase('z'));
    assert(!isLowerCase('Z'));
}

void testToUpperCase()
{
    assert(toUpperCase('b') == 'B');
    assert(toUpperCase('B') == 'B');
}

void testToLowerCase()
{
    assert(toLowerCase('D') == 'd');
    assert(toLowerCase('d') == 'd');
}

void testToUpperCase_withString()
{
    assert(toUpperCase("Hola") == "HOLA");
    assert(toUpperCase("abc123") == "ABC123");
}

void testToLowerCase_withString()
{
    assert(toLowerCase("Hola") == "hola");
    assert(toLowerCase("ABC123") == "abc123");
}

void testCmpString()
{
    assert(cmpString("abc", "abc") == 0);
    assert(cmpString("abc", "abd") == -1);
    assert(cmpString("abd", "abc") == 1);
}

void testCmpDouble()
{
    assert(cmpDouble(1.5, 1.5) == 0);
    assert(cmpDouble(1.5, 2.0) == -1);
    assert(cmpDouble(2.0, 1.5) == 1);
}

void testStringToCString()
{
    char* c = stringToCString("hola");

    assert(c != NULL);
    assert(c[0] == 'h');
    assert(c[1] == 'o');
    assert(c[2] == 'l');
    assert(c[3] == 'a');
    assert(c[4] == '\0');

    delete[] c;
}

void testCStringToString()
{
    char c[] = "hola";
    assert(cStringToString(c) == "hola");
}

