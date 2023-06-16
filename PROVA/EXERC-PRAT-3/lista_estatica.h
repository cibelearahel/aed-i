#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#define TAMANHO_MAX 10

typedef struct {
    int elementos[TAMANHO_MAX];
    int tamanho;
} ListaEstatica;

ListaEstatica CriarLista();
void InserirElemento(ListaEstatica* lista, int elemento);
int ObterMaiorElemento(ListaEstatica* lista);
int ExcluirMaiorElemento(ListaEstatica* lista);
void ImprimirMaiorElemento(ListaEstatica* lista);

#endif
