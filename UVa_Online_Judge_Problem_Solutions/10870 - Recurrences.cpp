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

int d;
int M;
struct mat{
    int X[16][16];
    mat(){mem(X, 0);}
    mat mult(mat A, mat B);
};

mat mult(mat A, mat B){
    mat ans;
    FOR(i, d)
        FOR(j, d)
            FOR(k, d) ans.X[i][j] = (ans.X[i][j] + (A.X[i][k] * B.X[k][j]) % M) % M;
    return ans;
}

mat power(mat A, int p)
{

    if(p==0)
    {
        mat ret;
        FOR(i, d) ret.X[i][i] = 1;
        return ret;
    }
    if(p&1) return mult(A, power(A, p-1));
    mat mo = power(A, p/2);
    return mult(mo, mo);
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n;
    while(sf3(d, n, M))
    {
        if(!d && !n && !M) return 0;
        int f[d], a[d];
        FOR(i, d) sf1(a[i]), a[i]%=M;
        FOR(i, d) {sf1(f[i]); f[i]%=M;}
        if(n<=d) {pf1(f[n-1]); continue;}
        mat A;
        FOR(i, d) A.X[0][i] = a[i];
        FOR1(i, d-1) A.X[i][i-1] = 1;
        A = power(A, n-d);
        int ans = 0;
        FOR(i, d) ans = (ans + (A.X[0][i]*f[d-i-1])% M) % M;
        pf1(ans);
    }
    return 0;
}














