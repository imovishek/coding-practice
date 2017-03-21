#include<stdio.h>
void in_s(long long ara[],long long p,long long q);

int main()
{

    long long n,high,i,low,ara[20],j,mult;
    while(scanf("%lld",&n)!=EOF)
    {
        high=0;
        low=0;
        mult=1;
        for(i=0; n>0; i++)
        {
            ara[i]=n%10;
            n/=10;
        }
        j=i;
        in_s(ara,0,--i);
        for(;i>=0;i--)high=high*10+ara[i];
        for(i=0;i<j;i++){
                low=low*10+ara[i];
        if(ara[i]==0)mult*=10;
        else {low*=mult;mult=1;}
        }
        printf("%lld - %lld = %lld = 9 * %lld\n",high,low,high-low,(high-low)/9);

    }
    return 0;
}

void in_s(long long ara[],long long p,long long q)
{
    int j,k,key;
    for(j=p+1; j<=q; j++)
    {
        key=ara[j];
        for(k=0; j-k-1>=0; k++)
        {
            if(ara[j-k-1]>key) ara[j-k]=ara[j-k-1];
            else break;
        }
        ara[j-k]=key;
    }
}
