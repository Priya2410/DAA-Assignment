#include "header.h"
int main()
{
    long int a[MAX_SIZE],b[MAX_SIZE],c[MAX_SIZE],d[MAX_SIZE],e[MAX_SIZE];
    clock_t start, end;
    double cpu_time_used;
    FILE *fp,*fp1,*fp2,*fp3,*fp4;
    fp=fopen("bubblesort.txt","a+");
    fp1=fopen("selectionsort.txt","a+");
    fp2=fopen("insertionsort.txt","a+");
    fp3=fopen("mergesort.txt","a+");
    fp4=fopen("quicksort.txt","a+");
    for(int i=0;i<MAX_SIZE;i++)
    {
        int num=rand();
        a[i]=num;
        b[i]=num;
        c[i]=num;
        d[i]=num;
        e[i]=num;
    }
    printf("INPUT SIZE %d\n",MAX_SIZE);

    start = clock();
    bubblesort(a,MAX_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(fp,"%d %lf\n",MAX_SIZE,cpu_time_used);

    start = clock();
    selectionSort(b,MAX_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(fp1,"%d %lf\n",MAX_SIZE,cpu_time_used);

    start = clock();
    insertionSort(c,MAX_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(fp2,"%d %lf\n",MAX_SIZE,cpu_time_used);

    start = clock();
    mergeSort(d,0,MAX_SIZE);
    print1();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(fp3,"%d %lf\n",MAX_SIZE,cpu_time_used);

    start = clock();
    quickSort(e,0,MAX_SIZE-1);
    print();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(fp4,"%d %lf\n",MAX_SIZE,cpu_time_used);
}