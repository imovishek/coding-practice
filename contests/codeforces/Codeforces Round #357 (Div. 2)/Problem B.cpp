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
    int n,ans=0,l,m;
    scanf("%d",&n);

    for(int i=0;i<811;i++)
    {
        for(int j=0;j<8101;j++)
        {
           int x=(n-567*i-56*j-1234000*i-123400*j);
           if(x>=0 && x%1234==0){ans=1;break;}
        }
        if(ans==1)break;
    }

    if(ans==1)printf("YES\n");
    else printf("NO\n");
    return 0;
}
