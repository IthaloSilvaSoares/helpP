#include <stdio.h>

struct No {
    int valor;
    No* prox;
};

struct Lista {
    No* cabeca;
    No* cauda;
    No* mediana;
    int n;

    Lista() {
        cabeca = NULL;
        cauda = NULL;
        mediana = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }

    void inserirFinal(int v) { // O(1)
        No* novo = new No();
        novo->valor = v;
        novo->prox = NULL;
        if (vazia()) {
            cabeca = novo;
            cauda = novo;
            mediana = novo;
        } else {
            cauda->prox = novo;
            cauda = novo;
            if (n % 2 == 0 && v > mediana->valor) {
                mediana = mediana->prox;
            } else if (n % 2 != 0 && v < mediana->valor) {
                mediana = mediana->prox;
            }
        }
        n++;
    }

    void imprimir() { // O(n)
        No* aux = cabeca;
        double valorMediana;
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        if(n % 2 == 0){
            valorMediana = (mediana->valor + mediana->prox->valor)/2.0;
        } else {
            valorMediana = mediana->valor * 1.0;
        }

        printf("%.2f\n", valorMediana);
    }

    int tamanho() { // O(1)
        return n;
    }
};

int main() {
    int n;
    scanf("%d", &n);

    Lista lista;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        lista.inserirFinal(x);
        lista.imprimir();
    }

    return 0;
}
