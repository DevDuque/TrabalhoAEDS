#include "biblioteca.h"

int main() {
    int escolha;
    int quantidadeAlunos = 0;
    alunoX *listaAlunos[30] = {NULL};
    
    // Alocando alunos na memoria
    for (int i = 0; i < 30; i++) {
        listaAlunos[i] = malloc(sizeof(alunoX));
            if (listaAlunos[i] == NULL) {
                printf("Erro: Não foi possível alocar memória para o aluno.\n");
        }
    }
    do {
        printf("\n\033[1;34m============================ MENU PRINCIPAL ============================\033[0m\n");
        printf("\033[1;36m[1]\033[0m Inserir um aluno\n");
        printf("\033[1;36m[2]\033[0m Imprimir a lista\n");
        printf("\033[1;36m[3]\033[0m Buscar um aluno\n");
        printf("\033[1;36m[4]\033[0m Atualizar notas\n");
        printf("\033[1;36m[5]\033[0m Situacao dos alunos\n");
        printf("\033[1;36m[6]\033[0m Importar lista\n");
        printf("\033[1;36m[7]\033[0m Exportar lista\n");
        printf("\033[1;31m[0]\033[0m Sair do programa\n");
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
                    OrdemNotas(listaAlunos, quantidadeAlunos);
                } else {
                    printf("A lista de alunos esta vazia! \n");
                }
            break;

            case 6:
                    importarCSV(listaAlunos, &quantidadeAlunos);
            break;

            case 7: 
                if(!isEmpty(quantidadeAlunos)) {
                    exportarCSV(listaAlunos, quantidadeAlunos);
                } else {
                    printf("A lista de alunos esta vazia! \n");
                }
            break;

        }
    } while (escolha != 0);

    // Liberando os dados alocados
    for (int i = 0; i < quantidadeAlunos; i++) {
        free(listaAlunos[i]);
    }
    return 0;
}
