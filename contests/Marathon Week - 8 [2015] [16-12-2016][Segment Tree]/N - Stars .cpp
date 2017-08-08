/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<cstdio>
#include<cstring>
#include<algorithm>
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

struct tt{
    int first, second, ts;
    tt(){}

    bool operator<(const tt &a) const{
       if(second!=a.second) return second<a.second;
       else return first<a.first;
    }

};

int tree[mx*3];
void update(int node, int b, int e, int i)
{
    if(b==e && e==i){
        tree[node]++;
        return;
    }
    if(i<b || e<i) return;
    int lson = node*2, rson = lson+1, mid = b +(e-b)/2;
    update(lson, b, mid, i);
    update(rson, mid+1, e, i);
    tree[node] = tree[lson] + tree[rson];
}

int query(int node, int b, int e, int i, int j)
{
    if(e<i || j<b) return 0;
    if(i<=b && e<=j) return tree[node];
    int lson = node*2, rson = lson+1, mid = b +(e-b)/2;
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
    int n;
    sf1(n);
    tt ara[n];
    int maxi = 0;
    FOR(i, n) {
        sf2(ara[i].fs, ara[i].sc);
        ara[i].ts = i;
        maxi = max(maxi, ara[i].fs);
    }
//    sort(ara, ara+n);
    int ans[n];
    mem(ans, 0);
    FOR(i, n)
    {
        ans[ query(1, 0, maxi, 0, ara[i].fs) ] ++;
        update(1, 0, maxi, ara[i].fs);
    }

    FOR(i, n) pf1(ans[i]);

    return 0;
}














