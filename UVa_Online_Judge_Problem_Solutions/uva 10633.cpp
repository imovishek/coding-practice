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
int main()
{
    lint n;
    while(sf("%lld",&n) && n)
    {
        int flag=0;
        for(int i=1;i<=9;i++)
        {
            if((n-i)%9==0){
                    if(flag)pf(" %lld",(n-i)/9*10+i);
                    else pf("%lld",(n-i)/9*10+i);
                    flag=1;
            }
        }
        if((n)%9==0){
                    if(flag)pf(" %lld",(n)/9*10);
                    else pf("%lld",(n)/9*10);
                    flag=1;
            }
        pf("\n");

    }
    return 0;
}
