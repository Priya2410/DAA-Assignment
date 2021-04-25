#include "PES2UG19CS301_H.h"

int main(void)
{
    Graph*g=input(); 
    Heap*h=create(g->n); 
    g=Dijkstra(g,h);
    display_output(g);
}