OBJETIVOS, ENTRADA E SAÍDA

OBJETIVO: O objetivo do programa é, recebendo o mapeamento através de uma matriz, simular o passar de N dias levando em
consideração cada elemento da matriz e seus vizinhos. No código o usuário tem até 3 (três) opções diferentes
de imput para a matriz, sendo 0, 1 ou 2, onde 0 é VAZIO, 1 é HUMANO e 2 é ZUMBI
Cada posição [i][j] da matriz irá levar em consideração os seus 8 (oito) vizinhos, localizados fixamente.

Os vizinhos estarão nas posições: (i-1,j-1), (i-1, j), (i-1,j+1), (i,j-1), (i,j+1), (i+1,j-1), (i+1,j), (i+1,j+1)
As interações estão descritas como: 
        Se X for humano e possuir pelo menos um vizinho zumbi, então X é infectado e se torna um zumbi no dia seguinte;
        Se X for zumbi e possuir dois ou mais vizinhos humanos, ele é caçado e morto pelos humanos;
        Se X for zumbi e não possuir nenhum vizinho humano, ele morre de fome e fica vazio no dia seguinte;
        Se X estiver vazio e possuir exatamente dois vizinhos humanos, independente dos demais vizinhos serem zumbis
        ou vazio, então um humano nasce em X no dia seguinte.
        Se nenhuma das alternativas anteriores for verdade, então X permanece como está.

ENTRADA: A entrada possui 1 linha apenas, contendo os inteiros M e N, separados por espaço, representando a quantidade
de linhas e de colunas, respectivamente. A segunda linha contem o inteiro I, que recebe a quantia de dias que o usuário
deseja simular. Por fim, as próximas M*N linhas para que o usuário possa inserir cada posição da matriz.

SAÍDA: A saída contém o estado atual da matriz após a passagem de todos os I dias.
