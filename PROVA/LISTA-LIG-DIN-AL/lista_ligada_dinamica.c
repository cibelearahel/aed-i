#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada_dinamica.h"

ListaLigadaDinamica* CriarLista() {
    ListaLigadaDinamica* lista = (ListaLigadaDinamica*)malloc(sizeof(ListaLigadaDinamica));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

void InserirElemento(ListaLigadaDinamica* lista, Aluno aluno) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    *novoAluno = aluno;
    novoAluno->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoAluno;
    } else {
        Aluno* atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoAluno;
    }

    lista->tamanho++;
}

void InserirElementoOrdenado(ListaLigadaDinamica* lista, Aluno aluno) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    *novoAluno = aluno;
    novoAluno->proximo = NULL;

    if (lista->inicio == NULL || aluno.codigo < lista->inicio->codigo) {
        novoAluno->proximo = lista->inicio;
        lista->inicio = novoAluno;
    } else {
        Aluno* anterior = lista->inicio;
        Aluno* atual = lista->inicio->proximo;

        while (atual != NULL && aluno.codigo > atual->codigo) {
            anterior = atual;
            atual = atual->proximo;
        }

        anterior->proximo = novoAluno;
        novoAluno->proximo = atual;
    }

    lista->tamanho++;
}

int ObterQuantidadeElementos(ListaLigadaDinamica* lista) {
    return lista->tamanho;
}

Aluno* BuscarSequencial(ListaLigadaDinamica* lista, int codigo) {
    Aluno* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

Aluno* BuscaBinaria(ListaLigadaDinamica* lista, int codigo) {
    // A busca binária não é aplicável a uma lista ligada dinâmica, pois requer acesso aleatório aos elementos.
    // Nesse caso, a busca sequencial é mais adequada.
    return BuscarSequencial(lista, codigo);
}

void ExcluirElemento(ListaLigadaDinamica* lista, int codigo) {
    Aluno* anterior = NULL;
    Aluno* atual = lista->inicio;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
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
}

void ImprimirLista(ListaLigadaDinamica* lista) {
    Aluno* atual = lista->inicio;
    while (atual != NULL) {
        printf("Codigo: %d\n", atual->codigo);
        printf("Nome: %s\n", atual->nome);
        printf("Idade: %d\n", atual->idade);
        printf("Numero de filhos: %d\n", atual->numFilhos);
        printf("\n");
        atual = atual->proximo;
    }
}
