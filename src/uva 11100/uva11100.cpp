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
