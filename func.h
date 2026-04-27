#ifndef TEG_FUNC_H
#define TEG_FUNC_H
    typedef struct Node{
        int val;
        struct Node* next;
    } Node;

    typedef struct{
        Node *head;
        Node *tail;
        int size;
    } List;

    void init(List *l);
    void push_back(List *l, int v);
    int get_size(List *l);
    void mostra(List *l);
    void free_list(List *l);

    void graus(List *adj, int *menor, int *maior, int MAXN);
    int* conexos(List *adj, int MAXN, int *cor);
    void dfs(List *adj, int vis[], int u, int c);

#endif //TEG_FUNC_H
