#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fptr = fopen("dados.csv", "r");
    if (fptr == NULL) {
        return -1;
    }

    int u, v;

    while (fscanf(fptr, "%d,%d", &u, &v) == 2) {
        printf("%d -> %d\n", u, v);
    }

    fclose(fptr);
}