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
int dp[21][10005];
int n,k,ara[21];
vector<int>vt;
//int maxi(int a, int b)
//{
//    if(a>b)
//        return a;
//    return b;
//}
int flag[22],maxi=0,anf[235];
void rec(int pos)
{
    int siz=vt.size();

    if(siz==k){
            int ans=0;
//            if(0<vt[0])return;
            for(int i=0;i<siz;i++)
             ans^=ara[vt[i]];
            if(maxi<ans)maxi=ans;
            return;
        }

//    if(dp[pos][cp]!=-1)return dp[pos][cp];
//    int& ret=dp[pos][cp];
    for(int i=pos;i<n;i++)
    {
        if(flag[i]==0)
        {
            flag[i]=1;
            vt.push_back(i);
            rec(i+1);
            vt.pop_back();
            flag[i]=0;
        }
    }
    return;
}
int main()
{

    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }
        rec(0);
        printf("%d\n",maxi);
//        printf("%d\n",vt.size());
        maxi=0;

    }
    return 0;
}
