#include <stdio.h>
#include <stdlib.h>
#include "lista_linear_sequencial.h"

int main() {
    ListaLinearSequencial* lista = CriarLista(10);

    InserirElementoOrdenado(lista, 3);
    InserirElementoOrdenado(lista, 5);
    InserirElementoOrdenado(lista, 1);
    InserirElementoOrdenado(lista, 4);
    InserirElementoOrdenado(lista, 4);
    InserirElementoOrdenado(lista, 5);
    InserirElementoOrdenado(lista, 4);

    ImprimirElementos(lista);

    int elemento = 4;
    int quantidade = ContarElemento(lista, elemento);
    printf("O elemento %d aparece %d vezes na lista.\n", elemento, quantidade);

    DestruirLista(lista);

    return 0;
}
