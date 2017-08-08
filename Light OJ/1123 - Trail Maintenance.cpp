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
int par[207];
int n, m;
struct data{
    int u, v, w;
    bool operator<(const data &a) const{
        return w<a.w;
    }
} edge[60007];

int tree[207][207];

int id(int u)
{
    if(par[u]!=u) par[u] = id(par[u]);
    return par[u];
}
int vis[207];
int stx, sty, bigflag = 0;
int dfs(int u, int st, int en,int maxi)
{
    if(vis[u]) return 0;
    if(u==en) {
            bigflag = 1;
            return maxi;
    }
    vis[u] = 1;
    int ret = 0;
    FOR1(i, n)
    {
        if(tree[u][i]!=inf)
        {
            ret = max(ret, dfs(i, st, en, max(maxi, tree[u][i])));
            if(bigflag){
                if(ret==tree[u][i]) stx = u, sty = i;
                return ret;
            }
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
        sf2(n, m);
        int sum = 0;
        pf("Case %d:\n", tst++);
        FOR1(i, n)
            FOR1(j, n)
                tree[i][j] = inf;
        FOR1(i, n) par[i] = i;
        int f = 0;
        FOR(i, m)
        {
            int u, v, w;
            sf3(u, v, w);
            int x = id(u), y = id(v);
            if(x!=y){
                par[x] = y;
                sum+=w;
                tree[u][v] = w;
                tree[v][u] = w;
            }
            else{

                bigflag = 0;
                mem(vis, 0);
                if(u==v);
                else if(w<dfs(u, u, v, 0)){
                    sum-=tree[stx][sty];
                    tree[u][v] = w;
                    tree[v][u] = w;
                    sum+=w;
                    if(stx==u && sty==v);
                    else{
                        tree[stx][sty] = inf;
                        tree[sty][stx] = inf;
                    }
                }
            }
            set<int> st;
            if(!f){
                FOR1(i, n) st.insert(id(i));
                if(st.size()==1) f = 1;
            }
            if(f) pf1(sum);
            else pf1(-1);
        }

    }
    return 0;
}














