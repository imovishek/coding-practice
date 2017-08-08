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

vector<int> edge[mx], comp[mx];
int low[mx], disc[mx], vis[mx], col[mx];
int pos = 0, timer = 0;
stack<int> st;
int scc(int u, int p)
{
    vis[u] = 1;
    low[u] = disc[u] = timer++;
    st.push(u);
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!vis[v]){
            scc(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v]==1){
            low[u] = min(low[u], disc[v]);
        }
    }
    if(low[u]==disc[u]){
        while(!st.empty()){
            int x = st.top();
            st.pop();
            col[x] = pos;
            comp[pos].pb(x);
            if(x==u) break;
        }
        pos++;
    }

    vis[u] = 2;
}



int main()
{
#ifdef OVI
         freopen("input.txt", "r", stdin);
         freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n, m;
    while(sf2(n, m)!=EOF)
    {
        FOR1(i, n) edge[i].clear();
        mem(vis, 0);
        pos = 0, timer = 0;
        FOR(i, m)
        {
            int u, v;
            sf2(u, v);
            int sig;
            sf1(sig);
            if(sig==2) edge[v].pb(u);
            edge[u].pb(v);

        }
        FOR1(i, n) if(!vis[i])scc(i, -1);
        int ind[n+1], out[n+1];
        mem(ind, 0);
        mem(out, 0);
        FOR1(u, n)
        {
            FOR(i, edge[u].size())
            {
                int v = edge[u][i];
                int x = col[u], y = col[v];
                if(x==y) continue;
                ind[y]++, out[x]++;
            }
        }
        int in = 0, ou = 0;
        FOR(i, pos)
        {
            if(ind[i]==0) in++;
            if(out[i]==0) ou++;
        }
        if(pos==1) pf("1\n");
        else {
            pf("!%d\n", max(in, ou));
        }
    }
    return 0;
}














