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
int lazy[mx*4];
struct data{
    int a[3];
    data(){}
    data(int x, int y, int z)
    {
        a[0] = x, a[1] = y, a[2] = z;
    }
} tree[mx*4];

void init(int node, int b, int e)
{
    tree[node].a[0] = (e-b+1);
    if(b==e) return;
    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    init(lson, b, mid);
    init(rson, mid+1, e);
}

void update(int node, int b, int e, int i, int j)
{
    if(i<=b && e<=j) lazy[node] = (lazy[node]+1)%3;
    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    if(lazy[node]!=0){
        if(b!=e){
            lazy[lson] = (lazy[lson] + lazy[node]) % 3;
            lazy[rson] = (lazy[rson] + lazy[node]) % 3;
        }
        if(lazy[node]==1){
            int prev = tree[node].a[2];
            FOR(i, 3) {
                swap(prev, tree[node].a[i]);
            }
        }
        else{
            int prev = tree[node].a[0];
            FOR(i, 3) {
                swap(prev, tree[node].a[2-i]);
            }
        }
        lazy[node] = 0;

    }

    if(e<i || j<b) return;
    if(i<=b && e<=j) return;
    update(lson, b, mid, i, j);
    update(rson, mid+1, e, i, j);
    tree[node] = data(tree[lson].a[0]+tree[rson].a[0],tree[lson].a[1]+tree[rson].a[1],tree[lson].a[2]+tree[rson].a[2]);
}

data query(int node, int b, int e, int i, int j)
{
    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    if(lazy[node]!=0){
        if(b!=e){
            lazy[lson] = (lazy[lson] + lazy[node]) % 3;
            lazy[rson] = (lazy[rson] + lazy[node]) % 3;
        }
        if(lazy[node]==1){
            int prev = tree[node].a[2];
            FOR(i, 3) {
                swap(prev, tree[node].a[i]);
            }
        }
        else{
            int prev = tree[node].a[0];
            FOR(i, 3) {
                swap(prev, tree[node].a[2-i]);
            }
        }
        lazy[node] = 0;
    }
    if(e<i || j<b) return data(0, 0, 0);
    if(i<=b && e<=j) return tree[node];
    data x = query(lson, b, mid, i, j);
    data y = query(rson, mid+1, e, i, j);
    return data(x.a[0]+y.a[0],x.a[1]+y.a[1],x.a[2]+y.a[2]);
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
        FOR(i, 4*mx) mem(tree[i].a, 0);
        mem(lazy, 0);
        init(1, 0, n-1);
        pf("Case %d:\n", tst++);
        FOR(i, m)
        {
            int sig, l, r;
            sf3(sig, l, r);
            if(sig==0) update(1, 0, n-1, l, r);
            else pf1(query(1, 0, n-1, l, r).a[0]);
        }
    }
    return 0;
}














