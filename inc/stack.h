#pragma once

// This structure represents our stack
typedef struct _STACK {
    int Index;          // This is the index of our stack
    char Values[50];    // This field holds our stacks's values
} STACK, *PSTACK;

void StackInit(PSTACK Stack);               // This function initializes the stack structure
void StackPush(PSTACK Stack, char Value);   // This function pushes a value on our stack
char StackPop(PSTACK Stack);                // This function pops an element from our stack
