// Prim's Algorithm in C

#include <stdio.h>
#include <stdbool.h>

#define INF 9999999
#define V 5

int G[V][V] = {
    {0, 1, 7, 0, 0},
    {1, 0, 5, 4, 3},
    {7, 5, 0, 0, 6},
    {0, 4, 0, 0, 2},
    {0, 3, 6, 2, 0}};

int main()
{
  int edge_no;
  int total_cost = 0;
  int selected[V];

  memset(selected, false, sizeof(selected));

  edge_no = 0;
  selected[0] = true;

  int x; //  row number
  int y; //  col number
  printf("Aresta : Peso\n");

  while (edge_no < V - 1)
  {

    int min = INF;
    x = 0;
    y = 0;
    int i, j;

    for (i = 0; i < V; i++)
    {
      if (selected[i] == true) //verifica se o vértice  I já foi selecionado para árvore 
      {
        for (j = 0; j < V; j++)
        {
          if (!selected[j] && G[i][j]) //verifica se o vértice J não foi selecionado para árvore e se existe uma conexão entre I e J.
          {
            if (min > G[i][j]) //verifica se a conexão é menor que min.
            {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    total_cost += G[x][y];
    selected[y] = true;
    edge_no++;
  }
  printf("Total Cost: %d", total_cost);
  return 0;
}
