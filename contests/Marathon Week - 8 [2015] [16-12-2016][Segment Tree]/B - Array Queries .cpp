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

int ara[mx], tree[mx*4];
int init(int node, int b, int e){

    if(b==e) return tree[node] = ara[b];
    int lson = node*2, rson = lson + 1, mid = b + (e-b)/2;
    init(lson, b, mid);
    init(rson, mid+1, e);
    return tree[node] = min(tree[lson] , tree[rson]);
}

int query(int node, int b, int e, int i, int j)
{
    if(j<b || e<i) return inf;
    if(i<=b && e<=j) return tree[node];
    int lson = node*2, rson = lson + 1, mid = b + (e-b)/2;
    int x = query(lson, b, mid, i, j);
    int y = query(rson, mid+1, e, i, j);
    return min(x,y);
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
        int n, m;
        sf2(n, m);
        FOR(i, n) sf1(ara[i]);
        init(1, 0, n-1);
        pf("Case %d:\n", tst++);
        FOR(i, m)
        {
            int l, r;
            sf2(l, r);
            pf1(query(1, 0, n-1, l-1, r-1));
        }
    }
    return 0;
}














