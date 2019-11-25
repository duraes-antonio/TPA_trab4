/* Problema #108 - Maximum Sum
 * Autores:
 *  Antônio Carlos Durães da Silva
 */
#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n, max_soma, temp_soma, temp_vet[MAX_N], mat[MAX_N][MAX_N];

int kadane(int ind_ini_linha, int ind_fim_linha) {
    int max_atual = 0;
    int max_geral = 0;

    for (int i = ind_ini_linha; i < ind_fim_linha; ++i) {
        max_atual = max_atual + temp_vet[i];
        if (max_atual < 0) max_atual = 0;
        if (max_atual > max_geral) max_geral = max_atual;
    }

    return max_geral > 0 ? max_geral : *min_element(temp_vet, temp_vet + n);
}

int main() {

    while(cin >> n && n > 0) {
        max_soma = temp_soma = 0;

        /*Laços para leitura de entrada de dados e preenchimento da matriz*/
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cin >> mat[i][j];
        }

        /* Busque a soma máxima que comece na linha 'i' e se extenda até a
         * coluna 'j'*/
        for (int col_ini = 0; col_ini < n; ++col_ini) {
            fill(temp_vet, temp_vet + MAX_N, 0);

            for (int col_fim = col_ini; col_fim < n; ++col_fim) {
                for (int ind_lin = 0; ind_lin < n; ++ind_lin) {
                    temp_vet[ind_lin] += mat[ind_lin][col_fim];
                }
                temp_soma = kadane(0, n);
                if (temp_soma > max_soma) max_soma = temp_soma;
            }
        }

        cout << max_soma << endl;
    }

    return 0;
}