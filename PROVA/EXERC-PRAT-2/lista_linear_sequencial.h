#ifndef LISTA_LINEAR_SEQUENCIAL_H
#define LISTA_LINEAR_SEQUENCIAL_H

typedef struct {
    int* elementos;
    int tamanho;
    int capacidade;
} ListaLinearSequencial;

ListaLinearSequencial* CriarLista(int capacidade);
void InserirElementoOrdenado(ListaLinearSequencial* lista, int elemento);
int ContarElemento(ListaLinearSequencial* lista, int elemento);
void ImprimirElementos(ListaLinearSequencial* lista);
void DestruirLista(ListaLinearSequencial* lista);

#endif
