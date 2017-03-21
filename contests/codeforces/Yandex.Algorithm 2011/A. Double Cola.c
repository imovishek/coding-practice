#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
#define pf printf
#define sf scanf
#define pcase(x) printf("Case %d: ",x)
typedef long long int lint;
typedef double dbl;
int logi(int n)
{
    int i=-1;
    while(n)
    {
        n>>=1;
        i++;
    }
    return i;
}
int main()
{
    int n,lg,power;
    sf("%d",&n);
    double res=n/5.0+1;
    res=logi(res);
    lg=floor((int)res);
    power=1<<lg;
    res=(double)(n-5*(power-1))/power;
    lg=ceil(res);
    switch (lg)
    {
    case 0:
        pf("Howard\n");
        break;
    case 1:
        pf("Sheldon\n");
        break;
    case 2:
        pf("Leonard\n");
        break;
    case 3:
        pf("Penny\n");
        break;
    case 4:
        pf("Rajesh\n");
        break;
    case 5:
        pf("Howard\n");
        break;
    }
    return 0;
}
