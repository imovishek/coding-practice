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
struct data{
    int u, v, w;
    bool operator<(data a) const{
        return u<a.u;
    }
}ara[100];
int n;
int flag[29];
int rec(int pos, int cost, int cp)
{

    if(pos==n) return cost;
    int u = ara[pos].u;
    int now[9], x = 0;
    FOR(i, u+1){
        now[i] = flag[i];
        cp+=flag[i];
        flag[i] = 0;
    }
    now[ara[pos].v] = flag[ara[pos].v];
    int ret = rec(pos+1, cost, cp);
    if(ara[pos].w<=cp){
        flag[ara[pos].v] += ara[pos].w;
        int c = (ara[pos].v - ara[pos].u) * ara[pos].w;
        ret = max(ret, rec(pos+1, cost+c, cp-ara[pos].w));
    }
     FOR(i, u+1){
        flag[i] = now[i];
    }
    flag[ara[pos].v] = now[ara[pos].v];
    return ret;
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int cp, b;
    while(sf3(cp, b, n)){
        if(cp==b && b==n && !b) return 0;
        FOR(i, n)
            sf3(ara[i].u, ara[i].v, ara[i].w);
        sort(ara, ara+n);
        int ans = rec(0, 0, cp);
        pf1(ans);

    }
    return 0;
}














