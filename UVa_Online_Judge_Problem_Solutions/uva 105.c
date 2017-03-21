#include<stdio.h>
int main()
{


    int i,x,y,h,rh=0,ry=0,rx=0;//ara[5000];
    for(i=1;scanf("%d %d %d",&x,&h,&y)==3;i++)
    {
        if(ry<x && i!=1){rx=0;rh=0;printf("%d ",rx);}
        if(rh<h)rh=h;
        if(ry<y)ry=y;
        if(rx<x)rx=x;

        if(i%2==1)printf("%d ",rx);
        else printf("%d ",rh);

    }
    printf("0\n");
    return 0;
}
