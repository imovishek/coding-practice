#include<stdio.h>
#include<string.h>
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
int main()
{
    int t;
    char ara[100];
    sf("%d",&t);
    while(t--)
    {
        sf("%s",ara);
        int counti=0,flag=0;
        for(int i=0;ara[i];i++)
        {
            if(ara[i]=='1')counti++;
            else counti--;
            if(counti<0){flag=1;break;}
        }
        pf("%s\n","NORMAL\0MAGIC"+flag*7);
    }
    return 0;
}

