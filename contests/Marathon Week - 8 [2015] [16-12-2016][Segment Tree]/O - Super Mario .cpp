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

int tree[mx*4];
template<class T> bool comp(T a, T b)
{
    return a>b;
}

void update(int node, int b, int e, int i)
{
    if(b==e && b==i){
        tree[node] = 1;
        return;
    }
    if(i<b || e<i) return;
    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    update(lson, b, mid, i);
    update(rson, mid+1, e, i);
    tree[node] = tree[lson] + tree[rson];
}

int query(int node, int b, int e, int i, int j)
{
    if(e<i || j<b) return 0;
    if(i<=b && e<=j) return tree[node];
    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    int x = query(lson, b, mid, i, j);
    int y = query(rson, mid+1, e, i, j);
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
        mem(tree, 0);
        int n, m;
        sf2(n, m);
        pii val[n];
        int ans[m];
        FOR(i, n) {
            int a;
            sf1(a);
            val[i] = pii(a, i);
        }
        sort(val, val+n);
        pair< pii, pii> q[m];
        FOR(i, m)
        {
            sf3(q[i].sc.fs, q[i].sc.sc, q[i].fs.fs);
            q[i].fs.sc = i;
        }
        sort(q, q+m);
        int pos = 0;
        FOR(i, m)
        {
            while(pos<n && val[pos].fs<=q[i].fs.fs)
                update(1, 0, n-1, val[pos++].sc);
            ans[q[i].fs.sc] = query(1, 0, n-1, q[i].sc.fs, q[i].sc.sc);
        }
        pf("Case %d:\n", tst++);
        FOR(i, m)
            pf1(ans[i]);
    }
    return 0;
}














