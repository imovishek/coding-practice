#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
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
    string st;
    while(getline(cin, st)){
        istringstream ss(st);
        int a;
        vector<int>vt;
        while(ss>>a) vt.pb(a);
        int sum=0, maxi=0;
        for(int i=0;i<vt.size();i++)
        {
            if(sum+vt[i]<=0)
                sum = 0;
            else sum+=vt[i];
            maxi = max(maxi, sum);
        }
        pf("%d\n",maxi);
    }
    return 0;
}
