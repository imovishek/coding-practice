#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char ara[4],ara2[4];
    int test,mon,day;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s %s",ara,ara2);
        if(ara[0]=='F')mon=28;
        else if(ara[0]=='S')mon=30;
        else if(ara[0]=='O')mon=31;
        else if(ara[0]=='N')mon=30;
        else if(ara[0]=='D')mon=31;
        else if(ara[0]=='M')mon=31;
        else if(ara[0]=='J')
        {
            if(ara[1]=='U' && ara[2]=='N')mon=30;
            else mon=31;
        }
        else if(ara[1]=='P')mon=30;
        else mon=31;

        if(ara2[0]=='M')day=5;
        else if(ara2[0]=='W')day=3;
        else if(ara2[0]=='F')day=1;
        else if(ara2[2]=='E')day=4;
        else if(ara2[2]=='N')day=6;
        else if(ara2[2]=='T')day=7;
        else day=2;
        if(day!=7) mon=(mon-day)/7+1+(mon-day-1)/7+1;
        else mon=(mon-7)/7+1+(mon-1)/7+1;
        printf("%d\n",mon);

    }
    return 0;
}
