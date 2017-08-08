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
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;
vector<int> edge[mx], level[mx];
int n, q, m, k;
lint b[mx], a[mx][21];
int lev[mx];

lint bigmod(lint a, lint p, lint mod)
{
    if(p==0) return 1;
    if(p&1) return (a*bigmod(a, p-1, mod)) % mod;
    lint mo = bigmod(a, p/2, mod);
    return (mo*mo) % mod;
}


int eulerphi(int p)
{
    int tn = p;
    if(p%2==0){
        while(p%2==0) p/=2;
        tn-=(tn/2);
    }
    for(int i = 3; i*i<=p ; i+=2){
        if(p%i==0){
            while(p%i==0) p/=i;
            tn-=(tn/i);
        }
    }
    if(p>1) tn-=(tn/p);
    return tn;
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int phi[23], prev = MOD;
    phi[0] = MOD;
    FOR1(i, 21)
    {
        phi[i] = eulerphi(phi[i-1]);
//        pf("%d ", phi[i]);
    }
    sf3(n, m, k);
    FOR1(i, n) sf1ll(b[i]);
    FOR(i, k) {
        int r, a;
        sf1(r);
        while(r--) {
            sf1(a);
            level[i].pb(a);
            lev[a] = i;
        }
    }

    FOR(i, m){
        int u, v;
        sf2(u, v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    for(int i = k-1; i>=0; i--)
    {
        FOR(j, level[i].size())
        {
            int u = level[i][j], cnt = 0;
            FOR(k, edge[u].size()){
                int v = edge[u][k];
                if(lev[v]==i+1){
                    cnt++;
                    FOR(l, i+1)
                    {
                        a[u][l] = (a[u][l] + bigmod(b[u], a[v][l+1], phi[l])) % phi[l];
                    }
                }
            }
            if(cnt==0) {
                FOR(i, 21)
                    a[u][i] = b[u] % phi[i];
            }
        }
    }
    sf1(q);
    FOR(i, q)
    {
        int u;
        sf1(u);
        pf1(a[u][0]);
    }

//    cout << a[2][1] << ' ' << a[3][1] << endl;
    return 0;
}














