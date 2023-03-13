#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 30000

int main(int argc, char *argv[]) {
    char memory[MEMORY_SIZE] = {0};
    char *ptr = memory;
    char input;

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: unable to open file %s\n", argv[1]);
        return 1;
    }

    char code[MEMORY_SIZE];
    int code_size = fread(code, 1, MEMORY_SIZE, file);
    fclose(file);

    for (int i = 0; i < code_size; i++) {
        if (code[i] == '>') {
            ptr++;
        } else if (code[i] == '<') {
            ptr--;
        } else if (code[i] == '+') {
            (*ptr)++;
        } else if (code[i] == '-') {
            (*ptr)--;
        } else if (code[i] == '.') {
            putchar(*ptr);
        } else if (code[i] == ',') {
            input = getchar();
            if (input != EOF) {
                *ptr = input;
            }
        } else if (code[i] == '[') {
            if (*ptr == 0) {
                int level = 1;
                while (level > 0) {
                    i++;
                    if (code[i] == '[') {
                        level++;
                    } else if (code[i] == ']') {
                        level--;
                    }
                }
            }
        } else if (code[i] == ']') {
            if (*ptr != 0) {
                int level = 1;
                while (level > 0) {
                    i--;
                    if (code[i] == ']') {
                        level++;
                    } else if (code[i] == '[') {
                        level--;
                    }
                }
            }
        }
    }

    return 0;
}
