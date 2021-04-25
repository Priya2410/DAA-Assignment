#include "selectionSort.h"
void selectionSort(long int *a, long int n) 
{ 
    int min,temp;
    for (long int i = 0; i < n - 1; i++) { 
        min= i; 
        for (long int j = i + 1; j < n; j++)
        { 
            if (a[j] < a[min]) 
                min = j; 
        }

        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    } 

    FILE *fp;
    fp = fopen("selectionSortOutput4", "w+");
    for(int k=0;k<n;k++)
    {   
        fprintf(fp, "%ld ",a[k]);
    }
} 
 