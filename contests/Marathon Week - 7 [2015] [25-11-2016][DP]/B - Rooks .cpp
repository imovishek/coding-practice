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
lint ncr[35][35];
int nCr(int n, int r)
{
    if(n==r || r==0) return 1;
    if(ncr[n][r]!=-1) return ncr[n][r];
    return ncr[n][r] = nCr(n-1, r-1) + nCr(n-1, r);
}
int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    mem(ncr, -1);
    lint fact[31]={1};
    for(int i = 1;i<31; i++) fact[i] = fact[i-1] * i;
    pf("%lld\n",fact[16]);
    sf1(t);
    while(t--)
    {
        int n, k;
        sf2(n, k);
        pcase(tst++);
        if(n<k) {pf1(0); continue;}
        pf("%lld\n", fact[k]*nCr(n, k)*nCr(n, k));
    }
    return 0;
}














