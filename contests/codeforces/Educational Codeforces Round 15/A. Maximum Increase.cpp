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

int ara[100007],endi[100007],n;

int main()
{
    sf("%d",&n);
    FOR(i, n) sf1(ara[i]);
    int len=0,counti=1;
    FOR(i, n-1){
        if(ara[i]<ara[i+1]) counti++;
        else {
            if(len<counti)len=counti;
                counti=1;
        }
    }

            if(len<counti)len=counti;
    pf("%d\n",len);

    return 0;
}
