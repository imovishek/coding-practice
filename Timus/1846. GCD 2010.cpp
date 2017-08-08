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
int ara[mx];
int tree[mx*4];
int gcd(int a, int b)
{
    if(a<b) return gcd(b, a);
    if(b==0) return a;
    return gcd(b, a%b);
}

int update(int node, int b, int e, int i, int val)
{
    if(b==e && b==i) return tree[node] = val;
    if(i<b || e<i) return 0;

    int lson = node*2, rson = lson+1, mid = b+(e-b)/2;
    update(lson, b, mid, i, val);
    update(rson, mid+1, e, i, val);
    return tree[node] = gcd(tree[lson], tree[rson]);
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int pos = 0;
    int q, n = mx;
    map<int, vector<int> > mp;
    sf1(q);
    while(q--)
    {
        char ch;
        int a;
        sf(" %c %d", &ch, &a);
        if(ch=='+'){
            int ans = update(1, 0, n-1, pos, a);
            if(ans==0) ans = 1;
            pf1(ans);
            mp[a].push_back(pos++);
        }
        else{
            int i = mp[a].back();
            mp[a].pop_back();
            int ans = update(1, 0, n-1, i, 0);
            if(ans==0) ans = 1;
            pf1(ans);
        }
    }
    return 0;
}













