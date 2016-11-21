#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
typedef long long int lint;
int coin[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
lint dp[11][30005];
lint rec(int pos, int ammount)
{
    if(ammount==0)return 1;
    if(pos==11)
        return 0;
    if(dp[pos][ammount]!=-1)
        return dp[pos][ammount];
    lint ret1=0,ret2=0;
    ret1=rec(pos+1,ammount);
    if(ammount-coin[pos]>=0)
        ret2=rec(pos,ammount-coin[pos]);
    dp[pos][ammount]=ret1+ret2;
    return dp[pos][ammount];

}
int main()
{
    double mone;
    memset(dp,-1,sizeof(dp));
    while(scanf("%lf",&mone)==1)
    {
        if(mone==0)break;
        int money=mone*1000;
        money/=10;
        printf("%6.2lf%17lld\n",mone,rec(0,money));
    }
    return 0;
}
