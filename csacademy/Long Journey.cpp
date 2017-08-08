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
#define inf             100000007
#define pi              acos(-1.0)
#define mem(arr,x)      memset((arr), (x), sizeof((arr)));
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i=1;i<=(x); i++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;

vector<int> edge[mx];

vector<int> bfs(int s){
    vector<int> dist(mx);
    FOR(i, mx) dist[i] = -1;
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        FOR(i, edge[u].size()){
            int v = edge[u][i];
            if(dist[v]==-1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n, m;
    sf2(n, m);
    int s, a, b;
    sf3(s, a, b);
    FOR(i, m)
    {
        int u, v;
        sf2(u, v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    vector<int> adist = bfs(a);
    vector<int> bdist = bfs(b);
    vector<int> sdist = bfs(s);
    int ans = 0, mini = inf;
    FOR1(i, n)
    {
        int now = adist[i] + bdist[i] + sdist[i]*2;
        if( now < mini ){
            mini = now;
            ans = sdist[i];
        }
        else if(now==mini){
            ans = max(ans, sdist[i]);
        }
    }
//    cout << mini << endl;
    pf1(ans);
    return 0;
}














