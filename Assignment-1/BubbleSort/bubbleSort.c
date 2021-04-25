#include "bubbleSort.h"
void bubblesort(long int *a,long int n)
{
   for (long int i = 0; i < n-1; i++)      
    {  
    for (long int j = 0; j < n-i-1; j++)  
        {
            if (a[j] > a[j+1])  
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    FILE *fp;
    fp = fopen("bubbleSortOutput4", "w+");
    for(long int k=0;k<n;k++)
    {   
        fprintf(fp, "%ld ",a[k]);
    }
}