#include<stdio.h>
#define n 4

int graph[n][n];


int safe(int row,int col)
{
    //row check on left bcoz we place from left to right
    for(int i=0;i<col;i++)
    {
        if(graph[row][i])
        return 0;
    }
    for(int i=row,j=col;i>=0,j>=0;i--,j--)
    {
        if(graph[i][j]==1)
        return 0;
    }
    for(int i=row,j=col;i<n,j>=0;i++,j--)
    {
        if(graph[i][j]==1)
        return 0;
    }
    return 1;
}

int nqueens(int col)
{
    
    if(col==n)
        return 1;//base case
    for(int i=0;i<n;i++)
    {
        if(safe(i,col))
         {
            graph[i][col]=1;
            if(nqueens(col+1))//next col
                return 1;
            else
            {
                graph[i][col]=0; // not correct soln
            }
        }
    }
    return 0;

}

void main()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;//init with 0
        }
    }
    int res =nqueens(0);// let start be 0 col
    if(res == 0)
    {
        printf("no soln\n");
    }else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                printf("%d ",graph[i][j]);
            printf("\n");
        }
    }
}