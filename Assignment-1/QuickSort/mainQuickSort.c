#include "quickSort.h"
int main()
{
    int a[MAX_SIZE];
    time_t t;
    clock_t start, end;
    double cpu_time_used;
    srand((unsigned) time(&t));
    for(int i=0;i<MAX_SIZE;i++)
    {
        a[i]=rand();
    }
    start = clock();
    quickSort(a,0,MAX_SIZE-1);
    insert(a,MAX_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("TIME TAKEN %lf",cpu_time_used);
}
