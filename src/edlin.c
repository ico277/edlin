#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define VERSION "1.0.0"

// This function creates the input prompt and gets a string of commands from the user. 
// Outputs: a buffer containing the input from the user
char* prompt_for_input() {
    static char buf[1024];
    printf("*");
    fgets(buf, sizeof(buf), stdin);
    return buf;
}

//This searches for a string in an array of strings and returns the index of it
//The array has to be sorted
//Outputs: the index of the string if found, -1 if not found
int search_for_string_in_array(char** array, char* searchTerm, int high, int low) {
    while (low <= high) {
        int mid = floor((high + low) / 2);
        //strcmp will return less than 0 is array[mid] comes first alphabetically
        //than searchTerm
        if (strcmp(array[mid], searchTerm) < 0) {
            low = mid + 1;
        }
        else if (strcmp(array[mid], searchTerm) > 0) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
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
    //char** textbuffer = NULL;
    //size_t textbuffer_count = 0;
    
    // check if a file has been given and read it into the textbuffer
    if (argc > optind) {
        // TODO read file
        char *file_path = argv[optind];
        FILE *file_fp = fopen(file_path, "r");
        
        if (file_fp == NULL) {
            perror("Error opening file");
            return 1;
        }
        

    }

    return 0;
}
