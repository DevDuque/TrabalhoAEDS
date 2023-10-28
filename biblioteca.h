#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    // ID auto incremental
    int id;

    // Nome e Sobrenome do Aluno
    char nome[30];
    char sobrenome[30];

    // Curso do Aluno (Implementar uma diferenciação na hora das notas)
    char curso[50];

    // Notas
    double notaTotal;

    // Double notaProva, notaComplementar, notaTrabalho (A diferenciação na hora da nota)
    int quantidadeNotas;

    // Presença para fazer a porcentagem com a quantidade de aulas
    double presencaP;
};

typedef struct Aluno alunoX;

// Coloquei todos pra evitar erro de qualquer um
void inserirAluno(alunoX *listaAlunos[30], int *quantidadeAlunos);
void inserirNota(alunoX *listaAlunos[30], int quantidadeAlunos);
void imprimirAluno(alunoX *listaAlunos[30], int quantidadeAlunos);
void buscarAluno(alunoX *listaAlunos[30], int quantidadeAlunos);
void OrdemNotas(alunoX *listaAlunos[30], int quantidadeAlunos);
int isEmpty(int quantidadeAlunos);

void inserirAluno(alunoX *listaAlunos[30], int *quantidadeAlunos) { 
    // Espaço de 30 na lista de alunos
    if (*quantidadeAlunos >= 30) {
        printf("Erro: Não há espaço para adicionar mais alunos.\n");
        return;
    }

    // Alocando um aluno na estrutura
    alunoX *novoAluno = malloc(sizeof(alunoX));
    if (novoAluno == NULL) {
        printf("Erro: Não foi possível alocar memória para o aluno.\n");
        exit(1);
    }

    novoAluno->quantidadeNotas = 0;

    // Incrementando o ID
    novoAluno->id = (*quantidadeAlunos) + 1;

    printf("Entre o nome do aluno: ");
    scanf("%s", novoAluno->nome);

    printf("Entre o sobrenome do aluno: ");
    scanf("%s", novoAluno->sobrenome);

    printf("Entre o curso do aluno: ");
    scanf("%s", novoAluno->curso);

    printf("Entre a presenca do aluno: ");
    scanf("%lf", &novoAluno->presencaP);



    // Alocando os dados inseridos para posição quantidadeAlunos
    listaAlunos[*quantidadeAlunos] = novoAluno;
    
    // Incrementando para próxima vez que chamar a função
    (*quantidadeAlunos)++;

    
}

void inserirNota(alunoX *listaAlunos[30], int quantidadeAlunos) {
    // Imprime a lista para facilitar a escolha
    imprimirAluno(listaAlunos, quantidadeAlunos);

    int idAluno;
    // Pega o ID para conferir se existe
    printf("Digite o ID do aluno escolhido (ou 0 para cancelar): ");
    scanf("%d", &idAluno);

    // Se inserir 0 para a operação, porque não deve ter ID de usuário = 0
    if (idAluno == 0) {
        printf("Operacao cancelada.\n");
        return;
    }

    int alunoEncontrado = 0;
    // Vendo se o ID foi encontrado
    for(int i = 0; i < quantidadeAlunos; i++) {
        if(listaAlunos[i]->id == idAluno) {

            int escolha;
            double novaNota;

            do { 
                // Registrando qual nota deve ser inserida
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

                // Salvando a notaInserida, somando com a nota anterior
                listaAlunos[i]->notaTotal += novaNota;

                // Aumentando a quantidade de notas inseridas
                listaAlunos[i]->quantidadeNotas++;

            } while(escolha != 0);

            alunoEncontrado = 1;
            break;
        }
    }

    if (!alunoEncontrado) {
        printf("Aluno com ID %d nao encontrado.\n", idAluno);
    }
}

void imprimirAluno(alunoX *listaAlunos[30], int quantidadeAlunos) {

    // Formatando como tabela
    // Cabeçalho
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-4s | %-20s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "ID", "Nome", "Sobrenome", "Curso", "Presenca", "Nota Total", "Nota Media");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");

    // Lista de alunos com a mesma regra do cabeçalho
    for(int i = 0; i < quantidadeAlunos; i++) {
        printf("| %-4d | %-20s | %-15s | %-15s | %-15.2lf |", 
        listaAlunos[i]->id, 
        listaAlunos[i]->nome, listaAlunos[i]->sobrenome,
        listaAlunos[i]->curso, 
        listaAlunos[i]->presencaP);
        
        // Conferindo se alguma nota foi inserida
        if (listaAlunos[i]->quantidadeNotas > 0) {
            printf(" %-15.2lf |", listaAlunos[i]->notaTotal);
            printf(" %-15.2lf |\n", listaAlunos[i]->notaTotal / listaAlunos[i]->quantidadeNotas);
        } else {
            printf(" %-15s |", "N/A"); // Usando um traço para indicar notas não disponíveis
            printf(" %-15s |\n", "N/A");
        }
    }

    printf("--------------------------------------------------------------------------------------------------------------------------\n");
}

