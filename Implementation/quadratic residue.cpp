#include<bits/stdc++.h>
#define mx 10000007
using namespace std;
#define ll long long

inline ll mm(const ll a,const ll b,const ll M){
    ll y=a*(double)b/M+.5,r=a*b-y*M;
    return r<0?r+M:r;
}
inline ll pw(ll a, ll p, ll m)
{
    ll ret = 1;
    while(p)
    {
        if(p&1) ret = mm(ret, a, m);
        a = mm(a, a, m);
        p/=2;
    }
    return ret;
}

ll mp(ll a, ll b, ll m) {
    ll result = 1;a %= m;
    while (b) {
        if (b & 1) {
            result = (result * a) % m;
        }
        a = (a*a) % m;
        b >>= 1;
    }
    return result;
}
ll ls(ll a, ll p) {
    return mp(a, (p - 1)/2, p);
}
ll iqr(ll a, ll p) {
    return ls(a, p) == 1;
}
int ts(ll n, ll p) {
    if (!iqr(n, p)) {
        return -1;
    }
    ll q = p - 1;
    ll s = 0;
    while (~q & 1) {
        q >>= 1;
        s += 1;
    }
    if (s == 1) {
        auto x = mp(n, (p + 1)/4, p);
        return x;
    }
    ll z = 0;
    for (ll k = 1; k < p; ++k) {
        if (!iqr(k, p)) {
            z = k;
            break;
        }
    }

    ll c = mp(z, q, p);
    ll r = mp(n, (q + 1)/2, p);
    ll t = mp(n, q, p);
    ll m = s;

    while (t != 1) {
        int i = 1;
        ll x = (t*t) % p;
        while (x != 1) {
            x = (x*x) % p;
            i += 1;
        }
        ll b = mp(c, (1ll << (m - i - 1)), p);
        r = (r*b) % p;
        c = (b*b) % p;
        t = (t*c) % p;
        m = i;
    }
    return r;
}
 
const int magic = 1000000;
int pr[magic] ;
#define MX 4000006
bitset<MX> mark;
bool millerRobin(ll p, int iter = 1)
{
    if(p < MX) return !mark[p];
    ll a = (rand()) % (p-4) + 2;
    ll s = p - 1;
    while(!(s&1)) s>>=1;
    ll mod = pw(a, s, p);
    if(mod==1 || mod==p-1) return 1;
    bool flag = 0;
    s<<=1;
    while(s != p-1)
    {
        mod = mm(mod, mod, p);
        if(mod==p-1){
            flag = 1;
            break;
        }
        s<<=1;
    }
    if(flag==0) return 0;
    // }
    return 1;
}
int cum[10000007];
int vis[10000007];
int main()
{
    for(int i = 4; i<MX; i+=2) mark[i] = 1;
    for(int i = 3; i*i<MX; i+=2)
        if(!mark[i])
            for(int j=i*i; j<MX; j+=i+i)
                mark[j] = 1;
    int ps = 0;
    int n = 10000000;
    for(int i = 2; i<magic; i++){
        if(!mark[i]){
            if(i%8 == 1 || i%8==7){
                pr[ps] = i;
                int a = ts((i+1)/2, i);
                for(int j = i+i+i; j+a<n; j+=i){
                    vis[j+a] = vis[j-a] = i;
                }
                ps++;
            }
        }
    }
    int cnt = 0;
    for(int i = 2; i<n; i++)
    {
        if(vis[i]){
            ll num = 2ll*i*i-1;
            assert(num%vis[i]==0 && num!=vis[i]);
            cum[i+1] = cum[i];
            continue;
        }
        
        if(millerRobin(1ll*2*i*i-1)) {
            cum[i+1]++;
        }
        cnt++;
        cum[i+1] += cum[i];
    }
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", cum[n]);
    }
    return 0;
}
