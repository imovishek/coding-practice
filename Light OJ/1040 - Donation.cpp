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
int par[5000];
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
}edge[100000];
int pos;
int kruskal()
{
    sort(edge, edge+pos);
    int ans = 0;
    FOR(i, pos)
    {
        int x = id(edge[i].u), y = id(edge[i].v), w = edge[i].w;
        if(x!=y) {
                par[x] = y;
                ans+=w;
        }
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
        int n;
        sf1(n);
        pos = 0;
        int ans = 0;
        FOR(i, n)
        {
            FOR(j, n)
            {
                int a;
                sf1(a);
                if(a>0){
                    edge[pos].u = i;
                    edge[pos].v = j;
                    edge[pos++].w = a;
                }
                ans+=a;
            }
        }
        FOR(i, n+1) par[i] = i;
        pcase(tst++);
        int kru = kruskal();
        set<int> st;
        FOR(i, n) st.insert(id(i));
        if(st.size()>1) pf1(-1);
        else pf1(ans-kru);

    }
    return 0;
}














