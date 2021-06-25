#include<stdio.h>
#include<stdlib.h>

void merge(int l,int m,int r,int a[])
{
    int s1=m-l+1;
    int s2=r-m;
    int b[s1];
    int c[s2];

    for(int u=0;u<s1;u++)b[u]=a[l+u];
    for(int v=0;v<s2;v++)c[v]=a[m+1+v];

    int i=0,j=0,k=l;
    while(i<s1&&j<s2)
    {
        if(b[i]<=c[j])
        {
            a[k]=b[i];
            i++;
        }
        else
        {
            a[k]=c[j];
            j++;
        }
        k++;
    }
    while(i<s1)
    {
        a[k]=b[i];
        i++;k++;
    }
    while(j<s2)
    {
        a[k]=c[j];
        j++;
        k++;
    }
}
void mergesort(int l,int r,int a[])
{
    if(l<r){
       int m = (l + r) /2;
        mergesort(l,m,a);
        mergesort(m+1,r,a);
        merge(l,m,r,a);
    }
}
void main()
{
    int a[5];
    for(int i=0;i<5;i++)a[i]=5-i;
    int s=sizeof(a)/sizeof(a[0]);
    
    for(int i=0;i<s;i++)printf("%d ",a[i]);
    mergesort(0,s-1,a);
    for(int i=0;i<s;i++)printf("%d ",a[i]);

}