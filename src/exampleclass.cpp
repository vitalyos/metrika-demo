#include "exampleclass.h"
#include <cstring>

ExampleClass::ExampleClass()
{
    m_goodFile = fopen("good.txt", "w");
    m_badFile = fopen("bad.txt", "w");
}

ExampleClass::~ExampleClass()
{
    if(m_goodFile)
    {
        fclose(m_goodFile);
    }
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

