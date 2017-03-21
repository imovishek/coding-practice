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
char ara[1000007],ara2[1000007];

int main()
{
    char i,j;
    sf("%s %s",ara,ara2);
    int len1=strlen(ara),len2=strlen(ara2);
    for( i=0;ara[i];i++)
    {
        if(ara[i]!='0')break;
    }
    int p1=i;
//    len1-=p1;
    for( i=0;ara2[i];i++)
    {
        if(ara2[i]!='0')break;
    }
    int p2=i;
//    len2-=p2;
    for( i=p1,j=p2;ara2[j] && ara[i];i++,j++)
    {
        if(ara[i]!=ara2[j])break;
    }
//    printf("%d %d %d %d*\n",len1,i,len2,j);
    printf("%d\n",len1-i+len2-j);
    return 0;
}

