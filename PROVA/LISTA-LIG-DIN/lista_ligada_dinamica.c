#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada_dinamica.h"

ListaLigadaDinamica* CriarLista() {
    ListaLigadaDinamica* lista = (ListaLigadaDinamica*)malloc(sizeof(ListaLigadaDinamica));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

void InserirElemento(ListaLigadaDinamica* lista, int elemento) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->elemento = elemento;
    novoNo->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoNo;
    } else {
        No* atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }

    lista->tamanho++;
}

void InserirElementoOrdenado(ListaLigadaDinamica* lista, int elemento) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->elemento = elemento;

    if (lista->inicio == NULL || elemento < lista->inicio->elemento) {
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;
    } else {
        No* atual = lista->inicio;
        while (atual->proximo != NULL && elemento > atual->proximo->elemento) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }

    lista->tamanho++;
}

int ObterQuantidadeElementos(ListaLigadaDinamica* lista) {
    return lista->tamanho;
}

int BuscarSequencial(ListaLigadaDinamica* lista, int elemento) {
    No* atual = lista->inicio;
    int posicao = 0;

    while (atual != NULL) {
        if (atual->elemento == elemento) {
            return posicao;
        }
        atual = atual->proximo;
        posicao++;
    }

    return -1;
}

No* BuscaBinariaRecursiva(No* inicio, int elemento) {
    if (inicio == NULL || inicio->elemento == elemento) {
        return inicio;
    }

    if (elemento < inicio->elemento) {
        return BuscaBinariaRecursiva(inicio->proximo, elemento);
    }

    return BuscaBinariaRecursiva(inicio->proximo, elemento);
}

int BuscaBinaria(ListaLigadaDinamica* lista, int elemento) {
    No* resultado = BuscaBinariaRecursiva(lista->inicio, elemento);

    if (resultado == NULL) {
        return -1;
    }

    int posicao = 0;
    No* atual = lista->inicio;
    while (atual != resultado) {
        atual = atual->proximo;
        posicao++;
    }

    return posicao;
}

void ExcluirElementoPosicao(ListaLigadaDinamica* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Erro: Posicao invalida.\n");
        return;
    }

    if (posicao == 0) {
        No* auxiliar = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(auxiliar);
    } else {
        No* anterior = NULL;
        No* atual = lista->inicio;
        int contador = 0;

        while (contador < posicao) {
            anterior = atual;
            atual = atual->proximo;
            contador++;
        }

        anterior->proximo = atual->proximo;
        free(atual);
    }

    lista->tamanho--;
}

void ExcluirElementoValor(ListaLigadaDinamica* lista, int valor) {
    No* anterior = NULL;
    No* atual = lista->inicio;

    while (atual != NULL) {
        if (atual->elemento == valor) {
            if (anterior == NULL) {
                lista->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            lista->tamanho--;
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Erro: Elemento nao encontrado.\n");
}

void ImprimirElementos(ListaLigadaDinamica* lista) {
    printf("Elementos da lista: ");
    No* atual = lista->inicio;

    while (atual != NULL) {
        printf("%d ", atual->elemento);
        atual = atual->proximo;
    }

    printf("\n");
}

void DestruirLista(ListaLigadaDinamica* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(lista);
}
