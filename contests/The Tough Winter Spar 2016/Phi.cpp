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

int ara[10000];
int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int sum = 0;
    FOR1(i, 2015) sum += ara[__gcd(i, 2015)]++;
    pf1(sum);
    FOR(i, 2015)
    {
        if(ara[i]) pf("%d %d\n", i, ara[i]);
    }
    cout << 12187 + eulerphi(2015) << endl;
    return 0;
}














