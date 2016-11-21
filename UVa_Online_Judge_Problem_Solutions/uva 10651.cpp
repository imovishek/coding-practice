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
#define pcase(x) printf("Case %d: ",x)
#define pi acos(-1.0)
#define mini(x,y) ((x<y)?x:y)
using namespace std;
typedef long long int lint;
typedef double dbl;
#define check(x,i) (x&(1<<i))
#define seti (x,i) x|=(1<<i)
#define toggle(x,i) x^=(1<<i)

int dp[1<<13];
int rec(int bit)
{
    if(dp[bit]!=-1) return dp[bit];
    int biti=bit,mino=13,flag=0;
    for(int i=0;i<10;i++)
    {
        bit=biti;
        int s1=check(bit,i), s2=check(bit,i+1) , s3=check(bit,i+2);
        if(( !s1 && s2 && s3 ) || ( s1 && s2 && !s3 ))
        {
            toggle(bit,i);
            toggle(bit,i+1);
            toggle(bit,i+2);
            mino=mini(mino,rec(bit));
            flag=1;
        }

    }
    if(!flag) {
        int siz=0;
        for(int i=0;i<12;i++){
            if(check(bit,0))siz++;
            bit>>=1;
        }

        return siz;
    }
    dp[biti]=mino;
    return mino;
}
int main()
{
    int t;
    char ara[15];
    sf1(t);
    while(t--)
    {
        memset(dp,-1, sizeof(dp));
        sf("%s",ara);
        int bit=0;
        for(int i=0;ara[i];i++)
        {
            bit<<=1;
            bit|=((ara[i]=='o')? 1 : 0);
        }
        pf("%d\n",rec(bit));

    }
    return 0;
}
/*
5
---oo-------

*/
