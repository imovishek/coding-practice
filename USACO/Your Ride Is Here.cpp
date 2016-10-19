/*
ID: ovishek1
LANG: C++11
PROB: ride
*/
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
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;


int main()
{
    int t, tst = 1;
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    char str[10], str2[10];
    sf("%s %s", str, str2);
    int l1 = strlen(str);
    int l2 = strlen(str2);
    int a = 1, b = 1;
    FOR(i, l1) a*=str[i]-'A'+1;
    FOR(i, l2) b*=str2[i]-'A'+1;
    a%=47;
    b%=47;
    if(a==b) pf("GO\n");
    else pf("STAY\n");
    return 0;
}














