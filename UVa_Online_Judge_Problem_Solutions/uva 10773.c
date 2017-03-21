#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,i;
    double d,v,u,t1,t2;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf %lf %lf",&d,&v,&u);
        if(u<=v || d==0 || v==0){printf("Case %d: can't determine\n",i);continue;}
        v=sqrt(u*u-v*v);
        t1=d/v;
        t2=d/u;
        t1=t1-t2;
        printf("Case %d: %.3lf\n",i,t1);


    }
    return 0;
}
