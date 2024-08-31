#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct {
    int itens[MAX];
    int frente, tras;
} Fila;

void inicializarFila(Fila *fila) {
    fila->frente = -1;
    fila->tras = -1;
}

int isVazia(Fila *fila) {
    return fila->frente == -1;
}

int isCheia(Fila *fila) {
    return fila->tras == MAX - 1;
}

void enfileirar(Fila *fila, int elemento) {
    if (isCheia(fila)) {
        printf("Fila cheia. Não é possível enfileirar.\n");
        return;
    }
    if (fila->frente == -1) {
        fila->frente = 0;
    }
    fila->tras++;
    fila->itens[fila->tras] = elemento;
    printf("%d enfileirado na fila.\n", elemento);
}

int desenfileirar(Fila *fila) {
    if (isVazia(fila)) {
        printf("Fila vazia. Não é possível desenfileirar.\n");
        return -1;
    }
    int elemento = fila->itens[fila->frente];
    fila->frente++;
    if (fila->frente > fila->tras) {
        fila->frente = fila->tras = -1; 
    }
    return elemento;
}

void exibirFila(Fila *fila) {
    if (isVazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Elementos na fila: ");
    for (int i = fila->frente; i <= fila->tras; i++) {
        printf("%d ", fila->itens[i]);
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);

    exibirFila(&fila);

    printf("Elemento desenfileirado: %d\n", desenfileirar(&fila));
    printf("Elemento desenfileirado: %d\n", desenfileirar(&fila));

    exibirFila(&fila);

    return 0;
}
