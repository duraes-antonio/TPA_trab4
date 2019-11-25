/* Problema #10684 - The jackpot
 * Autores:
 *  Antônio Carlos Durães da Silva
 */
#include <iostream>

using namespace std;

#define MAX_N   10000
#define MSG_SUC "The maximum winning streak is %d.\n"
#define MSG_FAL "Losing streak.\n"

int main() {

    int acumulador, max_num, n_entrada, numeros[MAX_N];

    while(cin >> n_entrada && n_entrada > 0) {

        acumulador = max_num = -1;

        /*Leia os N números de entrada*/
        for (int i = 0; i < n_entrada; ++i) {

            /*Leia e armazene o número no array*/
            cin >> numeros[i];

            /*Some o número ao acomulador*/
            acumulador += numeros[i];

            /*Se o acumulador for maior que o máx., atualize o máx. encontrado*/
            if(acumulador > max_num) max_num = acumulador;

            /*Senão, se o AC for negativo, zere-o e recomece a contagem*/
            else if(acumulador < 0) acumulador = 0;
        }

        /*Se o máx for positivo, imprima-o, senão, a mensagem de falha*/
        (max_num > 0) ? printf(MSG_SUC, max_num) : printf(MSG_FAL);
    }

    return 0;
}