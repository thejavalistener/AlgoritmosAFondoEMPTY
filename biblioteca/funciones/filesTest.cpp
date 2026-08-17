#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>

#include "files.hpp"

using std::cout;
using std::endl;
using std::remove;
using std::string;

// -- PROTOTIPOS --
void testWrite();
void testRead();
void testFileSize();
void testSeek();
void testFilePos();
void testReadLine_withByteNo();
void testReadLine_withFields();
void testReadLine();
void testReadWord_withAlsoAllowed();
void testReadWord();
void testWriteString();
void testWriteWord();
void testWriteLine();

// -- MAIN --
int main()
{
    testWrite();
    // testRead();
    // testFileSize();
    // testSeek();
    // testFilePos();
    // testReadLine_withByteNo();
    // testReadLine();
    // testReadWord_withAlsoAllowed();
    // testReadWord();
    // testWriteString();
    // testWriteWord();
    // testWriteLine();

    // -- Luego de la leccion 13 -- 
    // testReadLine_withFields();

    cout << "Todos los tests de files pasaron correctamente." << endl;
    return 0;
}

FILE* openFile(const char* path, const char* mode)
{
    FILE* f = fopen(path, mode);
    assert(f != NULL);
    return f;
}

void closeAndDeleteFile(FILE* f, const char* path)
{
    fclose(f);
    remove(path);
}

void testWrite()
{
    const char* path = "files_test_write_bin.dat";
    FILE* f = openFile(path, "w+b");

    write<int>(f, 42);

    assert(ftell(f) == static_cast<long>(sizeof(int)));
    fseek(f, 0, SEEK_SET);

    int value = 0;
    fread(&value, sizeof(int), 1, f);
    assert(value == 42);

    closeAndDeleteFile(f, path);
}

void testRead()
{
    const char* path = "files_test_read_bin.dat";
    FILE* f = openFile(path, "w+b");

    int expected = 73;
    fwrite(&expected, sizeof(int), 1, f);
    fseek(f, 0, SEEK_SET);

    int actual = read<int>(f);
    assert(actual == 73);
    assert(ftell(f) == static_cast<long>(sizeof(int)));

    closeAndDeleteFile(f, path);
}

void testFileSize()
{
    const char* path = "files_test_file_size.dat";
    FILE* f = openFile(path, "w+b");

    int values[] = {10, 20, 30, 40};
    fwrite(values, sizeof(int), 4, f);
    fseek(f, sizeof(int), SEEK_SET);

    assert(fileSize<int>(f) == 4);
    assert(ftell(f) == static_cast<long>(sizeof(int)));

    closeAndDeleteFile(f, path);
}

void testSeek()
{
    const char* path = "files_test_seek.dat";
    FILE* f = openFile(path, "w+b");

    int values[] = {5, 15, 25};
    fwrite(values, sizeof(int), 3, f);

    seek<int>(f, 2);

    assert(ftell(f) == static_cast<long>(2 * sizeof(int)));
    int value = 0;
    fread(&value, sizeof(int), 1, f);
    assert(value == 25);

    closeAndDeleteFile(f, path);
}

void testFilePos()
{
    const char* path = "files_test_file_pos.dat";
    FILE* f = openFile(path, "w+b");

    int values[] = {1, 2, 3, 4};
    fwrite(values, sizeof(int), 4, f);
    fseek(f, 3 * sizeof(int), SEEK_SET);

    assert(filePos<int>(f) == 3);

    closeAndDeleteFile(f, path);
}

void testReadLine_withByteNo()
{
    const char* path = "files_test_read_line_byteno.txt";
    FILE* f = openFile(path, "w+b");

    const char* text = "uno\n\rdos\r\ntres";
    fwrite(text, 1, 14, f);
    fseek(f, 0, SEEK_SET);

    string line;
    long long byteno = -1;

    assert(readLine(f, line, byteno));
    assert(line == "uno");
    assert(byteno == 0);

    assert(readLine(f, line, byteno));
    assert(line == "dos");
    assert(byteno == 4);

    assert(readLine(f, line, byteno));
    assert(line == "tres");
    assert(byteno == 10);

    assert(!readLine(f, line, byteno));
    assert(byteno == 14);

    closeAndDeleteFile(f, path);
}

