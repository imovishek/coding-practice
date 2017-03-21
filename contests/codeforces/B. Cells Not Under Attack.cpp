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
#define sf1(a) scanf("%I64d",&a)
#define sf2(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define pi acos(-1.0)
#define FOR(i,x) for(int i=0; i<x ;i++)
#define inf 2147483647
#define mem(arr, x) memset(arr, x, sizeof(arr))
using namespace std;
typedef long long int lint;
typedef double dbl;
int row[100007], col[100007];
int main()
{
    lint ro=0,co=0;
    lint n,m,r,c;
    sf2(n,m);
    lint sum=0,ans;
    FOR(i,m)
    {
        sf2(r,c);
        if(row[r]==0){
            ro++;
            row[r]=1;
        }
        if(col[c]==0){
            co++;
            col[c]=1;
        }
        ans=n*n-ro*n-co*n+ro*co;
        pf("%I64d%c",ans," \n"[i==m-1]);
    }
    return 0;
}
