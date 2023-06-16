#include <stdio.h>
#include "lista_estatica_alunos.h"

int main() {
    Aluno lista[TAMANHO_MAX] = {
        {1, "Daniel", 21, 0},
        {2, "Suza", 19, 0},
        {3, "Danilo", 24, 1},
        {4, "Camila", 18, 0},
        {5, "Carlos", 22, 1}
    };

    imprimirAlunoMaiorIdade(lista, TAMANHO_MAX);

    return 0;
}
