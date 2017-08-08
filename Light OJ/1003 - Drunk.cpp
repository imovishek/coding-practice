#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
vector<int> edge[100007];
int vis[100007];
int bigflag = 0;
stack<int> st;
int dfs(int u)
{
    vis[u] = 1;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!vis[v])
            dfs(v);
        else if(vis[v]==1){
            bigflag = 1;
        }
    }
    st.push(u);
    vis[u] = 2;
}

int main()
{
    int t, tst = 1;
    sf1(t);
    int n;
    while(t-- && sf1(n))
    {
        int pos = 0;
        map<string, int> mp;
        FOR(i, n)
        {
            string u, v;
            cin >> u >> v;
            int x, y;
            if(mp.find(u)!=mp.end()) x = mp[u];
            else x = mp[u] = pos++;
            if(mp.find(v)!=mp.end()) y = mp[v];
            else y = mp[v] = pos++;
            edge[x].pb(y);
        }
        bigflag = 0;
        while(!st.empty()) st.pop();
        FOR(i, pos)
        {
            if(!vis[i]) dfs(i);
        }
        stack<int> orgi = st;
        mem(vis, 0);
        while(!orgi.empty())
        {
            int u = orgi.top();
            orgi.pop();
            if(!vis[u]) dfs(u);
        }
        pcase(tst++);
        if(bigflag) pf("No\n");
        else pf("Yes\n");
        mem(vis, 0);
        FOR(i, pos) edge[i].clear();
    }
    return 0;
}














