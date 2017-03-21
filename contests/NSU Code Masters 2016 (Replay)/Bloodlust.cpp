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
    double res;
    double r,tmp;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&r);
        tmp=r*sqrt(15)/4;
        res=-tmp/(tmp+(r*sqrt(3)/2))*r/4+3*r/4;
        printf("%.9lf\n",res+r);
    }
    return 0;
}
