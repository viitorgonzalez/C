#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Crie um programa que receba dados de vários alunos (Matricula e Telefone) e armazene em
um arquivo texto. Crie no mesmo programa uma opção de ler dados de um arquivo já
armazenado dados de alunos.
*/

//estrutura de aluno
typedef struct aluno {
    int matricula;
    char *telefone;
} Aluno;

//criar vetor do tamanho de telefone, transcreve e retorna ele no tamanho certo
char *novoTelefone(char telefone[]) {
    char *resultado = (char *)malloc(sizeof(char) * strlen(telefone));
    strcpy(resultado, telefone);
    resultado[strlen(telefone) - 1] = '\0';
    return resultado;
}
const int TAM = 5;

int main(void) {
    Aluno alunos[TAM];
    char entrada[50];

    for (int i = 0; i < TAM; i++) {
        printf("Digite sua matrícula:");
        getchar();
        scanf("%d", &alunos[i].matricula);
        getchar();
        printf("Digite seu telefone:");
        fgets(entrada, 50, stdin);
        getchar();
        alunos[i].telefone = novoTelefone(entrada);
    }

    //escreve no arquivo
    FILE *arquivo = fopen("entrada.txt", "wb");
    for (int i = 0; i < TAM; i++) {
        fprintf(arquivo, "O aluno de matrícula %d, possui o telefone %s\n", alunos[i].matricula, alunos[i].telefone);
    }

    //fechar arquivo
    fclose(arquivo);

    //lê o arquivo
    FILE *arquivoLer = fopen("entrada.txt", "rb");
    while (!feof(arquivoLer)) {
        char letra = fgetc(arquivoLer);
        printf("%c", letra);
    }

    //fecha o arquivo
    fcole(arquivoLer);

    return 0;
}