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
#define mx              1000007

using namespace std;
typedef long long int lint;
typedef double dbl;


lint pref[mx], suf[mx];
char ara[mx];
int prm = 31;
lint bigmod(lint a, lint p)
{
    if(p==0) return 1;
    if(p&1) return (a * bigmod(a, p-1)) % MOD;
    lint mo = bigmod(a, p/2);
    return (mo*mo) % MOD;
}
lint modinv[mx];

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    sf1(t);
    modinv[0] = 1;
    lint prm_inv = bigmod(prm, MOD-2);;
    FOR1(i, mx-1) {
        modinv[i] = (modinv[i-1] * prm_inv) % MOD;
    }
    while(t--)
    {
        sf("%s", ara);
        int n = strlen(ara);
        lint hashi = 0;
        suf[n+1] = 0;
        lint mult = 1;
        FOR1(i, n) {
            pref[i] = (pref[i-1] + mult*(ara[i-1] - 'a')) % MOD;
            mult = (mult * prm) % MOD;
        }
        mult = 1;
        for(int i = n; i>0; i--) {
                suf[i] = (suf[i+1] + mult*(ara[i-1] - 'a')) % MOD;
                mult = (mult * prm) % MOD;
        }
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            int j = n-1;
            lint hash1 = (((pref[j+1] - pref[i] + MOD)% MOD) * modinv[i]) % MOD;
            lint hash2 = (suf[i+1]) % MOD ;
            if(hash1==hash2) {ans = i; break;}
        }
        pcase(tst++);
        pf1(ans+n);
    }
    return 0;
}














