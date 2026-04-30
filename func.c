#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct{
    Node *head;
    Node *tail;
    int size;
} List;

void init(List *l){
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

void push_back(List *l, int v){
    Node *node = malloc(sizeof(Node));
    node->val = v;
    node->next = NULL;

    if(l->head == NULL){
        l->head = node;
        l->tail = node;
    }else{
        l->tail->next = node;
        l->tail = node;
    }

    l->size++;
}

int get_size(List *l){
    return l->size;
}

void mostra(List *l){
    Node *it = l->head;
    while(it != NULL){
        printf("%d ", it->val);
        it = it->next;
    }
    printf("\n");
}

void free_list(List *l){
    Node *cur = l->head;
    while(cur){
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    l->size = 0;
}

void dfs(List *adj, int vis[], int u, int c){
    vis[u] = c;
    Node *cur = adj[u].head;
    while(cur != NULL){
        if(!vis[cur->val]){
            dfs(adj, vis, cur->val, c);
        }
        cur = cur->next;
    }
}

int* conexos(List *adj, int MAXN, int *cor){
    int c = 0;
    int vis[MAXN];
    for(int i = 0; i < MAXN; i++) vis[i] = 0;
    for(int i = 0; i < MAXN; i++){
        if(!vis[i]){
            c++;
            dfs(adj, vis, i, c);
        }
    }

    int *tamanhos = malloc((c+1) * sizeof(int));
    for(int i = 0; i < MAXN; i++) tamanhos[i] = 0;

    for(int i = 0; i < MAXN; i++){
        tamanhos[vis[i]]++;
    }

    *cor = c;
    return tamanhos;
}

void graus(List *adj, int *maior, int *menor, int MAXN){
    for(int i = 0; i < MAXN; i++){
        int sz = get_size(&adj[i]);

        *menor = (*menor < sz ? *menor : sz);
        *maior = (*maior > sz ? *maior : sz);
    }
}

int comp(const void *a, const void *b){
    int *v1 = (int *)a;
    int *v2 = (int *)b;
    return v1-v2;
}

void multigrafo(List *adj, int *lacos, int *multiplas, int MAXN){
    for(int i = 0; i < MAXN; i++){
        int sz = get_size(&adj[i]);

        if(!sz) continue;

        int *v = malloc(sz * sizeof(int));

        int j = 0;
        for(Node *cur = adj[i].head; cur != NULL; cur = cur->next){
            v[j] = cur->val;
            j++;
        }

        qsort(v, sz, sizeof(int), comp);

        int atual = v[0];
        if(atual == i) *lacos = *lacos + 1;

        for(j = 1; j < sz; j++){
            if(v[j] == i) *lacos = *lacos + 1;
            if(v[j] == v[j-1]) *multiplas = *multiplas + 1;
        }
    }
}
