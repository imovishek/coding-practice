#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fpos ffoos
ll mulmod(ll a, ll b, ll m)
{
//    __int128 xa = a, xb = b;
//    __int128 ret = xa*xb%m;
//    return (ll) ret;
    if(b==0) return 0;
    if(b&1) return (2ll * mulmod(a, b/2, m) % m + a) % m;
    return 2ll * mulmod(a, b/2, m) % m;
}
double l;
inline ll bigmod(ll a, ll p, ll m)
{
    ll ret = 1;
    while(p)
    {
        if(p&1) ret = mulmod(ret, a, m);
        a = mulmod(a, a, m);
        p/=2;
    }
    return ret;
}
inline bool millerRobin(ll p, int iter = 20)
{
    if(p==3 || p==2 || p==5) return true;
    if(p%2==0) return 0;
    if(p<3) return 0;

    for(int i = 0; i<iter; i++)
    {
        ll a = ((rand() << 15) | rand()) % (p-4) + 2;
        ll s = p - 1;
        while(s%2==0) s/=2;
        ll mod = bigmod(a, s, p);
        if(mod==1 || mod==p-1) continue;
        bool flag = 0;
        s *= 2;
        while(s != p-1)
        {
            mod = mulmod(mod, mod, p);
            if(mod==p-1){
                flag = 1;
                break;
            }
            s*=2;
        }
        if(flag==0) return 0;
    }
    return 1;
}

ll PollardRho(ll n)
{
    srand (time(NULL));
    if (n==1) return n;
    if (n % 2 == 0) return 2;
    ll x = (rand()%(n-2))+2;
    ll y = x;
    ll c = (rand()%(n-1))+1;
    ll d = 1;

    while(d==1)
    {
//        if((clock() - l)/CLOCKS_PER_SEC > 0.3) assert(0);
        x = (mulmod(x, x, n) + c)%n;
        y = (mulmod(y, y, n) + c)%n;
        y = (mulmod(y, y, n) + c)%n;
        d = __gcd(abs(x-y), n);
    }
    if(d==1 || d==n) return PollardRho(n);
    return d;
}

ll brent(ll n)
{
    if(n%2==0) return 2;
    ll y = ((rand() << 15) | rand()) % (n-1) + 1;
    ll c = ((rand() << 15) | rand()) % (n-1) + 1;
    ll m = ((rand() << 15) | rand()) % (n-1) + 1;
    ll g = 1, r = 1, q = 1, ys, x;
    while(g==1){
        x = y;
        for(int i = 0; i<r; i++)
            y = (mulmod(y, y, n) + c) % n;
        ll k = 0;
        while( k<r && g==1 ){
            ys = y;
            for(int i = 0; i<min(m, r-k); i++){
                y = (mulmod(y, y, n) + c) % n;
                q = mulmod(q , abs(x-y), n);
            }
            g = __gcd(q, n);
            k = k + m;
        }
        r *= 2;
    }
    if(g==n){
        while(true){
            ys = (mulmod(ys, ys, n) + c) % n;
            g = __gcd(abs(x-ys), n);
            if(g > 1) break;
        }
    }
    return g;
}
const int mx = 1000000;
ll prm[mx];
bitset<mx> mark;
int pos = 1;
inline void sieve()
{
    for(int i = 3; i*i<mx; i+=2)
        if(!mark[i])
            for(int j = i*i; j<mx; j+=i+i)
                mark[j] = 1;
    prm[0] = 2;
    for(int i = 3; i<mx; i+=2)
        if(!mark[i]) prm[pos++] = i;
}
ll fact[20], fpos = 0;
int cnt[20];
int dppos = 0;
pair<ll, ll> divphi[200005];
void rec(int ps, ll mult, ll phi)
{
    if(mult > 4e18 / phi) return;
    if(ps==fpos){
        if(mult==1) return;
        divphi[dppos++] = {mult, phi};
        return;
    }
    rec(ps+1, mult, phi);
    ll nw = 1;
    for(int i = 0; i<cnt[ps]; i++)
    {
        nw *= fact[ps];
        ll nwphi = phi * nw;
        nwphi -= nwphi / fact[ps];
        rec(ps+1, mult*nw, nwphi);
    }
}

const int multiplier[] = {1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};
#define nelems(x) (sizeof(x) / sizeof((x)[0]))
ll SQUFOF( ll N )
{
    ll D, Po, P, Pprev, Q, Qprev, q, b, r, s;
    ll L, B, i;
    s = (ll)(sqrtl(N)+0.5);
    if (s*s == N) return s;
    for (int k = 0; k < nelems(multiplier) && N <= UINT64_MAX/multiplier[k]; k++) {
        D = multiplier[k]*N;
        Po = Pprev = P = sqrtl(D);
        Qprev = 1;
        Q = D - Po*Po;
        L = 2 * sqrtl( 2*s );
        B = 3 * L;
        for (i = 2 ; i < B ; i++) {
            b = (ll)((Po + P)/Q);
            P = b*Q - P;
            q = Q;
            Q = Qprev + b*(Pprev - P);
            r = (ll)(sqrtl(Q)+0.5);
            if (!(i & 1) && r*r == Q) break;
            Qprev = q;
            Pprev = P;
        };
        if (i >= B) continue;
        b = (ll)((Po - P)/r);
        Pprev = P = b*r + P;
        Qprev = r;
        Q = (D - Pprev*Pprev)/Qprev;
        i = 0;
        do {
            b = (ll)((Po + P)/Q);
            Pprev = P;
            P = b*Q - P;
            q = Q;
            Q = Qprev + b*(Pprev - P);
            Qprev = q;
            i++;
        } while (P != Pprev);
        r = __gcd(N, Qprev);
        if (r != 1 && r != N) return r;
    }
    return 0;
}
int main()
{
//    cout << PollardRho(21) << endl;
    srand(time(NULL));
    sieve();
//    for(int i = 0; i<25; i++)
//        cout << prm[i] << " ";
//    cout << endl;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ll fn;
        scanf("%lld", &fn);
        if(fn==1){
            printf("2\n");
            continue;
        }
        ll tmp = fn;
        fpos = 0, dppos = 0;
        for(int i = 0; i<pos; i++)
        {
            int c = 0;
            while(tmp % prm[i]==0){
                tmp /= prm[i];
                c++;
            }
            if(c) fact[fpos++] = prm[i], cnt[fpos-1] = c;
        }
        ll sq = round(sqrt(tmp));
        if(tmp==1);
        else if(sq * sq == tmp){
            fact[fpos++] = sq;
            cnt[fpos-1] = 2;
        } else if(millerRobin(tmp)){
            fact[fpos++] = tmp;
            cnt[fpos-1] = 1;
        } else{
            ll divi = SQUFOF(tmp);
            fact[fpos++] = divi;
            cnt[fpos-1] = 1;
            fact[fpos++] = tmp/divi;
            cnt[fpos-1] = 1;
        }
        rec(0, 1, 1);
        ll ans = -1;
        for(int i = 0; i<dppos; i++)
        {
            ll d = divphi[i].first, p = divphi[i].second;

            if(d > 4e18 / p) continue;
            if(divphi[i].first * divphi[i].second / 2ll == fn){
                ans = divphi[i].first;
                break;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}



















