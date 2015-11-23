#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H

#include <fstream>
#include <cstdio>

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
    std::fstream m_goodFile;
    std::fstream m_badFile;
    FILE* file;
};

#endif // EXAMPLECLASS_H
