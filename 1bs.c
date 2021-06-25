#include<stdio.h>

void main()
{
    int a[10];
    int l=10;
    for(int i=0;i<=9;i++)
    {
        a[i]=10-i;
    }

    //bs

    for(int i=0;i<=l-1;i++)
    {
        for(int j=0;j<=l-2;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<=9;i++)
    {
        printf("%d\n",a[i]);
    }
    

}