void buscarAluno(alunoX *listaAlunos[30], int quantidadeAlunos){

    char nome[30];
    char sobrenome[30];
    int escolha;

    do {
        // Escolha de critério de busca
        printf("Buscar Aluno:\n"
           "[1] Pelo nome\n"
           "[2] Pelo sobrenome\n"
           "[0] Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                printf("Digite o nome do aluno que deseja buscar: ");
                scanf("%s", nome);

                // Flag para ver se encontrou com o criterio de busca
                int alunoEncontrado = 0;

                printf("---------------------------------------------------------------------------------------------\n");
                printf("| %-4s | %-20s | %-15s | %-15s | %-15s |\n", "ID", "Nome", "Sobrenome", "Curso", "Presenca");
                printf("---------------------------------------------------------------------------------------------\n");

                // Comparando com toda lista
                for(int i = 0; i < quantidadeAlunos; i++){
                    if(strcmp(listaAlunos[i]->nome, nome) == 0){

                        printf("| %-4d | %-20s | %-15s | %-15s | %-15.2lf |\n", 
                        listaAlunos[i]->id, 
                        listaAlunos[i]->nome, listaAlunos[i]->sobrenome,
                        listaAlunos[i]->curso, 
                        listaAlunos[i]->presencaP);

                        printf("---------------------------------------------------------------------------------------------\n");


                        alunoEncontrado++;
                    }
                }

                // Vendo se o aluno foi encontrado
                if (alunoEncontrado == 0) {
                    printf("Aluno(a) %s nao encontrado!\n", nome);
                    printf("---------------------------------------------------------------------------------------------\n");

                }
                break;
            }

            case 2: {
                printf("Digite o sobrenome do aluno que deseja buscar: ");
                scanf("%s", sobrenome);

                // Flag para ver se encontrou com o criterio de busca
                int alunoEncontrado = 0;

                printf("---------------------------------------------------------------------------------------------\n");
                printf("| %-4s | %-20s | %-15s | %-15s | %-15s |\n", "ID", "Nome", "Sobrenome", "Curso", "Presenca");
                printf("---------------------------------------------------------------------------------------------\n");

                // Comparando com toda lista
                for(int i = 0; i < quantidadeAlunos; i++){
                    if(strcmp(listaAlunos[i]->sobrenome, sobrenome) == 0){

                        printf("| %-4d | %-20s | %-15s | %-15s | %-15.2lf |\n", 
                        listaAlunos[i]->id, 
                        listaAlunos[i]->nome, listaAlunos[i]->sobrenome,
                        listaAlunos[i]->curso, 
                        listaAlunos[i]->presencaP);
                        
                        printf("---------------------------------------------------------------------------------------------\n");

                        alunoEncontrado++;
                    }
                }

                // Vendo se o aluno foi encontrado
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

// Criando uma cópia temporária para continuar em ordem alfabética quando for salva/carregada.
void OrdemNotas(alunoX *listaAlunos[30], int quantidadeAlunos) {
    // Criar uma cópia temporária da lista de alunos
    alunoX *copiaAlunos[30];
    for (int i = 0; i < quantidadeAlunos; i++) {
        copiaAlunos[i] = listaAlunos[i];
    }

    // Ordenar a cópia da lista pelas notas em ordem decrescente usando o algoritmo de seleção
    for (int i = 0; i < quantidadeAlunos - 1; i++) {
        int maior = i;
        for (int j = i + 1; j < quantidadeAlunos; j++) {
            if (copiaAlunos[j]->notaTotal > copiaAlunos[maior]->notaTotal) {
                maior = j;
            }
        }
        if (i != maior) {
            alunoX *temp = copiaAlunos[i];
            copiaAlunos[i] = copiaAlunos[maior];
            copiaAlunos[maior] = temp;
        }
    }

    // Atualizar os IDs com base na classificação das notas (ordem decrescente)
    for (int i = 0; i < quantidadeAlunos; i++) {
        copiaAlunos[i]->id = i + 1;
    }

    // Imprimir a tabela dos alunos ordenada por notas em ordem decrescente
    printf("Tabela dos alunos ordenada por notas em ordem decrescente: \n");
    imprimirAluno(copiaAlunos, quantidadeAlunos);
}
