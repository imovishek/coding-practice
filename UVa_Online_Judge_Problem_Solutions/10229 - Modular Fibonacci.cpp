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
#define inf             1000000007
#define pi              acos(-1.0)
#define mem(arr,x)      memset((arr), (x), sizeof((arr)));
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i=1;i<=(x); i++)
#define mx              107

using namespace std;
typedef long long int lint;
typedef double dbl;

lint MOD = 0;
lint a[mx][mx] = {{1, 1}, {1, 0}}, b[mx][mx], ans[mx][mx], temp[mx][mx];
lint f[2][2] = {{1}, {0}};

int mult(int n, int m, int r, int c)
{
    if(m!=r) return 0;
    FOR(i, n)
    {
        FOR(j, c)
        {
            ans[i][j] = 0;
            FOR(k, m)
            ans[i][j] = (ans[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;;
        }
    }
    return 1;
}

int rec(lint p)
{
    if(p==1)
    {
        FOR(i, 4)
        FOR(j, 4) ans[i][j] = a[i][j];
        return 0;
    }

    if(p&1)
    {
        rec(p-1);
        FOR(i, 4)
        FOR(j, 4) b[i][j] = ans[i][j];
        mult(2, 2, 2, 2);
    }
    else
    {
        rec(p/2);
        FOR(i, 4)
        FOR(j, 4) b[i][j] = a[i][j] = ans[i][j];
        mult(2, 2, 2, 2);
        FOR(i, 4) FOR(j, 4) a[i][j] = 1;
        a[1][1] = 0;
    }
    return 0;
}

int main()
{
#ifdef OVI
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    lint n, m, r, c;
    while(sf2ll(n, m)==2)
    {
        MOD = (1 << m);
        FOR(i, 4) FOR(j, 4) a[i][j] = 1;
        a[1][1] = 0;
        f[0][0] = 1;
        f[1][0] = 0;
        if(n==0)
        {
            pf1(0);
            continue;
        }
        else if(n==1)
        {
            pf1(1%MOD);
            continue;
        }
        rec(n-1);
        FOR(i, 4)
            FOR(j, 4)
            {
                a[i][j] = ans[i][j];
                b[i][j] = f[i][j];
            }
        pf1(ans[0][0]);
    }

    return 0;
}














