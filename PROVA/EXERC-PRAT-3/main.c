#include <stdio.h>
#include "lista_estatica.h"

int main() {
    ListaEstatica lista = CriarLista();

    InserirElemento(&lista, 15);
    InserirElemento(&lista, 28);
    InserirElemento(&lista, 9);
    InserirElemento(&lista, 31);
    InserirElemento(&lista, 2);

    ImprimirMaiorElemento(&lista);
    int maiorElemento = ExcluirMaiorElemento(&lista);
    printf("O maior elemento excluido foi: %d\n", maiorElemento);
    ImprimirMaiorElemento(&lista);

    printf("Elementos restantes da lista: ");
    for (int i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.elementos[i]);
    }
    printf("\n");

    return 0;
}
