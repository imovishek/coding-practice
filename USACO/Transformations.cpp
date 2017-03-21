/*
ID: ovishek1
LANG: C++11
PROB: transform
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

char temp[30][30];
char ara[30][30], ta[30][30], desti[30][30];
int n;
bool check()
{
    FOR(i, n)
        FOR(j, n)
            if(desti[i][j]!=temp[i][j]) return false;
    return true;
}

void rotate90()
{
    FOR(i, n)
        FOR(j, n)
            temp[j][n-i-1] = ta[i][j];
    FOR(i, n){
        FOR(j, n)
           /* pf("%d ", temp[i][j]), */ta[i][j] = temp[i][j];
//        puts("");
    }
}

int main()
{
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    int t, tst = 1;
    sf1(n);
    FOR(i, n)
        FOR(j, n){
            sf(" %c", &ara[i][j]);
            ta[i][j] = ara[i][j];
        }
    FOR(i, n)
        FOR(j, n){
            sf(" %c", &desti[i][j]);
        }
    rotate90();
    if(check()) {pf("1\n"); return 0;}
    rotate90();
    if(check()) {pf("2\n"); return 0;}
    rotate90();
    if(check()) {pf("3\n"); return 0;}
    int f = 1;
    FOR(i, n)
        FOR(j, n){
            f &= (ara[i][j] == desti[i][n-j-1]);
            ta[i][j] = ara[i][n-j-1];
        }
    if(f) {pf("4\n"); return 0;}
    FOR(i, 3){
        rotate90();
        f |= check();
    }
    if(f) {pf("5\n"); return 0;}
    FOR(i, n)
        FOR(j, n) ta[i][j] = ara[i][j];
    if(check()) {pf("6\n"); return 0;}
    pf("7\n");
    return 0;
}