void testReadLine_withFields()
{
    const char* path = "files_test_read_line_fields.txt";
    FILE* f = openFile(path, "w+b");

    const char* text = "10,juan,perez\n20,ana,lopez\n";
    fwrite(text, 1, 27, f);
    fseek(f, 0, SEEK_SET);

    string line = "sin_cambios";
    string* fields = NULL;
    int len = -1;

    assert(readLine(f, line, ',', fields, len));
    assert(len == 3);
    assert(fields != NULL);
    assert(fields[0] == "10");
    assert(fields[1] == "juan");
    assert(fields[2] == "perez");
    delete[] fields;

    fields = NULL;
    len = -1;
    assert(readLine(f, line, ',', fields, len));
    assert(len == 3);
    assert(fields != NULL);
    assert(fields[0] == "20");
    assert(fields[1] == "ana");
    assert(fields[2] == "lopez");
    delete[] fields;

    fields = NULL;
    len = -1;
    assert(!readLine(f, line, ',', fields, len));
    assert(fields == NULL);
    assert(len == -1);

    closeAndDeleteFile(f, path);
}

void testReadLine()
{
    const char* path = "files_test_read_line.txt";
    FILE* f = openFile(path, "w+b");

    const char* text = "uno\n\rdos\r\ntres";
    fwrite(text, 1, 14, f);
    fseek(f, 0, SEEK_SET);

    string line;
    assert(readLine(f, line));
    assert(line == "uno");
    assert(readLine(f, line));
    assert(line == "dos");
    assert(readLine(f, line));
    assert(line == "tres");
    assert(!readLine(f, line));

    closeAndDeleteFile(f, path);
}

void testReadWord_withAlsoAllowed()
{
    const char* path = "files_test_read_word_allowed.txt";
    FILE* f = openFile(path, "w+b");

    const char* text = "uno-dos _tres cuatro ";
    fwrite(text, 1, 21, f);
    fseek(f, 0, SEEK_SET);

    string word;
    assert(readWord(f, word, "-"));
    assert(word == "uno-dos");
    assert(readWord(f, word, "_"));
    assert(word == "_tres");
    assert(readWord(f, word, ""));
    assert(word == "cuatro");
    assert(!readWord(f, word, ""));

    closeAndDeleteFile(f, path);
}

void testReadWord()
{
    const char* path = "files_test_read_word.txt";
    FILE* f = openFile(path, "w+b");

    const char* text = " hola,123 fin.";
    fwrite(text, 1, 14, f);
    fseek(f, 0, SEEK_SET);

    string word;
    assert(readWord(f, word));
    assert(word == "hola");
    assert(readWord(f, word));
    assert(word == "123");
    assert(readWord(f, word));
    assert(word == "fin");
    assert(!readWord(f, word));

    closeAndDeleteFile(f, path);
}

void testWriteString()
{
    const char* path = "files_test_write_string.txt";
    FILE* f = openFile(path, "w+b");

    writeString(f, "abc");

    assert(ftell(f) == 3);
    fseek(f, 0, SEEK_SET);

    char buffer[4] = {};
    fread(buffer, 1, 3, f);
    assert(string(buffer) == "abc");

    closeAndDeleteFile(f, path);
}

void testWriteWord()
{
    const char* path = "files_test_write_word.txt";
    FILE* f = openFile(path, "w+b");

    writeWord(f, "hola");

    assert(ftell(f) == 5);
    fseek(f, 0, SEEK_SET);

    char buffer[6] = {};
    fread(buffer, 1, 5, f);
    assert(string(buffer) == "hola ");

    closeAndDeleteFile(f, path);
}

void testWriteLine()
{
    const char* path = "files_test_write_line.txt";
    FILE* f = openFile(path, "w+b");

    writeLine(f, "chau");

    assert(ftell(f) == 6);
    fseek(f, 0, SEEK_SET);

    char buffer[7] = {};
    fread(buffer, 1, 6, f);
    assert(string(buffer) == "chau \n");

    closeAndDeleteFile(f, path);
}
