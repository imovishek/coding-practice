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
int par[5007];
int find(int u)
{
    if(par[u]!=u) par[u] = find(par[u]);
    return par[u];
}
int main()
{
    int t, tst = 1;
    int n, r;
    string u, v;
    while(sf2(n, r))
    {
        map<string, int> mp;
        int pos = 0, cnt[n];
        mem(cnt, 0);
        if(n==0 && r==0) return 0;
        FOR(i, n) par[i] = i;
        FOR(i, n){
            cin >> u;
            mp[u] = pos++;
        }
        FOR(i, r)
        {
            cin >> u >> v;
            int x = mp[u], y = mp[v];
            par[find(x)] = find(y);
        }
        int maxi = 0;
        FOR(i, n) maxi = max(maxi, ++cnt[find(i)]);
        pf1(maxi);
    }
    return 0;
}













