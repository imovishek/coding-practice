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

int col[mx], low[mx], disc[mx], vis[mx], mini[mx], counter[mx];
vector<int> edge[mx], DAG[mx];

stack<int> st;
int timer = 0;
int pos = 0;
int scc(int u)
{
    vis[u] = 1;
    st.push(u);
    low[u] = disc[u] = timer++;
    FOR(i, edge[u].size()){
        int v = edge[u][i];
        if(!vis[v])
        {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v]==1)low[u] = min(low[u] , disc[v]);
    }
    if(low[u] == disc[u]){
        mini[pos] = inf;
        counter[pos] = 0;
        while(!st.empty()){
            int x = st.top();
            col[x] = pos;
            vis[x] = 2;
            mini[pos] = min(mini[pos], x);
            st.pop();
            counter[pos]++;
            pf("%d ", x);
            if(x==u) break;
        }
        pf("\n");
        pos++;
    }
}
int cnt = 0;
int dfs(int u)
{
    vis[u] = 1;
    cnt+=counter[u];
    FOR(i, DAG[u].size())
    {
        int v = DAG[u][i];
        if(!vis[v]) dfs(v);
    }
    st.push(u);
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
        FOR(i, n)
        {
            int u, v;
            sf2(u, v);
            edge[u].pb(v);
        }
        FOR1(i, n) if(!vis[i]) scc(i);
        FOR1(u, n){
            FOR(i, edge[u].size()){
                int v = edge[u][i];
                int x = col[u], y = col[v];
                if(x!=y){
                    DAG[x].pb(y);
                }
            }

        }
        mem(vis, 0);
        FOR(i, pos) if(!vis[i]) dfs(i);
        mem(vis, 0);
        stack<int> emp, now = st;
        st = emp;
        int ans = inf, res = 0;
        while(!now.empty()){
            int u = now.top();
            now.pop();
            cnt = 0;
            if(!vis[u]) dfs(u);
            st = emp;
            if(cnt>res) res = cnt, ans = mini[u];
            else if(cnt==res) ans = min(ans, mini[u]);
        }
        pcase(tst++);
//        pf("%d %d\n", ans, res);
        pf1(ans);
        pos = 0, timer = 0;
        mem(vis, 0);
        FOR1(i, n) edge[i].clear(), DAG[i-1].clear();
    }
    return 0;
}














