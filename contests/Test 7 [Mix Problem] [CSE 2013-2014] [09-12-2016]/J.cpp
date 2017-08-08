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
#define pcase(x)        printf("Case %d:\n",x)
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

int ara[mx], tree[3*mx];
int init(int node, int b, int e)
{
    if(b==e) {
            return tree[node]=ara[b];
    }
    int mid = (b+e)/2, left = node*2;
    tree[node] = min(init(left+1, mid+1, e), init(left, b, mid));
//    pf("%d %d %d*\n", b, e, tree[node]);
    return tree[node];
}

int query(int node, int b, int e, int i, int j)
{
    if(b>=i && e<=j) return tree[node];
    if(e<i || b>j) return inf;
    int mid = (b+e)/2, left = node*2;
    int x;
    x = min(query(left+1, mid+1, e, i, j), query(left, b, mid, i, j));
    return x;
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
        FOR1(i, n) sf1(ara[i]);
        init(1, 1, n);
        pcase(tst++);
        FOR(i, m){
            int u, v;
            sf2(u, v);
            pf1(query(1, 1, n, u, v));
        }
    }
    return 0;
}














