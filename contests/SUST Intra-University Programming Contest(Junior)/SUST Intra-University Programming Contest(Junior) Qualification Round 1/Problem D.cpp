#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<climits>
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
#define pf1(a) printf("%d\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define pinf 2147483647
#define ninf -2147483647
//#define seti(p,x) p|=(1<<x)
//#define check(p,x) (p & (1<<x))
//#define reseti(p,x) p&=(~(1<<x))

using namespace std;
typedef long long int lint;
typedef double dbl;
char ara[]="ACGT";
int n,k,counti=0;
vector<char>vt;
void permu()
{
    if(vt.size()==k)
    {
        counti++;
        if(counti==n)
        {
            for(int i=0; i<vt.size(); i++)
            {
                printf("%c",vt[i]);

            }
            pf("\n");
        }
        return;

    }
    for(int i=0; i<4; i++)
    {
        vt.pb(ara[i]);
        permu();
        vt.ppb;
        if(counti==n)return;
    }
}

int main()
{
    while(sf("%d %d",&k,&n)==2)
    {
        counti=0;
        permu();
    }
    return 0;
}

