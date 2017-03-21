#include<stdio.h>
#define sf scanf
#define pf printf

int main()
{
    int t,n,i;
    char ara[100];
    sf("%d",&t);
    while(t--)
    {
        sf("%s",ara);
        for(i=0;ara[i];i++)
            if(ara[i]=='L') ara[i]=ara[i-1];
            else if(ara[i]=='R') ara[i]=ara[i+1];
        puts(ara);
    }
    return 0;
}

