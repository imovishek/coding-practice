#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
int ara[]={1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};
lint dp[21][10007];
int cap;
lint rec(int pos, int cp)
{
    if(cp==0)return 1;
    if(pos==21)return 0;
    lint &ret= dp[pos][cp];
    if(ret!=-1)
        return ret;
    ret=0;
    ret+=rec(pos+1,cp);
    if(cp-ara[pos]>=0)ret+=rec(pos,cp-ara[pos]);
    return ret;

}
int main()
{
//    dbl l=clock(),li;
    for(int i=0;i<21;i++)for(int j=0;j<10007;j++)dp[i][j]=-1;
//    pf("time to memset: %.10lf\n",(clock()-l)/CLOCKS_PER_SEC);

    while(sf("%d",&cap)!=EOF)
    {
        pf("%lld\n",rec(0,cap));
    }

    return 0;
}
