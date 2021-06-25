#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[low]; 
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

void quicksort(int arr[], int low, int high)
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
    int arr[] = {7, 6, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr,0,n-1);
for(int i=0;i<n;i++)printf("%d ",arr[i]);
}