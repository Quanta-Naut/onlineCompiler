#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERT 6
#define MAX_EDGE 9

struct Edge{
    int src,dest,weight;
};

struct Subset{
    int parent;
    int rank;
};

struct Graph{
    int V,E;
    struct Edge edges[MAX_EDGE];
};

void initGraph(int Graph[][MAX_VERT], int n, struct Graph* graph) {
    graph->V = n;
    graph->E = 0; // Since we're not explicitly providing the number of edges, initialize it to 0.

    // Copying the given data into the graph's edges array
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (Graph[i][j] != 0) {
                // Add the edge to the graph
                graph->edges[graph->E].src = i;
                graph->edges[graph->E].dest = j;
                graph->edges[graph->E].weight = Graph[i][j];
                graph->E++; // Increment the edge count
            }
        }
    }
}

int find(struct Subset subsets[], int i){
    if(subsets[i].parent != i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    int xrank = subsets[xroot].rank;
    int yrank = subsets[yroot].rank;

    if(xrank < yrank){
        subsets[xroot].parent = yroot;
    }
    else if(yrank < xrank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void bubbleSort(struct Edge edges[], int n){
    for(int i = 0; i< n-1;i++){
        for(int j =0; j < n-i-1; j++){
            if(edges[j].weight > edges[j+1].weight){
                struct Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

void KruskalMST(struct Graph* graph){
    int V = graph->V;
    struct Edge result[MAX_VERT];
    int e = 0;

    bubbleSort(graph->edges, graph->E);

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    for(int v = 0; v < V; v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for(int i = 0; i < graph->E && e < V-1; i++){

        struct Edge next_edge = graph->edges[i];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if(x != y){
            result[e++] = next_edge;
            Union(subsets, x ,y);
        }
    }
    int totalWeight = 0;
    for (int i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

int main() {
    int Graph[6][6] = {
        {0, 4, 4, 0, 0, 0},
        {4, 0, 2, 0, 0, 0},
        {4, 2, 0, 3, 4, 0},
        {0, 0, 3, 0, 3, 0},
        {0, 0, 4, 3, 0, 0},
        {0, 0, 2, 0, 3, 0}
    };
    struct Graph graph;

    initGraph(Graph, 6, &graph);
    KruskalMST(&graph);

    return 0;
}