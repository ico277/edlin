#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "linkedlist.h"

#define VERSION "1.0.0"

// This function creates the input prompt and gets a string of commands from the user. 
// Outputs: a buffer containing the input from the user
// Returns the return value that fgets() returns
char* prompt_for_input() {
    static char buf[BUFSIZ];
    printf("*");
    fflush(stdout);
    return fgets(buf, BUFSIZ, stdin);
}

// Reads file into linked list
// Inputs: file {FILE*} - a file to read
//	   list {linkedlist_t*} - a list to read into
// Return: list {linkedlist_t* - the list with the lines added
linkedlist_t* read_into_buffer(FILE* file, linkedlist_t* list) {
    char* buf = malloc(BUFSIZ);
    while(fgets(buf, BUFSIZ, file) != NULL) {
        __linkedlist_push_back(list, buf);
        buf = malloc(BUFSIZ);
    }
    return list;
}

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
	    case "q":
	    case "Q":
		quit = 1;
            default:
                puts("error");
                break;
        }
    }

    __linkedlist_cleanup(&textbuffer);
    return 0;
}
