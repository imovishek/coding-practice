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
lint dp[107][107][107];

lint rec(int pos, int roise, int pat)
{
    if(roise==0 && pos>0) return 0;
    if(pos<=0){
        if(roise==0){
                int cnt = 0;
                while(pat)
                {
                    if(pat&1) cnt++;
                    pat >>= 1;
                }
                if(cnt==0) return 1;
                return 0;
        }
        return 0;
    }

    lint &ret = dp[pos][roise][pat];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i = 1; i<=roise; i++)
        ret = (ret + rec(pos-1, roise-i, pat^i)) % MOD;
    return ret;
}
int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n, m;
    mem(dp, -1);
    while(sf2(n, m)){
        if(n==0 && m==0) return 0;
        pcase(tst++);
        pf("%lld\n", rec(m, n, 0));
    }
    return 0;
}














