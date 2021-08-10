#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(long int* a,long int* b)
{
  long  int t = *a;
    *a = *b;
    *b = t;
}

int partition (long int arr[], int low, int high)
{
  long  int pivot = arr[low]; 
    int idx = low;
    int i = low+1; // Index of smaller element and indicates the right position of pivot found so far
    int j = high;
    while(i<j)
    {
        while(pivot<arr[j])
        j--;
        while(arr[i]<pivot)
        i++;        
       if(i<j) swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void quicksort(long int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void main()
{
int i,k,n;long int arr[100000];
for(k=1;k<=10;k++)
{
	n=10000*k;
	for(i=0;i<n;i++)
	{
		long int r = rand();
		arr[i] =r;
	}
double start = clock();
    quicksort(arr,0,n-1);
double end = clock();
double time = (end-start)/CLOCKS_PER_SEC;
printf("n:%d -- time:%lf\n",n,time);
}
}




