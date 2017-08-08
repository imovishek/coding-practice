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
#define inf             1000000007
#define pi              acos(-1.0)
#define mem(arr,x)      memset((arr), (x), sizeof((arr)));
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i=1;i<=(x); i++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;

int dp[51][1007];
int ara[51];
int cap[51], n;
int rec(int pos, int k)
{
    if(k<0) return 0;
    if(pos==n)
    {
        if(k==0) return 1;
        return 0;
    }
    int &ret = dp[pos][k];
    if(ret!=-1) return ret;
    ret = 0;
    FOR(i, cap[pos]+1){
        if(i*ara[pos]<=k)
            ret = (ret + rec(pos+1, k-i*ara[pos])) % 100000007;
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
    int k;
    sf1(t);
    while(t--)
    {
        sf2(n, k);
        FOR(i, n) sf1(ara[i]);
        FOR(i, n) sf1(cap[i]);
        mem(dp, -1);
        pcase(tst++);
        pf1(rec(0, k));
    }
    return 0;
}













