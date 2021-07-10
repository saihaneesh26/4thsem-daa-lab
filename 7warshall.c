#include<stdio.h>
#include<stdlib.h>

//warshalls transitive closure
void main()
{
    int i,j,k,v=4;
    int graph[4][4] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
    int reach[v][v];//result
    for(i=0;i<v;i++)
    {
        for(j=0;j<4;j++)
        {
            reach[i][j]=graph[i][j]; // copy same
        }
    }
   
    
    for(k=0;k<v;k++)
    {
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                reach[i][j]=reach[i][j] || (reach[i][k]&&reach[k][j]);
            }
        }
    }
    
    //print
    for(i=0;i<v;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i==j)
            printf("1 ");
            else
           printf("%d ",reach[i][j]);

        }printf("\n");
    }

}
