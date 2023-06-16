#include <stdio.h>
#include <stdlib.h>
#include "lista_linear_sequencial.h"

ListaLinearSequencial* CriarLista(int capacidade) {
    ListaLinearSequencial* lista = (ListaLinearSequencial*)malloc(sizeof(ListaLinearSequencial));
    lista->elementos = (int*)malloc(capacidade * sizeof(int));
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    return lista;
}

void InserirElementoOrdenado(ListaLinearSequencial* lista, int elemento) {
    if (lista->tamanho >= lista->capacidade) {
        printf("Erro: Lista cheia.\n");
        return;
    }

    int posicao = 0;
    while (posicao < lista->tamanho && lista->elementos[posicao] < elemento) {
        posicao++;
    }

    for (int i = lista->tamanho - 1; i >= posicao; i--) {
        lista->elementos[i + 1] = lista->elementos[i];
    }

    lista->elementos[posicao] = elemento;
    lista->tamanho++;
}

int ContarElemento(ListaLinearSequencial* lista, int elemento) {
    int contador = 0;
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == elemento) {
            contador++;
        }
    }
    return contador;
}

void ImprimirElementos(ListaLinearSequencial* lista) {
    printf("Elementos da lista: ");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

void DestruirLista(ListaLinearSequencial* lista) {
    free(lista->elementos);
    free(lista);
}
