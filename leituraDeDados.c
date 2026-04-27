#include <stdio.h>
#include <stdlib.h>
#include "leituraDeDados.h"
#include "func.h"

List *ler_adjacencias(const char *nome_arquivo, int *MAXN) {
    FILE *fptr = fopen(nome_arquivo, "r");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }else {
        printf("Abriu o arquivo.\n");
    }

    List *adj = NULL;
    int capacidade = 0;

    int u, v;

    while (fscanf(fptr, "%d,%d", &u, &v) == 2) {

        u--;
        v--;

        int max = 0;
        if (u > v) max = u;
        else max = v;

        if (max >= capacidade) {
            int nova_capacidade = max+1;
            adj = realloc(adj, nova_capacidade * sizeof(List));

            for (int i = capacidade; i < nova_capacidade; i++) {
                init(&adj[i]);
            }

            capacidade = nova_capacidade;
        }
        push_back(&adj[u], v);
        push_back(&adj[v], u);
    }
    *MAXN = capacidade;
    fclose(fptr);
    return adj;
}
