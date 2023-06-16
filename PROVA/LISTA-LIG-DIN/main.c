#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada_dinamica.h"

int main() {
    ListaLigadaDinamica* lista = CriarLista();

    InserirElemento(lista, 3);
    InserirElemento(lista, 5);
    InserirElemento(lista, 1);
    InserirElemento(lista, 4);
    InserirElemento(lista, 4);
    InserirElemento(lista, 5);
    InserirElemento(lista, 4);

    ImprimirElementos(lista);

    int elemento = 4;
    int quantidade = BuscarSequencial(lista, elemento);
    printf("O elemento %d aparece na posicao %d.\n", elemento, quantidade);

    int elemento2 = 5;
    int quantidade2 = BuscaBinaria(lista, elemento2);
    printf("O elemento %d aparece na posicao %d.\n", elemento2, quantidade2);

    ExcluirElementoValor(lista, 4);
    ImprimirElementos(lista);

    DestruirLista(lista);

    return 0;
}
