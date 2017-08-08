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
pii ara[mx];

void init(int node, int b, int e)
{
    if(b==e){
        tree[node] = 1;
        return;
    }

    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    init(lson, b, mid);
    init(rson, mid+1, e);
    tree[node] = max(tree[lson], tree[rson]);
    int x = max(b, ara[mid].fs), y = min(ara[mid].sc, e);
    tree[node] = max(tree[node], y-x+1);

}

int query(int node, int b, int e, int i, int j)
{
    if(e<i || j<b) return 0;
    if(i<=b && e<=j) return tree[node];

    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    int a = query(lson, b, mid, i, j);
    int t = query(rson, mid+1, e, i, j);
    int ret =  max(a, t);
    if(a && t){
        int x = max(i, ara[mid].fs), y = min(ara[mid].sc, j);
        ret = max(ret, y-x+1);
    }
    return ret;
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
        int n, c, m;
        sf3(n, c, m);
        int prev, x = 0;
        sf1(prev);
        FOR(i, n-1)
        {
            int a;
            sf1(a);
            if(prev!=a){
                for(int j = i; j>=x ; j--)
                    ara[j] = pii(x, i);
                x = i+1;
            }
            prev = a;
        }
        for(int j = n-1; j>=x ; j--)
                ara[j] = pii(x, n-1);
//        FOR(i, n) pf("%d %d**\n", ara[i].fs, ara[i].sc);
        mem(tree, 0);
        pf("Case %d:\n", tst++);
        init(1, 0, n-1);
        FOR(i , m)
        {
            int l, r;
            sf2(l, r);
            pf1(query(1, 0, n-1, l-1, r-1));
        }

    }
    return 0;
}














