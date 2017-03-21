#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define piii pair<int, pii>

using namespace std;
typedef long long int lint;
typedef double dbl;
vector<pii>G[207];
int n, m;
int mst(int st, int desti)
{
    priority_queue<piii, vector<piii>, less<piii> > pQ;
    pQ.push(piii(inf, pii(st, st)));
    bool flag[n+7];
    mem(flag, 0);
    int mini[n+7];
    FOR(i, n+7) mini[i] = inf;
    while(!pQ.empty())
    {
        int u = pQ.top().sc.sc;
        int x = pQ.top().sc.fs;
        mini[u] = min(pQ.top().fs, mini[x]);
        pQ.pop();
        if(flag[u]) continue;
        flag[u] = 1;

        if(u==desti) return mini[desti];
        FOR(i, G[u].size())
        {
            int v = G[u][i].fs;
            int w = G[u][i].sc;
            if(!flag[v]) {
                    pQ.push(piii(w, pii(u, v)));
            }
        }
    }

}
int main()
{
    int t, tst = 1;
    while(sf2(n, m))
    {
        if(n==0 && m==0) break;
        map<string, int> mp;
        string u, v;
        int w;
        int pos = 0;
        FOR(i, m)
        {
            cin >> u >> v >> w;
            if(mp.find(u)==mp.end())mp[u] = pos++;
            if(mp.find(v)==mp.end())mp[v] = pos++;
            int x = mp[u], y = mp[v];
            G[x].pb(pii(y, w));
            G[y].pb(pii(x, w));
        }
        cin >> u >> v;
        int ans = mst(mp[u], mp[v]);
        pf("Scenario #%d\n", tst++);
        pf("%d tons\n\n", ans);
        FOR(i, n) G[i].clear();
    }
    return 0;
}

