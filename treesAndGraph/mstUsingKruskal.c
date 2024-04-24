#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct {
    int rank;
    int parent;
} Subset;

int compare(const void* a, const void* b) {
    return ((Edge*)a)->weight > ((Edge*)b)->weight;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void KruskalMST(Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(edges[0]), compare);

    Subset* subsets = (Subset*) malloc(V * sizeof(Subset));

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    Edge* result = (Edge*) malloc((V - 1) * sizeof(Edge));
    int e = 0;
    int i = 0;

    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    Edge edges[E];

    // add edge 0-1
    edges[0].src = 0;
    edges[0].dest = 1;
    edges[0].weight = 10;

    // add edge 0-2
    edges[1].src = 0;
    edges[1].dest = 2;
    edges[1].weight = 6;

    // add edge 0-3
    edges[2].src = 0;
    edges[2].dest = 3;
    edges[2].weight = 5;

    // add edge 1-3
    edges[3].src = 1;
    edges[3].dest = 3;
    edges[3].weight = 15;

    // add edge 2-3
    edges[4].src = 2;
    edges[4].dest = 3;
    edges[4].weight = 4;

    KruskalMST(edges, V, E);

    return 0;
}