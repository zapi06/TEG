#include <stdio.h>
#include <stdlib.h>
#include "func.c"

const int MAXN = 100;

int main(){

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
}

