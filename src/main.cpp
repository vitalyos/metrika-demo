#include <iostream>
#include <cstring>
#include <stdlib.h>         // malloc, free
#include <stdio.h>          // printf, scanf
#include <string.h>         // strlen
#include <ctype.h>          // isalpha
#include "stack.h"          // This is our stack implementation


#include "exampleclass.h"

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
    if(1 > 2)
    {
        std::cout << "...";
    }
    char* str = new char[100];
    strcpy(str, "droppin' the table");
    make_safe_sqlite(&str);
    std::cout << str << std::endl;
    ExampleClass ex;
    ex.style_error();

    STACK stack;            // stack used to reorder the characters in the words
    char buffer[200];       // input buffer
    char* output;           // output string
    long length;            // length of the string
    char i;                 // input index variable
    char o;                 // output index variable
    char c;                 // character from the stack

    //
    // Initializations
    //
    StackInit(&stack);

    //
    // Reading a string from the standard input
    //

    printf("Input: ");
    scanf("%[^\n]s", buffer);       // reading a string until the first newline character
    printf("Read:  %s\n", buffer);  // printing out the original buffer

    length = strlen(buffer);        // calculating the length of string
    printf("Length of string: %ld\n", length);

    if (length == 0)                // if the string is empty we have nothing to do
    {
        printf("No input string!");
        goto cleanup;
    }

    output = (char*)malloc(length+1);      // allocating a character in plus, because the length does not include the ending \0
    memset(output, '\0', length+1); // filling the buffer with null characters

    //
    // Reversing the words and storing them in the output buffer
    //

    o = 0;                          // setting the current output buffer's index to 0
    for(i=0; i<=length; i++)        // traversing the string and processing every character
    {
        if (!isalnum(buffer[i]))    // if it's not alphanumeric we pop everything from the stack and store these characters in the output
        {
            while ('\0' != (c = StackPop(&stack)))  // popping the top character from the string (if there is any)
            {
                output[o++] = c;    // storing the actual character on the end of the output string
            }
            output[o++] = buffer[i];// storing the non alphanumeric character too
        }
        else
        {
            StackPush(&stack, buffer[i]);    // it's the part of the word, so we need to put on the stack
        }
    }

    printf("Output: %s\n", output); // printing the output string

cleanup:
    //
    // Cleaning up the memory on exit
    //

    if (NULL != output)             // if memory was allocated for the output buffer we need to free it
    {
        free(output);
    }

    return 0;
}
