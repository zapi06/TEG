#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "leituraDeDados.h"

int main(){

    int MAXN;
    List *adj = ler_adjacencias("dados.csv", &MAXN);

    /*
    printf("\n");
    for (int i = 0; i < MAXN; i++) {
        if(get_size(&adj[i])){
            printf("%d: ", i+1);
            mostra(&adj[i]);
        }
    }
    */

    int maior = 0, menor = 10000;

    graus(adj, &maior, &menor, MAXN);

    printf("\n=======================\n\n");

    printf("Maior grau: %d -- Menor grau: %d\n", maior, menor);

    printf("\n=======================\n\n");

    int lacos = 0, multiplas = 0;

    multigrafo(adj, &lacos, &multiplas, MAXN);

    if(lacos > 0 || multiplas > 0){
        printf("Eh multigrafo!\n");
        printf("Possui %d lacos e %d arestas multiplas\n", lacos, multiplas);
    }else printf("Nao eh multigrafo!\n");

    printf("\n=======================\n\n");

    int cor = 0;

    int *tamanhos = conexos(adj, MAXN, &cor);

    printf("O grafo tem %d componentes conexos\n", cor);

    FILE *fptr = fopen("saida_histograma.csv", "w");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo de sáida.\n");
    }

    for(int i = 1; i <= cor; i++){
        printf("O tamanho do componente %d eh: %d\n", i, tamanhos[i]);
        fprintf(fptr, "%d,%d\n", i, tamanhos[i]);
    }

    printf("\n=======================\n\n");
}

