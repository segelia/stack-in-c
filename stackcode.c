#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10

typedef struct
{
    int *data;
    int size;
    int capacity;
} Stack;

void init(Stack *s)
{
    s->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    if (s->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        abort();
    }
    s->size = 0;
    s->capacity = INITIAL_CAPACITY;
}

void destroy(Stack *s)
{
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
}

void push(Stack *s, int element)
{
    s->size += 1;
    
    if (s->size > s->capacity)
    {
        s->capacity = 1.2 * s->capacity + 1;
        printf("Stack capacity: %d\n",s->capacity);
        int *new_data = (int *)malloc(s->capacity * sizeof(int));
        if (new_data == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            free(s->data); // Tu mogloby być destroy(s) gdyby nie było abort, bo nie dodałam
						   // zerowania zmeinnych w strukturze, które ma destroy. Nie jest to jednak tu potrzebne.
            abort();
        }

        for (int i = 0; i < s->size - 1; i++)
        {
            new_data[i] = s->data[i];
        }

        free(s->data);
        s->data = new_data;
    }

    s->data[s->size - 1] = element;
}


bool isEmpty(Stack *s)
{
    return s->size == 0;
}

int pop(Stack *s)
{
    // jesli stack jest pusty - abort
    if (isEmpty(s))
    {
        fprintf(stderr, "Error: Stack is empty\n");
        destroy(s);
        //abort();
        exit(EXIT_FAILURE);
    }
    s->size--;
    return s->data[s->size];
}

