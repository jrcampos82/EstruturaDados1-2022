typedef struct _double_node DoubleNode, Node;
typedef struct _double_linked_list DoubleLinkedList, List;

#include <stdbool.h>

Node *Node_create(int val);
List *List_create();
void List_Destroy(DoubleLinkedList **list); // *

bool List_is_empty(const DoubleLinkedList *list); // *
void List_add_first(DoubleLinkedList *list, int val);
void List_add_last(DoubleLinkedList *list, int val); // *
void List_print(const DoubleLinkedList *list);
void List_inverted_print(const DoubleLinkedList *list); // *
void List_remove(DoubleLinkedList *list); // *

