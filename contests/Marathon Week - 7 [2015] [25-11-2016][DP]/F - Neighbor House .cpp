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

int dp[22][4];
int ara[22][3], n;
int rec(int pos, int sig)
{
    if(pos==n) return 0;
    int &ret = dp[pos][sig];
    if(ret!=-1) return ret;
    ret = inf;
    int a = (sig+1) % 3, b = (sig+2) % 3;
    ret = min(ret, ara[pos][a] + rec(pos+1, a));
    ret = min(ret, ara[pos][b] + rec(pos+1, b));
    if(sig==3) ret = min(ret, ara[pos][0] + rec(pos+1, 0));
    return ret;
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf1(n);
        FOR(i, n)
        {
            sf3(ara[i][0], ara[i][1], ara[i][2]);
        }
        mem(dp, -1);
        pcase(tst++);
        pf1(rec(0, 3));
    }
    return 0;
}













