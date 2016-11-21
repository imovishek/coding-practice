#include<stdio.h>
int main()
{
    int a,b,c,n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a<b && b<c)a=b;
        else if(a>b && b>c)a=b;
        else if(a<c && c<b)a=c;
        else if(a>c && c>b)a=c;
        printf("Case %d: %d\n",i,a);
    }
    return 0;
}
