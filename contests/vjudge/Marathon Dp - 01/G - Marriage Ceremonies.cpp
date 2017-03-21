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
#define maxi(x,y) (x>y)?x:y
#define mini(x,y) (x<y)?x:y
#define seti(p,x) p|=(1<<x)
#define reseti(p,x) p&=(~(1<<x))
#define hi() pf("hi!\n")
using namespace std;
typedef long long int lint;
typedef double dbl;
int dp[16][65537],ara[16][16],flag[16];
int n;
int bit=0;
int rec(int pom, int pw)
{
    if(pom==n)return 0;
    int &ret=dp[pom][pw];
    if(ret!=-1)
        return ret;
    ret=-123456;
    for(int i=0;i<n;i++)
    {
        if(flag[i]==1)continue;
        flag[i]=1;
        seti(bit,i);
        ret=maxi(ret,ara[pom][i]+rec(pom+1,bit));
        reseti(bit,i);
        flag[i]=0;
    }
    return ret;
}
int main()
{
    int t,tst=1,ans;
    sf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        sf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                sf("%d",&ara[i][j]);
        ans=rec(0,0);
        pcase(tst++);
        pf("%d\n",ans);
    }
    return 0;
}

/*
2
16
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
2 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
4 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
5 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
6 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
7 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
8 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
9 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
10 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
11 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
12 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
13 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
14 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
15 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
16 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

*/
