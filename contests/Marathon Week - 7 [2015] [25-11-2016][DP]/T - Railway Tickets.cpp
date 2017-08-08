/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<bits/stdc++.h>
#define pii             pair<int,int>
#define mkp             make_pair
#define fs              first
#define sc              second
#define pb              push_back
#define ppb             pop_back()
#define pf              printf
#define pf1(a)          printf("%lld\n",a)
#define hi              printf("hi!\n");
#define sf              scanf
#define sf1(a)          scanf("%d",&a)
#define sf2(a,b)        scanf("%d %d",&a,&b)
#define sf3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a)        scanf("%lld",&a)
#define sf2ll(a,b)      scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x)        printf("Case %d: ",x)
#define MOD             1000000007
#define infl             1000000007
#define pi              acos(-1.0)
#define mem(arr,x)      memset((arr), (x), sizeof((arr)));
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i=1;i<=(x); i++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;
lint l[3], c[3];
int n;
lint inf = 10000000000000007;
int st, en;
lint ara[10007];
lint dp[10007];

lint rec(int pos)
{
    if(pos>=en) return 0;
    lint &ret = dp[pos];
    if(ret!=-1) return ret;
    ret = inf;
    FOR(i, 3){
        int to = upper_bound(ara+1, ara+n+1, ara[pos]+l[i]) - ara - 1;
        if(to>pos) ret = min(ret, c[i] + rec(to));
    }
    return ret;

}
int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    mem(dp, -1);
    FOR(i, 3) sf1ll(l[i]);
    FOR(i, 3) sf1ll(c[i]);
    sf1(n);
    sf2(st, en);
    if(st>en) swap(st, en);
    FOR1(i, n-1)
        sf1ll(ara[i+1]);
    ara[1] = 0;
    pf1(rec(st));
    return 0;
}














