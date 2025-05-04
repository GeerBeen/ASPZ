#include <stdio.h>

int main() {
    FILE *from_rwho;
    FILE *to_more;
    char buffer[256];

    from_rwho = popen("who", "r");
    if (from_rwho == NULL) {
        perror("popen rwho");
        return 1;
    }

    to_more = popen("more", "w");
    if (to_more == NULL) {
        perror("popen more");
        pclose(from_rwho);
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), from_rwho) != NULL) {
        fputs(buffer, to_more);
    }

    pclose(from_rwho);
    pclose(to_more);

    return 0;
}
