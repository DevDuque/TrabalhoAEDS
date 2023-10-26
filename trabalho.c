#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    int id;
    char nome[30];
    char sobrenome[30];
    char curso[50];
    double notaTotal;
    int quantidadeNotas;
    double presencaP;
};

typedef struct Aluno alunoX;

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

    printf("Entre a presenca do aluno: ");
    scanf("%lf", &novoAluno->presencaP);

    listaAlunos[*quantidadeAlunos] = novoAluno;
    (*quantidadeAlunos)++;
}

void inserirNota(alunoX *listaAlunos[30], int quantidadeAlunos) {
    imprimirAluno(listaAlunos, quantidadeAlunos);

    int idAluno;
    printf("Digite o ID do aluno escolhido (ou 0 para cancelar): ");
    scanf("%d", &idAluno);

    if (idAluno == 0) {
        printf("Operação cancelada.\n");
        return;
    }

    int alunoEncontrado = 0;

    for(int i = 0; i < quantidadeAlunos; i++) {
        if(listaAlunos[i]->id == idAluno) {
            int escolha;
            double novaNota;

            do {
                printf("Entre o tipo de nota a ser inserida:\n"
                       "[1] Atividades Complementares\n"
                       "[2] Provas\n"
                       "[3] Trabalho\n"
                       "[0] Sair\n");
                scanf("%d", &escolha);

                switch (escolha) {
                    case 1:
                        printf("Entre a nota de Atividades Complementares: ");
                        scanf("%lf", &novaNota);
                        break;
                    case 2:
                        printf("Entre a nota de Provas: ");
                        scanf("%lf", &novaNota);
                        break;
                    case 3:
                        printf("Entre a nota de Trabalho: ");
                        scanf("%lf", &novaNota);
                        break;
                    default:
                        continue;
                }

                listaAlunos[i]->notaTotal += novaNota;
                listaAlunos[i]->quantidadeNotas++;

            } while(escolha != 0);

            alunoEncontrado = 1;
            break;
        }
    }

    if (!alunoEncontrado) {
        printf("Aluno com ID %d não encontrado.\n", idAluno);
    }
}

void imprimirAluno(alunoX *listaAlunos[30], int quantidadeAlunos) {
    printf("-------------------------------------------------------------------------------------------\n");
    printf("| %-4s | %-20s | %-15s | %-15s | %-8s |\n", "ID", "Nome", "Sobrenome", "Curso", "Presenca");
    printf("-------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < quantidadeAlunos; i++) {
        printf("| %-4d | %-20s | %-15s | %-15s | %-8.2lf |\n", listaAlunos[i]->id, listaAlunos[i]->nome,
               listaAlunos[i]->sobrenome, listaAlunos[i]->curso, listaAlunos[i]->presencaP);
    }

    printf("---------------------------------------------------------------------------------------------\n");
}

void imprimirNota(alunoX *listaAlunos[30], int quantidadeAlunos) {
    printf("-------------------------------------------------------------------------------------------\n");
    printf("| %-4s | %-20s | %-15s | %-15s | %-10s | %-10s |\n", "ID", "Nome", "Sobrenome", "Curso", "Nota Total", "Nota Media");
    printf("-------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < quantidadeAlunos; i++) {
        printf("| %-4d | %-20s | %-15s | %-15s | %-10.2lf |", 
        listaAlunos[i]->id, 
        listaAlunos[i]->nome, listaAlunos[i]->sobrenome,
        listaAlunos[i]->curso, 
        listaAlunos[i]->notaTotal);
        
        if (listaAlunos[i]->quantidadeNotas > 0) {
            printf(" %-10.2lf |\n", listaAlunos[i]->notaTotal / listaAlunos[i]->quantidadeNotas);
        } else {
            printf(" %-10s |\n", "N/A");
        }
    }

    printf("---------------------------------------------------------------------------------------------\n");
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

                int alunoEncontrado = 0;

                for(int i = 0; i < quantidadeAlunos; i++){
                    if(strcmp(listaAlunos[i]->nome, nome) == 0){
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("| %-4s | %-20s | %-15s | %-15s | %-8s |\n", "ID", "Nome", "Sobrenome", "Curso", "Presenca");
                        printf("-------------------------------------------------------------------------------------------\n");

                        printf("| %-4d | %-20s | %-15s | %-15s | %-8.2lf |\n", 
                        listaAlunos[i]->id, 
                        listaAlunos[i]->nome, listaAlunos[i]->sobrenome,
                        listaAlunos[i]->curso, 
                        listaAlunos[i]->presencaP);

                        printf("---------------------------------------------------------------------------------------------\n");

                        alunoEncontrado++;
                    }
                }

                if (alunoEncontrado == 0) {
                    printf("Aluno(a) %s nao encontrado!\n", nome);
                }
                break;
            }

            case 2: {
                printf("Digite o sobrenome do aluno que deseja buscar: ");
                scanf("%s", sobrenome);

                int alunoEncontrado = 0;

                for(int i = 0; i < quantidadeAlunos; i++){
                    if(strcmp(listaAlunos[i]->sobrenome, sobrenome) == 0){
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("| %-4s | %-20s | %-15s | %-15s | %-8s |\n", "ID", "Nome", "Sobrenome", "Curso", "Presenca");
                        printf("-------------------------------------------------------------------------------------------\n");

                        printf("| %-4d | %-20s | %-15s | %-15s | %-8.2lf |\n", 
                        listaAlunos[i]->id, 
                        listaAlunos[i]->nome, listaAlunos[i]->sobrenome,
                        listaAlunos[i]->curso, 
                        listaAlunos[i]->presencaP);
                        
                        printf("---------------------------------------------------------------------------------------------\n");

                        alunoEncontrado++;
                    }
                }

                if (alunoEncontrado == 0) {
                    printf("Aluno(a) %s nao encontrado!\n", sobrenome);
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
        printf("Digite sua escolha:\n"
           "[1] Inserir um aluno\n"
           "[2] Imprimir a lista de alunos\n"
           "[3] Buscar um aluno\n"
           "[4] Inserir notas\n"
           "[5] Visualizar notas\n"
           "[0] Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                inserirAluno(listaAlunos, &quantidadeAlunos);
            break;
            
            case 2:
                if(!isEmpty(quantidadeAlunos)){
                    imprimirAluno(listaAlunos, quantidadeAlunos);
                } else {
                    printf("A lista de alunos esta vazia!\n");
                }
            break;
                
            case 3:
                if(!isEmpty(quantidadeAlunos)){
                    buscarAluno(listaAlunos, quantidadeAlunos);
                } else {
                    printf("A lista de alunos esta vazia!\n");
                }
            break;

            case 4:
                if(!isEmpty(quantidadeAlunos)) {
                    inserirNota(listaAlunos, quantidadeAlunos);
                } else {
                    printf("A lista de alunos esta vazia! \n");
                }
            break;

            case 5:
                if(!isEmpty(quantidadeAlunos)) {
                    imprimirNota(listaAlunos, quantidadeAlunos);
                } else {
                    printf("A lista de alunos esta vazia! \n");
                }
            break;

        }
    } while (escolha != 0);

    for (int i = 0; i < quantidadeAlunos; i++) {
        free(listaAlunos[i]);
    }

    return 0;
}
