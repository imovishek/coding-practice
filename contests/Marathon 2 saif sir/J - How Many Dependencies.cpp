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
vector<int> edge[107];
int cnt;
int flag[107];
void dfs(int u)
{
    FOR(i, edge[u].size()){
        int v = edge[u][i];
        if(flag[v]==0){
            cnt++;
            flag[v] = 1;
            dfs(v);
        }
    }
}
int main()
{
    int t, tst = 1;
    int n;
    while(sf1(n) && n)
    {
        FOR(i, n)
        {
            int a,b;
            sf1(a);
            FOR(j, a) {
                sf1(b);
                edge[i+1].pb(b);
            }
        }
        int ans = 0, maxi = -inf;
        FOR(i, n)
        {
            cnt = 0;
            mem(flag, 0);
            dfs(i+1);
            if(cnt>maxi){
                ans = i+1;
                maxi = cnt;
            }
        }
        pf1(ans);
        FOR(i, n+1) edge[i].clear();
    }
    return 0;
}














