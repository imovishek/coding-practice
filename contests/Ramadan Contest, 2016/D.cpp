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
    int t,tst=1;
    sf("%d",&t);
    while(t--)
    {
        int a,sum=0;
        for(int i=0;i<4;i++){
            sf1(a);
            sum+=a;
        }
        int ans=sum;
        if(sum>=10000)ans=sum-sum/5;
        else if(sum>=7500)ans=sum-sum/10;
        pcase(tst++);
        pf("%d\n",ans);

    }
    return 0;
}
