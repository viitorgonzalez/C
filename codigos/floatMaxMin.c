#include <stdio.h>
#include <float.h> //biblioteca para pegar maiores e menores valores para float

/*Considere um arquivo texto que armazene números em ponto flutuante em cada uma de suas
linhas. Escreva um programa em C que determine o valor máximo, o valor mínimo e a média
desses valores armazenados no arquivo. Imprima esses valores na tela.
*/

int main(void) {

    //abre e lê o arquivo
    float num, maior = FLT_MIN, menor = FLT_MAX, soma = 0, numElements = 0;
    FILE *arquivo = fopen("entrada.txt", "r");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f", &num);
        if (num < menor) {
            menor = num;
        }
        if (num > maior) {
            maior = num;
        }

        //calculos de incrementação
        soma += num;
        numElements++;
    }

    //fecha arquivo e mostra os resultados
    fclose(arquivo);
    printf("O menor número é %.2f, o maior é %.2f, e a média é %.2f!\n", menor, maior, (soma / numElements));

    return 0;
}