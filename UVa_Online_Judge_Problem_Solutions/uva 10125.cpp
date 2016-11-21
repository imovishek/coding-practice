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
using namespace std;
typedef long long int lint;
typedef double dbl;
map<int,pii>mp;
map<int,pii> :: iterator it;
int ara[1001];
bool check(int a, int b, int c, int d)
{
    if(a==c || b==c || b==d || d==a)return false;
    return true;
}
int main()
{
    int n;
    while(sf1(n) && n)
    {
        for(int i=0;i<n;i++) sf1(ara[i]);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                mp[ara[i]-ara[j]]=pii(ara[i],ara[j]);
            }
        }
        int maxi=-2147483647;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
            {
                it=mp.find(ara[i]+ara[j]);
                if(it!=mp.end())
                {
                    if(check(it->sc.fs,it->sc.sc,ara[i],ara[j]))
                    {
                        if(maxi<(it->sc.fs)){
                                maxi=it->sc.fs;
//                                pf("%d + %d + %d = %d\n",ara[i],ara[j],it->sc.sc,maxi);
                        }
                    }
                }
            }
        }
        if(maxi==-2147483647)pf("no solution\n");
        else pf("%d\n",maxi);
        mp.clear();

    }
    return 0;
}
/*

5
-2
-5
3
0
-6

*/
