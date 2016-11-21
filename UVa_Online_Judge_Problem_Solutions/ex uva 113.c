#include<stdio.h>
int main()
{
    double n,i,p,temp,mult=1;
    while(scanf("%lf %lf",&n,&p)==2)
    {
        mult=1;
        if(p==1 || p==0){printf("%.0lf\n",p);continue;}
        for(i=2;;i++)
        {
            temp=n;
            while(temp--)
            mult*=i;
            if(mult==p){printf("%.0lf\n",i);break;}
            mult=1;
        }
    }
    return 0;
}
