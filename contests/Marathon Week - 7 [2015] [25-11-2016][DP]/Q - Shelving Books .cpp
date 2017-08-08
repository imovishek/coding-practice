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
int ara[107];
int dp[102][102][102];
int n;

int rec(int pos, int left, int right)
{
    if(pos==n+1) return 0;
    int &ret = dp[pos][left][right];
    if(ret!=-1) return ret;
    if(ara[pos]>=ara[left] && ara[pos]<=ara[right]){
            ret = max(ret, 1+rec(pos+1, pos, right));
            ret = max(ret, 1+rec(pos+1, left, pos));
    }
    ret = max(ret, rec(pos+1, left, right));
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
    ara[0] = -inf;

    while(t--)
    {
        sf1(n);
        FOR1(i, n) sf1(ara[i]);
        mem(dp, -1);
        ara[n+1] = inf;
        pcase(tst++);
        pf1(rec(1, 0, n+1));
    }
    return 0;
}














