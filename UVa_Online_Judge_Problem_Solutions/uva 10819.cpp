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
int cap,n;
int ara[101];
int fav[101];
int dp[101][10501];
int rec(int pos, int cp)
{
    if(pos==n){
        if(cp>2000 && cap+200>=cp){
                return 0;
        }
        if(cp<=cap){
            return 0;
        }
        return -2147483647;
    }
    if(cp>cap+200)return -2147483647;
    /*
1900
3
2000 15
1950 10
5 1*/
    if(dp[pos][cp]!=-1)
        return dp[pos][cp];
    int &ret = dp[pos][cp];
    ret=rec(pos+1,cp);
    ret=max(ret,fav[pos]+rec(pos+1,cp+ara[pos]));

    return ret;
}
int main()
{
    while(sf2(cap,n)!=EOF)
    {
        for(int i=0;i<n;i++)for(int j=0;j<=cap+300;j++)dp[i][j]=-1;
        for(int i=0;i<n;i++)
        {
            int cost,f;
            sf2(cost,f);
            ara[i]=cost;
            fav[i]=f;
        }
//        if(cap+200>=2000)cap+=200;
        pf("%d\n",rec(0,0));
    }
    return 0;
}


