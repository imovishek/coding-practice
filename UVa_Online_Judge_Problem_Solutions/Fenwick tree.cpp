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

int ara[10] = {1, 2, 4, -2, 5, 3, 5, -3, 7, 8}, n = 10;
int tree[12];
void build()
{
    FOR(i, n)
    {
        unsigned int x = i+1;
        while(1)
        {
            if(x>n+1) break;
            tree[x]+=ara[i];
            x = x+(x&((~x)+1));
        }
    }
}
int query(int x, int y)
{
    if(x!=0) return query(0, y) - query(0, x-1);
    int sum = 0;
    unsigned int xi = y+1;
    while(xi)
    {
        sum+=tree[xi];
        xi = xi- (xi&((~xi)+1));
    }
    return sum;
}
int main()
{
    int t, tst = 1;
    build();
    int x, y;
    while(sf2(x, y)==2){
        pf("%d\n", query(x, y));
    }
    return 0;
}














