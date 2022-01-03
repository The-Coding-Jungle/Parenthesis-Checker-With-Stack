#include "stack.h"

bool isBalanced(char *str) {
    stack* s;
    s = initStack();
    char cur;

    while (*str != '\0') {
        cur = *str;

        if (cur == '(' || cur == '{' || cur == '[') {
            push(s, cur);
        } else if (cur == ')' || cur == '}' || cur == ']') {
            if (isEmpty(s)) {
                return false;
            } else {
                char t = top(s);
                if (cur == ')' && t != '(') {
                    return false;
                } else if (cur == '}' && t != '{') {
                    return false;
                    return false;
                } pop(s);
            }
        }

        str++;
    }

    bool toReturn = isEmpty(s);
    freeStack(s);
    return toReturn;
}

