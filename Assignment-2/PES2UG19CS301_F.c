#include "PES2UG19CS301_H.h"
#define inf INT_MAX

//Function to initialize the graph
Graph* initialize(int size)
{
    Graph *g=(Graph*)malloc(sizeof(Graph));  // Create a GRAPH

    g->n=size;
    g->graph=malloc(size * sizeof(Node));

    for (int i=0;i<size;i++)
    {
        g->graph[i].head=NULL;
        g->graph[i].pre=0;
        g->graph[i].d=inf;
    }
    return g;
}

// Inserting graphs to adjacency list
Head insert(Head head, int id, int weight)
{
    // Creating a new node with id and weight
    Node* newpath = malloc(sizeof(Node));
    newpath->id = id;
    newpath->weight = weight;
    newpath->next = NULL;
    newpath->d = inf;
    newpath->pre = 0; //nodes start from 1.0 indicates no previous node in the path

    if (head.head == NULL)
                head.head = newpath;  //case when the list is empty
    else
    {
        Node*t = head.head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = newpath;
    }
    return head;
}


Heap* create(int size)
{
    Heap*ele=(Heap*)malloc(sizeof(Heap));
    ele->n = size - 1;

    ele->heap=malloc((ele->n + 1) * sizeof(Node));

    for (int i = 0; i < ele->n; i++)
    {
        ele->heap[i].id = i + 1;
        ele->heap[i].d = inf;
        ele->heap[i].pre = 0;
    }
    return ele;
}


Heap* delete(Heap* element, int* del)
{
    *del = element->heap[0].id;

    for (int i = 0; i < (element->n - 1); i++)
    {
        element->heap[i] = element->heap[i + 1];
    }
    element->n--;
    return element;
}

Heap* update(Heap* element)
{
    Node t;

    for (int i = 0; i < element->n - 1; i++)
    {
        int counter = 0;
        
        for (int j = 0; j < (element->n - i - 1); j++)
        {
            if (element->heap[j].d > element->heap[j + 1].d)
            {
                t = element->heap[j];
                element->heap[j] = element->heap[j + 1];
                element->heap[j + 1] = t;
                counter ++;
            }
        }
        if (counter == 0)
                    break;
    }
    return element;
}

Node* check_outgoing(Graph* gr, int* visited, int id)
{
    Node* t = gr->graph[id].head;

    while (t != NULL)
    {
        if (visited[t->id] == 0)
            return t;
        t = t->next;
    }
    return NULL;
}

Heap* update_distance(Heap* element, int id, int d)
{
    for (int i = 0; i < element->n;i++)
    {
        if (element->heap[i].id == id)
        {
            element->heap[i].d = d;
            break;
        }
    }

    element= update(element);
    return element;
}
Graph* input(void)
{
    
    FILE* fp;
    fp=fopen("adjacencylist2.txt","r");

    if (fp == NULL) //If file isn't present
    {
        return NULL;
    }

    size_t size = 1000;

    char* num = malloc(1000 * sizeof(char));
    int fd=getline(&num,&size,fp);
    Graph* g = initialize(atoi(num)+1); 

    while(getline(&num,&size,fp) != -1)
    {
        
        char* token = strtok(num, " ");
        int node = atoi(token);

        int weight,v; //weight and vertex

        while (token != NULL)
        {
            // Get vertex token
            token = strtok(NULL," "); //Comparing tokens
            if (token == NULL)
                break;

            v=atoi(token);
            token=strtok(NULL," ");

            if (token == NULL)
                break;
            
            weight=atoi(token);
            g->graph[v] = insert(g->graph[v],node,weight);
        }
    }
    return g;
}

Graph* Dijkstra(Graph* graph, Heap* element)
{
    int src= graph->n - 1;

    element->heap[element->n - 1].d = 0;
    graph->graph[element->heap[element->n - 1].id].d = 0;
    element = update(element);

    int v[graph->n];
    for (int i = 1; i < graph->n;i++)
    {
        v[i] = 0;
    }
    v[graph->n - 1] = 1;
    int del;

    Node* n;

    for (int i = 1; i < (graph->n - 1);i++)
    {
        element = delete(element,&del);
        v[del] = 1;

        Node*t=graph->graph[del].head;

        while (t != NULL)
        {
            if ((graph->graph[del].d + t->weight) < (graph->graph[t->id].d))
            {
                graph->graph[t->id].d = graph->graph[del].d + t->weight;
                element = update_distance(element, t->id, graph->graph[t->id].d);
                graph->graph[t->id].pre = del;
            }
            t=t->next;
        }
    }
    return graph;
}

Node* insert_path(Node* head, int val)
{
    Node* newpath = malloc(sizeof(Node));
    newpath->id = val;
    newpath->next = NULL;

    if (head == NULL)
               head=newpath;
    else
    {
        Node* t = head;
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = newpath;
    }
    return head;
}

int* reset(int* arr,int size)
{
    for (int i = 1; i < size; i ++)
    {
        arr[i] = 0;
    }
    return arr;
}


void display_output(Graph* gr)
{
    Paths* p = malloc(sizeof(Paths));
    p->paths = malloc((gr->n - 1) * sizeof(Node));

    int src=gr->n-1;
    int* arr = malloc(src * sizeof(int));

    for (int i = 1; i < src; i ++)
    {
        if (gr->graph[i].pre != 0)
        {
            Node* newpath = malloc(sizeof(Node));
            newpath->id = i;
            newpath->next = NULL;
            p->paths[i].head = newpath; 
        }
        else
            p->paths[i].head = NULL;
    }

    for (int i=1; i < src; i ++)
    {
        int pre = gr->graph[i].pre;
        int j=0,k=0;
        arr = reset(arr,src);

        if (pre != 0)
        {
            while (pre != src)
            {
                arr[j] = pre;
                j++;
                pre =gr->graph[pre].pre;
            }
            arr[j] = pre;
        }
        while (k <= j && (arr[j]==src))
        {
            p->paths[i].head = insert_path(p->paths[i].head,arr[k]);
            k++;
        }
    }
    Node*t;

    for (int i = 1; i < src; i++)
    {
        t = p->paths[i].head;
        if (t == NULL)
               printf("%d NO PATH\n",i);
        else
        {
            printf("%d ",i);

            while (t != NULL)
            {
                printf("%d ",t->id);
                t = t->next;
            }
            printf("%d\n",gr->graph[i].d);
        }
    }
}