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
int ara[105][105];
int temp[105];
int main()
{
    int n;
    sf1(n);
    FOR(i, n)
    {
        FOR(j, n)
            sf1(ara[i][j]);
    }
    FOR(j, n)
    {
        for(int i=n-2;i>-1;i--)
        {
            ara[i][j]+=ara[i+1][j];
        }
    }

    int maxRec=0;
    FOR(i, n-1)
    {
        for(int j=i+1;j<=n;j++)
        {
            FOR(k, n)
                temp[k]=ara[i][k]-ara[j][k];

            int maxi=0;
            FOR(k,n)
            {
                if(maxi+temp[k]>=0)maxi+=temp[k];
                else {
                    if(maxRec<maxi) maxRec=maxi;
                    maxi=0;
                }
                if(maxRec<maxi) maxRec=maxi;
            }
        }
    }
    pf("%d\n", maxRec);
    return 0;
}
