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
#define all(vt)         vt.begin(), vt.end()
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
#define repr(vt, it)    for(typeof(vt.begin()) it = vt.begin(); it!=vt.end(); it++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;
typedef vector<int> vi;
int shidha[mx];
map<pii, bool> mp;
vector<int> edge[mx];
void dfs(int u, int p)
{
    shidha[u] = 0;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(v==p) continue;
        int jug = 0;
//        pf("%d %d**\n", u, v);
        if(mp.find(pii(u, v))!=mp.end()) jug = 1;
//        if(mp.find(pii(v, u))!=mp.end()) exv = 1;
        dfs(v, u);
        shidha[u] += jug + shidha[v];
    }
//    pf("%d shidha of %d\n", shidha[u], u);
}
int maxi[mx];

void sp_dfs(int u, int jug, int biyug, int p){
    int pre = 0;
    if(p!=-1) pre = maxi[p];
    maxi[u] = shidha[u];
    maxi[u] = max(maxi[u], pre + jug - biyug);
    FOR(i, edge[u].size()){
        int v = edge[u][i];
        if(v==p) continue;
        jug = 0, biyug = 0;
        if(mp.find(pii(u,v))!=mp.end()) biyug = 1;
        if(mp.find(pii(v,u))!=mp.end()) jug = 1;
        sp_dfs(v, jug, biyug, u);
    }
//    pf("%d sp of %d\n", maxi[u], u);
}

int main()
{
#ifdef OVI
         freopen("input.txt", "r", stdin);
         freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        mp.clear();
        int n;
        sf1(n);
        FOR(i, n-1)
        {
            int u, v;
            sf2(u, v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        int g, k;
        sf2(g, k);
        FOR(i, g)
        {
            int u, v;
            sf2(u, v);
            mp[ pii(u,v) ] = 1;
        }
        int root;
        FOR1(i, n) if((int)edge[i].size()==1) {root = i; break;}
//        cout << root << endl;
        dfs(root, -1);
        sp_dfs(root, 0, 0, -1);
        int ans = 0;
        FOR1(i, n) if(maxi[i]>=k) ans++;
        int down = __gcd(n, ans);
        ans/=down;
        down = n/down;
        pf("%d/%d\n", ans, down);
        FOR1(i, n) edge[i].clear();
    }
    return 0;
}















