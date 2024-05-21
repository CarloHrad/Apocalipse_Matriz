#include <stdio.h>

/* OBJETIVO: O objetivo do programa é, recebendo o mapeamento através de uma matriz, simular o passar de N dias levando em
consideração cada elemento da matriz e seus vizinhos. No código a seguir, o usuário tem até 3 (três) opções diferentes
de imput para a matriz, sendo 0, 1 ou 2, onde 0 é VAZIO, 1 é HUMANO e 2 é ZUMBI
Cada posição [i][j] da matriz irá levar em consideração os seus 8 (oito) vizinhos, localizados fixamente: */

// Os vizinhos estarão nas posições: (i-1,j-1), (i-1, j), (i-1,j+1), (i,j-1), (i,j+1), (i+1,j-1), (i+1,j), (i+1,j+1)
// A descrição da interação entre elementos está entre as linhas 91 e 103*

/* ENTRADA: A entrada possui 1 linha apenas, contendo os inteiros M e N, separados por espaço, representando a quantidade
de linhas e de colunas, respectivamente. A segunda linha contem o inteiro I, que recebe a quantia de dias que o usuário
deseja simular. Por fim, as próximas M*N linhas para que o usuário possa inserir cada posição da matriz.

SAÍDA: A saída contém o estado atual da matriz após a passagem de todos os I dias.*/

int main()
{
    int i = 0, j = 0, k = 0, m = 0, n = 0, dia=0; //j linhas, k colunas
    int  p = 0, q = 0, cont_dia = 0, x = 0, y = 0;

    int humano = 0, zumbi = 0; //contadores de humanos e zumbis

    printf("Digite dois valores (tamanho da matriz) respectivamente M (linhas) e N (colunas): ");
    scanf("%d", &m);
    scanf("%d", &n);

    while (m<0 || n>50) {
        // Garante que M >= 0 ou/e que N <= 50
        printf("\nValor inv�lido, digite novamente. (linhas >= 0, colunas <= 50\n");
        scanf("%d %d", &m, &n);
    }

    int matriz[m][n];
    int iteracao[m][n]; // matriz auxiliar

    printf("Digite quantos dias deseja simular: ");
    scanf("%d", &i);

    printf("\nAgora digite as posicoes da matriz! \n");
    //entrada de cada posição da matriz MxN
    for (j = 0; j < m; j++) {
        for (k = 0; k < n; k++) {
            printf("\nMatriz [%d][%d] = ", j, k);
            scanf("%d", &matriz[j][k]);
        }
    }


    //Exibição do primeiro dia (matriz original separada)
    printf("\n DIA 0 \n");
    for (j = 0; j < m; j++) {
        for (k = 0; k < n; k++) {
            printf("%d ", matriz[j][k]);
        }
        printf("\n");
    }


    for (cont_dia = 1; cont_dia <= i; cont_dia++) {
        // Atualização da matriz original para a auxiliar
        for (j = 0; j < m; j++) {
            for (k = 0; k < n; k++) {
                iteracao[j][k] = matriz[j][k];
            }
        }

        for (j = 0; j < m; j++) {
            for (k = 0; k < n; k++) {
                humano = 0;
                zumbi = 0;
                //Verifica todas as 8 posições vizinhas de um elemento [j][k]
                for (p = -1; p < 2; p++) {
                    for (q = -1; q < 2; q++) {
                        if (p == 0 && q == 0) continue; // Ignora o elemento central (o próprio elemento)
                        // X e Y são as somas de variáveis para cada vizinho
                        // %m e %n impedem que haja um vizinho inválido (ex: coluna = -1)
                        x = (j + p + m) % m;
                        y = (k + q + n) % n;

                        if (matriz[x][y] == 1) {
                            humano += 1;
                        }

                        if (matriz[x][y] == 2) {
                            zumbi += 1;
                        }

                    }
                }
                if (matriz[j][k] == 0) { // Se vazio
                    if (humano == 2) // E possuir dois (exatamente dois) humanos
                        iteracao[j][k] = 1; //nascer um humano
                }

                if (matriz[j][k] == 1) { //Se humano
                    if (zumbi >= 1)       // e houver pelo menos 1 zumbi
                        iteracao[j][k] = 2; // Se transformar em zumbi
                }

                if (matriz[j][k] == 2) { // Se zumbi
                    if (humano == 0 || humano >= 2) { //(Não possuir humanos OU ter 2 ou mais humanos)
                        iteracao[j][k] = 0; //(Morrer de fome OU caçado e morto) --> (respectivamente em ordem)
                    }
                }
            }
        }

        //Repassa os elementos da matriz auxiliar para a original
        for (j = 0; j < m; j++){
            for (k = 0; k < n; k++) {
                matriz[j][k] = iteracao[j][k];
            }
        }
        // Printa a matriz original de cada dia
        printf("\nIteração %d\n", cont_dia);
        for (j = 0; j < m; j++) {
            for (k = 0; k < n; k++) {
                printf("%d ", matriz[j][k]);
            }
            printf("\n");
        }
    }
    return 0;
}
