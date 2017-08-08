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

int lazy[6*mx];

void update(int node, int b, int e, int i, int j, int val)
{
    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    if(i<=b && e<=j) lazy[node] = val;
    if(lazy[node]!=0 && b!=e){
        lazy[lson] = lazy[rson] = lazy[node];
        lazy[node] = 0;
    }

    if(e<i || j<b) return;
    if(i<=b && e<=j) return;
    update(lson, b, mid, i, j, val);
    update(rson, mid+1, e, i, j, val);
}

int query(int node, int b, int e, int i)
{
    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    if(lazy[node]!=0 && b!=e){
        lazy[lson] = lazy[rson] = lazy[node];
        lazy[node] = 0;
    }
    if(i<b || e<i) return 0;
    if(b==e && b==i) return lazy[node];
    int x = query(lson, b, mid, i);
    int y = query(rson, mid+1, e, i);
    return x+y;
}

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
        int n;
        sf1(n);
        int l, r;
        mem(lazy, 0);
        FOR(i, n)
        {
            sf2(l, r);
            update(1, 0, 2*n-1, l-1, r-1, i+1);
        }
        int ara[n+1], ans = 0;;
        mem(ara, 0);
        FOR(i, 2*n) ara[ query(1, 0, 2*n-1, i) ] = 1;
        FOR1(i, n) ans+=ara[i];
        pcase(tst++);
        pf1(ans);
    }
    return 0;
}

/*
1
10
5 12
10 14
7 10
2 3
16 17
14 20
11 11
12 12
13 13
11 13

*/














