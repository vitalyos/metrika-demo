#include "exampleclass.h"
#include <cstring>

ExampleClass::ExampleClass()
{
    m_goodFile.open("bad.txt", std::fstream::in | std::fstream::out);
    m_badFile.open("good.txt", std::fstream::in | std::fstream::out);
    file = fopen("example.txt", "w");
}

ExampleClass::~ExampleClass()
{
    m_goodFile.close();
}

void ExampleClass::memory_leak()
{
    char *str = new char[1024];
    memcpy(str, "123", sizeof("123"));
}

void ExampleClass::wrong_buffer()
{
    char buff[5];
    memcpy(buff, "Hello World", sizeof("Hello World"));
    printf("%s\n", buff);
}

void ExampleClass::wrong_printf()
{

}

int ExampleClass::style_error()
{
    int a = 24;
    int b = 25;
    int c;
    c = a << 2;
    return c;
    b = 24;
    return b;
}

