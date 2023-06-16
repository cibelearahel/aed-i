#include <stdio.h>
#include "lista_linear_sequencial.h"

int main() {
    ListaLinearSequencial* lista = CriarLista(10);

    InserirElemento(lista, 3);
    InserirElemento(lista, 5);
    InserirElemento(lista, 1);
    InserirElementoOrdenado(lista, 4);

    printf("Quantidade de elementos na lista: %d\n", ObterQuantidadeElementos(lista));

    int posicao = BuscarSequencial(lista, 5);
    if (posicao != -1) {
        printf("O elemento 5 foi encontrado na posicao: %d\n", posicao);
    } else {
        printf("O elemento 5 nao foi encontrado na lista.\n");
    }

    posicao = BuscaBinaria(lista, 4);
    if (posicao != -1) {
        printf("O elemento 4 foi encontrado na posicao: %d\n", posicao);
    } else {
        printf("O elemento 4 nao foi encontrado na lista.\n");
    }

    ExcluirElementoValor(lista, 3);

    printf("Elementos presentes na lista: ");
    ImprimirElementos(lista);

    DestruirLista(lista);

    return 0;
}
