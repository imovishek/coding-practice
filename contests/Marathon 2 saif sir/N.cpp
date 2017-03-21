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
#define mem(arr,x) memset((arr), (x), sizeof((arr)))
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;


int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int n, k;
        sf2(n, k);
        k++, n++;
        int ara[n];
        int mx = 0, sum = 0;
        FOR(i, n) {
            sf1(ara[i]);
            mx = max(mx, ara[i]);
            sum += ara[i];
        }
        if(n==k)
        {
            pcase(tst++);
            pf1(mx);
            FOR(i, n) pf1(ara[i]);
            continue;
        }
        int l = mx, r = sum, ans = inf;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int x = 0, s = 0;
            FOR(i, n)
            {
                if(s+ara[i]<=mid) s+=ara[i];
                else {
                    x++;
                    s = ara[i];
                }
            }
            if(s) x++;
            if(x<=k) {
                    ans = mid;
                    r = mid-1;
            }
            else l = mid+1;
        }
        pcase(tst++);
        pf("%d\n", ans);
        int x = 0;
        int b[k];
        mem(b, 0);
        FOR(i, k) {
            int s = 0;
            while(x<n && s+ara[x]<=ans) s+=ara[x++];
            b[i] = s;
        }
        x = 0;
        for(int i = k-1; i>=0 ; i--)
        {
            if(b[i]) {x = i; break;}
        }
        int y = n-1;
        if(x!=k-1){
            for(int i = k-1; i>=0 ; i--)
            {
                if(b[i]) break;
                b[i] = ara[y];
                b[x]-=ara[y];
                if(b[x]==0) x--;
                y--;
            }
        }
        FOR(i, k)
        pf1(b[i]);
    }
    return 0;
}

/*
4
3 2
5
1
1
1
*/












