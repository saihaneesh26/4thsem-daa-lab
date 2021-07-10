#include<stdio.h>
#define v 4
#define INF 999

void main()
{
    int graph[v][v] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
    int res[v][v],i,j,k;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            res[i][j]=graph[i][j];//copy
        }
    }
    for(k=0;k<v;k++)
        for(i=0;i<v;i++)
            for(j=0;j<v;j++)
                if(res[i][k]+res[k][j]<res[i][j]) // find min and append min
                    res[i][j]=res[i][k]+res[k][j];
    //print
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
            {if(res[i][j]==INF)
                printf("INF ");
            else
                printf("%d ",res[i][j]);
            }
            printf("\n");
    }
}
