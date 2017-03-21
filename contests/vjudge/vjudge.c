#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
typedef long long int lint;

int main()
{
    int n,m,test=1,t,ans;

    scanf("%d",&t);
    while(t-- && scanf("%d %d",&n,&m))
    {
        ans=(n/2)*(m/2)+(n-n/2)*(m-m/2);
        if(n==1 || m==1)ans=(n==1)?m:n;
        else if((n==2 && m==3)||(n==3&&m==2))ans=4;
        else if(n==2 && m==2)ans=4;
        printf("Case %d: %d\n",test++,ans);
    }
        return 0;
    }
