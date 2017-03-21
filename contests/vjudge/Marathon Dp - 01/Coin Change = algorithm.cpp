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
int coin[100];
int find_way(int n, int k)
{
    int table[k+1];
    for(int i=1;i<=k;i++)table[i]=0;
    table[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=coin[i];j<=k;j++)
        {
            table[j]+=table[j-coin[i]];
            table[j]%=100000007;
        }
    }
    return table[k];
}
int main()
{
    int t,tst=1,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&coin[i]);
        pcase(tst++);
        printf("%d\n",find_way(n,k));
    }
    return 0;
}

