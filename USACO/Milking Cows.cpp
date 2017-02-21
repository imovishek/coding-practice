/*
ID: ovishek1
LANG: C++11
PROB: milk2
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

int ara[mx*10];

int main()
{
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    int t, tst = 1;
    int n;
    sf1(n);
    int maxi = 0, mini = inf;
    FOR1(i, n)
    {
        int u, v;
        sf2(u, v);
        mini = min(mini, u);
        maxi = max(maxi, v);
        for(int j = u; j<v ; j++)
            ara[j] = i;
    }
    int a = 1, b = -1;
    int s1 = 0, s2 = 0;
    for(int i = mini; i<maxi; i++){
        if(ara[i]==0){
            s2++;
            s1 = 0;
        }
        else{
            s1++;
            s2 = 0;
        }
        a = max(a, s1);
        b = max(b, s2);
    }
    cout << a << " " << b << endl;
    return 0;
}














