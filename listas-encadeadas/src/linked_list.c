#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"

typedef struct _snode
{
  int val;
  struct _snode *next;
} SNode;

typedef struct _slinked_list
{
  SNode *begin;
  SNode *end;
  size_t size; // qtos elementos existem n LL
} LinkedList;

/// @brief Aloca um nó com valor
/// @param val -> valor do nó
/// @return ponteiro SNode
SNode *SNode_create(int val)
{
  SNode *snode = (SNode *)calloc(1, sizeof(SNode));
  snode->val = val;
  snode->next = NULL;
  return snode;
}

LinkedList *LinkedList_create()
{
  LinkedList *linked_list = (LinkedList *)calloc(1, sizeof(LinkedList));
  linked_list->begin = NULL;
  return linked_list;
}

void add_first(LinkedList *L, int val)
{
  SNode *p = SNode_create(val);
  p->next = L->begin;
  L->begin = p;
  L->size++;
}

void add_last(LinkedList *L, int val)
{
  SNode *p = SNode_create(val);
  // se a LL estiver vazia
  if (L->begin == NULL)
  {
    L->begin = p;
  }
  else
  {
    // enquanto o p n for o ultimo elemento, prox
    SNode *aux = L->begin;
    while (aux->next != NULL)
    {
      aux = aux->next;
    }
    // neste momento o aux aponta p o último elemento da LL
    // corrige o encadeamento
    aux->next = p;
  }
  L->size++;
}

void print_LL(LinkedList *L)
{
  SNode *p = L->begin;
  printf("L -> ");

  while (p != NULL)
  {
    printf("%d -> ", p->val);
    p = p->next;
  }

  printf("NULL\n");
}

bool LinkedList_is_empty(const LinkedList *L) {
    return L->size == 0;
}

void LinkedList_remove(LinkedList *L, int val) {
    if (!LinkedList_is_empty(L)) {
        SNode *prev = NULL;
        SNode *pos = L->begin;

        while (pos != NULL && pos->val != val) {
            prev = pos;
            pos = pos->next;
        }

        // se achou um nó com valor val
        if (pos != NULL) {
            if (L->end == pos) {
                L->end = prev;
            }
            if (L->begin == pos) {
                L->begin = L->begin->next;
            }
            else {
                prev->next = pos->next;
            }

            free(pos);
            L->size--;
        }
    }
}

void LinkedList_destroy(LinkedList **L_ref){
  LinkedList *L = *L_ref;
  SNode *p = L->begin;
  SNode *aux = NULL;

  while(p != NULL){
    aux = p;
    p = p->next;
    free(aux);
  }

  free(L);

}