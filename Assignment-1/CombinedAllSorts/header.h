#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 110000
void bubblesort(long int *a,long int n);
void insertionSort(long int *a, long int n);
void merge(long int *a, int l, int m, int r);
void mergeSort(long int *a, int l, int r);
void quickSort(long int *a,int first,int last);
void selectionSort(long int *a, long int n);
void print();
void print1();