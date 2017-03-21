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
#define mini(x,y) (x<y)?x:y
using namespace std;
typedef long long int lint;
typedef double dbl;
int dp[20][3],ara[20][3],n;

int rec(int pos, int poc)
{
    if(pos==n)return 0;
    int &ret=dp[pos][poc];
    if(ret!=-1)
        return ret;
    ret=21474836;
    for(int i=0;i<3;i++)
    {
        if(i==poc)continue;
        ret=mini(ret,ara[pos][i]+rec(pos+1,i));
    }
    return ret;
}
int main()
{
    int t,tst=1;
    sf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d %d",&ara[i][0],&ara[i][1],&ara[i][2]);
        pcase(tst++);
        int ans=mini(rec(0,0),rec(0,1));
        ans=mini(ans,rec(0,2));
        printf("%d\n",ans);

    }
    return 0;
}
