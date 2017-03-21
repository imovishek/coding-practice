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
    int n;
    char ara[100];
    int flag=0,a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s %d %d",ara,&a,&b);
        if(a>=2400){
            if(b>a)
                flag=1;
        }
    }
    if(flag)printf("YES\n");
    else printf("NO\n");
    return 0;
}
