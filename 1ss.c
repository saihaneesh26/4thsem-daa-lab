//selection sort
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
    int i,k;
   for(i=1;i<11;i++)
   {
        int n=10000*i;
         int arr[n];
        for(k=0;k<n;k++)
        {
            int r = rand();
            arr[k]=r;
        }
        double start = clock();
        {
            for(int j=0;j<n-1;j++)
            {
                 int temp = arr[j];
                int min = j;
                for(int k=j+1,k<n-1;k++)
                {
                    if(arr[k]<min)
                    {
                        min = k;
                    }
                }
                arr[j] = arr[k];
                arr[k]= temp;
            }
        }
        double end = clock();
        double time = (end-start)/CLOCKS_PER_SEC;
        printf("n:%d time:%lf\n",n,time);
   }
}
