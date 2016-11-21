#include<stdio.h>
int func(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main()
{
    int n,sum;
    while(scanf("%d",&n)==1)
    {
        if(n==0)break;
        sum=func(n);
        sum=func(sum);
        sum=func(sum);
        printf("%d\n",sum);
    }
}
