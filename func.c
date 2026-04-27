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

void dfs(List *adj[], int vis[], int u, int c){
    vis[u] = c;
    if(adj[u] == NULL) return;
    List *vizinhos = adj[u];
    Node *cur = vizinhos->head;
    while(cur != NULL){
        if(!vis[cur->val]){
            dfs(adj, vis, cur->val, c);
        }

        cur = cur->next;
    }
}
