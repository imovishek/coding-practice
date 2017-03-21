#include<stdio.h>
int f91(int n)
{
    if(n>=101)return n-10;
    else if    (n<=100)return 91;
}
int main()
{
    int n,x;
    while(scanf("%d",&n)==1)
    {
        if(n==0)break;
        x=f91(n);
        printf("f91(%d) = %d\n",n,x);
    }


return 0;
}
