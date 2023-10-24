#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    int id;
    char nome[30];
    char sobrenome[30];
    char curso[50];
    double nota;
    double presencaP;
};

typedef struct Aluno alunoX;

void instructions(void) {
    printf("Digite sua escolha:\n"
           "[1] Inserir um aluno\n"
           "[2] Imprimir a lista de alunos\n"
           "[3] Buscar um aluno\n"
           "[0] Sair\n");
}

void inserirAluno(alunoX *listaAlunos[30], int *quantidadeAlunos) {
    if (*quantidadeAlunos >= 30) {
        printf("Erro: Não há espaço para adicionar mais alunos.\n");
        return;
    }

    alunoX *novoAluno = malloc(sizeof(alunoX));
    if (novoAluno == NULL) {
        printf("Erro: Não foi possível alocar memória para o aluno.\n");
        exit(1);
    }

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

    listaAlunos[*quantidadeAlunos] = novoAluno;
    (*quantidadeAlunos)++;
}

void imprimirAluno(alunoX *listaAlunos[30], int quantidadeAlunos) {
    for(int i = 0; i < quantidadeAlunos; i++) {
        printf("ID: %d\n", listaAlunos[i]->id);
        printf("Nome: %s %s\n", listaAlunos[i]->nome, listaAlunos[i]->sobrenome);
        printf("Curso: %s\n", listaAlunos[i]->curso);
        printf("Nota: %.2lf\n", listaAlunos[i]->nota);
        printf("Presença: %.2lf\n", listaAlunos[i]->presencaP);
        printf("------------------------------\n");
    }
}

void buscarAluno(alunoX *listaAlunos[30], int quantidadeAlunos){
    char nome[30];
    char sobrenome[30];
    int escolha;

    do {
        printf("Buscar Aluno:\n"
           "[1] Pelo nome\n"
           "[2] Pelo sobrenome\n"
           "[0] Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                printf("Digite o nome do aluno que deseja buscar: ");
                scanf("%s", nome);

                for(int i = 0; i < quantidadeAlunos; i++){
                    if(strcmp(listaAlunos[i]->nome, nome) == 0){
                        printf("Aluno encontrado!\n");
                        printf("------------------------------\n");
                        printf("ID: %d\n", listaAlunos[i]->id);
                        printf("Nome: %s %s\n", listaAlunos[i]->nome, listaAlunos[i]->sobrenome);
                        printf("Curso: %s\n", listaAlunos[i]->curso);
                        printf("Nota: %.2lf\n", listaAlunos[i]->nota);
                        printf("Presença: %.2lf\n", listaAlunos[i]->presencaP);
                        printf("------------------------------\n");
                    } else {
                        printf("Aluno(a) %s não encontrado!\n", nome);
                    }
                }
                break;
            }

            case 2: {
                printf("Digite o sobrenome do aluno que deseja buscar: ");
                scanf("%s", sobrenome);

                int alunoEncontrado = 0;

                for(int i = 0; i < quantidadeAlunos; i++){
                    if(strcmp(listaAlunos[i]->sobrenome, sobrenome) == 0){
                        printf("Aluno encontrado!\n");
                        printf("------------------------------\n");
                        printf("ID: %d\n", listaAlunos[i]->id);
                        printf("Nome: %s %s\n", listaAlunos[i]->nome, listaAlunos[i]->sobrenome);
                        printf("Curso: %s\n", listaAlunos[i]->curso);
                        printf("Nota: %.2lf\n", listaAlunos[i]->nota);
                        printf("Presença: %.2lf\n", listaAlunos[i]->presencaP);
                        printf("------------------------------\n");

                        alunoEncontrado++;
                    }
                }

                if (alunoEncontrado == 0) {
                    printf("Aluno(a) %s não encontrado!\n", sobrenome);
                }
                break;
            }
        }

    } while(escolha != 0);
}

int isEmpty(int quantidadeAlunos){
    return quantidadeAlunos == 0;
}

int main() {
    int escolha;
    int quantidadeAlunos = 0;
    alunoX *listaAlunos[30] = {NULL};

    do {
        instructions();
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                inserirAluno(listaAlunos, &quantidadeAlunos);
                break;
            
            case 2:
                if(!isEmpty(quantidadeAlunos)){
                    imprimirAluno(listaAlunos, quantidadeAlunos);
                } else {
                    printf("A lista de alunos está vazia!\n");
                }
                break;
                
            case 3:
                if(!isEmpty(quantidadeAlunos)){
                    buscarAluno(listaAlunos, quantidadeAlunos);
                } else {
                    printf("A lista de alunos está vazia!\n");
                }
                break;
        }
    } while (escolha != 0);

    for (int i = 0; i < quantidadeAlunos; i++) {
        free(listaAlunos[i]);
    }

    return 0;
}
