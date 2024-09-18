#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// estrutura do grafo
typedef struct {
  double **matriz; // Use double for edge weights
  char *vertice;   // Changed to char since we are storing chars
  int tam;
} Grafo;

// define o tamanho do grafo
Grafo *criar_grafo(int tam) {
  Grafo *grafo = malloc(sizeof(Grafo));
  grafo->tam = tam;
  grafo->matriz = malloc(tam * sizeof(double *));

  for (int i = 0; i < tam; i++) {
    grafo->matriz[i] = calloc(tam, sizeof(double));
  }
  grafo->vertice = malloc(tam * sizeof(char));
  return grafo;
}

// define a distância das arestas entre um vértice e outro
void cria_arestas(Grafo *grafo, int u, int v, double distancia) {
  if (u >= 0 && u < grafo->tam && v >= 0 && v < grafo->tam) {
    grafo->matriz[u][v] = distancia;
    grafo->matriz[v][u] = distancia; // Assume undirected graph
  }
}

// cria os vértices na matriz
void cria_vertices(Grafo *grafo, int vertices, char alfa) {
  if (vertices >= 0 && vertices < grafo->tam) {
    grafo->vertice[vertices] = alfa;
  }
}

// define a distância mínima de um vértice para o outro
int distancia_minima(double distancia[], bool visitado[], int tam) {
  int min_indice = -1;
  double min = INT_MAX;

  for (int v = 0; v < tam; v++) {
    if (!visitado[v] && distancia[v] < min) {
      min = distancia[v];
      min_indice = v;
    }
  }
  return min_indice;
}

void dijkstra(Grafo *grafo, char ini_vertice) {
  int inicio = -1;
  for (int i = 0; i < grafo->tam; i++) {
    if (grafo->vertice[i] == ini_vertice) {
      inicio = i;
      break;
    }
  }

  double distancia[grafo->tam];
  bool visitado[grafo->tam];

  for (int i = 0; i < grafo->tam; i++) {
    distancia[i] = INT_MAX;
    visitado[i] = false;
  }

  distancia[inicio] = 0;

  for (int count = 0; count < grafo->tam - 1; count++) {
    int u = distancia_minima(distancia, visitado, grafo->tam);
    visitado[u] = true;

    for (int v = 0; v < grafo->tam; v++) {
      if (!visitado[v] && grafo->matriz[u][v] && distancia[u] != INT_MAX &&
          distancia[u] + grafo->matriz[u][v] < distancia[v]) {
        distancia[v] = distancia[u] + grafo->matriz[u][v];
      }
    }
  }

  // After processing all vertices, print distances
  for (int i = 0; i < grafo->tam; i++) {
    printf("Menor caminho de %c para %c => %.2f \n\n", ini_vertice,
           grafo->vertice[i], distancia[i]);
  }
}

void free_grafo(Grafo *grafo) {
  for (int i = 0; i < grafo->tam; i++) {
    free(grafo->matriz[i]);
  }
  free(grafo->matriz);
  free(grafo->vertice);
  free(grafo);
}

int main() {
  // define o tamanho do grafo
  Grafo *grafo = criar_grafo(7);

  // define as posições e os vértices
  cria_vertices(grafo, 0, 'A');
  cria_vertices(grafo, 1, 'B');
  cria_vertices(grafo, 2, 'C');
  cria_vertices(grafo, 3, 'D');
  cria_vertices(grafo, 4, 'E');
  cria_vertices(grafo, 5, 'F');
  cria_vertices(grafo, 6, 'G');

  // define as distâncias das arestas adjacentes
  cria_arestas(grafo, 0, 1, 13.52);
  cria_arestas(grafo, 0, 2, 23.71);
  cria_arestas(grafo, 1, 2, 5.08);
  cria_arestas(grafo, 1, 3, 12.15);
  cria_arestas(grafo, 1, 4, 12.15);
  cria_arestas(grafo, 2, 4, 2.0);
  cria_arestas(grafo, 3, 4, 58.32);
  cria_arestas(grafo, 3, 5, 32.55);
  cria_arestas(grafo, 4, 5, 5.95);
  cria_arestas(grafo, 4, 6, 35.88);
  cria_arestas(grafo, 5, 6, 18.25);

  printf("Distancia do vertice ");
  dijkstra(grafo, 'A');

  free_grafo(grafo);
  return 0;
}
