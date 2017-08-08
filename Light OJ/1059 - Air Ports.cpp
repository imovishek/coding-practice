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

int par[100007];
int id(int u)
{
    if(par[u]!=u) par[u] = id(par[u]);
    return par[u];
}
struct data{
    int u, v, w;
    bool operator<(const data &a) const{
        return w<a.w;
    }
} edge[100007];
int n, m, a, ans, cp;
int kruskal()
{
    sort(edge, edge+m);
    int flag[n+1];
    FOR(i, n+1) {
        par[i] = i;
        flag[i] = 0;
    }
    cp = n;
    int comp= n;
    int sum = 0;
    FOR(i, m)
    {
        data &now = edge[i];
        int x = id(now.u), y = id(now.v);
        if(x!=y){
            comp--;
            sum+=now.w;
            par[x] = y;
            if(ans>comp*a+sum){
                cp = comp;
                ans = comp*a+sum;
            }
        }
    }
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
        sf3(n, m, a);
        ans = n*a;
        FOR(i, m)
        {
            data &x = edge[i];
            sf3(x.u, x.v, x.w);
        }
        kruskal();
        pcase(tst++);
        pf("%d %d\n", ans, cp);
    }
    return 0;
}














