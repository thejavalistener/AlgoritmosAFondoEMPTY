#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>

#include "files.hpp"

using std::cout;
using std::endl;
using std::remove;
using std::string;

void testBinaryReadWriteAndSeek()
{
   const char* path = "files_test_bin.dat";
   FILE* f = fopen(path, "w+b");
   assert(f != NULL);

   write<int>(f, 10);
   write<int>(f, 20);
   write<int>(f, 30);

   assert(fileSize<int>(f) == 3);
   assert(filePos<int>(f) == 3);

   seek<int>(f, 0);
   assert(filePos<int>(f) == 0);
   assert(read<int>(f) == 10);
   assert(filePos<int>(f) == 1);
   assert(read<int>(f) == 20);
   assert(filePos<int>(f) == 2);

   seek<int>(f, 2);
   assert(read<int>(f) == 30);

   fclose(f);
   remove(path);
}

void testReadLine()
{
   const char* path = "files_test_line.txt";
   FILE* f = fopen(path, "w+b");
   assert(f != NULL);

   writeString(f, "uno\n");
   writeString(f, "dos\r\n");
   writeString(f, "tres");
   fclose(f);

   f = fopen(path, "r+b");
   assert(f != NULL);

   string ln;
   assert(readLine(f, ln));
   assert(ln == "uno");
   assert(readLine(f, ln));
   assert(ln == "dos");
   assert(readLine(f, ln));
   assert(ln == "tres");
   assert(!readLine(f, ln));

   fclose(f);
   remove(path);
}

void testReadWord()
{
   const char* path = "files_test_word.txt";
   FILE* f = fopen(path, "w+b");
   assert(f != NULL);

   writeString(f, "hola, mundo 123 fin.");
   fclose(f);

   f = fopen(path, "r+b");
   assert(f != NULL);

   string w;
   assert(readWord(f, w));
   assert(w == "hola");
   assert(readWord(f, w));
   assert(w == "mundo");
   assert(readWord(f, w));
   assert(w == "123");
   assert(readWord(f, w));
   assert(w == "fin");
   assert(!readWord(f, w));

   fclose(f);
   remove(path);
}

void testReadWordWithAllowedChars()
{
   const char* path = "files_test_word_allowed.txt";
   FILE* f = fopen(path, "w+b");
   assert(f != NULL);

   writeString(f, "uno-dos tres_cuatro ");
   fclose(f);

   f = fopen(path, "r+b");
   assert(f != NULL);

   string w;
   assert(readWord(f, w, "-"));
   assert(w == "uno-dos");
   assert(readWord(f, w, "_"));
   assert(w == "tres_cuatro");

   fclose(f);
   remove(path);
}

void testWriteHelpers()
{
   const char* path = "files_test_write.txt";
   FILE* f = fopen(path, "w+b");
   assert(f != NULL);

   writeString(f, "abc");
   writeWord(f, "def");
   writeLine(f, "ghi");
   fclose(f);

   f = fopen(path, "r+b");
   assert(f != NULL);

   string ln;
   assert(readLine(f, ln));
   assert(ln == "abcdef ghi ");
   assert(!readLine(f, ln));

   fclose(f);
   remove(path);
}

int main()
{
   testBinaryReadWriteAndSeek();
   testReadLine();
   testReadWord();
   testReadWordWithAllowedChars();
   testWriteHelpers();

   cout << "Todos los tests de files pasaron correctamente." << endl;
   return 0;
}
