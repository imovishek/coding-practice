#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    float c;
    for(a=1;a<1000;a++)
    {
        for(b=1;b<1000;b++)
        {
            c=(float)sqrt(a*a+b*b);
            if(c-(int)c==0 && a+b+(int)c==1000) {printf("%d %d %0.0f\n",a,b,c);
            printf("%f\n",a*b*c); break;}
        }
    }
    return 0;
}
