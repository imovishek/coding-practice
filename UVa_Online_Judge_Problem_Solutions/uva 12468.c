#include<stdio.h>
int main()
{
    int a,b,x;
    while(scanf("%d %d",&a,&b))
    {
        if(a==-1 && b==-1)break;
        if(a>b){x=a;a=b;b=x;}
        x=b-a;
        if(x<100-x)printf("%d\n",x);
        else printf("%d\n",100-x);

    }

    return 0;
}
