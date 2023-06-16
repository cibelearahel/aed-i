#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada_estatica.h"

int main() {
    ListaLigadaEstatica* lista = CriarLista();

    Aluno aluno1 = { 1, "Joao", 20, 0 };
    Aluno aluno2 = { 2, "Maria", 22, 1 };
    Aluno aluno3 = { 3, "Pedro", 19, 2 };
    Aluno aluno4 = { 4, "Ana", 21, 0 };

    InserirElemento(lista, aluno1);
    InserirElemento(lista, aluno2);
    InserirElemento(lista, aluno3);

    int codigo = 3;
    if (VerificarDuplicidade(lista, codigo)) {
        printf("Aluno com codigo %d esta duplicado na lista.\n", codigo);
    } else {
        printf("Aluno com codigo %d nao esta duplicado na lista.\n", codigo);
    }

    InserirElemento(lista, aluno4);

    codigo = 3;
    if (VerificarDuplicidade(lista, codigo)) {
        printf("Aluno com codigo %d esta duplicado na lista.\n", codigo);
    } else {
        printf("Aluno com codigo %d nao esta duplicado na lista.\n", codigo);
    }

    ImprimirElementos(lista);

    DestruirLista(lista);

    return 0;
}
