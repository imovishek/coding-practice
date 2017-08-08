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


int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    lint tk, tst = 1;
    lint n, m;
    sf2ll(n, m);
    lint k;
    lint x, y;
    sf3ll(k, x, y);
    tk = k;
    lint mod = 2 * (n-1) * m;
    lint cnt = 0;
    if(mod){
        cnt = k/mod;
        k = k%mod;
    }

    lint cnt2 = cnt*2, ncnt = cnt*2, mi = cnt, c1 = 1;
    if(x!=1 && x!=n) cnt*=2;
    int f = 0;
    int ci = 0;
    for(int i = 1; i<=n ; i++)
    {
        if(k>=m){
            k-=m;
            if(i==x) cnt++;
            if(i==2) cnt2++;
            if(i==n-1) ncnt++;
        }
        else{
            if(k && k>=y) cnt++;
            if(k && i==2) cnt2++;
            if(k && i==n-1) ncnt++;
            break;
        }
        if(!f && i==n) f = 1;
        if(f) i-=2;
        if(f && i==2) f = 0;
        if(n==1) i = 0;
        ci++;
    }
    lint a = max(cnt2, max(cnt, ncnt));
    lint b = cnt;
    lint c = mi;
    if(ci>=n) c++;
    if(n==1){
        c = tk/m;
    }
    pf("%lld %lld %lld\n", a, c, b);
    return 0;
}














