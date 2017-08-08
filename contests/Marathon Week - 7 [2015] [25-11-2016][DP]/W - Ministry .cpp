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
lint dp[107][507];
lint ara[107][507];
int par[107][507];
int n, m;
int rec(int row, int col)
{
    if(row==n) return 0;

    lint &ret = dp[row][col];
    if(ret!=-1) return ret;
    lint sum = 0;
    ret = 1000000000000000;
    for(int i = col; i<m ; i++)
    {
        sum = sum + ara[row][i];
        lint ret1 = sum + rec(row+1, i);
        if(ret > ret1){
            par[row][col] = i;
            ret = ret1;
        }
    }
    sum = 0;
    for(int i = col; i>=0 ; i--)
    {
        sum = sum + ara[row][i];
        lint ret1 = sum + rec(row+1, i);
        if(ret > ret1){
            par[row][col] = i;
            ret = ret1;
        }
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
    sf2(n,m);
    FOR(i, n) FOR(j, m) sf("%lld", &ara[i][j]);
    lint mini = 10000000000000000;
    int col;
    FOR(i, m)
    {
        lint ret1 = ara[0][i] + rec(1, i);
        if(mini > ret1){
            mini = ret1;
//            pf("%d %lld**\n", i, mini);
            col = i;
        }
    }
    pf("%d", col+1);
    FOR1(i, n-1)
    {
        int now = par[i][col];
        if(col<=now){
            for(int j = col; j<=now ; j++) pf(" %d", j+1);
        }
        else{
            for(int j = col; j>=now ; j--) pf(" %d", j+1);
        }
        col = now;
    }
    pf("\n");
    return 0;
}














