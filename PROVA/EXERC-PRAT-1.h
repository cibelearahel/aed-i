#ifndef LISTA_LIGADA_ESTATICA_H
#define LISTA_LIGADA_ESTATICA_H

#define TAM_MAX 100

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    int numeroFilhos;
} Aluno;

typedef struct {
    Aluno elementos[TAM_MAX];
    int tamanho;
} ListaLigadaEstatica;

ListaLigadaEstatica* CriarLista();
void InserirElemento(ListaLigadaEstatica* lista, Aluno aluno);
int VerificarDuplicidade(ListaLigadaEstatica* lista, int codigo);
void ImprimirElementos(ListaLigadaEstatica* lista);
void DestruirLista(ListaLigadaEstatica* lista);

#endif
