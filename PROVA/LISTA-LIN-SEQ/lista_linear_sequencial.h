#ifndef LISTA_LINEAR_SEQUENCIAL_H
#define LISTA_LINEAR_SEQUENCIAL_H

typedef struct {
    int* elementos;
    int tamanho;
    int capacidade;
} ListaLinearSequencial;

ListaLinearSequencial* CriarLista(int tamanhoMaximo);
void DestruirLista(ListaLinearSequencial* lista);
void InserirElemento(ListaLinearSequencial* lista, int elemento);
void InserirElementoOrdenado(ListaLinearSequencial* lista, int elemento);
int ObterQuantidadeElementos(ListaLinearSequencial* lista);
int BuscarSequencial(ListaLinearSequencial* lista, int elemento);
int BuscaBinaria(ListaLinearSequencial* lista, int elemento);
void ExcluirElementoPosicao(ListaLinearSequencial* lista, int posicao);
void ExcluirElementoValor(ListaLinearSequencial* lista, int elemento);
void ImprimirElementos(ListaLinearSequencial* lista);

#endif /* LISTA_LINEAR_SEQUENCIAL_H */
