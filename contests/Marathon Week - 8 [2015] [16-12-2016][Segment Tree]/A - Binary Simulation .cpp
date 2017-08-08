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
char ara[mx];

void update(int node, int b, int e, int i, int j)
{
    if(e<i || j<b) return;
    if(i<=b && e<=j) {
            lazy[node]^=1;
            return;
    }

    int lson = node*2, rson = lson+1, mid = b + (e-b)/2;
    update(lson, b, mid, i, j);
    update(rson, mid+1, e, i, j);
}

int query(int node, int b, int e, int i)
{
    if(i<b || e<i) return 0;
    if(b==e && i==b) return (ara[i] - '0') ^ lazy[node];
    int lson = node*2, rson = lson+1, mid = b + (e-b)/2;
    int x = query(lson, b, mid, i);
    int y = query(rson, mid+1, e, i);
    return (x^y) ^ lazy[node];
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
        sf("%s", ara);
        int n = strlen(ara);
        mem(lazy, 0);
        int q;
        sf1(q);

        pf("Case %d:\n", tst++);

        while(q--)
        {
            char ch;
            int i, j;
            sf(" %c", &ch);
            if(ch=='I'){
                sf2(i, j);
                update(1, 0, n-1, i-1, j-1);
            }
            else{
                sf1(i);
                pf1(query(1, 0, n-1, i-1));
            }
        }
    }
    return 0;
}














