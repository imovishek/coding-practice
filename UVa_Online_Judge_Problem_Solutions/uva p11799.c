#include<stdio.h>
int main()
{
    int ntest,i,j,nvel,maxvel=0,vel;
    scanf("%d",&ntest);
    for(i=0;i<ntest;i++)
    {
        scanf("%d",&nvel);
        for(j=0;j<nvel;j++)
        {
            scanf("%d",&vel);
            if(vel>maxvel)maxvel=vel;
        }
        printf("Case %d: %d\n",i+1,maxvel);
        maxvel=0;
    }
    return 0;
}
