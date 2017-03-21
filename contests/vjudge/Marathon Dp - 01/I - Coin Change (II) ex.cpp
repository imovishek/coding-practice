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
    int table[k+1][n];
    for(int i=0;i<=n;i++)table[0][i]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j>0)table[i][j]=table[i][j-1];
            else table[i][j]=0;
            if(i-coin[j]>=0)table[i][j]+=table[i-coin[j]][j];
            if(table[i][j]>100000006)
                table[i][j]%=100000007;
        }
    }
    return table[k][n-1];
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
