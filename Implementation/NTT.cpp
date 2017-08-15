/*input
3 3
3 5 11
*/

#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
 
inline ld gett() { return ld(clock()) / CLOCKS_PER_SEC; }
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
 
int n, k;
vector<int> a;
 
const int LOGN = 20, N = (1 << LOGN) + 3;
 
namespace fftMod {
    typedef int T;
    inline li mul(li a, li b, li mod) {
        li q = li(ld(a) * b / mod);
        li ans = (a * b - q * mod) % mod;
        return ans < 0 ? ans + mod : ans;
    }
    inline int mul(int a, int b, int mod) { return int(a * 1ll * b % mod); }
    inline T add(T a, T b, T mod) { return a + b >= mod ? (a + b - mod) : (a + b); }
    inline T sub(T a, T b, T mod) { return add(a, mod - b, mod); }
    T gcd(T a, T b, T& x, T& y) {
        if (!a) {
            x = 0, y = 1;
            return b;
        }
        T xx, yy, g = gcd(b % a, a, xx, yy);
        x = yy - b / a * xx;
        y = xx;
        return g;
    }
    inline T inv(T a, T mod) {
        T x, y;
        assert(gcd(a, mod, x, y) == 1);
        x %= mod;
        (x < 0) && (x += mod);
        return x;
    }
    inline T binPow(T a, T b, T mod) {
        T ans = 1;
        while (b) {
            if (b & 1) ans = mul(ans, a, mod);
            a = mul(a, a, mod);
            b >>= 1;
        }
        return ans;
    }
 
    int logn, n;
    T p, g;
    inline int get(int i) {
        int ans = 0;
        forn(j, logn) if (i & (1 << j)) ans |= 1 << (logn - 1 - j);
        return ans;
    }
    void fft(T *a, bool inverse) {
        forn(i, n) {
            int ni = get(i);
            if (i < ni) swap(a[i], a[ni]);
        }
        assert(binPow(g, n, p) == 1);
        for (int i = 0; i < logn; i++) {
            T cg = binPow(g, 1 << (logn - (i + 1)), p);
            assert(binPow(cg, 1 << (i + 1), p) == 1);
            assert(binPow(cg, 1 << i, p) != 1);
            if (inverse) cg = inv(cg, p);
            for (int j = 0; j < n; j += (1 << (i + 1))) {
                T cur = 1;
                for (int k = 0; k < (1 << i); k++) {
                    T u = a[j + k], v = mul(a[j + (1 << i) + k], cur, p);
                    a[j + k] = add(u, v, p);
                    a[j + (1 << i) + k] = sub(u, v, p);
                    cur = mul(cur, cg, p);
                }
            }
        }
        if (inverse) forn(i, n) a[i] = mul(a[i], inv(n, p), p);
    }
    // p                   | deg | g
    // 469762049             26    3
    // 998244353             23    3
    // 1107296257            24    10
    // 10000093151233        26    5
    // 1000000523862017      26    3
    // 1000000000949747713   26    2
    inline void prepare() {
        p = 469762049; // You can use your own p = c * 2^logn + 1
        g = 3;         // but you should find it's generator
        assert(!((p - 1) & (n - 1)));
        T cs = (p - 1) >> logn;
        g = binPow(g, cs, p);
    }
    void mul(T *a, int na, T *b, int nb, T *ans) {
        while (na && !a[na - 1]) na--;
        while (nb && !b[nb - 1]) nb--;
        logn = 0; while ((1 << logn) < na + nb) logn++;
        n = 1 << logn;
 
        static T _b[N];
        forn(i, n) ans[i] = a[i], _b[i] = b[i];
        prepare();
        fft(ans, false);
        fft(_b, false);
        forn(i, n) ans[i] = mul(ans[i], _b[i], p);
        fft(ans, true);
    }
};
 
inline void mul(int* a, int* b) {
    forn(i, 1 << LOGN) {
        a[i] = !!a[i];
        b[i] = !!b[i];
    }
    fftMod::mul(a, 1 << LOGN, b, 1 << LOGN, a);
}
 
inline void binPow(int* a, int b) {
    static int ans[N];
    forn(i, 1 << LOGN) ans[i] = !i;
    while (b) {
        if (b & 1) mul(ans, a);
        mul(a, a);
        b >>= 1;
    }
    forn(i, 1 << LOGN) a[i] = ans[i];
}
 
int ans[N];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		ans[x]++;
	}
	binPow(ans, k);
	for(int i = 0; i < N; i++)
		if(ans[i]){
			cout << i << " ";
		}

	return 0;
}