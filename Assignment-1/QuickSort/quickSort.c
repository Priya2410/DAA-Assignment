#include "quickSort.h"
void quickSort(int *a,int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
            i++;
         while(a[j]>a[pivot])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quickSort(a,first,j-1);
      quickSort(a,j+1,last);

   }
}

void insert(int *a,int n)
{
    FILE *fp;
    fp = fopen("quickSortOutput4", "w+");
    for(int k=0;k<n;k++)
    {   
        fprintf(fp, "%d ",a[k]);
    }
}