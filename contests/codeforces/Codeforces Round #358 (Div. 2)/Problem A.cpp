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
#define pf printf
#define sf scanf
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
int main()
{
    lint n,m;
    scanf("%I64d %I64d",&n,&m);
    lint ans=5*(n/5)*(m/5);
    ans+=(n%5)*(m/5);
//    if((n%5)>=5-(m%5))
//        ans+=(n%5);
//    else if((m%5)>=5-(n%5))
//        ans+=(m%5);
    ans+=(m%5)*(n/5);
    lint remn=n%5, remm=m%5;
    for(int i=1;i<=remn;i++)
        for(int j=1;j<=remm;j++)
        if((i+j)%5==0) ans++;
    printf("%I64d\n",ans);
    return 0;
}
