#include <stdio.h>

typedef struct node {
    void* value;
    struct node* next;
} node_t;

typedef struct linkedlist {
    node_t* head;
} linkedlist_t;

// Search for a string in the linked list. (Linear search)
// Inputs: list {linkedlist_t*} - pointer to a list to search
//         search_term {char*} - string to search for
// Return: {size_t} - index of the node which contains the string in the list, -1 if not found
size_t __linkedlist_search(linkedlist_t* list, char* search_term);

//Prints lines from the linked list.
//Inputs: list {linkedlist_t*} - pointer to the linked list to print.
//        number_of_lines {int} - number of lines to print.
//Return: nothing.
void __print_lines_from_linkedlist(linkedlist_t* list, size_t number_of_lines);

//Print an inclusive range of lines from the linked list.
//Inputs: list {linkedlist_t*} - pointer to the linked list to print.
//        start_index {int} - start index to print from.
//        end_index {int} - end index to print to.
//Return: nothing.
void __print_range_from_linkedlist(linkedlist_t* list, size_t start_index, size_t end_index);

// Initialise a linkedlist, input may not be a null pointer
// Inputs: list {linkedlist_t*} - pointer to the linked list to initialise (just declare a linkedlist_t* variable and pass it to this function)
// Return: {linkedlist_t*} - pointer to the linked list 
linkedlist_t* __linkedlist_init(linkedlist_t* list);

// Iteratates through every node returning the amount of them
// Inputs: list {linkedlist_t*} - pointer to the linked list to count
// Return: {size_t} - the number of nodes in the linked list
size_t __linkedlist_size(linkedlist_t* list);

// Free()s all nodes and the list itself
// Inputs: list {linkedlist_t*} - pointer to the linked list to free
// Return: nothing
void __linkedlist_cleanup(linkedlist_t* list);

// Get node by index
// Inputs: list {linkedlist_t*} - pointer to the linked list to get the node from
//         index {size_t} - index of the node to get
// Return: {node_t*} - pointer to the node at the given index
node_t* __linkedlist_get_node_index(linkedlist_t* list, size_t index);

// Creates a new node and sets new node as the new head
// Inputs: list {linkedlist_t*} - pointer to the linked list to push to
//         value {void*} - value to set the node to
// Return: {linkedlist_t*} - pointer to the linked list
linkedlist_t* __linkedlist_push_front(linkedlist_t* list, void* value);

// Creates a new node, iterates through the nodes until it finds the last and links new node with the last node
// Inputs: list {linkedlist_t*} - pointer to the linked list
//         value {void*} - value to set the node to
// Return: {linkedlist_t*} - pointer to the linked list
linkedlist_t* __linkedlist_push_back(linkedlist_t* list, void* value);

//TODO: Write documentation for these functions
linkedlist_t* __linkedlist_push_infront_of(linkedlist_t* list, node_t* node, void* value);

linkedlist_t* __linkedlist_push_back_of(linkedlist_t* list, node_t* node, void* value);

linkedlist_t* __linkedlist_push_infront_of_index(linkedlist_t* list, size_t index, void* value);

linkedlist_t* __linkedlist_push_back_of_index(linkedlist_t* list, size_t index, void* value);

linkedlist_t* __linkedlist_pop(linkedlist_t* list);

linkedlist_t* __linkedlist_remove(linkedlist_t* list, node_t* node);

linkedlist_t* __linkedlist_remove_index(linkedlist_t* list, size_t index);
