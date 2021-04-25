#include "selectionSort.h"
int main()
{
    long int a[MAX_SIZE];
    clock_t start, end;
    double cpu_time_used;
    for(int i=0;i<MAX_SIZE;i++)
    {
        a[i]=rand();
    }
    start = clock();
    selectionSort(a,MAX_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("TIME TAKEN %lf",cpu_time_used);
}