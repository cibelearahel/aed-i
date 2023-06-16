#include <stdio.h>
#include "lista_estatica.h"

ListaEstatica CriarLista() {
    ListaEstatica lista;
    lista.tamanho = 0;
    return lista;
}

void InserirElemento(ListaEstatica* lista, int elemento) {
    if (lista->tamanho < TAMANHO_MAX) {
        lista->elementos[lista->tamanho] = elemento;
        lista->tamanho++;
    } else {
        printf("Erro: Lista cheia. Nao e possivel inserir elemento.\n");
    }
}

int ObterMaiorElemento(ListaEstatica* lista) {
    int maior = lista->elementos[0];
    for (int i = 1; i < lista->tamanho; i++) {
        if (lista->elementos[i] > maior) {
            maior = lista->elementos[i];
        }
    }
    return maior;
}

int ExcluirMaiorElemento(ListaEstatica* lista) {
    int posicaoMaior = 0;
    int maior = lista->elementos[0];

    for (int i = 1; i < lista->tamanho; i++) {
        if (lista->elementos[i] > maior) {
            posicaoMaior = i;
            maior = lista->elementos[i];
        }
    }

    for (int i = posicaoMaior; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }

    lista->tamanho--;

    return maior;
}

void ImprimirMaiorElemento(ListaEstatica* lista) {
    int maior = ObterMaiorElemento(lista);
    printf("O maior elemento da lista e: %d\n", maior);
}
