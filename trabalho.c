#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    int id;
    char nome[30];
    char sobrenome[30];
    char curso[50];
    double nota;
    double presencaP;
};

typedef struct Aluno alunoX;
alunoX *listaAlunos[30];

void instructions(void) {
    printf("Digite sua escolha:\n"
           "[1] Inserir um aluno\n"
           "[2] Imprimir a lista de alunos\n"
           "[0] Sair\n");
}

void inserirAluno(alunoX *listaAlunos[30], int quantidadeAlunos) {
    alunoX *novoAluno = malloc(sizeof(alunoX));
    if (novoAluno == NULL) {
        printf("Erro: Não foi possível alocar memória para o aluno.\n");
        exit(1);
    }

    printf("Entre o nome do aluno: ");
    scanf("%s", novoAluno->nome);

    printf("Entre o sobrenome do aluno: ");
    scanf("%s", novoAluno->sobrenome);

    printf("Entre o curso do aluno: ");
    scanf("%s", novoAluno->curso);

    printf("Entre a nota do aluno: ");
    scanf("%lf", &novoAluno->nota);

    printf("Entre a presença do aluno: ");
    scanf("%lf", &novoAluno->presencaP);

    listaAlunos[quantidadeAlunos] = novoAluno;
    quantidadeAlunos++;
}

void imprimirAluno(alunoX *listaAlunos[30], int *quantidadeAlunos) {
    for(int i = 0; i < quantidadeAlunos; i++) {
        printf("Nome: %s", listaAlunos[i]->nome);
    }
}

int main() {
    int escolha;
    int quantidadeAlunos = 0;

    do {
        instructions();
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                inserirAluno(listaAlunos, quantidadeAlunos);
            break;
            
            case 2:
                imprimirAluno(listaAlunos, &quantidadeAlunos);
            break;
        }
    } while (escolha != 0);

    // Liberar a memória alocada para os alunos antes de sair do programa
    for (int i = 0; i < quantidadeAlunos; i++) {
        free(listaAlunos[i]);
    }

    return 0;
}
