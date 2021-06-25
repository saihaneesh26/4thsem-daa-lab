#include<stdio.h>

void max_heap(int arr[],int n,int i)
{
    int largest =i;
    int l = 2*i+1;
    int r = 2*i+2;
    
    if(l<n && arr[l]>arr[largest])
    largest=l;
    if(r<n&&arr[r]>arr[largest])
    largest=r;
    if(largest!=i)
    {
        int t = arr[largest];
        arr[largest]=arr[i];
        arr[i]=t;
        max_heap(arr,n,largest);
    }
}

void heapsort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        max_heap(arr,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        int t=arr[0];
        arr[0]=arr[i];
        arr[i]=t;
        max_heap(arr,i,0);
    }
}

void main()
{
    int arr[]={12,11,13,6,5,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
}