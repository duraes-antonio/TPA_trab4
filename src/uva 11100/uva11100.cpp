/* Problema #11100 - The Trip, 2007
 * Autores:
 *  Lucas Gomes Flegler
 */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, resposta, flag;
// armazena o tamanho de todos os n pacotes
int pacotes[10010];
// armazena o numero total de pacotes contidos num pacote maior
int pacoteMaior[10010];

void saida()
{
    int i, j, tmp;
    if (!flag)
        printf("\n");
    printf("%d\n", resposta);

    //  O primeiro pacote de cada pacote Maior
    for (i = 0; i < resposta; i++)
    {
        printf("%d", pacotes[i]);
        for (j = 1; j < pacoteMaior[i]; j++)
            printf(" %d", pacotes[i + resposta * j]);
        printf("\n");
    }
}

void resolver()
{
    int i, pos, sum, tmp;
    // ordenando para encontrar o número mínimo de 
    // pacotes e o numero de cada pacote
    sort(pacotes, pacotes + n);
    pos = 0;
    sum = 1;
    resposta = 0;
    for (i = 1; i < n; i++)
    {
        // se o tamanho do pacote anterior for diferente
        if (pacotes[i] != pacotes[i - 1])
        {
            if (resposta < sum)
                resposta = sum;
            sum = 1;
        }
        else
            sum++;
    }
    if (resposta < sum)
        resposta = sum;
    for (i = 0, tmp = n / resposta; i < resposta; i++)
        pacoteMaior[i] = tmp;
    for (i = 0, tmp = n % resposta; i < tmp; i++)
        pacoteMaior[i]++;
}

int main()
{
    flag = 1;
    while (scanf("%d%*c", &n) && n)
    {
        // preenchendo a dimensao de cada pacote
        for (int i = 0; i < n; i++)
            scanf("%d", &pacotes[i]);
        resolver();
        saida();
        if (flag)
            flag = 0;
    }
    return 0;
}

// resposta: 
// Primeiro, sabemos que o mesmo pacote de tamanho normal não pode ser 
// incluído no mesmo pacote de tamanho grande; portanto, o número de pacotes grandes
//  necessários é o valor máximo do mesmo pacote de modelo na sequência original.

// a descricao do problema diz que qualquer tipo de saída pode ser satisfeita, logo, nossa idéia é colocar n pacotes em ordem. 
// Depois disso, as primeiras respostas no array pacotes, após a classificação, são divididos respectivamente em pacotes maiores diferentes.

// Por exemplo: 1 1 1 2 2 2 3 3 3 3 
// Então resposta = 4, o número de pacotes necessários para 4 pacotes é 3 3 2 2. 
// e entao Primeiro pacote: 1 1 1 2 2 2 3 3 3 Saída três das linhas 1 2 3 
// O segundo pacote: 1 1 1 2 2 2 3 3 3 Três linhas de linhas de saída 1 2 3 

// Nota: a descricao requer que uma linha em branco seja impressa entre duas amostras. 
// Nste caso, usamos uma variável de flag para marcar a primeira amostra sem gerar uma 
// linha em branco, seguida por output uma linha em branco antes da saída, para evitar 
// o último conjunto de linhas em branco de saída
