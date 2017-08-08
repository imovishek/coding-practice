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
#define pf1(a)          printf("%d\n",a)
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
#define infd             1000000007
#define pi              acos(-1.0)
#define mem(arr,x)      memset((arr), (x), sizeof((arr)));
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i=1;i<=(x); i++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;
lint inf = 100000000000000007;
lint ara[307][307];
lint dp[307][307];
int n, m;
lint rec(int r, int num)
{
    if(r==n) {
        if(num==n) return 0;
        return inf;
    }
    lint &ret = dp[r][num];

    if(ret!=-1) return ret;
    ret = rec(r+1, num);
    lint sum = 0;
    FOR(i, m)
    {
        sum+=ara[r][i];
        ret = min(ret, sum + rec(r+1, num+i+1) + (i+1)*(i+1));
    }
    return ret;
}

int main()
{
#ifdef OVI
         freopen("input.txt", "r", stdin);
         freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf2(n, m);
        FOR(i, n)
            FOR(j, m)
                sf1(ara[i][j]);
        FOR(i, n) sort(ara[i], ara[i]+m);
        mem(dp, -1);
        pf("Case #%d: %lld\n", tst++, rec(0, 0));
    }
    return 0;
}














