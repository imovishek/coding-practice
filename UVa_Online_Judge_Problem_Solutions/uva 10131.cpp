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
using namespace std;
typedef long long int lint;
typedef double dbl;
struct elephant{
    int w, IQ, index;
}ara[1007];
bool comp(elephant a, elephant b){
    if(a.w< b.w && a.IQ>b.IQ) return true;
    return false;
}
int main()
{
    int n=0;
    while(sf("%d %d",&ara[n].w, &ara[n].IQ)!=EOF)ara[n].index=n++;
    sort(ara,ara+n,comp);
    vector<int>v;
    int counti=0;
    v.pb(ara[0].index);
    for(int i=0;i<n;i++)pf("%d %d*\n",ara[i].index, ara[i].w);
    for(int i=1;i<n;i++)
        if(comp(ara[i-1], ara[i])){
                counti++;
                v.pb(ara[i].index);
        }
        pf("%d\n",counti);
    for(int i=0;i<v.size();i++)
        pf("%d\n",v[i]+1);
    return 0;
}
