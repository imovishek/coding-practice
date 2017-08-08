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
#define pf1(a)          printf("%llu\n",a)
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
typedef unsigned long long int ulint;
typedef double dbl;

struct mat{
    ulint X[2][2];
    mat(){
        mem(X, 0);
    }
};

mat mult(mat a, mat b){
    mat ret;
    FOR(i, 2)
        FOR(j, 2){
            ulint ans = 0;
            FOR(k, 2) ans += a.X[i][k] * b.X[k][j];
            ret.X[i][j] = ans;
        }
    return ret;
}

mat power(mat a, int p)
{
    if(p==1) return a;
    if(p&1) return mult(a, power(a, p-1));
    mat mo = power(a, p/2);
    return mult(mo, mo);
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
        int p, q, n;
        sf3(p, q, n);
        pcase(tst++);
        if(n==0) {pf1(2); continue;}
        if(n==1) {pf1(p); continue;}
        n--;
        mat a;
        a.X[0][0] = p;
        a.X[0][1] = -q;
        a.X[1][0] = 1;
        a = power(a, n);
        pf1(a.X[0][0] * p + a.X[0][1] * 2);
    }
    return 0;
}














