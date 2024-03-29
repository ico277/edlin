#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

linkedlist_t* __linkedlist_init(linkedlist_t* list) {
    list->head = NULL;
    return list;
}

size_t __linkedlist_size(linkedlist_t* list) {
    node_t* current = list->head;
    size_t i = 0;
    while (current != NULL) {
        ++i;
        current = current->next;
    }
    return i;
}

void __linkedlist_cleanup(linkedlist_t* list) {
    node_t* current = list->head;
    node_t* next;

    while (current != NULL) {
        next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
}

node_t* __linkedlist_get_node_index(linkedlist_t* list, size_t index) {
    if (index == 0) return list->head;

    node_t* current = list->head;
    size_t i = 0;

    while (current != NULL) {
        if (i == index) {
            return current;
        }
        current = current->next;
        ++i;
    }

    // not found
    return NULL;
}

linkedlist_t* __linkedlist_push_front(linkedlist_t* list, void* value) {
    // create new node
    node_t* node = malloc(sizeof(node_t));
    node->value = value;
    if (list->head == NULL) {
        list->head = node;
        list->head->next = NULL;
    } else {
        // set new node's next as the current head
        // and change the new head of the list to new node
        node->next = list->head;
        list->head = node;
    }
    return list;
}


linkedlist_t* __linkedlist_push_back(linkedlist_t* list, void* value) {
    if (list->head == NULL) return __linkedlist_push_front(list, value);
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

linkedlist_t* __linkedlist_push_back_of(linkedlist_t* list, node_t* node, void* value) {
    node_t* current;
    while ((current = list->head) != NULL) {
        if (current == node) {
            node_t* newnode = malloc(sizeof(node_t));
            newnode->value = value;

            current->next = newnode;
            newnode->next = current->next;
            return list;
        }
    }
    // not found
    return NULL;
}

linkedlist_t* __linkedlist_push_infront_of_index(linkedlist_t* list, size_t index, void* value) {
    if (index == 0) return __linkedlist_push_front(list, value);
    node_t* current = __linkedlist_get_node_index(list, index);
    if (current == NULL) return NULL;
    
    return __linkedlist_push_infront_of(list, current, value);
}

linkedlist_t* __linkedlist_push_back_of_index(linkedlist_t* list, size_t index, void* value) {
    node_t* current = __linkedlist_get_node_index(list, index);
    if (current == NULL) return NULL;
    
    return __linkedlist_push_back_of(list, current, value);
}

linkedlist_t* __linkedlist_pop(linkedlist_t* list) {
    if (list->head == NULL) return list;
    
    node_t* head = list->head;
    free(head->value);
    list->head = head->next;
    free(head);
    
    return list;
}

linkedlist_t* __linkedlist_remove(linkedlist_t* list, node_t* node) {
    if (list->head == node) 
        return __linkedlist_pop(list);

    node_t* current = list->head;
    node_t* prev = NULL;

    while (current != node) {
        prev = current;
        current = current->next;
    }

    prev->next = node->next;
    free(node->value);
    free(node);

    return list;
}

linkedlist_t* __linkedlist_remove_index(linkedlist_t* list, size_t index) {
    node_t* node_to_remove = __linkedlist_get_node_index(list, index);

    // Node not found
    if (node_to_remove == NULL) 
        return NULL;

    return __linkedlist_remove(list, node_to_remove);
}

