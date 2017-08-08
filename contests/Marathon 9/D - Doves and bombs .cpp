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
#define mx              10007

using namespace std;
typedef long long int lint;
typedef double dbl;
vector<int> edge[mx];
set<int> st[mx];
int low[mx], disc[mx], vis[mx], timer = 0;

void clear(int n){
    FOR(i, n) edge[i].clear(), st[i].clear(), vis[i] = 0;
    timer = 0;
}
void ap(int u, int p)
{
    vis[u] = 1;
    low[u] = disc[u] = timer++;
    int cnt = 0;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(v==p) continue;
        if(!vis[v]){
            cnt++;
            ap(v, u);
            low[u] = min(low[u] , low[v]);
            if(low[v]>=disc[u] && u){
                st[u].insert(low[v]);
            }
        }
        else low[u] = min(low[u], disc[v]);
    }
    if(u==0 && cnt>1){
        FOR(i, cnt-1) st[0].insert(i);
    }
}
bool comp(pii a, pii b)
{
    if(a.sc==b.sc)
        return a.fs < b.fs;
    return a.sc>b.sc;
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n, m;
    while(sf2(n, m)){
        if(n==m && m==0) return 0;
        int u, v;
        clear(n);
        while(sf2(u, v)){
            if(u==v && u==-1) break;
            edge[u].pb(v);
            edge[v].pb(u);
        }
        ap(0, -1);
        vector<pii> ans;
        FOR(i, n){
                ans.pb(pii(i, st[i].size()+1));
        }
        sort(ans.begin(), ans.end(), comp);
        FOR(i, m) pf("%d %d\n", ans[i].fs, ans[i].sc);
        pf("\n");
    }
    return 0;
}














