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
    int n,i;
    scanf("%d",&n);
    int ara[n],k=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }
    sort(ara,ara+n);
    int num=1;
    for(i=1;i<n;i++)
    {
        if(ara[i]==num);
        else if(ara[i]-num>=1){num++;}
    }
    printf("%d\n",num+1);

    return 0;
}
