#include "header.h"
void selectionSort(long int *a, long int n) 
{ 
    int min,temp;
    long long int comp=0;
    for (long int i = 0; i < n - 1; i++) { 
        min= i; 
        for (long int j = i + 1; j < n; j++)
        { 
            comp+=1;
            if (a[j] < a[min]) 
            {   
                min = j; 
            }
        }

        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    } 

    FILE *fp;
    fp=fopen("selectionsortcomparison.txt","a+");
    fprintf(fp,"%d %lld\n",MAX_SIZE,comp);
} 
 