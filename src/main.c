#include "modules/checker.h"

int main() {
    char *str = "{{{[()]}}}";
    printf("%d\n", isBalanced(str));
    char *str2 = "{{{[(]}})";
    printf("%d\n", isBalanced(str2));
    return 0;
}