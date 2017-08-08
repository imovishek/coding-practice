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

vector<int> edge[mx];
set<int> st;
int low[mx], disc[mx], vis[mx], timer;
int root;
int dfs(int u, int p)
{
     low[u] = disc[u] = timer++;
     vis[u] = 1;
     int cnt = 0;
     FOR(i, edge[u].size())
     {
         int v = edge[u][i];
         if(v==p) continue;
         if(!vis[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            cnt++;
            if(low[v]>=disc[u] && u!=1)
                st.insert(u);
         }
         else{
            low[u] = min(low[u], disc[v]);
         }
     }
     if(u==root && cnt>1) st.insert(root);
}


int main()
{
#ifdef OVI
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n;
    sf1(t);
    while(t--)
    {
        int m;
        sf2(n, m);
        FOR(i, m)
        {
            int u, v;;
            sf2(u, v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        mem(vis, 0);
        timer = 0;
        st.clear();
        FOR1(i, n) if(!vis[i]) {
            root = i;
            dfs(i, -1);
        }
        pcase(tst++);
        pf1(st.size());
        FOR1(i, n) edge[i].clear();
    }
    return 0;
}













