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
void update(int node, int b, int e, int i, int val)
{
    if(b==e && i==b) {
        tree[node]+=val;
        ara[b] = tree[node];
        return;
    }
    if(i<b || i>e) return;
    int lson = node*2, rson = lson+1, mid = b + (e-b)/2;
    update(lson, b, mid, i, val);
    update(rson, mid+1, e, i, val);
    tree[node] = tree[lson] + tree[rson];
}

int query(int node, int b, int e, int i, int j)
{
    if(e<i || j<b) return 0;
    if(i<=b && e<=j) return tree[node];
    int lson = node*2, rson = lson+1, mid = b + (e - b)/2;
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
        int n, q;
        sf2(n, q);

        mem(tree, 0);
        FOR(i, n) {
            sf1(ara[i]);
            update(1, 0, n-1, i, ara[i]);
        }
        pf("Case %d:\n", tst++);
        while(q--)
        {
            int sig, i, j, v;
            sf1(sig);
            if(sig==1) {
                    sf1(i);
                    pf1(ara[i]);
                    update(1, 0, n-1, i, -ara[i]);
            }
            else if(sig==2){
                sf2(i, v);
                update(1, 0, n-1, i, v);
            }
            else{
                sf2(i, j);
                pf1(query(1, 0, n-1, i, j));
            }
        }
    }
    return 0;
}














