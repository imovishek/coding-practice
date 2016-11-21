#include<stdio.h>
int GCD(int a, int b)
{
    int x;
    if(a<b){x=a;a=b;b=x;}

    while(b>0)
    {
        x=a%b;
        a=b;
        b=x;
   }
    return a;
}
int main()
{

    double i,a,b,n,c,d1,d,m,gc;
    while(scanf("%lf %lf",&a,&b)!=EOF)
    {
        scanf("%lf",&n);
        m=1;
        d=214748364;
        if(n<=1/(m*b))m++;
        while(1)
        {
            if(n>=1/(m*b)){
                d1=m*b;c=m*a+1;
                gc=(double)GCD((int)d1,(int)c);

                d1/=gc;
                c/=gc;
                printf("%.0lf %.0lf\n",c,d1);
            }
            if(d1<d)d=d1;
            else break;
            m++;

        }
        printf("%.0lf %.0lf\n",c,d);



    }
    return 0;

}
