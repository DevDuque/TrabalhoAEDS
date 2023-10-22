#include <stdio.h>
#include <stdlib.h>

// Estrutura básica de Aluno
struct Aluno {
    int id;
    char nome[30];
    char sobrenome[30];
    char curso[50];
    double nota;
    double presencaP;
};
// Declarando a tipagem de aluno
typedef struct Aluno alunoX;

// Fazendo um array de ponteiros para a estrutura
alunoX *listaAlunos[30];

// Opções de programa
void instructions(void) {
    printf("Digite sua escolha:\n"
           "[1] Inserir um aluno\n"
           "[2] Imprimir a lista de alunos\n"
           "[0] Sair\n");
}

// Inserindo um aluno na lista de ponteiros
// Quantidade de Alunos é ponteiro para aumentar na hora de chamar no main
void inserirAluno(alunoX *listaAlunos[30], int *quantidadeAlunos) {
    // Verifica se há espaço na lista para adicionar um novo aluno
    if (*quantidadeAlunos >= 30) {
        printf("Erro: Não há espaço para adicionar mais alunos.\n");
        return;
    }

    // Alocando um aluno na memória
    alunoX *novoAluno = malloc(sizeof(alunoX));
    if (novoAluno == NULL) {
        printf("Erro: Não foi possível alocar memória para o aluno.\n");
        exit(1);
    }

    // Subindo ID automaticamente
    static int id = 1;
    novoAluno->id = id++;

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

    // Adicionando os dados para o aluno na posição quantidade, ou seja, no index 0, 1 e etc...
    listaAlunos[*quantidadeAlunos] = novoAluno;
    (*quantidadeAlunos)++;
}

void imprimirAluno(alunoX *listaAlunos[30], int quantidadeAlunos) {
    // Repetindo o looping até acabar os alunos registrados
    for(int i = 0; i < quantidadeAlunos; i++) {
        printf("ID: %d\n", listaAlunos[i]->id);
        printf("Nome: %s %s\n", listaAlunos[i]->nome, listaAlunos[i]->sobrenome);
        printf("Curso: %s\n", listaAlunos[i]->curso);
        printf("Nota: %.2lf\n", listaAlunos[i]->nota);
        printf("Presença: %.2lf\n", listaAlunos[i]->presencaP);
        printf("------------------------------\n");
    }
}

int main() {
    int escolha;
    // Inicializando as variáveis para evitar bugs na hora de chamar as funções
    int quantidadeAlunos = 0;
    alunoX *listaAlunos[30] = {NULL};

    do {
        instructions();
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                // QuantidadeAlunos como ponteiro para aumentar também dentro da função de inserir e não só nossa variável no main
                inserirAluno(listaAlunos, &quantidadeAlunos);
            break;
            
            case 2:
                imprimirAluno(listaAlunos, quantidadeAlunos);
            break;
        }
    } while (escolha != 0);

    // Liberar a memória alocada para os alunos antes de sair do programa
    for (int i = 0; i < quantidadeAlunos; i++) {
        free(listaAlunos[i]);
    }

    return 0;
}
