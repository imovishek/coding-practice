/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<bits/stdc++.h>
#define pii             pair<lint,lint>
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

vector<int> edge[mx];
int low[mx], disc[mx], vis[mx], T = 0, pos = 0;
pii scc_solver[mx];
stack<int> st;

int dfs(int u, int p)
{
    low[u] = disc[u] = T++;
    vis[u] = 1;
    st.push(u);
    FOR(i, edge[u].size()){
        int v = edge[u][i];
        if(!vis[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v]==1) low[u] = min(low[u], disc[v]);
    }
    lint cnt = 1, mini = inf;
    if(low[u]==disc[u]){
        pf("SCC number %d# contains:\n", pos+1);
        while(!st.empty()){
            int x = st.top();
            st.pop();
            pf("%d\n", x);          // eikhaner shobgula x ekta SCC er ontorvukto
            vis[x] = 2;
            if(x==u) break;
        }
        pos++;
    }
}

int main()
{
    int t, tst = 1;
    int n, m;
    sf2(n, m);
    FOR(i, m)
    {
        int u, v;
        sf2(u, v);
        edge[u].pb(v);
    }

    FOR1(i, n) {
        if(!vis[i]) dfs(i, -1);
    }

    return 0;
}

/*
Sample Graph Input:

5 4

1 2
2 3
3 1
4 5
*/











