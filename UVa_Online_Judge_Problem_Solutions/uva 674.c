#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>

int dp[5][7490];
int coin[5]= {1,5,10,25,50},n;

int rec(int pos, int money)
{
    int i;

    if(pos==5)
    {
        if(money==n)
        {
            return 1;
        }
        return 0;
    }
    if(dp[pos][money]!=-1)
    {
//            printf("%d %d: %d\n",pos,money,dp[pos][money]);
        return dp[pos][money];
    }
    int *ret=&dp[pos][money];
    if(*ret==-1)*ret=0;
    *ret+=rec(pos+1,money);

        if(money+coin[pos]<=n)
        {
            *ret+=rec(pos,money+coin[pos]);
        }



    return *ret;
}

int main()
{

    while(scanf("%d",&n)==1)
    {
        memset(dp,0,sizeof(dp));
        printf("%d\n",rec(0,0));
    }
    return 0;
}

