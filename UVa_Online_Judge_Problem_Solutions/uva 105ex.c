#include<stdio.h>
int main()
{

    int ara[20000],i,x,y,h,start=0,end=0,rh=0;
    for(i=0;i<20000;i++)ara[i]=-1;
    while(scanf("%d %d %d",&x,&h,&y)==3)
    {
        start=x*2;if(y>end/2)rh=y;end=y*2;
        for(i=start;i<=end;i++){
            if(h>ara[i])ara[i]=h;
        }
    }
    y=-1;
    x=-1;

    for(i=0;i<rh*2;i++)
    {
        if(i%2==0 && ara[i]!=y){y=ara[i];x=i;
        printf("%d %d ",x/2,y);
               }
               else if (i%2==0 && y!=-1 && ara[i+1]==-1) {y=-1;printf("%d 0 ",i/2);}
    else if(i%2==1 && ara[i]!=y){y=ara[i];x=i;
        printf("%d %d ",x/2,y);}
        x=i;
    }
    printf("%d 0\n",rh);

    return 0;
}
