/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<cstdio>
#include<iostream>
#include<vector>
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
#define inf             2000000007
#define pi              acos(-1.0)
#define mem(arr,x)      memset((arr), (x), sizeof((arr)));
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i=1;i<=(x); i++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;

struct data{
    int mini, maxi;
    data(){}
    data(int a, int b)
    {
        mini = a;
        maxi = b;
    }
}tree[400006];
int ara[mx];
void init(int node, int b, int e)
{
    if(b==e){
        tree[node] = data(ara[b], ara[b]);
        return;
    }

    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    init(lson, b, mid);
    init(rson, mid+1, e);
    tree[node] = data(min(tree[lson].mini, tree[rson].mini), max(tree[lson].maxi, tree[rson].maxi));
}

data query(int node, int b, int e, int i, int j)
{
    if(e<i || j<b) return data(inf, -inf);
    if(i<=b && e<=j) return tree[node];

    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    data a = query(lson, b, mid, i, j);
    data c = query(rson, mid+1, e, i, j);
    return data(min(a.mini, c.mini), max(a.maxi, c.maxi));
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n, k;
    sf1(t);
    while(t--)
    {
        sf2(n , k);
        FOR(i, n) sf1(ara[i]);
        init(1, 0, n-1);
        int maxi = 0;
        for(int i = 0, j = k-1; j<n; j++, i++)
        {

            data a = query(1, 0, n-1, i, j);
            if(a.maxi - a.mini > maxi) maxi = a.maxi - a.mini;
        }
        pcase(tst++);
        pf1(maxi);

    }
    return 0;
}














