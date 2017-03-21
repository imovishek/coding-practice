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
    int n, m;
    sf2(n,m);
    int tower[m+1], city[n+1];
    FOR(i, n)
        sf1(city[i]);
    FOR(j, m)
        sf1(tower[j]);
    int to=1 , ci=0, mx=0;
        int dist=inf,flag=0;
    FOR(i, n)
    {
        dist=inf;
        if(!flag)to--;
        flag=0;
        if(tower[to]> city[i])flag=1;
        while(tower[to]<= city[i])
        {
            dist= city[i]-tower[to];
            to++;
            if(to>=m)break;
        }
        if(to>=m){
                if(dist>mx)mx=dist;
                continue;
        }
        dist = min(dist, tower[to]-city[i]);
//        pf("%d %d, i = %d\n", dist, city[i], i);
        if(dist>mx)mx=dist;
    }
    pf("%d\n",mx);

    return 0;
}
