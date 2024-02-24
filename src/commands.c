#include "linkedlist.h"
#include <string.h>

void list_command(linkedlist_t* list, size_t number_of_lines) {
    node_t* current = list->head;
    for (size_t i = 0; i < number_of_lines; i++) {
        if (current == NULL)
            break;
        char* str = current->value;
        printf("%ld: %s", i, str);
        if (str[strlen(str) - 1] != '\n') {
            printf("\n");
        }
        current = current->next;
    }
}
