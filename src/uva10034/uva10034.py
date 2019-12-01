# Problema #10034 - Freckles
# Autores:
#   Antônio Carlos Durães da Silva
import sys

MAX_N = 100
P = [(0, 0)]*100
n = 0
dists = [0] * MAX_N
visitados = [False] * MAX_N

def calc_dist_euclid(x1, y1, x2, y2):
    return ((x1 - x2)**2 + (y1 - y2)**2)**0.5

def dikjstra():
    vert = 0
    soma_pesos = 0

    for i in range(n):
        dists[i] = sys.maxsize
        visitados[i] = False

    dists[0] = 0

    while (not visitados[vert]):
        visitados[vert] = True
        soma_pesos += dists[vert]

        for i in range(n):
            if (not visitados[i]):
                dist = calc_dist_euclid(P[vert][0], P[vert][1], P[i][0], P[i][1])

                if(dist < dists[i]): dists[i] = dist

        vert = 0
        minimo = sys.maxsize

        for i in range(n):
            if (not visitados[i] and dists[i] < minimo):
                vert = i
                minimo = dists[i]
    return soma_pesos

def main():
    n_casos = int(input())
    input()
    global n

    try:
        for i in range(n_casos):
            n = int(input())

            for j in range(n):
                par_num = input().strip().split(' ')
                P[j] = (float(par_num[0]), float(par_num[1]))

            print("%.2f" %dikjstra())
            if (i < (n_casos - 1)): print()
            input()

    except EOFError: exit(0)
    return 0

main()
