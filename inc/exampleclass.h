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
    int style_error();
    void use_uninitialized();
private:
    std::fstream m_goodFile;
    std::fstream m_badFile;
    FILE* file;
    int m_uninit;
};

#endif // EXAMPLECLASS_H
