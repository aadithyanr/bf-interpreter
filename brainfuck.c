#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEM_LEN 30000  // std brainfuck uses 30,000 cells

void cleanup(FILE* file, char* source) {
    free(source);
    if (file) fclose(file);
}

int interpret(FILE* file) {
    int mem = 0;
    int code = 0;
    char memory[MEM_LEN] = {0}; 
    
    fseek(file, 0, SEEK_END);
    long source_len = ftell(file);
    char* source = (char*)malloc(source_len + 1);  // +1 for null terminator
    if (!source) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return 1;
    }
    
    rewind(file);
    size_t bytes_read = fread(source, 1, source_len, file);
    source[bytes_read] = '\0';
    
    while (code < source_len) {
        char c = source[code];
        switch (c) {
            case '>': 
                mem = (mem + 1) % MEM_LEN;
                break;
            case '<': 
                mem = (mem - 1 + MEM_LEN) % MEM_LEN;
                break;
            case '+': 
                memory[mem]++;
                break;
            case '-': 
                memory[mem]--;
                break;
            case '.': 
                putchar(memory[mem]);
                fflush(stdout);
                break;
            case ',': 
                memory[mem] = getchar();
                break;
            case '[':
                if (!memory[mem]) {
                    int brackets = 1;
                    while (brackets && ++code < source_len) {
                        if (source[code] == '[') brackets++;
                        if (source[code] == ']') brackets--;
                    }
                    if (brackets) {
                        fprintf(stderr, "Unmatched '['\n");
                        cleanup(file, source);
                        return 1;
                    }
                }
                break;
            case ']':
                if (memory[mem]) {
                    int brackets = 1;
                    while (brackets && --code >= 0) {
                        if (source[code] == ']') brackets++;
                        if (source[code] == '[') brackets--;
                    }
                    if (brackets) {
                        fprintf(stderr, "Unmatched ']'\n");
                        cleanup(file, source);
                        return 1;
                    }
                }
                break;
            case ' ':
            case '\n':
            case '\r':
            case '\t':
                break;
            default:
                fprintf(stderr, "Invalid character in source: '%c'\n", c);
                cleanup(file, source);
                return 1;
        }
        code++;
    }
    
    cleanup(file, source);
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    FILE* source = fopen(argv[1], "r");
    if (!source) {
        fprintf(stderr, "Could not open source file: %s\n", argv[1]);
        return 1;
    }
    
    return interpret(source);
}