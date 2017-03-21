#include<stdio.h>
#include<math.h>
int main()
{
    freopen("input.txt","r",stdin);
    int i,n,m,sum,nsq;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n)==1)
    {

        sum=1;
        if(n==0)break;
        nsq=sqrt(n);
        for(i=2;i<=nsq;i++)
        {
            if(n%i==0)sum=sum+i+n/i;
        }
        if(n%nsq==0 && nsq==n/nsq)sum-=nsq;
        m=n;
        for(i=0;m>0;i++)m/=10;
        i=5-i;
        while(i--)printf(" ");
        printf("%d  ",n);
        if(sum==n)printf("PERFECT\n");
        else if(sum<n)printf("DEFICIENT\n");
        else printf("ABUNDANT\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
    }

