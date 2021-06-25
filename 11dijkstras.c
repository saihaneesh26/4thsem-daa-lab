#include<stdio.h>

#define v 9
#define m 99
int w[v] ={m,m,m,m,m,m,m,m,m};
int visited[v]={0,0,0,0,0,0,0,0,0};
int graph[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
int min_arr(int arr[])
{
    //min wt array which is not visited
    int index = 0;
    int min= m;

    for(int i=0;i<v;i++)
    {
        if(!visited[i] && w[i]<=min)
        {
            index = i;
            min = w[i];
        }
    }
    return index;
}

void dijkstras()
{
   
    
    w[0]=0;//considering start as 0

    for(int i=0;i<v;i++)
    {
        int index = min_arr(graph[i]);
        visited[index]=1;
        for(int j=0;j<v;j++)
        {
            if(!visited[j] && graph[index][j] && w[index] !=m && w[index]+graph[index][j] < w[j])
            {
                w[j] = w[index]+graph[index][j];
            }
        }

    }
}

void main()
{
    dijkstras();
    for(int i=0;i<v;i++)
    printf("%d : %d\n",i,w[i]);
}