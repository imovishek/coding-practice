#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
typedef long long int lint;
lint dp[5][7490];
int coin[5]= {1,5,10,25,50},n;

lint rec(int pos, int money)
{
    int i;

    if(pos==5){
            if(money==0)return 1;
            return 0;
    }

    if(dp[pos][money]!=-1)
    {
//            printf("%d %d: %d\n",pos,money,dp[pos][money]);
        return dp[pos][money];
    }
    lint *ret=&dp[pos][money];
    if(*ret==-1)*ret=0;
    *ret+=rec(pos+1,money);

    if(money-coin[pos]>=0)
    {
        *ret+=rec(pos,money-coin[pos]);
    }



    return *ret;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",rec(0,n));
    }
    return 0;
}


