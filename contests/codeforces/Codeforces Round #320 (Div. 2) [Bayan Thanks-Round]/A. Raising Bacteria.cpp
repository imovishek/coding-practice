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
    int n,i=33,counti=0;
    sf("%d",&n);
    while(--i)
    {
        if((n&(1<<(i-1)))!=0){
            counti++;
        }
    }
    printf("%d\n",counti);
    return 0;
}
