#include <stdio.h>

typedef struct node {
    void* value;
    struct node* next;
} node_t;

typedef struct linkedlist {
    node_t* head;
} linkedlist_t;

// initialise a linkedlist, input may not be a null pointer
linkedlist_t* __linkedlist_init(linkedlist_t* list);
// iteratates through every node returning the amount of them
size_t __linkedlist_size(linkedlist_t* list);
// free()s all nodes and the list itself
void __linkedlist_cleanup(linkedlist_t* list);
// get node by index
node_t* __linkedlist_get_node_index(linkedlist_t* list, size_t index);
// creates a new node and sets new node as the new head
linkedlist_t* __linkedlist_push_front(linkedlist_t* list, void* value);
// creates a new node, iterates through the nodes until it finds the last and links new node with the last node
linkedlist_t* __linkedlist_push_back(linkedlist_t* list, void* value);
linkedlist_t* __linkedlist_push_infront_of(linkedlist_t* list, node_t* node, void* value);
linkedlist_t* __linkedlist_push_infront_of_index(linkedlist_t* list, size_t index, void* value);
linkedlist_t* __linkedlist_push_back_of_index(linkedlist_t* list, size_t index, void* value);
linkedlist_t* __linkedlist_push_back_of(linkedlist_t* list, node_t* node, void* value);
linkedlist_t* __linkedlist_pop(linkedlist_t* list, node_t* node);
linkedlist_t* __linkedlist_pop_index(linkedlist_t* list, size_t index);
