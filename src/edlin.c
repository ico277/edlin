#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define VERSION "1.0.0"

//This function creates the input prompt and gets a string of commands from the user. 
//Inputs: none
//Outputs: {char*} the command received from the user
char* promptForInput() {
	char* command = (char*) malloc(10 * sizeof(char));	
	printf("*");
	scanf("%10s", command);
	printf("%s", command);
	return command;
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
    // check if a file has been given
    if (!(argc > optind)) {
        fprintf(stderr, "Usage: edlin [FILE]\n");
        return 1;
    }
    // TODO read file
    char *file = argv[optind];
    puts(file);
}
