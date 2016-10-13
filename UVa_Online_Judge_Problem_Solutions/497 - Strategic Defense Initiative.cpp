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
#define pcase(x) printf("Test #%d:\n",x)
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
using namespace std;
typedef long long int lint;
typedef double dbl;
int ara[10007],dp[10007],dir[10007];
int n;
bool compare(int u, int v)
{
    if(ara[u]< ara[v]) return true;
    return false;
}
int LIS(int u)
{
    if(dp[u]!=-1)return dp[u];
    int maxi=0, v;
    for(int v=u+1; v<n; v++)
    {
        if(compare(u, v))
        {
            if(LIS(v)> maxi)
            {
                maxi=LIS(v);
                dir[u]=v;
            }
        }
    }
    dp[u]=maxi+1;
    return dp[u];
}
void printpath(int u)
{

    while(u!=-1)
    {

        pf("%d\n",ara[u]);
        u=dir[u];
    }

}
int main()
{
    int t,flag=0;
    char str[500];
    sf1(t);
    getchar();
    gets(str);
    while(t--){
            if(flag)pf("\n");
            flag=1;
            n=0;
            while(gets(str) && str[0]){
                sscanf(str,"%d",&ara[n++]);
            }
            mem(dp, -1);
            mem(dir, -1);
            int maxi=0;
            int pos=0;
            FOR(i, n)
            if(LIS(i) >= maxi)
            {
                maxi=LIS(i);
                pos=i;
            }
            pf("Max hits: %d\n", maxi);
            printpath(pos);
    }

    return 0;
}
    /*
    4
    4 2 3 1
    1 3 2 4
    3 2 1 4
    3 2 4 1
    4 3 2 1
    */

