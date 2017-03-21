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
#define pf printf
#define sf scanf
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
int main()
{
    string sig,conf;
    int i=-1000000001,j,n,a;
    j=1000000001;

    sf("%d",&n);
    while(n--)
    {
        cin >> sig >> a >> conf ;
        if(conf=="Y"){
            if(sig==">")
            {
                if(i<=a)i=a+1;
            }
            else if(sig==">=")
            {
                if(i<a)i=a;
            }

            else if(sig=="<")
            {
                if(j>=a)j=a-1;
            }
            else if(sig=="<=")
            {
                if(j>a)j=a;
            }
        }
        else if(conf=="N")
        {
            if(sig==">")
            {
                if(j>a)j=a;
            }
            else if(sig==">=")
            {
                if(j>=a)j=a-1;
            }

            else if(sig=="<")
            {
                if(i<a)i=a;
            }
            else if(sig=="<=")
            {
                if(i<=a)i=a+1;
            }

        }
        if(i>j)break;
    }
    if(i>j)printf("Impossible\n");
    else printf("%d\n",i);
    return 0;
}
