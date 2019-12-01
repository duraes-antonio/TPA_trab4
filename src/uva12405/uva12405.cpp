/* Problema #12405 - Scarecrow
 * Autores:
 *  Antônio Carlos Durães da Silva
 */
#include <iostream>
#include <string>

using namespace std;

int main() {

    int n_testes, n_char, n_espants = 0;
    string entrada;
    cin >> n_testes;

    for (int n_caso = 0; n_caso < n_testes; ++n_caso, n_espants = 0) {
        cin >> n_char >> entrada;

        for (int i = 0; i < n_char; ++i) {
            if (entrada[i] == '.') {
                i += 2;
                ++n_espants;
            }
        }

        printf("Case %d: %d\n", n_caso + 1, n_espants);
    }

    return 0;
}