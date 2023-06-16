#ifndef LISTA_ESTATICA_ALUNOS_H
#define LISTA_ESTATICA_ALUNOS_H

#define TAMANHO_MAX 5

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    int numFilhos;
} Aluno;

void imprimirDadosAluno(Aluno aluno);
int encontrarMaiorIdade(Aluno lista[], int tamanho);
void imprimirAlunoMaiorIdade(Aluno lista[], int tamanho);

#endif
