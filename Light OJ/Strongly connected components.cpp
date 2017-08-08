/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
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

vector<int> edge[mx], strngly[mx];
int low[mx], disc[mx], vis[mx], col[mx], T = 0;
stack<int> st;
int pos = 0;
int dfs(int u, int p)
{
    low[u] = disc[u] = T++;
    vis[u] = 1;
    st.push(u);

    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!vis[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v]==1){
            low[u] = min(low[u], disc[v]);
        }
    }

    if(disc[u]==low[u])
    {
        int x;
        do
        {
            x = st.top();
            strngly[pos].pb(x);
            col[x] = pos;
            st.pop();
        }
        while(x!=u);
        pos++;
    }

    vis[u] = 2;
}
void clear(int n)
{
    FOR1(i, n) edge[i].clear();
    FOR(i, pos) strngly[i].clear();
    pos = 0, T = 0;
    mem(vis, 0);
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
//    sf1(t);
//    while(t--)
//    {
        int n, m;
        sf1(n);
        FOR1(i, n)
        {
            int u;
            while(sf1(u) && u)
                edge[i].pb(u);
        }
        FOR1(i, n)
            if(!vis[i]) dfs(i, -1);
//        pf1(pos);
//        FOR(i, pos) {
//            FOR(j, strngly[i].size()) pf("%d ", strngly[i][j]);
//            pf("\n");
//        }

        int ind[pos], outd[pos];
        mem(ind, 0);
        mem(outd, 0);
        FOR1(u, n)
        {
            FOR(i, edge[u].size())
            {
                int v = edge[u][i];
                if(col[u]==col[v]) continue;
                ind[col[v]]++;
                outd[col[u]]++;
            }
        }
        int in0 = 0, out0 = 0;
        FOR(i, pos){
            if(ind[i]==0) in0++;
            if(outd[i]==0) out0++;
        }
        int ans = 0;
        if(pos==1) ans = 0;
        else{
            ans = max(in0, out0);
        }
//        pcase(tst++);
        pf1(in0);
        pf1(ans);
//        clear(n);
//    }
    return 0;
}

/*
2

5 6
1 2
1 4
1 3
2 4
2 5
5 1

8 10
1 2
1 3
2 3
3 4
4 2
4 5
5 7
7 8
8 6
6 5


*/














