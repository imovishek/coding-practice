#include<stdio.h>

int main()
{
    int test,n,i,j,x;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        scanf("%d",&n);
        x=n/2;
        for(j=0;j<x;j++) scanf("%*d",&x);
        scanf("%d",&x);scanf("%*[^\n]s");
        printf("Case %d: %d\n",i,x);
    }

    return 0;
}
