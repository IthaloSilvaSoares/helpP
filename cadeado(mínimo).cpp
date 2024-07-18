#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    No *anterior, *proximo;
    No(int _valor) {
        valor = _valor;
        anterior = proximo = NULL;
    }
};

struct ListaCircular {
    No *cabeca;
    int n;
    ListaCircular() {
        cabeca = NULL;
        n = 0;
    }

    bool vazia() {
        return cabeca == NULL;
    }

    int tamanho() {
        return n;
    }

    void inserirFinal(int valor) {
        No *novo = new No(valor);
        if (vazia()) {
            cabeca = novo;
            cabeca->proximo = cabeca->anterior = cabeca;
        } else {
            novo->proximo = cabeca;
            novo->anterior = cabeca->anterior;
            cabeca->anterior->proximo = novo;
            cabeca->anterior = novo;
        }
        n++;
    }

    No *buscar(int valor) {
        No *atual = cabeca;
        do {
            if (atual->valor == valor) {
                return atual;
            }
            atual = atual->proximo;
        } while (atual != cabeca);
        return NULL;
    }

    int numeroMovimentos(int atual, int proximo) {
        int distancia = abs(atual - proximo);
        return distancia < tamanho() - distancia ? distancia : tamanho() - distancia;
    }
};

int main() {

    ListaCircular lc;
    int s1, s2, s3;
    scanf("%d %d %d", &s1, &s2, &s3);

    lc.inserirFinal(0);
    lc.inserirFinal(1);
    lc.inserirFinal(2);
    lc.inserirFinal(3);
    lc.inserirFinal(4);
    lc.inserirFinal(5);
    lc.inserirFinal(6);
    lc.inserirFinal(7);
    lc.inserirFinal(8);
    lc.inserirFinal(9);

    int movimentos = 0;

    No *atual = lc.buscar(0);
    movimentos += lc.numeroMovimentos(atual->valor, s1);
    atual = lc.buscar(s1);
    movimentos += lc.numeroMovimentos(atual->valor, s2);
    atual = lc.buscar(s2);
    movimentos += lc.numeroMovimentos(atual->valor, s3);
    atual = lc.buscar(s3);
    movimentos += lc.numeroMovimentos(atual->valor, 0);

    printf("%d\n", movimentos);

    return 0;
}
