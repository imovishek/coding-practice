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
int coin[100],limit[100],counti;
int rec(int n, int m)
{
    int table[m+1];
    memset(table,0,sizeof(table));
    table[0]=1;
    for(int i=0,j;i<n;i++)
    {
        int lm=coin[i]*(limit[i]+1);

        for(j=coin[i];j<=m && j<lm;j++){
            if(table[j]==0 && table[j-coin[i]]!=0)counti++;
            table[j]+=table[j-coin[i]];
        }
        if(j==lm && j<=m && table[j]==0 && table[j-coin[i]]>1){
                counti++;
                table[j]+=(table[j-coin[i]]-1);
        }

    }
}
int main()
{
    int t,tst=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        sf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            sf("%d",&coin[i]);

        for(int i=0;i<n;i++)
            sf("%d",&limit[i]);
        pcase(tst++);
        counti=0;
        rec(n,m);
        pf("%d\n",counti);
    }
    return 0;
}
/*
4
3 10
1 2 4 2 1 1
2 0
1 4 2 1
3 0
1 2 4 2 1 1
2 0
1 4 2 1
*/
