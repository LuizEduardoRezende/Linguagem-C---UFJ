#include <stdio.h>

#define MAX 30
#define VERTICES 5 // Definindo o número de vértices globalmente

typedef struct edge
{
  int u, v, w;
} edge;

typedef struct edge_list
{
  edge data[MAX];
  int n;
} edge_list;

edge_list e_list;

// Inicializando a matriz de adjacência globalmente
int graph[VERTICES][VERTICES] = {
    {0, 1, 7, 0, 0},
    {1, 0, 5, 4, 3},
    {7, 5, 0, 0, 6},
    {0, 4, 0, 0, 2},
    {0, 3, 6, 2, 0}};

int n = VERTICES; // Usando o número de vértices definido globalmente
edge_list spanlist;

// Usando Krushkal Algorithm
void kruskalAlgorithm()
{
  int belongs[MAX], i, j, cno1, cno2;
  e_list.n = 0;

  for (i = 1; i < n; i++) // 1 até o número de vértices
    for (j = 0; j < i; j++) // Percorre toda matriz com os pesos
    {
      if (graph[i][j] != 0)
      {
        e_list.data[e_list.n].u = i;
        e_list.data[e_list.n].v = j;
        e_list.data[e_list.n].w = graph[i][j];
        e_list.n++;
      }
    }

  sort();

  for (i = 0; i < n; i++)
    belongs[i] = i;

  spanlist.n = 0;

  for (i = 0; i < e_list.n; i++) // Percorre todas arestas do grafo
  {
    cno1 = find(belongs, e_list.data[i].u);
    cno2 = find(belongs, e_list.data[i].v);

    if (cno1 != cno2) //verifica se os vértices da aresta atual são de grupos diferentes, se fossem do mesmo grupo seria um ciclo
    {
      spanlist.data[spanlist.n] = e_list.data[i]; //aresta é colocada na árvore geradora mínima(spanlist)
      spanlist.n = spanlist.n + 1;
      applyUnion(belongs, cno1, cno2); //o grupo dos vértices são unidos
    }
  }
}

void applyUnion(int belongs[], int c1, int c2)
{
  int i;

  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

int find(int belongs[], int vertexno)
{
  return (belongs[vertexno]);
}

// Printing the result
void print()
{
  int i, cost = 0;

  for (i = 0; i < spanlist.n; i++)
  {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
}

// Sorting algorithm para aas arestas.
void sort()
{
  int i, j;
  edge tmp;

  for (i = 1; i < e_list.n; i++)
    for (j = 0; j < e_list.n - 1; j++)
      if (e_list.data[j].w > e_list.data[j + 1].w)
      {
        tmp = e_list.data[j];
        e_list.data[j] = e_list.data[j + 1];
        e_list.data[j + 1] = tmp;
      }
}

int main()
{
  kruskalAlgorithm();
  print();
  return 0;
}
