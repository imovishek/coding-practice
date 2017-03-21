#include<stdio.h>
int main(){


int t;
double ar,a,b,c;
scanf("%d",&t);
while(t--)
{

    scanf("%lf %lf %lf",&a,&b,&c);

    ar=a*c;
    printf("%.4lf\n",ar);

}




return 0;
}
