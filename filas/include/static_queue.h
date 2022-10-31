#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdbool.h>

typedef struct _static_queue StaticQueue;

StaticQueue *StaticQueue_create(long capacity);
void StaticQueue_destroy(StaticQueue **Q_Ref);

bool StaticQueue_is_empty(const StaticQueue *Q);
bool StaticQueue_is_full(const StaticQueue *Q);
long StaticQueue_size(const StaticQueue *Q);
void StaticQueue_print(const StaticQueue *Q);

void StaticQueue_enqueue(int info, StaticQueue *Q);
int StaticQueue_dequeue(StaticQueue *Q);
int StaticQueue_peek(StaticQueue *Q);





#endif