#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i,x) for(int i=1;i<=(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;


int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int n;
        sf1(n);
        int ara[n], ans = 0;
        int flag[n+7];
        mem(flag, -1);
        map<int, pii> mp;
        FOR1(i, n) {
            sf1(ara[i]);
            mp[i] = pii(i, ara[i]);
            flag[ara[i]] = i;
        }
        int f = 0;
        FOR(i, n)
        {
            int a = n-i;
            int x = distance(mp.find(flag[a]) , mp.end())-1;
//            pf("%d %d*\n", x, a);
            ans+=x;
            if(x>2) f = 1;
            mp.erase(mp.find(flag[a]));
        }
        if(!f)pf1(ans);
        else pf("Too chaotic\n");
    }
    return 0;
}














