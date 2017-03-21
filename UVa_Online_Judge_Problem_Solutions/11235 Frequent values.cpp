#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
int n, q;
int ara[100005], tree[300005];
pii frec[100005];

int build(int node, int b, int e)
{
    if(b==e){
        tree[node] = 1;
        return 1;
    }
    int left = 2 * node, mid = b +(e-b)/2;
    int x = build(left, b, mid), y =  build(left+1, mid+1, e);
    int l = max(frec[mid].fs, b), r = min(frec[mid].sc, e);
    tree[node] = max(max(x, y), r-l+1);
    return tree[node];
}
int l1, r1;
int query(int node, int b, int e, int i, int j)
{
    if(e<i || b>j) return -inf;
    if(e<=j && b>=i) return tree[node];
    int left = 2 * node, mid = b +(e-b)/2;
    int x = query(left, b, mid, i, j);
    int y = query(left+1, mid+1, e, i, j);
    int ans = max(x, y);
    int l = max(frec[mid].fs, l1), r = min(frec[mid].sc, r1);
    return max(ans, r-l+1);
}
int main()
{
    int t, tst = 1;
    while(sf1(n) && n)
    {
        sf1(q);
        FOR(i, n) sf1(ara[i+1]);
        int a = ara[1], s = 0, x = 0;
        for(int i = 1; i<=n ; i++)
        {
            if(a==ara[i]) s++;
            else{
                for(int j = i-1; j>=1 ; j--)
                {
                    if(ara[j]==a) {
                            frec[j].sc = i-1;
                            frec[j].fs = x;
                    }
                    else break;
                }
                s = 1;
                x = i;
                a = ara[i];
            }
        }
        for(int j = n; j>=1 ; j--)
        {
            if(ara[j]==a)
            {
                frec[j].sc = n;
                frec[j].fs = x;
            }
            else break;
        }
        build(1, 1, n);
        FOR(i, q)
        {
            sf2(l1, r1);
            pf1(query(1, 1, n, l1, r1));
        }

    }
    return 0;
}














