#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,n,mid,rang;
    char ara[1000000];
    for(i=0;i<1000000;i++)ara[i]='1';
    for(i=2;i<=1000;i++)
    {
        rang=1000000/i;
        for(j=2;j<=rang;j++)
        {
            ara[i*j-1]='0';
        }
    }
    while(scanf("%d",&n))
    {
        if(n==0)break;
        mid=n/2;
        if(mid%2==0)mid++;

        for(i=3;i<=mid;i+=2)
        {
            if(ara[i-1]-'0' && ara[n-i-1]-'0'){printf("%d = %d + %d\n",n,i,n-i);break;}
        }
        if(i>=n)printf("Goldbach's conjecture is wrong.\n");

    }
    return 0;
}
