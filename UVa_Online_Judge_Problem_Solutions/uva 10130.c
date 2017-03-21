#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
#define pf printf
#define sf scanf
#define double dbl
#define check(x,y) (flag[x]&(1<<y))
#define seti(x,y) flag[x]|=(1<<y)
typedef long long int lint;
int n,cap,dp[1001][31],flag[1001],w[1001],p[1001];
int maxi(int a, int b)
{
    if(a>b)return a;
    else return b;
}
int rec(int pos, int cp)
{
    if(pos==n || cp==cap)
        return 0;

    if(check(pos,cp))
        return dp[pos][cp];
    int *ret=&dp[pos][cp];
    *ret=rec(pos+1,cp);
    if(cp+w[pos]<=cap)
        *ret=maxi(*ret, rec(pos+1, cp+w[pos])+p[pos]);
    seti(pos,cp);
    return *ret;


}
int main()
{
    int i,m;

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d %d",&p[i],&w[i]);
        scanf("%d",&m);
        while(m--){
            for(i=0;i<n;i++)flag[i]=0;
            scanf("%d",&cap);
            int sumi=sum;
            sum+=rec(0,0);

        }
        printf("%d\n",sum);
    }
    return 0;
}
