/*
ID: ovishek1
LANG: C++11
PROB: beads
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


int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int t, tst = 1;
    int n;
    sf1(n);
    string st;
    cin >> st;
    int ans = 0;
    int flag[n];
    mem(flag, 0);
    FOR(i, n)
    {
        int x = 0, f = 0;
        f = 0;
        for(int j = i; (j!=i || !f); ){
            f = 1;
            if(st[j]!='r')
                x++, flag[j] = 1;
            else break;
            j = (j-1+n) % n;
        }
        f = 0;
        for(int j = (i+1)%n; (j!=((i+1)%n) || !f) ; ){
            f = 1;
            if(st[j]!='b' && flag[j]==0)
                x++;
            else break;
            j = (j+1) % n;
        }
        ans = max(ans, x);

        x = 0;
        mem(flag, 0);
        f = 0;
//        pf("***");
        for(int j = i; (j!=i || !f); ){
            f = 1;
//            pf("%d ", j);
            if(st[j]!='b')
                x++, flag[j] = 1;
            else break;
            j = (j-1+n) % n;
        }
        f = 0;
        for(int j = (i+1)%n; (j!=((i+1)%n) || !f) ; ){
            f = 1;
//            pf("%d ", j);
            if(st[j]!='r' && flag[j]==0)
                x++;
            else break;
            j = (j+1) % n;
        }
//        pf("&&\n");
//        pf("%d %d*\n", i, x);
        ans = max(ans, x);

    }
    pf1(ans);
    return 0;
}














