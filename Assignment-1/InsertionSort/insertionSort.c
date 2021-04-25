#include "insertionSort.h"
void insertionSort(long int *a, long int n) 
{ 
    long int key;
    long int j;
    for (long int i = 1; i < n; i++) { 
        key =a[i]; 
        j = i - 1; 
        while (j >= 0 &&a[j] > key) { 
        a[j + 1] =a[j]; 
            j = j - 1; 
        } 
    a[j + 1] = key; 
    } 

    FILE *fp;
    fp = fopen("insertionSortOutput4", "w+");
    for(long int k=0;k<n;k++)
    {   
        fprintf(fp, "%ld ",a[k]);
    }
}