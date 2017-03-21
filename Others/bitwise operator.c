#include<stdio.h>
int main()
{
    int a=123,count=0,b,i,x;
    b=a;
    while(b>0)
    {
        //printf("%d",1&b);
        b=b>>1;
        count++;
    }
    printf("\n%d\n",count);

    for(i=0,x=0;i<5;i++)
    {
        x=(x<<1)|1;
    }
    x=x<<1;
    printf("x = %d\n",x);
    for(b=0;count>0;count--)
        b=(b<<1)|1;
    printf("b = %d\n",b);
    printf("%d\n",a&(b^x));
    return 0;
}
