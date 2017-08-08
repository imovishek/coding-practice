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
#define seti(a, x)      (a|=(1<<x))
#define check(a, x)     (a & (1<<x))
using namespace std;
typedef long long int lint;
typedef double dbl;
int ara[200];
int arab[200];
int n, m, maxi = 0;
vector<int> vt;
int rec(int pos, int bit, int sum)
{
    if(pos==n+1)
    {
        int nbit = 0;
        FOR(i, vt.size())
        {
            int a = vt[i];
            nbit|=ara[a];
            if(bit&nbit) return 0;
        }
        int s = 0;
        int x = bit;
        while(bit)
        {
            if(bit&1) s++;
            bit>>=1;
        }
//        FOR(i, vt.size()) pf("%d ", vt[i]);
//        pf("\n");
//        FOR1(i, 20){
//            if(check(x, i)) pf("1");
//            else pf("0");
//        }
//        pf("     %d ***\n", s);
        maxi = max(maxi, s);
        return 0;
    }
    int x = bit;
    seti(x, pos);
    vt.pb(pos);
    rec(pos+1, x, sum+1);
    vt.ppb;
    rec(pos+1, bit, sum);
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t, tst = 1;
    while(sf2(n, m)==2)
    {
        if(n==0 && m==0) return 0;
        mem(ara, 0);
        mem(arab, 0);
        maxi = 0;
        FOR(i, m)
        {
            int u, v;
            sf2(u, v);
            if(v<0){
                v = -v;
                seti(ara[u], v);
                seti(ara[v], u);
            }
            else{
                seti(arab[u],v);
            }
        }
        rec(1, 0, 0);
        pf1(maxi);

    }
    return 0;
}













