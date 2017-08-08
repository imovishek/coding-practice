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
#define mx              1000007

using namespace std;
typedef long long int lint;
typedef double dbl;
typedef vector<int> vi;
vi edge[mx];
int ara[mx];
int sum = 0;
vi ans;
int dfs(int u, int p)
{
    int now = ara[u];
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(v==p) continue;
        now += dfs(v, u);
    }
    if(now==sum && p!=-1) {ans.pb(u); now = 0;}
    return now;
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n;
    sf1(n);
    int root;
    int total = 0;
    FOR1(i, n){
        int u, v;
        sf2(u, v);
        if(u==0) root = i;
        else edge[u].pb(i), edge[i].pb(u);
        ara[i] = v;
        total += v;
    }
    if(total%3){pf("-1\n"); return 0;}
    sum = total/3;
    dfs(root, -1);
    if(ans.size()>=2) pf("%d %d\n", ans[0], ans[1]);
    else pf("-1\n");
    return 0;
}















