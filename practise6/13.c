#include <stdio.h>
#include <string.h>

int main() {
    char *s = strdup("Hello, Leak!"); // Виділення пам’яті без звільнення
    printf("%s\n", s);
    return 0;
}