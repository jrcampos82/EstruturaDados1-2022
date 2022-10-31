#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/linked_list.h"

int main()
{
  LinkedList *ls;
  LinkedList *l = LinkedList_create();
  add_first(l, 3);
  add_first(l, 4);
  add_first(l, 5);
  add_first(l, 6);
  add_first(l, 7);
  print_LL(l);
}