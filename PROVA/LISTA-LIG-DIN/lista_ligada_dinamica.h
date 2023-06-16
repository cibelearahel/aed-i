#ifndef LISTA_LIGADA_DINAMICA_H
#define LISTA_LIGADA_DINAMICA_H

typedef struct No {
    int elemento;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} ListaLigadaDinamica;

ListaLigadaDinamica* CriarLista();
void InserirElemento(ListaLigadaDinamica* lista, int elemento);
void InserirElementoOrdenado(ListaLigadaDinamica* lista, int elemento);
int ObterQuantidadeElementos(ListaLigadaDinamica* lista);
int BuscarSequencial(ListaLigadaDinamica* lista, int elemento);
No* BuscaBinariaRecursiva(No* inicio, int elemento);
int BuscaBinaria(ListaLigadaDinamica* lista, int elemento);
void ExcluirElementoPosicao(ListaLigadaDinamica* lista, int posicao);
void ExcluirElementoValor(ListaLigadaDinamica* lista, int valor);
void ImprimirElementos(ListaLigadaDinamica* lista);
void DestruirLista(ListaLigadaDinamica* lista);

#endif
