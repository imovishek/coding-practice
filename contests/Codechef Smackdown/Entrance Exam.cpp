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
    int t,n,k,e,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&n,&k,&e,&m);
        lint ara[n],i=0,fn=n-1;
        n--;
        int temp,a;
        while(n--)
        {
            lint sum=0;
            temp=e;
            while(temp--)
            {
                scanf("%d",&a);
                sum+=a;
            }
            ara[i++]=sum;
        }
        e--;
        lint sum=0;
        while(e--)
        {
            scanf("%d",&a);
            sum+=a;
        }
        sort(ara,ara+fn);
        lint req=ara[fn-k]-sum+1;
        if(req>m)printf("Impossible\n");
        else if(req<=0)
            printf("0\n");
        else
            printf("%I64d\n",req);
    }
    return 0;
}

/*
3
5 3 4 15
10 11 9 7
5 13 2 7
11 5 3 9
15 4 2 6
10 6 11

6 4 3 10
9 9 3
9 4 7
8 8 7
5 3 6
2 3 4
6 8

6 4 3 10
9 9 3
9 4 7
8 8 7
5 3 6
2 3 4
2 1


*/
