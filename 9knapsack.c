//DP method 
#include<stdio.h>
#define n 10 //capacity
#define m 3 //no of items

int dp[m+1][n+1];

int max(int a ,int b)
{
    if(a>b)
        return a;
    else 
        return b; 
}

void knapsack(int wt[],int p[])
{
    for(int i=0;i<=m;i++)//items
    {
        for(int j=0;j<=n;j++) //capacity
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(wt[i-1]<=j)
            {
                dp[i][j]=max(p[i-1]+dp[i-1][j-wt[i-1]], //max value of price with this item
                        dp[i-1][j]); // max price without this item
            }
            else{
                dp[i][j]= dp[i-1][j];//wt exceeded so  max price with current capacity and without this item
            }
        }
    }
    printf("%d ", dp[m][n]);

//return dp[m][n];

}

void main()
{
    int wt[m]={4,5,6};//weight 
    int p[m]={60,100,120};//price
    int mw=10;//max capacity
    knapsack(wt,p);
}
