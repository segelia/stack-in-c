#include <stdio.h>
#include "stack.h"

// gcc -Wall -pedantic stackcode.c teststack.c -o stack -O2
// -O2 -> silna optymalizacja kodu.

int main(void)
{
    Stack stack;
    init(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    //push(&stack, 4);
    //push(&stack, 5);
    //push(&stack, 6);
    //push(&stack, 7);
    //push(&stack, 8);
    //push(&stack, 9);
    //push(&stack, 10);
    //push(&stack, 11);
    //push(&stack, 12);

    while (!isEmpty(&stack))
    {
        printf("%d ", pop(&stack));
    }
    printf("\n");
    
    //pop(&stack);

    destroy(&stack);

    return 0;
}
