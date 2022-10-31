#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _snode SNode;
typedef struct _slinked_list LinkedList;

SNode *SNode_create(int val);

LinkedList *LinkedList_create();

void add_first(LinkedList *L, int val);

void add_last(LinkedList *L, int val);

void print_LL(LinkedList *L);

bool LinkedList_is_empty(const LinkedList *L);

void LinkedList_remove(LinkedList *L, int val) ;

void LinkedList_destroy(LinkedList **L_ref);


#endif // !LINKED_LIST_H