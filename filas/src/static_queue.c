#include "../include/static_queue.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _static_queue {
  int *data;
  int size;
  long capacity;
  long begin;
  long end;
} StaticQueue;

StaticQueue *StaticQueue_create(long capacity){
  StaticQueue *Q = (StaticQueue *) calloc(1, sizeof(StaticQueue));

  Q->data = (int *) calloc(capacity, sizeof(int));

  Q->capacity = capacity;
  Q->begin = 0;
  Q->end = 0;
  Q->size = 0;
}

bool StaticQueue_is_empty(const StaticQueue *Q){
  return Q->size == 0;
}

bool StaticQueue_is_full(const StaticQueue *Q){
  return Q->size == Q->capacity;
}



void StaticQueue_enqueue(int info, StaticQueue *Q){

  // verificar se está cheia
  Q->data[Q->end] = info;
  Q->end = (Q->end + 1) % Q->capacity; // fila circular
  Q->size++;


}

int StaticQueue_dequeue(StaticQueue *Q){

  // verificar se vazia
  if (StaticQueue_is_empty(Q)) {
        fprintf(stderr, "ERROR in 'StaticQueue Dequeue'\n");
        fprintf(stderr, "A pilha está vazia\n");
        exit(EXIT_FAILURE); // termina o programa com um código de erro
        // EXIT_FAILURE ==> stdlib.h
    }

  int val = Q->data[Q->begin];
  Q->begin = (Q->begin + 1) % Q->capacity;
  Q->size--;


}