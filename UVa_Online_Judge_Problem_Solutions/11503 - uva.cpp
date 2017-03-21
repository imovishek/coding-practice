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
int par[1000007];
int siz[1000007];
int find(int u)
{
    if(par[u]!=u) par[u] = find(par[u]);
    return par[u];
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int n, pos = 0;
        sf1(n);
        map<string, int> mp;
        map<string, int> ::iterator ita, itb;
        string u, v;
        FOR(i, n){
            int x, y;
            cin >> u >> v;
            ita = mp.find(u), itb = mp.find(v);
            if(ita==mp.end()){
                mp[u] = pos++;
                x = par[pos-1] = pos-1;
                siz[pos-1] = 1;
            }
            else x = ita->sc;
            if(itb==mp.end()){
                mp[v] = pos++;
                y = par[pos-1] = pos-1;
                siz[pos-1] = 1;
            }
            else y = itb->sc;
            int a = find(x), b = find(y);
            if(a==b) pf("%d\n", siz[a]);
            else{
                pf("%d\n", siz[a]+siz[b]);
                par[a] = b;
                siz[b]+=siz[a];
            }
        }
    }
    return 0;
}














