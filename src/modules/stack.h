#include <stdlib.h>
#include <stdio.h>

#define LOG_DEBUG_STACK 0

// This file will be used for logging.
const char* logFileName = "data/log.txt";

typedef enum { 
    false, 
    true 
} bool;

typedef struct {
    char* arr;
    int size, tos;
} stack;

stack* initStack() {
    stack* s = (stack*) malloc(sizeof(stack));
    s->arr = (char*)malloc(sizeof(char));
    s->size = 1;
    s->tos = -1;
    return s;
}

void displaystack(stack* s, FILE* f) {
    fprintf(f, "Stack is: ");
    for (int i = 0; i <= s->tos; i++) {
        fprintf(f, "%c ", s->arr[i]);
    }
    fprintf(f, "\n");
}

void push(stack* s, char x) {
    // If the stack is full, double the size of the stack.
    if (s->tos == s->size - 1) {
        s->size *= 2;
        s->arr = (char*)realloc(s->arr, s->size * sizeof(char));
    }

    #if LOG_DEBUG_STACK
        FILE* logFile = fopen(logFileName, "a");
        fprintf(logFile, "Pushing %c onto stack.\n", x);
        fclose(logFile);
    #endif

    s->arr[++s->tos] = x;
    #if LOG_DEBUG_STACK
        displaystack(s);
    #endif
}

char pop(stack* s) {
    if (s->tos == -1) {
        FILE* f = fopen(logFileName, "a");
        fprintf(f, "Stack is empty so cannot pop. Returning a garbage value.\n");
        fclose(f);
        return -1;
    }

    #if LOG_DEBUG_STACK
        FILE* logFile = fopen(logFileName, "a");
        fprintf(logFile, "Popping %c from stack.\n", s->arr[s->tos]);
        fclose(logFile);
    #endif

    char toReturn = s->arr[s->tos];
    s->tos--;
    return toReturn;
}

char top(stack* s) {
    if (s->tos == -1) {
        FILE* f = fopen(logFileName, "a");
        fprintf(f, "Stack is empty so cannot top. Returning a garbage value.\n");
        fclose(f);
        return -1;
    }

    #if LOG_DEBUG_STACK
        FILE* logFile = fopen(logFileName, "a");
        fprintf(logFile, "Top of stack is %c.\n", s->arr[s->tos]);
        fclose(logFile);
    #endif

    return s->arr[s->tos];
}

bool isEmpty(stack* s) {
    return s->tos == -1;
}

void freeStack(stack* s) {
    free(s->arr);
    free(s);
}