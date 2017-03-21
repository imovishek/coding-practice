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
    int n,d;
    sf2(n,d);
    getchar();
    char ch;
    int counti=0,maxi=0;
    for(int i=0;i<d;i++)
    {
        int flag=0;
        for(int j=0;j<n;j++){
            sf("%c",&ch);
            if(ch=='0')flag=1;
        }
        getchar();
        if(flag==1)counti++;
        else {if(counti>maxi)maxi=counti; counti=0;}

    }
    if(counti>maxi)maxi=counti;
    pf("%d\n",maxi);
    return 0;
}
