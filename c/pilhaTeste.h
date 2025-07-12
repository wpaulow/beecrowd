#include <stdio.h> 
#include <stdlib.h> 

typedef int ItemP;

typedef struct pilha {
    int max;
    int topo;
    ItemP *item;
} *Pilha;

Pilha pilha(int max) {
    Pilha p = (Pilha)malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro: memoria insuficiente\n");
        exit(1);
    }
    p->max = max;
    p->topo = -1;
    p->item = (ItemP*)malloc(max * sizeof(ItemP));
    if (p->item == NULL) {
        printf("Erro: memoria insuficiente\n");
        exit(1);
    }
    return p;
}

void empilha(ItemP valor, Pilha p) {
    if (cheiaP(p)) {
        printf("Erro: pilha cheia\n");
        exit(1);
    }
    p->topo++;
    p->item[p->topo] = valor;
}

int desempilha(Pilha p) {
    if (vaziaP(p)) {
        printf("Erro: pilha vazia\n");
        exit(1);
    }
    int valor = p->item[p->topo];
    p->topo--;
    return valor;
}

int topoP(Pilha p) {
    if (vaziaP(p)) {
        printf("Erro: pilha vazia\n");
        exit(1);
    }
    return p->item[p->topo];
}

int vaziaP(Pilha p) {
    return p->topo == -1;
}

int cheiaP(Pilha p) {
    return p->topo == p->max - 1;
}

void destroiP(Pilha p) {
    free(p->item);
    free(p);
    p = NULL;
}

int existe(int x, Pilha p) {
    if(topoP(p) == x) return 1;
    if(vaziaP(p)) return 0;
    p->topo--;    
    return existe(x, p);
}
