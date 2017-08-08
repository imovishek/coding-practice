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
lint tree[mx*4], lazy[mx*4];

lint query(int node, lint b, lint e, int i, int j)
{
    int lson = node*2, rson = lson+1;
    lint mid = b + (e-b)/2;
    if(lazy[node]!=0){
        if(b!=e){
            lazy[lson]+=lazy[node];
            lazy[rson]+=lazy[node];
        }
        tree[node]+= (e-b+1) * 1LL * lazy[node];
        lazy[node] = 0;
    }
    if(i>e || j<b) return 0LL;
    if(b>=i && e<=j) return tree[node];
    lint x = query(lson, b, mid, i, j);
    lint y = query(rson, mid+1, e, i, j);
    return x+y;
}

lint update(int node, lint b, lint e, int i, int j, int val)
{
    int lson = node*2, rson = lson+1;
    lint mid = b+(e-b)/2;
    if(i<=b && e<=j) {lazy[node]+=val;}
     if(lazy[node]!=0){
        if(b!=e){
            lazy[lson]+=lazy[node];
            lazy[rson]+=lazy[node];
        }
        tree[node]+= ( e-b+1 ) * lazy[node];
        lazy[node] = 0;
    }
    if(i>e || j<b) return 0;
    if(i<=b && e<=j) {return tree[node];}

    lint x = update(lson, b, mid, i, j, val);
    lint y = update(rson, mid+1, e, i, j, val);
    tree[node] = tree[lson] + tree[rson];
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
        mem(tree, 0);
        mem(lazy, 0);
        pf("Case %d:\n", tst++);
        FOR(i, m){
            int sig, x, y, v;
            sf3(sig, x, y);
            if(sig==0){
                sf1(v);
                update(1, 0, n-1, x, y, v);
            }
            else{
                pf("%lld\n", query(1, 0, n-1, x, y));
            }
        }

    }
    return 0;
}














