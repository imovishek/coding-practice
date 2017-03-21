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
int n;
int dp[21];
int mini(int a, int b)
{
    if(a<b)
        return a;
    return b;
}
vector<int>vt;
int flag[21],bigflag=0;
int ara[21];
int find_min(int pos, int now)
{
    int sign;
    if(pos==n)return 0;
    if(dp[pos]!=-1){

//        if(pos==5)printf("%d %d--\n",pos,dp[pos]);
        return dp[pos];
    }
    if(flag[pos]==1 || now>n)
    {
//        bigflag=1;
        return 1100001;
    }
    int &ret=dp[pos];
//    flag[pos]=1;
    ret=1+find_min(pos+1,now+1);
////    vt.push_back(pos);
    if(ara[pos]+pos>0 && ara[pos]+pos<=n)
    {
//        flag[pos]=1;
//        printf("%d %d*\n",pos,now);
        ret=mini(ret,1+find_min(ara[pos]+pos,now+1));
    }
//    flag[pos]=0;
    return ret;

}
int main()
{

    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            sf("%d",&ara[i]);
//        printf("bla bla!\n");
        printf("%d\n",find_min(0,0));

    }
    return 0;
}

/*
5
5
1 -1 2 -1 -1
*/
