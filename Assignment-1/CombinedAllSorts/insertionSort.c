#include "header.h"
void insertionSort(long int *a, long int n) 
{ 
    long int key;
    long int j;
    long int comp=0;
    FILE *fp;
    fp=fopen("insertionsortcomparsion.txt","a+");
    for (long int i = 1; i < n; i++) { 
        key =a[i]; 
        j = i - 1; 
        comp+=1;
        while (j >= 0 &&a[j] > key) { 
        a[j + 1] =a[j]; 
            j = j - 1; 
        } 
    a[j + 1] = key; 
    } 

    fprintf(fp,"%ld %ld\n",n,comp);
}