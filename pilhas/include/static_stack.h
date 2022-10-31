#ifndef STATIC_STACK
#define STATIC_STACK

#include <stdbool.h>

typedef struct _static_stack StaticStack;

StaticStack *StaticStack_create(long capacity);

void StaticStack_destroy(StaticStack **s_stack);

bool StaticStack_isEmpty(const StaticStack *S);
bool StaticStack_isFull(const StaticStack *S);

long StaticStack_size(const StaticStack *S); // *

void StaticStack_push(StaticStack *S, long value);
int StaticStack_peek(StaticStack *S); // *
int StaticStack_pop(StaticStack *S);
void StaticStack_print(const StaticStack *S); // *


#endif // !STATIC_STACK