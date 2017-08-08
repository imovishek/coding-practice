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

struct mat{
    lint X[3][3];
    mat(){mem(X, 0);}

};
lint n, b;
mat mult(mat A, mat B)
{
    mat ans;
    FOR(i, 3)
        FOR(j, 3)
            FOR(k, 3) ans.X[i][j] = (ans.X[i][j] + A.X[i][k] * B.X[k][j]) % MOD;
    return ans;
}

mat power(mat A, int p)
{
    if(p==0){
        mat ans;
        FOR(i, 3) ans.X[i][i] = 1;
        return ans;
    }
    if(p&1){
        return mult(A, power(A, p-1));
    }
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
    sf1(t);

    while(t--)
    {
        sf2ll(n, b);
        if(n==1){
            pcase(tst++);
            pf1(1);
            continue;
        }
        mat now;
        now.X[0][0] = (b*b) % MOD;
        now.X[0][1] = 1;
        now.X[1][1] = 1;
        now.X[1][2] = 1;
        now.X[2][2] = 1;
        lint x = n/2;
        now = power(now, x-1);
        lint ans = (now.X[0][0] + now.X[0][1] * 2 + now.X[0][2]) % MOD;       // cout << ans << endl;

//        ans = (((ans*b) % MOD) * b) % MOD;        cout << ans << endl;

        ans = (ans + (b * ans) % MOD) % MOD;        //cout << ans << endl;

        if(n%2==1){
            ans = (ans*b + (n/2 + 1)) % MOD;
        }        //cout << ans << endl;

        pcase(tst++);
        pf("%lld\n", ans);
    }
    return 0;
}













