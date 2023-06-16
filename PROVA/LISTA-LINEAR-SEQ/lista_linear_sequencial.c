#include <stdio.h>
#include <stdlib.h>
#include "lista_linear_sequencial.h"

ListaLinearSequencial* CriarLista(int tamanhoMaximo) {
    ListaLinearSequencial* lista = (ListaLinearSequencial*)malloc(sizeof(ListaLinearSequencial));
    lista->elementos = (int*)malloc(tamanhoMaximo * sizeof(int));
    lista->tamanho = 0;
    lista->capacidade = tamanhoMaximo;
    return lista;
}

void DestruirLista(ListaLinearSequencial* lista) {
    free(lista->elementos);
    free(lista);
}

void InserirElemento(ListaLinearSequencial* lista, int elemento) {
    if (lista->tamanho >= lista->capacidade) {
        printf("Erro: Lista cheia.\n");
        return;
    }
    lista->elementos[lista->tamanho] = elemento;
    lista->tamanho++;
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
    for (int i = lista->tamanho; i > posicao; i--) {
        lista->elementos[i] = lista->elementos[i - 1];
    }
    lista->elementos[posicao] = elemento;
    lista->tamanho++;
}

int ObterQuantidadeElementos(ListaLinearSequencial* lista) {
    return lista->tamanho;
}

int BuscarSequencial(ListaLinearSequencial* lista, int elemento) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == elemento) {
            return i;
        }
    }
    return -1;
}

int BuscaBinaria(ListaLinearSequencial* lista, int elemento) {
    int esquerda = 0;
    int direita = lista->tamanho - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (lista->elementos[meio] == elemento) {
            return meio;
        }
        else if (lista->elementos[meio] < elemento) {
            esquerda = meio + 1;
        }
        else {
            direita = meio - 1;
        }
    }
    return -1;
}

void ExcluirElementoPosicao(ListaLinearSequencial* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Erro: Posicao invalida.\n");
        return;
    }
    for (int i = posicao; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
}

void ExcluirElementoValor(ListaLinearSequencial* lista, int elemento) {
    int posicao = BuscarSequencial(lista, elemento);
    if (posicao != -1) {
        ExcluirElementoPosicao(lista, posicao);
    }
}

void ImprimirElementos(ListaLinearSequencial* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}
