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
#define FOR(i,x) for(int i=0; i<x ;i++)
#define inf 2147483647
#define mem(arr, x) memset(arr, x, sizeof(arr))
using namespace std;
typedef long long int lint;
typedef double dbl;

int main()
{
    int n;
    sf1(n);
    char ara[n+3];
    sf("%s",ara);
    int len=strlen(ara);
    int mini= inf;
    int num[n+2];
    FOR(i,n)sf1(num[i]);
    for(int i=0;i<len-1;i++)
    {
        if(ara[i]=='R' && ara[i+1]=='L')
            if(mini>(num[i+1]-num[i])/2)mini=(num[i+1]-num[i])/2;
    }
    if(mini==inf)pf("-1\n");
    else pf("%d\n",mini);
    return 0;
}
