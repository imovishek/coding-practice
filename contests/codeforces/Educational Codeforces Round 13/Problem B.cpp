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
    int n;
    scanf("%d",&n);
    int c;
    if(c%400==0)c=1;
    else if(n%100)c=0;
    else if(n%4)c=1;
    for(int i=n+1;;i++)
    {
        int ans;
        ans=(i-n)+(i-n)/4-(i-n)
    }
    return 0;
}
