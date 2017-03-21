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
int main()
{
    int n;
    scanf("%d",&n);
    int mini,maxi,rem=n%7,div=n/7;
    maxi=(div)*2+((rem>2) ? 2 : rem);
    mini=div*2+((rem>5) ? 1 : 0);
    printf("%d %d\n",mini,maxi);
    return 0;
}
