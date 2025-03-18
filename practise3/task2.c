#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = fopen("output2.txt", "w");
    if (!fp) {
        perror("Cannot open file");
        return 1;
    }

    char data[512];
    memset(data, 'A', sizeof(data));

    while (1) {
        if (fwrite(data, sizeof(data), 1, fp) != 1) {
            perror("Write error");
            break;
        }
    }

    fclose(fp);
    return 0;
}
