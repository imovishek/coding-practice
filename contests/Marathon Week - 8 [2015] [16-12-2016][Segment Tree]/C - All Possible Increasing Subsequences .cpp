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

void update(int node, int b, int e, int i, int val)
{
    if(i<b || e<i) return;
    if(b==e && i==b) {
        tree[node] = val;
        return;
    }

    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    update(lson, b, mid, i, val);
    update(rson, mid+1, e, i, val);
    tree[node] = (tree[lson] + tree[rson]) % MOD;
}

int query(int node, int b , int e, int i)
{
    if(i<b) return 0;
    if(e<=i) return tree[node];
    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    int x = query(lson, b, mid, i);
    int y = query(rson, mid+1, e, i);
    return (x+y) % MOD;
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
        mem(tree, 0);
        pii ara[n];
        FOR(i, n)
        {
            sf1(ara[i].fs);
            ara[i].sc = i;
        }
        sort(ara, ara+n);
        queue <pii> Q;
        int prev = ara[0].fs;
        FOR(i, n)
        {
            if(prev!=ara[i].fs){
                while(!Q.empty()){
                    pii a = Q.front();
                    Q.pop();
                    update(1, 0, n-1, a.fs, a.sc);
                }
            }
            int x;
            Q.push(pii(ara[i].sc, x = (query(1, 0, n-1, ara[i].sc)+1) % MOD));
            prev = ara[i].fs;
        }
        while(!Q.empty()){
            pii a = Q.front();
            Q.pop();
            update(1, 0, n-1, a.fs, a.sc);
        }
        pcase(tst++);
        pf1(query(1, 0, n-1, n-1) % MOD);
    }
    return 0;
}














