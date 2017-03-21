#include<stdio.h>
int main()
{
    int test;
    double n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lf",&n);
        n=(n*63+7492)*5-498;
        n=n/10;
        n=(int)n%10;
        if(n<0)n=-1*n;
        printf("%.0lf\n",n);
    }
    return 0;
}
