#include<stdio.h>
int main()
{
    int n,i;
    double c,f;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lf %lf",&c,&f);
        c=c+(f/1.8);
        printf("Case %d: %.2lf\n",i,c);

    }
    return 0;
}
