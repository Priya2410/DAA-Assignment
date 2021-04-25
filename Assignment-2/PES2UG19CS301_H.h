#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Node
{
    // Required:vertex ID,Weight,pointer,path dist,previous vertex ID
    int id,weight,d,pre;
    struct Node* next;
}Node;

//Header node
typedef struct Head
{
    Node* head;
    int pre,d; // id of previous vertex in graph and length of shortest path
}Head;

//defining the graph
typedef struct Graph
{
    int n;
    Head* graph;
}Graph;

typedef struct Heap
{
    int n;
    Node*heap;
}Heap;

typedef struct Path
{
    Node* head;
    int d; 
} Path;

typedef struct Paths
{
    int n; // Number of vertices
    Path* paths;
}Paths;

Graph* initialize(int size);
Graph* input(void);
Graph* Dijkstra(Graph* g, Heap* h);
Head insert(Head head, int id, int weight);
Heap* create(int size);
Heap* delete(Heap* h, int* del);
Heap* update(Heap* h);
Heap* update_distance(Heap* h, int id, int d);
Node* check_outgoing(Graph* g, int* visited, int id);
Node* insert_path(Node* head, int id);
void display_output(Graph* g);
int* reset(int* arr, int size);