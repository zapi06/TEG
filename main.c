#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "leituraDeDados.h"

int main(){

    int MAXN;
    List *adj = ler_adjacencias("dados.csv", &MAXN);

    for (int i = 0; i < MAXN; i++) {
        printf("%d: ", i);
        mostra(&adj[i]);
    }

    int maior = 0, menor = 10000;

    graus(adj, &maior, &menor, MAXN);

    printf("maior grau: %d -- menor grau: %d\n", maior, menor);

    int cor = 0;

    int *tamanhos = conexos(adj, MAXN, &cor);

    printf("O grafo tem %d componentes conexos\n", cor);
    for(int i = 1; i <= cor; i++){
        printf("O tamanho do componente %d eh: %d", i, tamanhos[i]);
    }
    printf("\n");

    /*
    List adj[MAXN];

    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) init(&adj[i]);
    for(int i = 0; i < n; i++){
        int x, y; scanf("%d%d", &x, &y);
        x--, y--;
        push_back(&adj[x], y);
        push_back(&adj[y], x);
    }

    printf("****\n");

    for(int i = 0; i < n; i++){
        printf("%d: ", i);
        mostra(&adj[i]); 
    }
    */
}

