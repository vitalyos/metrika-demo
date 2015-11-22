#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H

#include <stdio.h>

class ExampleClass
{
public:
    ExampleClass();
    ~ExampleClass();
    void memory_leak();
    void wrong_buffer();
    void wrong_printf();
    int style_error();
private:
    FILE* m_goodFile;
    FILE* m_badFile;
};

#endif // EXAMPLECLASS_H
