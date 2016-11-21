#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,v,A,s,dist,de,lomd;
    while(scanf("%lf %lf %lf %lf %lf",&a,&b,&v,&A,&s)!=EOF)
    {
         A=A*acos(-1)/180;
        if(a==0 && b==0 && v==0 && A==0 && s==0)break;
        de=v/t;
        dist=(v-a*t/2)*t;
        if(A!=90){
            lomd=b/2/tan(A);
            }
            else lomd=0;
            if(A!=0){
            de=b/sin(A)/2;
            }
            else de=a/2;

        printf("%lf %lf\n",lomd,de);
    }


   return 0;
   }
