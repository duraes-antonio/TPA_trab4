def buscLarg(no, visitadoF, grafoF): #DADO UM Nó marca como visitado todos os nós do Grafo que contem esse nó
  visitadoF[no] = 1 #Marca no grafo de visitados a posicao visitada com 1
  for i in grafoF[no]: #Loop nos nós conectados ao NO passado como parametro em BuscLarg
      if visitadoF[i] == 0:  #Verifica se ainda tem nó não marcado com 1 em visitado
          buscLarg(i, visitadoF, grafoF) #Chama buscLarg para o nó do loop
  return 0

def main():
    entrada = "NELSON"
    qtdExec = int(input().strip())
    input()
    while qtdExec > 0:
        qtdExec = qtdExec - 1
        nos = ord(input().strip()) - 64 #Quantidade total de nós essa execucao vai ter
        grafo = [[] for x in range(nos+1)]
        visitado = [0 for x in range(nos+1)]
        subgrafo = 0
        entrada = input().strip()
        while entrada != '':
            valorLetra1 = ord(entrada[0]) - 64 #Valor do No1 em int
            valorLetra2 = ord(entrada[1]) - 64 #Valor do No2 em int
            grafo[valorLetra1].append(valorLetra2) #Relaciona o valor do No2 com o No1(Faz a ligação entre eles)
            grafo[valorLetra2].append(valorLetra1) #Relaciona o valor do No1 com o No2(Faz a ligação entre eles)
            try:
                entrada = input().strip()
            except(EOFError):
                break           

        for i in range(1,nos+1): #Varre todos os nós
            if visitado[i] == 0:  #Verifica se algum deles ainda não foi visitado
                buscLarg(i, visitado, grafo) # Se não for visitado chama buscLarg para visitar
                subgrafo = subgrafo + 1 #Adicionar 1 ao contador de grafos

        print(subgrafo)
        if qtdExec > 0:
            print()

    return 0

main()

