#include<stdio.h>
#define m 1000004
int prime[m]={0},digprime[m]={0};
void seive()
{
    int i,j,counti=1;
    for(i=4;i<m;i+=2)prime[i]=1;
    for(i=3;i<=1000;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<m;j+=i<<1)
            {
                prime[j]=1;
            }
        }
    }

    digprime[0]=0;
    for(i=1;i<m;i++)
    {
        if(prime[i]==0)
        {
            int temp=i,sum=0;
            while(temp)
            {
                sum+=temp%10;
                temp/=10;
            }
            if(prime[sum]==0){counti++;}
        }
        digprime[i]=counti;

    }

}
int main()
{
    seive();
    int t,ans,l,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&l,&n);
        ans=digprime[n]-digprime[l];
        if(digprime[l]==digprime[l-1]+1)ans++;
        printf("%d\n",ans);
    }
    return 0;
}
