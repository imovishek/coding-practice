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
#define seti(x, i)      x|=(1<<i)
#define checki(x, i)    (bool)(x&(1<<i))

using namespace std;
typedef long long int lint;
typedef double dbl;
int base, k, high, len;
char ara[20];
lint dp[(1<<16) + 7][20];
int tonum(char ch)
{
    if(ch>='0' && ch<='9') return ch - '0';
    return ch - 'A' + 10;
}

lint rec(int bit, int res)
{
    if(bit==high) {
        if(res==0) return 1;
        return 0;
    }
    lint &ret = dp[bit][res];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i = 0; i < len; i++)
    {
        int now = bit;
        if(checki(now, i));
        else{
            seti(now, i);
            ret+= rec(now, (res * base + tonum(ara[i])) % k);
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
    sf1(t);

    while(t--)
    {
        mem(dp, -1);
        sf2(base, k);
        sf("%s", ara);
        len = strlen(ara);
        high = (1 << len) - 1;
        pcase(tst++);
        pf("%lld\n", rec(0, 0));
    }
    return 0;
}













