#include <stdio.h>
#include <string.h>
#include "lista_ligada_dinamica.h"

int main() {
    ListaLigadaDinamica* lista = CriarLista();

    Aluno aluno1 = {1, "Daniel", 21, 0, NULL};
    Aluno aluno2 = {2, "Suza", 19, 0, NULL};
    Aluno aluno3 = {3, "Danilo", 24, 1, NULL};
    Aluno aluno4 = {4, "Camila", 18, 0, NULL};
    Aluno aluno5 = {5, "Carlos", 22, 1, NULL};

    InserirElemento(lista, aluno1);
    InserirElemento(lista, aluno2);
    InserirElemento(lista, aluno3);
    InserirElemento(lista, aluno4);
    InserirElemento(lista, aluno5);

    printf("Quantidade de elementos na lista: %d\n", ObterQuantidadeElementos(lista));

    Aluno* alunoBuscaSequencial = BuscarSequencial(lista, 3);
    if (alunoBuscaSequencial != NULL) {
        printf("Aluno encontrado (busca sequencial):\n");
        printf("Codigo: %d\n", alunoBuscaSequencial->codigo);
        printf("Nome: %s\n", alunoBuscaSequencial->nome);
        printf("Idade: %d\n", alunoBuscaSequencial->idade);
        printf("Numero de filhos: %d\n", alunoBuscaSequencial->numFilhos);
    } else {
        printf("Aluno nao encontrado (busca sequencial)\n");
    }

    ExcluirElemento(lista, 4);
    printf("Lista apos excluir elemento:\n");
    ImprimirLista(lista);

    return 0;
}
