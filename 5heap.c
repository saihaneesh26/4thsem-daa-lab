#include<stdio.h>
#include<time.h>
#include<stdlib.h>

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
int i;
    for( i=n/2-1;i>=0;i--)
    {
        max_heap(arr,n,i);
    }
    for( i=n-1;i>0;i--)
    {
        int t=arr[0];
        arr[0]=arr[i];
        arr[i]=t;
        max_heap(arr,i,0);
    }
}

void main()
{
	int i,n;
for(i=1;i<=10;i++){
	n=10000*i;
    int arr[n];
double st = clock();  
  heapsort(arr,n);
double e = clock();
double t = (e-st)/CLOCKS_PER_SEC;
printf("n:%d -- time:%lf\n",n,t);
//    for(int i=0;i<10;i++)printf("%d ",arr[i]);
}
}


