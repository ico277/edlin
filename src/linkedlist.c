#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

linkedlist_t* __linkedlist_init(linkedlist_t* list) {
    list = malloc(sizeof(linkedlist_t));
    list->head = malloc(sizeof(node_t));
    list->head->value = NULL;
    list->head->value = NULL;
    return list;
}

size_t __linkedlist_size(linkedlist_t* list) {
    node_t* current = list->head;
    size_t i = 0;
    while ((current = current->next) != NULL) {
        ++i;
    }
    return i;
}

void __linkedlist_cleanup(linkedlist_t* list) {
    node_t* current = list->head;
    while ((current = current->next) != NULL) {
        free(current->value);
        free(current);
    }
    free(list);
}

node_t* __linkedlist_get_node_index(linkedlist_t* list, size_t index) {
    node_t* current = list->head;
    size_t i = 0;
    while ((current = current->next) != NULL) {
        // found
        if (i == index)
            return current;
        ++i;
    }
    // not found
    return NULL;
}

linkedlist_t* __linkedlist_push_front(linkedlist_t* list, void* value) {
    // create new node
    node_t* node = malloc(sizeof(node_t));
    node->value = value;
    // set new node's next as the current head
    // and change the new head of the list to new node
    node->next = list->head;
    list->head = node;
    return list;
}


linkedlist_t* __linkedlist_push_back(linkedlist_t* list, void* value) {
    // create new node
    node_t* node = malloc(sizeof(node_t));
    node->value = value;
    // get last node
    node_t* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    // link last node to new node
    current->next = node;
    return list;
}

linkedlist_t* __linkedlist_push_infront_of(linkedlist_t* list, node_t* node, void* value) {
    node_t* current;
    while ((current = list->head) != NULL) {
        if (current->next == node) {
            node_t* newnode = malloc(sizeof(node_t));
            newnode->value = value;

            newnode->next = current->next;
            current->next = newnode;
            return list;
        }
    }
    // not found
    return NULL;
}

