#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
int dp[2007][2007];
int n, k;

int rec(int pos, int num){
    if(pos==k) return 1;
    int &ret = dp[pos][num];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i = num; i<= n ; i+=num)
        ret = (ret + rec(pos+1, i)) % MX;
    return ret;
}

int main()
{
    mem(dp, -1);
    sf2(n, k);
    int ans = 0;
    pf1(rec(0, 1));
    return 0;
}














