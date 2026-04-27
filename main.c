#include <stdio.h>
#include <stdlib.h>
#include "func.c"

int main(){

    List v;

    init(&v);

    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x; scanf("%d", &x);
        push_back(&v, x);
    }

    mostra(&v);
}

