#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "linkedlist.h"

#define VERSION "1.0.0"

// This function creates the input prompt and gets a string of commands from the user. 
// Outputs: a buffer containing the input from the user
char* prompt_for_input() {
    static char buf[BUFSIZ];
    printf("*");
    fflush(stdout);
    return fgets(buf, BUFSIZ, stdin);
}

void print_buffer(linkedlist_t* list) {
    size_t len = __linkedlist_size(list);
    node_t* current = list->head;
    for (size_t i = 0; i < len; i++) {
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

linkedlist_t* read_into_buffer(FILE* file, linkedlist_t* list) {
    char* buf = malloc(BUFSIZ);
    while(fgets(buf, BUFSIZ, file) != NULL) {
        __linkedlist_push_back(list, buf);
        buf = malloc(BUFSIZ);
    }
    return list;
}

//This searches for a string in an array of strings and returns the index of it
//Th7e array has to be sorted
//Outputs: the index of the string if found, -1 if not found
/*int search_for_string_in_array(char** array, char* search_term, int high, int low) {
    for (int i = 0; i < length; i++) {
        if (strcmp(array[i], search_term) == 0) {
            return i;
        }
    }

    return -1;
}*/

int main(int argc, char** argv) {
#ifdef DEBUG
    printf("argc: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[i]: %lld\n", argv[i]);
    }
#endif
    // parse arguments
    int c;
    while ((c = getopt(argc, argv, "vh")) != -1) {
        switch (c) {
            case 'v':
                printf("edlin v%s\n", VERSION);
                return 0;
                break;
            case 'h':
                printf("Usage: edlin [FILE]\n");
                return 0;
                break;
            default:
                return 1;
                break;
        }
    }

    // TODO linked list
    linkedlist_t textbuffer;
    __linkedlist_init(&textbuffer);
    
    // check if a file has been given and read it into the textbuffer
    if (argc > optind) {
        // TODO read file
        char *file_path = argv[optind];
        FILE *file_fp = fopen(file_path, "r");
        
        if (file_fp == NULL) {
            perror("Error opening file");
            return 1;
        }

	    read_into_buffer(file_fp, &textbuffer);
    }

    //print_buffer(&textbuffer);
    int quit = 0;
    while (!quit) {
        char* prompt = prompt_for_input();
        if (prompt == NULL)
            return -1;
        
        switch (prompt[0]) {
            case '?':
                puts("help here");
                break;
            case 'c':
            case 'C':
                puts("put copy operation here");
                break;
            case 'd':
            case 'D':
                puts("put delete operation here");
                break;
            case 'e':
            case 'E':
                puts("put exit and save operation here");
                break;
            case 'i':
            case 'I':
                puts("put add line operation here");
                break;
            case 'l':
            case 'L':
                puts("put list operation here");
                break;
            case 'm':
            case 'M':
                puts("put move line operation here");
                break;
            case 'p':
            case 'P':
                puts("put list page per page operation here");
                break;
            case 'r':
            case 'R':
                puts("put replace operation here");
                break;
            case 's':
            case 'S':
                puts("put search operation here");
                break;
            case 't':
            case 'T':
                puts("put combine file(?) operation here");
                break;
            default:
                puts("error");
                break;
        }
    }

    __linkedlist_cleanup(&textbuffer);
    return 0;
}
