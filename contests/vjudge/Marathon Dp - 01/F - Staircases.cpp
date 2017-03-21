#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pf printf
#define sf scanf
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
vector<int>vt;
lint dp[501][501],cap=212;
lint rec(int pos, int cp,int num)
{
    if(cp<0 || pos<0)return 0;
    if(num<2 && cp==0)return 0;
    if(num>1 && cp==0){
//            for(int i=0;i<vt.size();i++)
//                printf("%d ",vt[i]);
//            pf("*\n");
            return 1;
    }
    if(dp[pos][cp]!=-1)
        return dp[pos][cp];
    lint &ret=dp[pos][cp];
    ret=0;

    ret+=rec(pos-1,cp,num);
    vt.push_back(pos);
    ret+=rec(pos-1,cp-pos,num+1);
    vt.pop_back();
    return ret;

}
int main()
{
    while(scanf("%d",&cap)==1)
    {
        memset(dp,-1,sizeof(dp));
        printf("%I64d\n",rec(cap,cap,0));
    }
    return 0;
}
