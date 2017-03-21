#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 2147483647
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

pii EU;
int gcd(int a, int b)
{
    if(b==0)
    {
        EU.fs = 1;
        EU.sc = 0;
        return a;
    }
    int g = gcd(b, a%b);

    int x = EU.fs;
    EU.fs = EU.sc;
    EU.sc = x - (a/b) * EU.sc;
    return g;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int a, b;
    while(sf2(a, b)!=EOF)
    {
        int g = gcd(a, b);
        pf("%d %d %d\n",EU.fs, EU.sc, g);
    }
    return 0;
}

