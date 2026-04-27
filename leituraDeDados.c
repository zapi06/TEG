#include <stdio.h>
#include <stdlib.h>
#include "leituraDeDados.h"
#include "func.h"

List **ler_adjacencias(const char *nome_arquivo) {
    FILE *fptr = fopen(nome_arquivo, "r");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    List **adj = NULL;
    int capacidade = 0;

    int u, v;

    while (fscanf(fptr, "%d,%d", &u, &v) == 2) {

        int max = 0;
        if (u > v) max = u;
        else max = v;


        if (max > capacidade) {
            int nova_capacidade = max+1;
            adj = realloc(adj, nova_capacidade * sizeof(List*));

            for (int i = capacidade; i < nova_capacidade; i++) {
                init(&adj[i]);
            }

            capacidade = nova_capacidade;
        }
    }

    fclose(fptr);
    return adj;
}