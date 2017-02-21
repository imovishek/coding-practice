/*
ID: ovishek1
LANG: C++11
PROB: dualpal
*/


#include<bits/stdc++.h>
#define pii             pair<int,int>
#define mkp             make_pair
#define fs              first
#define sc              second
#define pb              push_back
#define ppb             pop_back()
#define all(vt)         vt.begin(), vt.end()
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
#define repr(vt, it)    for(typeof(vt.begin()) it = vt.begin(); it!=vt.end(); it++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;
typedef vector<int> vi;

bool ispali_conv(lint n, int b)
{
    vi vt;
    while(n){
        vt.pb(n%b);
        n/=b;
    }
    vi rvt (vt.rbegin(), vt.rend());
    return (vt==rvt);
}

int main()
{
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int t, tst = 1;
    lint n, s;
    sf2ll(n , s);
    int cnt = 0;
    while(1){
        if(cnt==n) break;
        s++;
        int pali_cnt = 0;
        for(int b = 2; b<=10; b++){
            pali_cnt += ispali_conv(s, b);
            if(pali_cnt==2) break;
        }
        if(pali_cnt==2) pf("%d\n", s), cnt++;
    }
    return 0;
}












