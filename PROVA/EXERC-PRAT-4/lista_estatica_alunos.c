#include <stdio.h>
#include "lista_estatica_alunos.h"

void imprimirDadosAluno(Aluno aluno) {
    printf("Codigo: %d\n", aluno.codigo);
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("Numero de filhos: %d\n", aluno.numFilhos);
}

int encontrarMaiorIdade(Aluno lista[], int tamanho) {
    int maiorIdade = lista[0].idade;

    for (int i = 1; i < tamanho; i++) {
        if (lista[i].idade > maiorIdade) {
            maiorIdade = lista[i].idade;
        }
    }

    return maiorIdade;
}

void imprimirAlunoMaiorIdade(Aluno lista[], int tamanho) {
    int maiorIdade = encontrarMaiorIdade(lista, tamanho);

    for (int i = 0; i < tamanho; i++) {
        if (lista[i].idade == maiorIdade) {
            printf("Dados do aluno com maior idade:\n");
            imprimirDadosAluno(lista[i]);
            printf("\n");
        }
    }
}
