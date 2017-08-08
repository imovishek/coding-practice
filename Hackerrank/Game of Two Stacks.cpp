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


int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        lint n, m, x;
        sf3ll(n, m , x);
        lint a[n], b[m];
        FOR(i, n) {
            sf1ll(a[i]);
            if(i) a[i] += a[i-1];
        }
        FOR(i, m) {
            sf1ll(b[i]);
            if(i) b[i] += b[i-1];
        }
        int maxi = upper_bound(b, b+m, x) - b;

        FOR(i, n){
            lint roise = x - a[i];
            if(roise<0) break;
            maxi = max(maxi, i + 1 + int(upper_bound(b, b+m, roise) - b));
        }
        cout << maxi << endl;
    }
    return 0;
}















