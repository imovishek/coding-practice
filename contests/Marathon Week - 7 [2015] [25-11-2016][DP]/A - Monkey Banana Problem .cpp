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
int ara[301][207];
int dp[207][107];
int n;
int rec(int x, int y)
{
    if(x==2*n-2) return ara[x][y];
    int &ret = dp[x][y];
    if(ret!=-1) return ret;

    if(ara[x+1][y]!=-1) ret = max(ret, ara[x][y] + rec(x+1, y));
    if(ara[x+1][y+1]!=-1) ret = max(ret, ara[x][y] + rec(x+1, y+1));
//        pf("%d %d %d*\n", x, y, ret);
    return ret;
}

int main()
{
#ifdef OVI
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf1(n);
        mem(ara, -1);
        mem(dp, -1);
        FOR(i, n){
            FOR(j, i+1) {
                sf1(ara[i][j]);
//                pf("%d ", ara[i][j]);
            }
//            pf("\n");
        }
        FOR(i, n-1)
        {
//            FOR(j, i+1) pf("-1 ");
            for(int j = i+1; j<n ; j++)
            {
                sf1(ara[i+n][j]);
//                pf("%d ", ara[i][j]);
            }
//            pf("\n");
        }
//        FOR(i, 2*n-1) {
//            FOR(j, n) pf("%d ", ara[i][j]);
//            pf("\n");
//        }
        pcase(tst++);
//        pf("\n");
        pf1(rec(0,0));
    }
    return 0;
}














