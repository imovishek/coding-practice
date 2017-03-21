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
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
int n1,n2,k1,k2;
int dp[101][101][11][11];
int rec(int s1,int s2, int num1, int num2)
{
    if(s1==0 && s2==0)return 1;
    if(s1+s2<=0)return 0;
    int&ret=dp[s1][s2][num1][num2];
    if(ret!=-1)
        return ret;
    ret=0;
    if(num1<k1 && s1>0)
    {
        ret+=rec(s1-1,s2,num1+1,0);
    }
    if(num2<k2 && s2>0)
    {
        ret+=rec(s1,s2-1,0,num2+1);
    }
    ret%=100000000;
    return ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    sf("%d %d %d %d",&n1,&n2,&k1,&k2);
    printf("%d\n",rec(n1,n2,0,0));
    return 0;
}
