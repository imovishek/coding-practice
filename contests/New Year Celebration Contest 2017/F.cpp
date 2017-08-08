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
//#define sf1(a)          scanf("%d",&a)
#define sf2(a,b)        scanf("%d %d",&a,&b)
#define sf3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a)        scanf("%lld",&a)
#define sf2ll(a,b)      scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x)        printf("Case %d: ",x)

#define pi              acos(-1.0)
#define mem(arr,x)      memset((arr), (x), sizeof((arr)));
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i=1;i<=(x); i++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;
lint ara[mx];
lint MOD = 2760727302517;
lint ans;
lint n, m;
lint tree[mx];
lint update2(lint idx, lint v){
    while(idx<=n)
    {
        tree[idx] += v;
        idx = idx + (idx & -idx);
    }
}

lint query(lint idx){
    lint ret = 0;
    while(idx<=n)
    {
        ret += tree[idx];
        idx = idx - (idx & -idx);
    }
    return ret;
}

lint mult(lint a, lint b)
{
    if(b==0) return 0;
    if(b%2==1) return (a + mult(a, b-1)) % MOD;
    lint mo = mult(a, b/2);
    return (mo+mo) % MOD;
}
lint update(lint x, lint v)
{
    lint a = ara[x];
    lint now = mult(mult(a, a) , x);
    ans = (ans-now+MOD) % MOD;
    now = mult(mult(a, a) , n+1 - x);
    ans = (ans - now + MOD) % MOD;
    now = abs(query(n) - query(x));
    ans = (ans + 2 * mult(now, a)) % MOD;

    a = v;

    now = mult(mult(a, a) , x);
    ans = (ans+now+MOD) % MOD;
    now = mult(mult(a, a) , n+1 - x);
    ans = (ans + now + MOD) % MOD;
    now = abs(query(n) - query(x));
    ans = (ans - 2 * mult(now, a) + MOD) % MOD;
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI
//    pf("%lld\n", mult(100, 125));
    int t, tst = 1;
    sf("%d", &t);
    while(t--)
    {
        sf2ll(n, m);
        mem(ara, 0);
        ans = 0;
        FOR1(i, n){
            lint a;
            sf1ll(a);
            update(i, a);
            ara[i] = a;
            update2(i, a);
//            pf("%lld\n", ans);
        }
        pf("Case %d:\n", tst++);
        FOR(i, m){
            lint sig, x, v;
            sf1ll(sig);
            if(sig==1){
                sf2ll(x, v);
                update(x, v);
                update2(i, v - ara[x]);
                ara[x] = v;
            }
            else if(sig==2){
                sf2ll(x, v);
                update(x, v+ara[x]);
                update2(i, v);
                ara[x] += v;
            }
            else pf("%lld\n", ans);
        }
    }

    return 0;
}













