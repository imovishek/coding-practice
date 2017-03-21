#include<stdio.h>
#include<string.h>
int main()
{
    int test,i,j,len,count;
    char ara[101];
    scanf("%d",&test);
    gets(ara);
    for(i=1;i<=test;i++)
    {
        count=0;
        gets(ara);
        len=strlen(ara);
        for(j=0;j<len;j++)
        {
            if(ara[j]==' ')count++;
            else if(ara[j]<='o') count=count+(ara[j]-'a')%3+1;
            else if(ara[j]<='s' && ara[j]>='p')count+=ara[j]-'p'+1;
            else if(ara[j]<='v' && ara[j]>='t')count+=ara[j]-'t'+1;
            else if(ara[j]<='z' && ara[j]>='w')count+=ara[j]-'w'+1;
        }
        printf("Case #%d: %d\n",i,count);
    }
    return 0;
}
