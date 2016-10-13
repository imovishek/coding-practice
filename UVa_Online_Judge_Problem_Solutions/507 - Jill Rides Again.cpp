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
    int t, tst=1;
    sf1(t);
    while(t--)
    {
        int n;
        sf1(n);
        int ara[n];
        FOR(i, n-1)
        {
            sf1(ara[i]);
        }
        int sum=0, maxi=0, x=0, y, st;
        FOR(i, n-1)
        {
            if(sum + ara[i]<0)
            {
                sum = 0;
                x = i+1;
            }
            else sum+=ara[i];
            if(maxi<sum)
            {
                st = x;
                y = i;
                maxi = sum;
            }
            else if(maxi==sum){
                if(y-st<i-x){
//                    pf("%d %d %d %d*\n",y, st, i, x);
                    st = x;
                    y = i;
                }
            }
        }
        if(maxi==0) pf("Route %d has no nice parts\n",tst++);
        else pf("The nicest part of route %d is between stops %d and %d\n",tst++, st+1, y+2);
    }
    return 0;
}
