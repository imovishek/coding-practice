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
#define mx              1000007

using namespace std;
typedef unsigned long long int lint;
typedef double dbl;
char a[mx], b[mx];
lint p[mx], prm = 33;
int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI
    p[0] = 1;
    FOR1(i, mx-1) p[i] = prm * p[i-1];
    int t, tst = 1;
    sf1(t);
    while(t--){
        sf("%s%s", a, b);
        lint hash_b = 0;
        int n = strlen(a);
        int m = strlen(b);
        for(int i = 0; i<m ; i++) hash_b = hash_b*prm + b[i] - '0';
        lint hash_a = 0;
        for(int i = 0; i<m && i<n; i++)
            hash_a = hash_a * prm + a[i] - '0';
        int cnt = 0;
        if(hash_a==hash_b) cnt = 1;
        for(int i = 0, j = m; j<n; j++, i++)
        {
            hash_a -= (p[m-1] * (a[i]-'0'));
            hash_a = hash_a * prm + a[j] - '0';
            if(hash_a==hash_b) cnt++;
        }
        pcase(tst++);
        pf1(cnt);
    }
    return 0;
}














