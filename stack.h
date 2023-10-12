#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#define INITIAL_CAPACITY 10

typedef struct
{
	int *data;
	int size;
	int capacity;
} Stack;

void init(Stack *s);
void destroy(Stack *s);
void push(Stack *s, int element);
bool isEmpty(const Stack *s);
int pop(Stack *s);

#endif