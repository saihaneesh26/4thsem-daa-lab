#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
int n=1000;
    int a[n];
int i,j;
    for( i=0;i<=n-1;i++)
    {
	int r = rand();
        a[i]=r;
    }

    //bs
double start = clock();

    for( i=0;i<=n-1;i++)
    {
        for( j=0;j<=n-2-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
double end = clock();
double t = (end-start)/CLOCKS_PER_SEC;
printf("n:%d -- total:%e\n",n,t);
}
