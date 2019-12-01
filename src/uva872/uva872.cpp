/* Problema #872 - Ordering
 * Autores:
 *  Antônio Carlos Durães da Silva
 */
#include <iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;

vector<char> letras;
map<char, bool> visitados;
map<char, vector<char>> map_vizinhos;

bool sem_vizinhos_visitados(char vertice) {
    for (char vert : map_vizinhos[vertice]) if(visitados[vert]) return false;
    return true;
}

bool dfs_backtrack(string str_verts) {
    bool resp_encontrada = str_verts.length() == letras.size();

    /*Se encontrou uma das respostas, então imprima-a*/
    if (resp_encontrada) {
        for(int i = 0; i < str_verts.length() - 1; ++i) cout << str_verts[i] << ' ';
        cout << str_verts[str_verts.length() - 1] << endl;
        return true;
    }

    /*Para cada letra, se ela não foi visitada E não tiver algum vizinho visitado*/
    for (char letra : letras) {
        if(!visitados[letra] and sem_vizinhos_visitados(letra)) {
            visitados[letra] = true;
            resp_encontrada = dfs_backtrack(str_verts + letra) || resp_encontrada;
            visitados[letra] = false;
        }
    }
    return resp_encontrada;
}


int main() {
    int n_testes;
    string linha;
    char fim_linha;
    cin >> n_testes;

    while(n_testes-- and scanf("%c\n", &fim_linha) and getline(cin, linha)) {
        letras.clear();
        map_vizinhos.clear();
        visitados.clear();

        for (char simb : linha) if (simb != ' ') letras.push_back(simb);

        sort(letras.begin(), letras.end());
        getline(cin, linha);

        for (int i = 0, tam = linha.size(); i < tam; i += 4) {
            map_vizinhos[linha[i]].push_back(linha[i+2]);
        }

        if (!dfs_backtrack("")) cout << (n_testes ? "NO\n\n" : "NO");
        else if (n_testes) cout << endl;
    }
}
