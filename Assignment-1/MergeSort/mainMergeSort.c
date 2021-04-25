#include "mergeSort.h"
int main()
{
    int a[MAX_SIZE];
    clock_t start, end;
    double cpu_time_used;
    for(int i=0;i<MAX_SIZE;i++)
    {
        a[i]=rand();
    }
    start = clock();
    mergeSort(a,0,MAX_SIZE);
    insert(a,MAX_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("TIME TAKEN %lf",cpu_time_used);
}
