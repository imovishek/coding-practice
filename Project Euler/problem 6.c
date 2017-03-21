#include<stdio.h>
int main()
{
    int n=100,i,sum1=0,sum2=0,dif;
    for(i=1;i<=n;i++)
    {
        sum1=sum1+i*i;
        sum2=sum2+i;
    }
    dif=sum2*sum2-sum1;
    printf("%d",dif);
}
