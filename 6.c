//string matching horspools algo
#include<stdio.h>
#include<string.h>
void main(){
    char* pattern = "abc";
    char* text = "bc abc";
    int m = strlen(pattern);
    int n = strlen(text);

    int table[26];
    for(int j=0;j<=25;j++)
    {
        table[j]=m;
    }
    for(int j=0;j<m;j++)
    {
        int index = pattern[j]-97;
        table[index]=m-j-1;
    }

    int i=m-1;
    while(i<=n-1)
    {
        int k=0;
        while(k<=m-1&&pattern[m-1-k]==text[i-k])
        {
            k++;
        }
        if(k==m)
        {
            printf("%d",i-m+1);
            break;
        }
        else{
            if(text[i]==' ')
            {
                i=i+m;
            }
            else
            i=i+table[text[i]-97];
        }
    }
    return;
}