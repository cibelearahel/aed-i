#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_ligada_estatica.h"

ListaLigadaEstatica* CriarLista() {
    ListaLigadaEstatica* lista = (ListaLigadaEstatica*)malloc(sizeof(ListaLigadaEstatica));
    lista->tamanho = 0;
    return lista;
}

void InserirElemento(ListaLigadaEstatica* lista, Aluno aluno) {
    if (lista->tamanho >= TAM_MAX) {
        printf("Erro: Lista cheia.\n");
        return;
    }
    lista->elementos[lista->tamanho] = aluno;
    lista->tamanho++;
}

int VerificarDuplicidade(ListaLigadaEstatica* lista, int codigo) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i].codigo == codigo) {
            return 1; // Duplicidade encontrada
        }
    }
    return 0; // Nenhuma duplicidade encontrada
}

void ImprimirElementos(ListaLigadaEstatica* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Aluno %d: Codigo: %d, Nome: %s, Idade: %d, Numero de filhos: %d\n",
               i + 1, lista->elementos[i].codigo, lista->elementos[i].nome,
               lista->elementos[i].idade, lista->elementos[i].numeroFilhos);
    }
}

void DestruirLista(ListaLigadaEstatica* lista) {
    free(lista);
}
