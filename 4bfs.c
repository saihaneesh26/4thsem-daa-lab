#include<stdio.h>
#include<stdlib.h>
int matrix[8][8] =    {//a,b,c,d,e,f,g,h
                        {0,1,0,1,0,0,0,0},//a
                        {0,0,1,0,1,0,1,0},//b
                        {1,0,0,0,0,0,0,0},//c
                        {0,0,1,0,0,0,0,0},//d
                        {0,0,0,0,0,0,0,1},//e
                        {0,0,0,0,0,0,0,0},//f
                        {0,0,0,0,0,1,0,0},//g
                        {0,0,0,0,0,1,1,0}//h
                        };
int visited[8] = {0,0,0,0,0,0,0,0};
int val=0;
int q[8];
int t=0;
int b=0;
void push(int i)
{
    q[t++]=i;
   // printf("pushed %d at %d \n", i, t-1);
    val++;
}
int pop()
{
    val--;
  return q[b++];  
}
void bfs(int start)
{   
    visited[start]=1;
    for(int i=0;i<8;i++)
    {
        if(matrix[start][i]==1&&visited[i]==0)
        {
            push(i);
            printf("%d ",i);
            visited[i]=1;
        }
    } 
    printf(" ");
    while(val>0){
        int v = pop();
      //  printf("val v %d\n",v);
        bfs(v);
    }
    return;
}
void main()
{
    
    //bfs
    int start = 0;//a
    printf("%d ",start);
    bfs(start);
}