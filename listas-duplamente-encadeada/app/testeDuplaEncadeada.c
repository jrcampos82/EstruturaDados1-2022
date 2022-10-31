#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/List.h"

int main(){

  List *l = List_create();
  List_add_first(l, 1);
  List_add_first(l, 2);
  List_add_first(l, 3);
  List_add_first(l, 4);
  printf("Lista duplamente encadeada\n");
  List_print(l);
}