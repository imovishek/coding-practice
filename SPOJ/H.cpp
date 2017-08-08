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

int ara[mx];
int dp[1007][1007];

int rec(int x, int y)
{
    if(abs(x-y)==1) return abs(ara[x] - ara[y]);
    int &ret = dp[x][y];
    if(ret!=-1) return ret;
    ret = -inf;
    if(ara[x+1]>=ara[y]){
        ret = max(ret, ara[x] - ara[x+1] + rec(x+2, y));
    }
    else{
        ret = max(ret, ara[x] - ara[y] + rec(x+1, y-1));
    }

    if(ara[y-1]>ara[x]){
        ret = max(ret, ara[y] - ara[y-1] + rec(x, y-2));
    }
    else{
        ret = max(ret, ara[y] - ara[x] + rec(x+1, y-1));
    }
//    pf("%d %d ans = %d\n", x, y, ret);
    return ret;
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n;
    while(sf1(n) && n)
    {
        int a = 0, b = 0;
        FOR(i, n) {
            sf1(ara[i]);
        }
        mem(dp, -1);
        int ans = rec(0, n-1);
        pf("In game %d, the greedy strategy might lose by as many as %d points.\n", tst++, ans);

    }
    return 0;
}














