#include "header.h"

void bubblesort(long int *a,long int n)
{
    FILE *fp;
    fp=fopen("bubblesortcomparison.txt","a+");
   long long int comp=0;
   for (long int i = 0; i < n-1; i++)      
    {  
    for (long int j = 0; j < n-i-1; j++)  
        {
            comp+=1;
            if (a[j] > a[j+1])  
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    fprintf(fp,"%ld %lld\n",n,comp);

    FILE *fp1;
    fp1= fopen("CombinedInput10", "w+");
    for(long int k=0;k<n;k++)
    {   
        fprintf(fp1, "%ld ",a[k]);
    }
}