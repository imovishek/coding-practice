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
int ara[121];
int getfake(int p, int q)
{
    printf("Test");
    for(int i=p;i<=q;i++)
        printf(" %d",i);
    fflush(stdout);
    int a;
    scanf("%d",&a);
    if(a==1)
        return getfake(p,)
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<121;i++)ara[i]=i;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("Answer %d\n",getfake(1,n));
        fflush(stdout);
    }
    return 0;
}
