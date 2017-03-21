#include<stdio.h>
#include<string.h>
#define sf scanf
#define pf printf

int main()
{
    int t,n,i;
    char ara[1000];
    sf("%d",&t);
    while(t--)
    {
        sf("%s",ara);
        n=ara[strlen(ara)-1]-'0';
        pf("%s\n","odd\0even\0"+((n&1)?0:4));
    }
    return 0;
}


