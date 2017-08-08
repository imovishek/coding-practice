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
    int n;
    sf1(n);
    int a;
    sf1(a);
    int maxi = a, mini = a;
    int cnta = 0, cntb = 0;
    FOR(i, n-1)
    {
        sf1(a);
        if(maxi<a) {cnta++; maxi = a;}
        if(mini>a) {cntb++; mini = a;}
    }
    cout << cnta << " " << cntb << endl;
    return 0;
}















