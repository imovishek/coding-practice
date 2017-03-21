#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
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
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
lint gcd(lint a, lint b){return __gcd(a,b);}
lint lcm(lint a, lint b){return a/gcd(a,b)*b;}
int main()
{
    int n,k,a,flag=0;
    sf2(n,k);
    lint st=1;
    while(n--)
    {
        sf1(a);
        st=gcd(k,lcm(st,a));
    }
    if(st==k)pf("Yes\n");
    else pf("No\n");
    return 0;
}
