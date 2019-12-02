/* Problema #280 - Vertex
 * Autores:
 *  Antônio Carlos Durães da Silva
 */
#include <iostream>
#define MAX_N 101

using namespace std;

int mat_acesseb[MAX_N][MAX_N];
bool acessaveis[MAX_N];

void busca_em_prof(int n_vertices, int vertice) {

    /*Visite cada vértice do grafo*/
    for (int i = 1; i <= n_vertices; ++i) {

        /*Se esse vértice estiver associado ao vértice de entrada E ainda não
         * foi marcado como acessível*/
        if (!acessaveis[i] and mat_acesseb[vertice][i]) {

            /*Marque o vértice atual como acessível e realize a busca para ele*/
            acessaveis[i] = true;
            busca_em_prof(n_vertices, i);
        }
    }
}

int main() {
    int n_vert, n_verif, vert_ini, vert, vert_inacess[MAX_N];

    /*Enquanto houverem vértices a serem processados*/
    while (cin >> n_vert, n_vert > 0) {
        fill(mat_acesseb[0], mat_acesseb[0] + MAX_N * MAX_N, 0);

        /*Enquanto houver um vértice inicial*/
        while (cin >> vert_ini, vert_ini) {

            /*Enquanto houver vértices relacionados ao vértice inicial*/
            while (cin >> vert, vert) mat_acesseb[vert_ini][vert] = 1;
        }

        cin >> n_verif;

        for (int i = 0; i < n_verif; ++i) {
            fill(acessaveis, acessaveis + MAX_N, false);
            cin >> vert;
            busca_em_prof(n_vert, vert);

            /*Pressuponha que o vértice atual não pode acessar nenhum outro*/
            vert_inacess[vert] = n_vert;

            /*Para cada vértice acessível a partir do atual, decremente o
             * número de vértices inacessíveis*/
            for (int j = 1; j <= n_vert; ++j) vert_inacess[vert] -= acessaveis[j];
            cout << vert_inacess[vert];

            /*Para cada vértice associado, se ele não for acessível a partir
             * do inicial, imprima-o*/
            for (int j = 1; j <= n_vert; ++j) if (!acessaveis[j]) cout << ' ' << j;
            cout << endl;
        }
    }
}