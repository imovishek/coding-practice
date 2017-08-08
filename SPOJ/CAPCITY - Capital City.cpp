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
typedef vector<int> vi;

vi edge[mx], rev[mx];
stack<int> st;
int vis[mx];
void dfs(int u)
{
//    pf("%d**", u);
    vis[u] = 1;
    FOR(i, rev[u].size())
        if(!vis[rev[u][i]]) dfs(rev[u][i]);
    st.push(u);
}
vi ans;

void dfs2(int u)
{
    vis[u] = 1;
    ans.pb(u);
    FOR(i, edge[u].size())
        if(!vis[edge[u][i]]) dfs2(edge[u][i]);

}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n, m;
    sf2(n, m);
    FOR(i, m)
    {
        int u, v;
        sf2(u, v);
        edge[u].pb(v);
        rev[v].pb(u);
    }
    FOR1(i, n) if(!vis[i])dfs(i);
    mem(vis, 0);
//    pf1(st.top()) ;
    dfs2(st.top());
    sort(ans.begin(), ans.end());
    pf1(ans.size());
    if(ans.size()>0) pf("%d", ans[0]);
    FOR1(i, ans.size()-1) pf(" %d", ans[i]);
    pf("\n");
    return 0;
}
