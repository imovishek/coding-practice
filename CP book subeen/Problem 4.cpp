#include<stdio.h>

int main()
{
    int t,l,w,h,vol;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&l,&w,&h);
        vol=l*w*h;
        printf("%d\n",vol);
    }

    return 0;
}

