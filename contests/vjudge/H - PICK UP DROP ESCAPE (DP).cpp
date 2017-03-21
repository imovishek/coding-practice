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
int dp[22][10005][2];
int n,k,ara[21];
vector<int>vt;
int maxi(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
int con=0;
int rec(int pos, int cp)
{
    int siz=vt.size();
    if(pos==n){
        if(siz==k){
//            for(int i=0;i<siz;i++)
//            printf("%d ",vt[i]);
//            printf("****\n");
            return cp;
        }
            return 0;
    }
    if(siz==k){
//            for(int i=0;i<siz;i++)
//            printf("%d ",vt[i]);
//            printf("****\n");
            return cp;
        }

    if(dp[pos][siz][0]!=-1)
    {
//        printf("%d %d %d %d<3\n",pos,siz,cp^dp[pos][siz],cp);
        return dp[pos][siz];
    }
    int& ret1=dp[pos][siz][0];
    int& ret2=dp[pos][siz][1];
    ret1=rec(pos+1,cp);
    vt.push_back(pos);
//    for(int i=0;i<vt.size();i++)
//            printf("%d ",vt[i]);
//        printf("11***\n");
//    printf("%d*\n",con++);
    ret=maxi(ret,cp^rec(pos+1,ara[pos]));
    vt.pop_back();
//    for(int i=0;i<vt.size();i++)
//            printf("%d ",vt[i]);
//        printf("22****\n");
//    printf("%d**\n",--con);
    return ret;
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
        printf("%d\n",rec(0,0));
//        printf("%d\n",vt.size());

    }
    return 0;
}
