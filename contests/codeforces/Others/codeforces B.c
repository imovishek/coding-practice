#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>

int main()
{

    double n,a;
    scanf("%lf %lf",&n,&a);
    double l=ceil(log(a));
    double ans=l*(l+1)/2;

    if(a>=pow(2,l)+1)ans+=(l+1)-2;
    if(a>=pow(2,l+1)-1)ans+2;

    printf("%.0lf\n",ans);



    return 0;
}
