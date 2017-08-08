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
#define mx              500050

using namespace std;
typedef long long int lint;
typedef double dbl;

lint prime[41541+7];
bool mark[mx];
void sieve()
{
    for(int i = 3; i*i<=mx; i+=2)
        if(!mark[i])
            for(int j = i*i; j<mx ; j+=i+i)
                mark[j] = 1;
    prime[0] = 2;
    int pos = 1;
    for(int i = 3; i<mx ; i+=2)
        if(!mark[i]) prime[pos++] = i;
//    pf1(pos);
//    pf1(prime[pos-1]);
}
lint power(lint n, int p)
{
    if(p==0) return 1;
    if(p&1) return n * power(n, p-1);
    lint mo = power(n, p/2);
    return mo*mo;
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    sieve();
    sf1(t);
    while(t--)
    {
        lint n;
        lint ans = 1;
        sf("%lld", &n);
        lint tmp = n;
        for(int i = 0; prime[i]*prime[i]<=n ; i++)
        {
            int cnt = 0;
            while(n%prime[i]==0) {
                    cnt++;
                    n/=prime[i];
            }
            if(cnt){
                ans*=(power(prime[i], cnt+1) - 1)/(prime[i]-1);
            }
        }
        if(n>1){
            ans*=(power(n, 2)-1)/(n-1);
        }

        pf("%lld\n", ans-tmp);
    }
    return 0;
}














