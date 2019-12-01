#include <iostream>
#include <cmath>
#define MAX_N 100

using namespace std;

int n_casos, n_vert, vert_min, visitados[MAX_N];
pair<double, double> pts[MAX_N];
double x, y, minimo, soma_pesos, dists[MAX_N];

double calc_dist(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2));
}

double dijkstra() {
    fill(dists, dists + n_vert, MAXFLOAT);
    fill(visitados, visitados + n_vert, 0);
    vert_min = soma_pesos = dists[0] = 0;

    while (!visitados[vert_min]++) {
        soma_pesos += dists[vert_min];

        for (int i = 0; i < n_vert; ++i) {
            if (!visitados[i]) dists[i] = min(calc_dist(pts[vert_min], pts[i]), dists[i]);
        }

        vert_min = 0;
        minimo = MAXFLOAT;

        for (int i = 0; i < n_vert; ++i) {
            if (!visitados[i] and dists[i] < minimo) {
                vert_min = i;
                minimo = dists[i];
            }
        }
    }
    return soma_pesos;
}

int main() {
    cin >> n_casos;

    while (n_casos--) {
        scanf("\n\n%d\n", &n_vert);

        for (int i = 0; i < n_vert; ++i) {
            cin >> x >> y;
            pts[i] = make_pair(x, y);
        }
        printf(n_casos ? "%.2f\n\n" : "%.2f\n", dijkstra());
    }

    return 0;
}