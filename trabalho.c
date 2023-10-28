#include "biblioteca.h"

int main() {
    int escolha;
    int quantidadeAlunos = 0;
    alunoX *listaAlunos[30] = {NULL};

    do {
        printf("Digite sua escolha:\n"
           "[1] Inserir um aluno\n"
           "[2] Imprimir a lista de alunos e Notas\n"
           "[3] Buscar um aluno\n"
           "[4] Inserir notas\n"
           "[5] Situacao dos alunos \n" // fiz a alternativa
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
                    OrdemNotas(listaAlunos, quantidadeAlunos); // Fiz o case 5
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
