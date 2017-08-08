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

lint CSOD(lint n)
{
    if(n==0) return 0;
    lint sq = sqrt(n), ans = 0, f = (n/sq!=sq);
    for(lint i = 2; i<=sq ; i++)
    {
        lint x = (n/(i) -  n/(i+1));
        lint a = (n/(i+1) + 1);
        ans += (x*a + x*(x-1)/2) * (i-1);
//        pf("%lld kore ase %lld ta start from: %lld\n", i-1, x, a);
//        ans += (n/i - 1) * i;
        if(i!=sq || f) ans += (n/i - 1) * i;
//        pf("%lld ase %lld\n", i, n/i-1);
    }
    return ans;
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
        lint n;
        sf1ll(n);
        pcase(tst++);
        pf("%lld\n", CSOD(n));
    }
    return 0;
}














