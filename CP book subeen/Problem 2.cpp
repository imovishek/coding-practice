#include<stdio.h>

int main()
{
    int t,negi=0,a,posi=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        if(a>0)posi++;
        else if(a<0)negi++;
    }
    printf("%d %d\n",posi,negi);
    return 0;
}
