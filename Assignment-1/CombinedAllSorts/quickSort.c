#include "header.h"
long int comp1=0;
void quickSort(long int *a,int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         comp1+=1;
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
void print()
{
   FILE *fp;
    fp=fopen("quicksortcomparison.txt","a+");
    fprintf(fp,"%d %ld\n",MAX_SIZE,comp1);
}
