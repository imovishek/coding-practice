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
#define mx              40007

using namespace std;
typedef long long int lint;
typedef double dbl;
vector<int> divi[mx];
int prime[mx];
void sieve()
{
    prime[0] = 2;
    int pos = 1;
    for(int i=3; i<mx ; i+=2)
        if(divi[i].size()==1) prime[pos++] = i;
}
int sz;
lint prmf(lint n)
{
    lint ret = 1;
    for(int i = 0; prime[i] * prime[i]<=n ; i++){
        int x = prime[i];
        if(n%x==0){
            ret *= x;
            while(n%x==0) n/=x;
            sz++;
        }
    }
    if(n>1) ret*=n, sz++;
    return ret;
}
int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    for(int i = 2; i<mx; i+=2) divi[i].pb(2);
    for(int i = 3; i<mx; i+=2)
        if(divi[i].size()==0){
            for(int j = i; j<mx ; j+=i)
                divi[j].pb(i);
        }
    sieve();
    sf1(t);
    while(t--)
    {
        lint n, k;
        sf2ll(n, k);
        k*=n;
        sz = 0;
        lint xn = prmf(n);
        lint ans = 0;
        lint sq = sqrt(xn);
        for(lint i = 1; i<=sq; i++)
        {
            if(xn%i==0){
                lint x = (k/i) - (n/i);
                lint j = (xn/i);
                lint y = (k/j) - (n/j);
                if(i==sq && sq*sq==xn) y = 0;
                if(i==1) x = 0;
                int a = divi[i].size(), b = sz - a;
                int asign, bsign;
                if(a&1) asign = 1;
                else asign = -1;
                if(b&1) bsign = 1;
                else bsign = -1;
                ans += asign * x + bsign * y;
//                pf("ans = %lld... %lld %lldta && %lld %lldta\n",ans, i,x,j,y);
            }
        }
//        pf1((int)ans);
        cout << k-n - ans << endl;
    }
    return 0;
}














