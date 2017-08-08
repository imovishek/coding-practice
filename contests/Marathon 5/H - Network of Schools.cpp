#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
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
vector<int> edge[207], G[207];
int newcolor[207], ind[207] , out[207];
int low[207], disc[207], vis[207], col[207], segG = 101;
stack<int> st;
stack<int> merge(stack<int> st1, stack<int> st2)
{
    while(!st2.empty()){
        st1.push(st2.top());
        st2.pop();
    }
    return st1;
}
stack<int> scc(int u)
{
    static int T = 1;
    low[u] = disc[u] = T++;
    col[u] = 1;
    vis[u] = 1;
//    pf("%d**\n", u);
    stack<int> temp;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!vis[v]){
            temp = merge(temp, scc(v));
            low[u] = min(low[u], low[v]);
//            temp.push(v);
        }
        else if(col[v]==1){
            low[u] = min(low[u], disc[v]);
        }
    }
            temp.push(u);
    if(disc[u]==low[u]){
//                        pf("%d **\n", u);
                        while(!temp.empty())
                        {
                            int x = temp.top();
                            newcolor[x] = segG ;
                            temp.pop();
                        }
                        segG++;
                    }
    col[u] = 2;
    return temp;

}
stack <int> topsort;
void dfs(int u)
{
    vis[u] = 1;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!vis[v]) dfs(v);
    }
    topsort.push(u);
}
int main()
{
    int t, tst = 1;
    int n;
    sf1(n);
    FOR(i, n)
    {
        int a;
        while(sf1(a) && a){
            edge[i+1].pb(a);
            ind[a]++;
            out[i+1]++;
        }

    }
    int ans1 = 0, ans2 = 0;
    FOR(i, n) if(vis[i+1]!=1)scc(i+1);
//    FOR(i, n) pf("%d %d*  newcolor\n", i+1, newcolor[i+1]);
    FOR(i, n){
        if(ind[i+1]==0) ans1++;
        for(int j = 0; j<edge[i+1].size() ; j++)
        {
            int v = edge[i+1][j];
            if(newcolor[v]!=newcolor[i+1]){
                    ind[newcolor[v]]++;
                    out[newcolor[i+1]]++;
            }
        }
    }
    if(segG==102) ans2 = 0;
    else{
        int in = 0, ou = 0;
        for(int i = 101; i<segG ; i++){
            if(ind[i]==0) {
                in++;
//                pf("%d ****\n", i);
            }
            if(out[i]==0){
                ou++;
//                pf("%d **##**\n", i);
            }
        }
        ans2 = max(in, ou);
    }

    mem(vis, 0);
    FOR(i, n) if(vis[i+1]==0) dfs(i+1);
    stack<int> loctop = topsort;
    mem(vis, 0);
    ans1 = 0;
    while(!loctop.empty())
    {
        int u = loctop.top();
        loctop.pop();
        if(vis[u]==0) {
            ans1++;
            dfs(u);
        }
    }

    pf1(ans1);
    pf1(ans2);
    return 0;
}


/*

8
2 8 0
6 3 0
4 0
5 0
3 0
7 0
1 0
0

7
3 0
1 0
2 0
5 0
6 0
4 0
0
*/











