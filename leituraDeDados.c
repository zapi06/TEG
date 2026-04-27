#include <stdio.h>
#include <stdlib.h>
#include "leituraDeDados.h"

void ler_adjacencias(const char *nome_arquivo) {
    FILE *fptr = fopen(nome_arquivo, "r");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int u, v;

    while (fscanf(fptr, "%d,%d", &u, &v) == 2) {
        printf("%d -> %d\n", u, v);
    }

    fclose(fptr);
}