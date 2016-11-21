#include<stdio.h>
int main()
{
    int t;
    double x,y,z;
    scanf("%d",&t);
    while(t--){
          scanf("%lf %lf %lf",&x,&y,&z);

        if(x>y)z=z/(x+y)*(x+x-y);
        else z=z-z/(x+y)*(y+y-x);
            printf("%.0lf\n",z);
    }
    return 0;
}
