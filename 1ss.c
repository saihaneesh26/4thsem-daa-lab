#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
    int i,k;
   for(i=1;i<10;i++)
    {
        int n=1000*i;
         int arr[n];
        for(k=0;k<n;k++)
        {
            int r = rand();
            arr[k]=11-k;
        }
        double start = clock();
        {
            for(int j=0;j<n-1;j++)
            {
                int temp = arr[j];
                int min = j;
                for(int k=j+1;k<n;k++)
                {
                    if(arr[k]<arr[min])
                    {
                        min = k;
                    }
                }
                arr[j] = arr[min];
                arr[min]= temp;
            }
        }
        double end = clock();
        double time = (end-start)/CLOCKS_PER_SEC;
        printf("n:%d time:%lfs\n",n,time);
    }
}
