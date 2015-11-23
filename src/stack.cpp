#include "stack.h"

void StackInit(PSTACK Stack)
{
    Stack->Index = 0;
    Stack->Values[0] = 0;
}

void StackPush(PSTACK Stack, char Value)
{
    Stack->Values[Stack->Index] = Value;
    Stack->Index += 1;
}

char StackPop(PSTACK Stack)
{
    if (Stack->Index != 0)
    {
        return Stack->Values[--Stack->Index];
    }

    return '\0';
}
