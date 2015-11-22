#include <iostream>
#include <cstring>

void make_safe_sqlite(char ** str)
{
    size_t length = strlen(*str);
    size_t i = 0;
    int amp = 0;
    char apc = '\'';
    for (; i < length; ++i)
    {
        if (apc == (*str)[i])
        {
            ++amp;
        }
    }
    if (amp <= 0)
        return;
    char * tmp = (char*)malloc((amp + length + 1) * sizeof(char));
    if(NULL == tmp)
    {
        printf("malloc error\n");
        return;
    }
    char *src = *str;
    char *dst = tmp;

    while (*src)
    {
        if (apc == *src)
        {
            *dst = apc;
            ++dst;
        }
        *dst = *src;
        ++dst;
        ++src;
    }
    *dst = '\0';
    free(*str);
    *str = tmp;
}

int main ()
{
    char* str = new char[100];
    strcpy(str, "droppin' the table");
    make_safe_sqlite(&str);
    std::cout << str << std::endl;
}
