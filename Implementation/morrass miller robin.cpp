#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define ZERO (1e-10)
#define INF int(1e9+1)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define DEB printf("DEB!\n");
#define D(X) cout<<"  "<<#X": "<<X<<endl;
#define EQ(A,B) (A+ZERO>B&&A-ZERO<B)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define IN(n) int n;scanf("%d",&n);
#define FOR(i, m, n) for (int i(m); i < n; i++)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define FT(m, n) FOR(k, m, n)
#define aa first
#define bb second
void ga(int N,int *A){F(N)scanf("%d",A+i);}
#define MX (4000000)
#define IS(A) ((cn[A>>6]>>(A&63))&1)
#define ST(A) (cn[A>>6]|=1ULL<<((A&63)))
ll cn[1+(MX>>6)];
void gen(){
    ST(0),ST(1);
    int Q(1+sqrt(MX));
    for(ll i(4);i<MX;i+=2)ST(i);
    for(int k(3);k<=Q;k+=2)if(!IS(k))
        for(ll h(k<<1),j(k*k);j<MX;j+=h)ST(j);
}
inline ll mm(const ll a,const ll b,const ll M){
    ll y=a*(double)b/M+.5,r=a*b-y*M;
    return r<0?r+M:r;
}
inline ll pw(ll k,const ll M){
    ll r=2,n=4294967296;
    if(k&1)r=8;k>>=1;
    if(k&1)r<<=4;k>>=1;
    if(k&1)r<<=8;k>>=1;
    if(k&1)r<<=16;k>>=1;
    while(k){
        if(k&1)r=mm(r,n,M);
        n=mm(n,n,M),k>>=1;
    }
    return r;
}
inline pari<int, int> tonelli_shanks(int64_t n, int64_t p) {
    int64_t q = p - 1;
    int64_t s = 0;
    while (~q & 1) {
        q >>= 1;
        s += 1;
    }

    // p = 3 (mod 4)
    // Hence, the solutions are trivial.
    if (s == 1) {
        auto x = bigmod(n, (p + 1)/4, p);
        return {x, p - x};
    }

    // Select a quadratic non-residue (mod p)
    // This runs in expected logarithmic time
    // given Lagrange's theorem on the number of
    // quadratic residues modulo p.
    int64_t z = 0;
    for (int64_t k = 1; k < p; ++k) {
        if (bigmod(k, (p-1)/2, p) != 1) {
            z = k;
            break;
        }
    }

    int64_t c = mod_pow(z, q, p);
    int64_t r = mod_pow(n, (q + 1)/2, p);
    int64_t t = mod_pow(n, q, p);
    int64_t m = s;

    while (t != 1) {
        int i = 1;
        int64_t x = (t*t) % p;
        while (x != 1) {
            x = (x*x) % p;
            i += 1;
        }
        int64_t b = bigmod(c, (1ll << (m - i - 1)), p);
        // You could use mod_mul to ensure safety when
        // handling very large numbers.
        r = (r*b) % p;
        c = (b*b) % p;
        t = (t*c) % p;
        m = i;
    }

    return {r, p - r};
}
bool PT(const ll n){
    ll N=n-1,S;
    int s=0;
    while(!(N&1))N>>=1,s++;
    S=pw(N>>1,n);
    if(S==1||S==n-1)return 1;
    F(s-2)if((S=mm(S,S,n))==n-1)return 1;
    return 0;
}
const int p[]={7,17,23,31,41,47,71,73,79,89,97,103,113,127,137,151};
bool isP(const ll n){
    if(n<MX)return !IS(n);
    FOR(i,0,16)if(!(n%p[i]))return 0;
    return PT(n);
}
#define SZ (10000001)
int S[SZ],a;
int main(void){
    gen();
    S[16384]=S[262144]=S[285825]=S[1048576]=S[2097152]=S[8388608]=-1;
    FT(2,SZ)S[k]+=isP(2ll*k*k-1)+S[k-1];
    IN(_)F(_)scanf("%d",&a),printf("%d\n",S[a-1]);
    return 0;
} 
