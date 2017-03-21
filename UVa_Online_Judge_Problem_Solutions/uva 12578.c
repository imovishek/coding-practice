#include<stdio.h>
#include<math.h>

int main()
{
    int test;
    double pi,l,carea,ocarea;
    pi=acos(-1);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lf",&l);
        carea=l*l/25*pi;
        ocarea=l*l/10*6-carea;
        printf("%.2lf %.2lf\n",carea,ocarea);

    }
    return 0;
}
