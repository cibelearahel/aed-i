#ifndef LISTA_LIGADA_DINAMICA_H
#define LISTA_LIGADA_DINAMICA_H

typedef struct Aluno {
    int codigo;
    char nome[50];
    int idade;
    int numFilhos;
    struct Aluno* proximo;
} Aluno;

typedef struct {
    Aluno* inicio;
    int tamanho;
} ListaLigadaDinamica;

ListaLigadaDinamica* CriarLista();
void InserirElemento(ListaLigadaDinamica* lista, Aluno aluno);
void InserirElementoOrdenado(ListaLigadaDinamica* lista, Aluno aluno);
int ObterQuantidadeElementos(ListaLigadaDinamica* lista);
Aluno* BuscarSequencial(ListaLigadaDinamica* lista, int codigo);
Aluno* BuscaBinaria(ListaLigadaDinamica* lista, int codigo);
void ExcluirElemento(ListaLigadaDinamica* lista, int codigo);
void ImprimirLista(ListaLigadaDinamica* lista);

#endif
