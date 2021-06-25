#include<stdio.h>

#define v 5
#define m 999

int graph[v][v]={   { 0, 2, 0, 6, 0 },  
                    { 2, 0, 3, 8, 5 },  
                    { 0, 3, 0, 0, 7 },  
                    { 6, 8, 0, 0, 9 },  
                    { 0, 5, 7, 9, 0 } };
int visited[v]={0,0,0,0,0};
int w[v]={0,m,m,m,m};
int parent[v]={-1,-1,-1,-1,-1};

int min_arr(int arr[])
{
   int index = 0;
   for(int i=1;i<v;i++)
   {
       if(arr[i]<arr[index])
       {
           index=i;
       }
   }
    return index;
}

void prims()
{
    //start node is taken as 0
    visited[0]=1;
    for(int i=0;i<v;i++)
    {
        int index = min_arr(graph[i]); //min wt to connected nodes from given node i;
        visited[index]=1;//make index as visited
        for(int j=0;j<v;j++)
        {
            if(visited[j]!=1 && w[j]>graph[index][j] && graph[index][j]!=0) // the node is not visited and wt is more than graph wt and graph wt is not zero implying route exist
            {
                parent[j]=index;
                w[j]=graph[index][j];
            }
        }
    }

}

void main()
{
    prims();
    for(int i=0;i<v;i++)
    printf("%d - %d : %d\n",parent[i],i,w[i]);
}